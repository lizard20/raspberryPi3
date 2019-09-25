#include "mainwindow.h"
#include "ui_mainwindow.h"

// constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui -> labelStatus -> setText ( "Port 3: OFF" );

    // creates  timer
    this -> timer = new QTimer ( this );

    // initializes port number and state
    const quint8 PORT = 3;
    this -> port = PORT;
    this -> state = LOW;

    // sets up wiringPi
    if ( wiringPiSetupPhys () )
    {
        // displays  error message
        ui -> labelStatus -> setText ( "<font color='red'>Fail to set up WiringPi!</font>" );

        // disables blink push button
        ui -> pushButtonBlink -> setEnabled ( false );
    }
    else
    {
        // configures port as output
        pinMode ( this -> port, OUTPUT );
        
        //  initializes output port to LOW
        digitalWrite ( this -> port, LOW );

        // connects timer to blink method and executes it every T seconds
        connect ( timer, SIGNAL ( timeout () ), this, SLOT ( blink () ) );
    }
}

// destructor
MainWindow::~MainWindow()
{
    // when finished writes LOW to output port
    digitalWrite ( this -> port, LOW );
    delete ui;
}

// blink method
void
MainWindow::blink ( void )
{
    // writes state to the output port
    digitalWrite ( this -> port, this -> state = !( this -> state ) );
}


// start and stop
void
MainWindow::on_pushButtonBlink_clicked ()
{
    // 100 ~ 100 ms
    const quint16 T = 100;

    // if clicked stop
    if ( this -> timer -> isActive () )
    {
        // stops timer
        this -> timer -> stop ();

        // displays "stop" status message
        ui -> labelStatus -> setText ( "Port 3: Stop" );

        // displays "Start" label on blink button
        ui -> pushButtonBlink -> setText ( "Start" );

        // enables "Quit" button
        ui -> pushButtonQuit -> setEnabled ( true );

        // writes LOW  to the output port
        digitalWrite ( this -> port, LOW );
    }
    // if clicked start
    else
    {
        // starts timer
        this -> timer -> start ( T );
        
        // displays "blink" status message
        ui -> labelStatus -> setText ( "Port 3: Blinking" );

        // displays 'Stop' label on blinkButton
        ui -> pushButtonBlink -> setText ( "Stop" );

        // disables "Quit" button
        ui -> pushButtonQuit -> setEnabled ( false );
    }
}
