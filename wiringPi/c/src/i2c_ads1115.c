/*
** Program: i2c_ads1115.c
** Purpose: Read analog signal using DAC
**          ADS1115 through i2c port
** Author:  Aldo Nunez
*/

#include<stdio.h>
#include<inttypes.h>
#include<ads1115.h>

/* ADS1115 address */
#define ADS_ADDRESS 0x48

int
main()
{
    /* chooses a PIN value > 63 */
    const int PIN = 64; 

    /* integer to double conversion constant */
    const double VOLTS_PER_STEP = 6.144 / 32768;
    
    int16_t int_value = 0x0;
    double  voltage = 0.0;

    /* sets up ADS1115 */
    if ( !ads1115Setup ( PIN, ADS_ADDRESS ) )
    {
        fprintf ( stderr, "Couldn't open i2c-1 device\n" );
        return 1;
    }
    
    /* configures gain control to 6.144 volts - 0 */
    digitalWrite ( PIN, 0 );
    
    /* configures data rate to 475 SPS - 6 */
    digitalWrite ( PIN + 1, 6 );

    while ( 1 )
    {
        /* reads input */ 
        int_value = ( uint16_t ) analogRead ( PIN );

        /* converts to double */
        voltage = int_value * VOLTS_PER_STEP;
        
        /* prints lecture */
        printf ( "Input voltage: %5.4f Volts\n", voltage );

        /* waits  1 second */
        delay ( 1000 );
    }

    return 0;
}

