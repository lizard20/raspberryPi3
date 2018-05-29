#include "mainwindow.h"
#include "ui_mainwindow.h"

// file descriptor
int fd;

// constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Creates timer
    QTimer* timer = new QTimer ( this );

    // sets up lcdNumber
    ui -> lcdNumber -> setDecMode( );

    // error message
    const QString err_message = "ERROR!";

    // ********** configuration ********
    // OS   = 0x1       Single shot
    // MUX  = 0x100     AINp = AIN0, AINn = GND
    // PGA  = 0x000     Full Scale +-6.144 Volts
    // MODE = 0x1       Power-down single shot 
    // DR   = 0x110     Data Rate 475 SPS
    // COMP_MODE = 0x0  Traditional comparator with hysteresis
    // COMP_POL  = 0x0  Active low
    // COMP_LAT  = 0x0  Non-latching comparator
    // COMP_QUE  = 0x0  Assert after one conversion
    // *******************************
    quint16  config = 0x0;
    config |= OS       | MUX2     | MUX1      | MUX0;
    config |= PGA2     | PGA1     | PGA0      | MODE;
    config |= DR2      | DR1      | DR0       | COMP_MODE;
    config |= COMP_POL | COMP_LAT | COMP_QUE1 | COMP_QUE0;

    // opens i2c-1 device
    fd =  wiringPiI2CSetup ( ADS_ADDRESS );
    if ( fd < 0 )
    {
        qDebug ( "Couldn't open i2c-1 device" );
        ui -> lcdNumber -> display ( 0 ); 
    }

    // writes config parameters
    else if ( wiringPiI2CWriteReg16 ( fd, 1, config ) )
    {
        qDebug ( "Error writing device" );
        ui -> lcdNumber -> display ( 0 ); 
    }
    else
    {
        // starts reading and displaying data
        this -> displayValue ();

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
    // to manipulate input data from ADS1115
    union Data
    {
        quint16 data16;
        quint8 data8 [ 2 ];
    };

    // integer to float conversion constant
    const float VOLTS_PER_STEP =  6.144 / 32768.0;

    // reads voltage as 16 bits integer
    Data t, *input =  &t;
    input -> data16 = wiringPiI2CReadReg16 ( fd, 4 );

    // arranges the bytes
    // MSByte in data8 [ 0 ]
    // LSByte in data8 [ 1 ]
    input -> data16 =  input -> data8 [ 1 ] | input -> data8 [ 0 ] << 8;

    // converts from 16 bits integer to float
    float floatValue = input -> data16 * VOLTS_PER_STEP;

    // displays float value 
    ui -> lcdNumber -> display ( floatValue );
}
