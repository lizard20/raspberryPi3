#include "mainwindow.h"
#include "ui_mainwindow.h"

// constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // ADS1115 address
    const unsigned int ADS_ADDRESS = 0x48;

    // chooses a PIN value > 63
    this -> pin = 64;

    // Creates timer
    QTimer* timer = new QTimer ( this );

    // sets up lcdNumber
    ui -> lcdNumber -> setDecMode ();

    // opens i2c-1 device
    if ( !ads1115Setup ( this -> pin, ADS_ADDRESS ) )
    {
        qDebug ( "Couldn't open i2c-1 device" );
        ui -> lcdNumber -> display ( 0 ); 
    }
    else
    {
        // configures Gain Control to 6.144 volts - 0
        digitalWrite ( this -> pin, 1 );
        // configures Data Rate to 475 SPS - 6
        digitalWrite ( this -> pin + 1, 4 );

        // reads and displays data periodiocally
        connect ( timer, SIGNAL ( timeout () ), this, SLOT ( displayValue () ) );

        // 1000 ~ 1 sec
        const int T = 1000;

        // starts timer
        timer -> start ( T );
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void
MainWindow::displayValue () const
{
    // integer to float conversion constant
//    const double VOLTS_PER_STEP =  6.144 / 32768.0;
    const double VOLTS_PER_STEP =  4.096 / 32768;

    quint16 int_value;

    int_value = static_cast < quint16 > ( analogRead ( this -> pin ) );

    // converts from 16 bits integer to float
    double voltage = int_value * VOLTS_PER_STEP;

    // displays float value 
    ui -> lcdNumber -> display ( voltage );
}
