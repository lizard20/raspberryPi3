#include "mainwindow.h"
#include "ui_mainwindow.h"

// constructor
MainWindow::MainWindow ( QWidget *parent ) :
    QMainWindow ( parent ),
    ui ( new Ui::MainWindow )
{
    ui -> setupUi ( this );
    ui -> status -> setText ( " " );
    this -> timer = new QTimer ( this );
    
    // output port 3
    this -> port = 3;
    this -> state = HIGH;

    // wiringPi setup
    if ( wiringPiSetupPhys () )
    {
        ui -> status -> setText ( "<font color='red'>Failing to setup wiringPi</font>" );
        ui -> blinkButton -> setEnabled ( false );
    }

    // configures port as output
    pinMode ( this -> port, OUTPUT );
    
    // writes 0 volts to the output port
    digitalWrite ( this -> port, LOW );

    // timer executes blink method periodically
    connect ( timer, SIGNAL ( timeout () ), this, SLOT ( blink () ) );
}

// destructor
MainWindow::~MainWindow()
{
    digitalWrite ( this -> port, LOW );
    delete ui;
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

    if ( this -> timer -> isActive () )
    {
        // stops timer
        this -> timer -> stop ();
        
        // displays 'Start' label on blinkButton
        ui -> blinkButton -> setText ( "Start" );
        
        // displays 'stop' state message
        ui -> status -> setText ( "<font color='blue'>stop</font>" );
        
        // writes 0 volts to the output port
        digitalWrite ( this -> port, LOW );

        // enables quit button
        ui -> quitButton -> setEnabled ( true );
    }
    else
    {
        // starts timer
        this -> timer -> start ( T );

        // displays 'Stop' label on blinkButton
        ui -> blinkButton -> setText ( "Stop" ); 
    
        // displays 'blinking' state message
        QString message = "blinking port " + QString::number ( this -> port );
        QString colour = "blue";
        QString display  = tr ( "<font color='%1'>%2</font>" );
        ui -> status -> setText ( display.arg ( colour, message ) );
        
        // disables quit button
        ui -> quitButton -> setEnabled ( false );
    }
}
