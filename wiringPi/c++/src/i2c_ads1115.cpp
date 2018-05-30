//
// Program: i2c_ads1115.cpp
// Purpose: Read analog signal using DAC
//          ADS1115 through i2c port
// Author:  Aldo Nunez
//

#include<iostream>
#include<inttypes.h>
#include<unistd.h>
#include<iomanip>
#include<wiringPi.h>
#include<ads1115.h>

using namespace std;

int
main()
{
    // ADS1115 address 
    const unsigned int  ADS_ADDRESS = 0x48;

    // chooses a PIN value > 63 
    const int PIN = 64; 

    // integer to double conversion constant 
    const double VOLTS_PER_STEP = 6.144 / 32768;
    
    int16_t int_value = 0x0;
    double  voltage = 0.0;

    // sets up ADS1115 
    if ( !ads1115Setup ( PIN, ADS_ADDRESS ) )
    {
        cerr <<  "Couldn't open i2c-1 device\n";
        return 1;
    }
    
    // configures gain control to 6.144 volts - 0 
    digitalWrite ( PIN, 0 );
    
    // configures data rate to 475 SPS - 6
    digitalWrite ( PIN + 1, 6 );

    while ( 1 )
    {
        // reads input 
        int_value = static_cast < uint16_t > ( analogRead ( PIN ) );

        // converts to double 
        voltage = int_value * VOLTS_PER_STEP;
        
        // prints lecture n
        cout << fixed << setprecision ( 4 )  << \
        "Input voltage: " <<  voltage << endl;

        /* waits  1 second */
        sleep ( 1 );
    }

    return 0;
}

