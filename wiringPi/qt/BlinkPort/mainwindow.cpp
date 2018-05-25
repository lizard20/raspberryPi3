#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow ( QWidget *parent ) :
    QMainWindow ( parent ),
    ui ( new Ui::MainWindow )
{
    ui->setupUi ( this );
    ui -> status -> setText ( " " );
    ui -> blinkButton -> setText ( "Start" );
    this -> timer = new QTimer ( this );

    this -> state = HIGH;

    // setup wiringPi
    wiringPiSetupPhys ();

    // slot
    connect ( timer, SIGNAL ( timeout () ), this, SLOT ( blink () ) );
}

MainWindow::~MainWindow ()
{
    digitalWrite ( this -> port, LOW );
    delete ui;
}

void
MainWindow::blink ()
{
    bool ok;
    this -> portStr = ui -> portBox -> currentText ();
    this -> port  = ( this -> portStr ).toUShort( &ok );
    ui -> status -> setText ("blinking  port " + this -> portStr );
    // setup port
    pinMode ( this -> port, OUTPUT );
    digitalWrite ( this -> port, this -> state );
    // flip state
    this -> state  = !( this -> state );
}

void
MainWindow::on_blinkButton_clicked ()
{
    // 100 ~ 100 ms
    const int T = 100;

    if ( timer -> isActive () )
    {
        timer -> stop ();
        ui -> blinkButton -> setText ( "Start" );
        ui -> status -> setText ( "Stop" );
        ui -> portBox -> setEnabled( true );
        digitalWrite ( this -> port, LOW );
    }
    else
    {
        timer -> start ( T );
        ui -> blinkButton -> setText ( "Stop" );
        ui -> portBox -> setEnabled( false );
    }
}
