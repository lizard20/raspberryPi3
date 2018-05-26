#include "mainwindow.h"
#include "ui_mainwindow.h"

// constructor
MainWindow::MainWindow ( QWidget *parent ) :
    QMainWindow ( parent ),
    ui ( new Ui::MainWindow )
{

    ui -> setupUi ( this );
    ui -> status -> setText ( " " );
    ui -> blinkButton -> setText ( "Start" );

    this -> timer = new QTimer ( this );

    this -> state = HIGH;

    // wiringPi setup
    if ( wiringPiSetupPhys () )
    {
        ui -> status -> setText ( "<font color='red'>Failing to setup wiringPi</font>" );
        ui -> portBox -> setEnabled ( false );
        ui -> blinkButton -> setEnabled ( false );
    }

    // config default output
    this -> config_port ();

    // timer executes blink method periodically
    connect ( timer, SIGNAL ( timeout () ), this, SLOT ( blink () ) );

    // detects any change in port number and configures the corresponding port
    connect ( ui -> portBox, SIGNAL ( activated ( int ) ), this, SLOT ( config_port () ) );
}

// destructor
MainWindow::~MainWindow ()
{
    digitalWrite ( this -> port, LOW );
    delete ui;
}

void
MainWindow::config_port ()
{
    // reads port number
    portStr = ui -> portBox -> currentText ();

    // convers string number port to unsigned integer
    bool ok;
    this -> port  = ( portStr ).toUShort ( &ok );

    // sets up port as output
    pinMode ( this -> port, OUTPUT );
}

// blink method
void
MainWindow::blink ()
{
    // writes to the output port
    digitalWrite ( this -> port, this -> state );
    
    // flips state

    this -> state  = !( this -> state );
}

// start stop method
void
MainWindow::on_blinkButton_clicked ()
{
    // 100 ~ 100 ms
    const int T = 100;

    if ( timer -> isActive () )
    {
        // stops timer
        timer -> stop ();

        // displays 'Start' label on blinkButton
        ui -> blinkButton -> setText ( "Start" );
        

        // displays 'stop' state message
        ui -> status -> setText ( "<font color='blue'>stop</font>" );
     
        // enables quitButton and portBox
        ui -> portBox -> setEnabled ( true );
        ui -> quitButton -> setEnabled ( true );

        // writes 0 volts to the output port
        digitalWrite ( this -> port, LOW );
    }
    else
    {
        // starts timer
        timer -> start ( T );

        // displays 'blinking' state message
        QString message = "blinking port " + portStr;
        QString colour = "blue";
        QString display  = tr ( "<font color='%1'>%2</font>" );
        ui -> status -> setText ( display.arg ( colour, message ) );

        // displays 'Stop' label on blinkButton
        ui -> blinkButton -> setText ( "Stop" );

        // disables portBox
        ui -> portBox -> setEnabled ( false );
        ui -> quitButton -> setEnabled ( false );
    }
}
