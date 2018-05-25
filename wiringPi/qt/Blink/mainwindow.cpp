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

    // pin configuration
    wiringPiSetupPhys ();
    pinMode ( this -> port, OUTPUT );
    digitalWrite ( this -> port, LOW );

    // slot
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
   ui -> status -> setText ( "blinking port " + QString::number ( this -> port ) );
   digitalWrite ( this -> port, this -> state );
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
        this -> timer -> stop ();
        ui -> blinkButton -> setText ( "Start" );
        ui -> status -> setText ( "stop" );
        digitalWrite ( this -> port, LOW );
    }
    else
    {
        this -> timer -> start ( T );
        ui -> blinkButton -> setText ( "Stop" );
    }
}
