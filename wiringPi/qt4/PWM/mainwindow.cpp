#include "mainwindow.h"
#include "ui_mainwindow.h"

// constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui -> setupUi(this);
    
    // correspondence between: frequency - string description
    this -> frequencyRange.insert ( 1e3   , "0 - 1K Hz"   );
    this -> frequencyRange.insert ( 10e3  , "0 - 10K Hz"  );
    this -> frequencyRange.insert ( 100e3 , "0 - 100K Hz" );

    // max and min frequencies
    const int MINFREQ = 0;

    // duty cycle max and min values
    const int MAXDC = 100;
    const int MINDC = 0;

    // add frequency range items
    QList < QString > values = frequencyRange.values ();
    for ( int i = 0; i < values.size (); ++i )
    {
        ui -> comboBox -> addItem ( values.at ( i ) );
    }

    // init values for frequency slider and freq display
    ui -> freqLcd -> display ( MINFREQ );
    ui -> freqSlider -> setMinimum ( MINFREQ );
    QMap < int, QString > :: const_iterator i = frequencyRange.constBegin ();
    ui -> freqSlider -> setMaximum ( i.key () );

    // init values for ducty cycle slider and duty cycle  display
    ui -> dcLcd -> display ( MAXDC / 2 );
    ui -> dcSlider -> setMaximum ( MAXDC);
    ui -> dcSlider -> setMinimum ( MINDC );

    // wiringPi setup
    if ( wiringPiSetupPhys () )
    {
        qDebug ( "Failing to setup wiringPi" );
    }
    else
    {
        // init duty cycle to 50 %
        this -> dutyCycleP = MAXDC / 2;

        // min frequency = 0
        this -> freq = MINFREQ;

        // sets duty cycle slider to 50 %
        ui -> dcSlider -> setValue ( this -> dutyCycleP );

        // config PWM port
        this -> config ();
    }
}

// destructor
MainWindow::~MainWindow()
{
    pwmSetRange ( 0 );
    pwmSetClock ( 0 );
    pwmWrite ( this -> pwmPort, 0 );
 
    delete ui;
}

// slot for frequency slider
void
MainWindow::on_freqSlider_valueChanged ( int f )
{
    ui -> freqLcd -> display( f );
    this ->  freq = f;
    this -> pwmOutput ();
}

// slot for duty cycle slider
void
MainWindow::on_dcSlider_valueChanged ( int dc ) 
{
    ui -> dcLcd -> display ( dc );
    this -> dutyCycleP = dc;
    this -> pwmOutput ();
}

// slot for frequency ranges box
void
MainWindow::on_comboBox_currentIndexChanged ( int index )
{
    QMap < int, QString > :: const_iterator i = frequencyRange.constBegin ();
    switch ( index )
    {
        // puts max frequency to 1K Hz
        case 0:
            ui -> freqSlider -> setMaximum ( i.key () );
            break;
        // puts max frequency to 10K Hz
        case 1:
            ui -> freqSlider -> setMaximum ( ( ++i ).key () );
            break;
        // puts max frequency to 100K Hz
        case 2:
            ++i;
            ui -> freqSlider -> setMaximum ( ( ++i ).key () );
            break;
        default:
            qDebug () << "Error choosing frequency range";
            break;
    }
}

void
MainWindow::config ()
{
    // sets PWM port to 35
    this -> pwmPort = 35; 

    // sets port to ALT MODE-5
    const int FSEL_ALT5 = 0b010;
    pinModeAlt ( this -> pwmPort, FSEL_ALT5 );

    // sets Mark/Space mode 
    pwmSetMode ( PWM_MODE_MS );
}

void
MainWindow::pwmOutput ()
{
    // Base frequency 19.2 MHz/
    const double FBASE = 19.2e6;
    int range = 0;
    int DIVISOR = 2;

    if ( this -> freq == 0 )
    {
        range = 0;
        DIVISOR = 0;
    }
    else
    {
        // range = 19.2e6 / ( DIVISOR x frequency ) 
        DIVISOR = 2;
        range = FBASE / ( DIVISOR * ( this -> freq ) );
    }
   
    // duty cycle = ( range * duty_cycle(%) ) / 100
    int dutyCycle = ( range * ( this -> dutyCycleP ) ) / 100;
    
    // frequency = 19.2e6 / ( DIVISOR x RANGE )
    pwmSetRange ( range );
    pwmSetClock ( DIVISOR );
    
    // generates PWM at a determined frequency and duty cycle
    pwmWrite ( this -> pwmPort,  dutyCycle );
}

