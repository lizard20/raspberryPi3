//
// Program: i2c_ads1115.cpp
// Purpose: Read analog signal using DAC
//          ADS115 through  i2c port
// Author:  Aldo Nunez

#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<inttypes.h>
#include<wiringPiI2C.h>
#include "i2c_ads1115.hpp"

using namespace std;

union DATA
{
    uint16_t data16;
    uint8_t data8 [ 2 ];
};

int
main ()
{
    DATA t, *input = &t;
    input -> data16 = 0x0;

    // integer to float conversion constant
    const float VOLTS_PER_STEP =  6.144 / 32768.0;

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
    uint16_t config = 0x0;
    config |= OS       | MUX2     | MUX1      | MUX0;
    config |= PGA2     | PGA1     | PGA0      | MODE;
    config |= DR2      | DR1      | DR0       | COMP_MODE;
    config |= COMP_POL | COMP_LAT | COMP_QUE1 | COMP_QUE0;

    // opens i2c-1 device
    int fd = wiringPiI2CSetup ( ADS_ADDRESS );
    if ( fd == -1 )
    {
        cerr << "Couldn't open i2c-1 device" << endl;
        return 1;
    }

    // writes config parameters
    if ( wiringPiI2CWriteReg16 ( fd, 1, config ) )
    {
        cerr << "Error writing device" << endl;
        return 1;
    }

    // reads voltage as 16 bits integer
    input -> data16 = wiringPiI2CReadReg16 ( fd, 4 );

    // arranges the bytes
    // MSByte in data8 [ 0 ]
    // LSByte in data8 [ 1 ]
    input -> data16 =  input -> data8 [ 1 ] | input -> data8 [ 0 ] << 8 ;

    float float_val = input -> data16 * VOLTS_PER_STEP;

    cout << fixed <<  setprecision ( 3 ) << \
    "Input voltage: " <<  float_val << " Volts" << endl;

    return 0;
}
