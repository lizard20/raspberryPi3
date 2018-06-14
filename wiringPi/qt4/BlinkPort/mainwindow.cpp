#include "mainwindow.h"
#include "ui_mainwindow.h"

// constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this -> timer = new QTimer ( this );
    ui -> labelStatus -> setText ( "" );
    ui -> pushButtonBlink -> setText( "Start" );

    //  list of valid ports
    this -> ports << 3  << 5  << 7  << 8  << 10 << 11 << 12 << 13 << 15;
    this -> ports << 16 << 18 << 19 << 21 << 22 << 23 << 24 << 26 << 29;
    this -> ports << 31 << 32 << 33 << 35 << 36 << 37 << 38 << 40;

    // combo box labels
    for ( int i = 0; i < ports.size (); ++i )
    {
        ui -> comboBoxPorts -> addItem ( QString::number ( ports.at ( i ) ) );
    }

    // init state 
    this -> state = LOW;

    // config wiringPi
    if ( wiringPiSetupPhys () )
    {
        ui -> labelStatus -> setText ( "<font color='red'>Failing to setup wiringPi</font>" );
        ui -> comboBoxPorts -> setEnabled ( false );
        ui -> pushButtonBlink -> setEnabled ( false );
    }
    else
    {
         // timer executes blink method periodically
        connect ( timer, SIGNAL ( timeout () ), this, SLOT ( blink () ) );

        // detects any change in port number and configures the corresponding port
        connect ( ui -> comboBoxPorts, SIGNAL ( currentIndexChanged ( int ) ), this, SLOT ( config_port () ) );
    }
}

// destructor
MainWindow::~MainWindow()
{
    digitalWrite ( this -> ports.at ( ui -> comboBoxPorts -> currentIndex () ), LOW );
    delete ui;
}

// blink method
void
MainWindow::blink( void )
{
    // writes to the output port
    digitalWrite ( this -> ports.at ( ui -> comboBoxPorts -> currentIndex () ), this -> state = !( this -> state ) );
}

// config method
void
MainWindow::config_port ()
{
    pinMode ( this -> ports.at ( ui -> comboBoxPorts -> currentIndex () ), OUTPUT );
}

// starts stops method
void
MainWindow::on_pushButtonBlink_clicked ()
{
    // 100 ~ 100ms
    const int T = 100;
    if ( timer -> isActive () )
    {
        // stops timer
        timer -> stop ();

        // displays 'Start' label on blinkButton
        ui -> pushButtonBlink -> setText ( "Start" );

        // displays 'stop' state message
        ui -> labelStatus -> setText ( "<font color='blue'>stop</font>" );

        // enables quitButton and portBox
        ui -> comboBoxPorts -> setEnabled ( true );
        ui -> pushButtonQuit -> setEnabled ( true );

        // writes 0 volts to the output port
        digitalWrite ( this -> ports.at ( ui -> comboBoxPorts -> currentIndex () ), LOW );
    }
    else
    {
        // starts timer
        timer -> start ( T );

        // displays 'blinking' state message
        QString message = "blinking port " + ui -> comboBoxPorts -> currentText ();
        QString colour = "blue";
        QString display  = tr ( "<font color='%1'>%2</font>" );
        ui -> labelStatus -> setText ( display.arg ( colour, message ) );

        // displays 'Stop' label on blinkButton
        ui -> pushButtonBlink -> setText ( "Stop" );

        // disables portBox and Quit button while led is blinking
        ui -> comboBoxPorts -> setEnabled ( false );
        ui -> pushButtonQuit -> setEnabled ( false );
    }
}
