#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // wiringPi setup
    if ( wiringPiSetupPhys () )
    {
        qDebug ( "Failing to setup wiringPi" );
    } 
    else
    {
        // init duty cycle to 50 %
        this -> dutyCycleP = ( ui -> dialDC ->  maximum () - 1 ) / 2;

        // min frequency = 0
        this -> freq = 0;

        // config PWM port
        this -> config ();
    }
}

MainWindow::~MainWindow()
{
    pwmSetRange ( 0 );
    pwmSetClock ( 0 );
    pwmWrite ( this -> pwmPort, 0 );
 
    delete ui;
}

void
MainWindow::on_dialFreq_valueChanged ( int value )
{
    /*  ********** Trick to avoid moving dial from min to max  and
    **  viceversa */
    static int flag = 0;

    if ( value > ui -> dialFreq -> maximum () - 1 && flag == 0 )
    {
        flag = 1;
    }
    else if ( value < ui -> dialFreq -> maximum () - 1 && value  > ui -> dialFreq -> maximum () - 1000  && flag == 1 )
    {
        flag = 0;
    }
    else if ( value < 0 && flag == 0 )
    {
        flag = -1;
    }
    else if ( value > 0 && value < 1000 && flag == -1 )
    {
        flag = 0;
    }

    if ( flag == 0 )
    {
        ui -> lcdFreq -> display ( value );
        this -> freq =  value;  
    }
    else if ( flag == 1 )
    {
        ui -> lcdFreq -> display ( ui -> dialFreq -> maximum() - 1 );
        this -> freq =  ui -> dialFreq -> maximum () - 1;
    }
    else if ( flag == -1 ) 
    {
        ui -> lcdFreq -> display (  ui -> dialFreq -> minimum() + 1 );
        this -> freq =  ui -> dialFreq -> minimum ()  + 1;  
    }
    /* ******************************************************/ 
    
    this -> pwmOutput ();
}

void
MainWindow::on_dialDC_valueChanged ( int value )
{
    /*  ********** Trick to avoid moving dial from min to max  and
    **  viceversa */
    static int flag = 0;

     if ( value > ui -> dialDC -> maximum () - 1 && flag == 0 )
     {
         flag = 1;
     }
     else if ( value < ui -> dialDC -> maximum () - 1 && value  > ui -> dialDC -> maximum () - 5  && flag == 1 )
     {
         flag = 0;
     }
     else if ( value < 0 && flag == 0 )
     {
         flag = -1;
     }
     else if ( value > 0 && value < 2 && flag == -1 )
     {
         flag = 0;
     }

    // display 
    if ( flag == 0 )
    {
        ui -> lcdDC -> display ( value );
        this -> dutyCycleP = value;
    }
    else if ( flag == 1 )
    {
        ui -> lcdDC -> display ( ui -> dialDC -> maximum () - 1 );
        this -> dutyCycleP = ui -> dialDC -> maximum () - 1 ;
    }
    else if ( flag == -1 )
    {
        ui -> lcdDC -> display ( ui -> dialDC -> minimum() + 1 );
        this -> dutyCycleP = ui -> dialDC -> minimum () + 1 ;
    }
    /* ******************************************************/

    this -> pwmOutput ();
}

void
MainWindow::config ()
{
    // sets PWM port to 35
    const quint8 PWM_PORT = 35;
    this -> pwmPort = PWM_PORT; 

    // sets port to ALT MODE-5
    const quint8 FSEL_ALT5 = 0b010;
    pinModeAlt ( this -> pwmPort, FSEL_ALT5 );

    // sets Mark/Space mode 
    pwmSetMode ( PWM_MODE_MS );
}

void
MainWindow::pwmOutput () const
{
    // Base frequency 19.2 MHz/
    const double FBASE = 19.2e6;
    quint32 range = 0;
    quint8 DIVISOR = 2;

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
    quint32 dutyCycle = ( range * ( this -> dutyCycleP ) ) / 100;
    
    // frequency = 19.2e6 / ( DIVISOR x RANGE )
    pwmSetRange ( range );
    pwmSetClock ( DIVISOR );
    
    // generates PWM at a determined frequency and duty cycle
    pwmWrite ( this -> pwmPort,  dutyCycle );
}

