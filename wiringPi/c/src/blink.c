/**
** Program: blink.c
** Purpose: Blinks led connected to Pin 5,
**          using wiringPi library
** Author:  Aldo Nunez
**/

#include <stdio.h>
#include <wiringPi.h>

int
main ( void )
{
    /* setup */
    if ( wiringPiSetup () )
    {
        fprintf ( stderr,  "Failing to setup wiringPi\n" );
        return 1;
    }

    /* wPi 9 corresponds to Pin 5 */
    const int WPI_PORT = 9;

    /* Delay in milliseconds */
    const int T = 50; 	

    /* set the port as output */
    pinMode ( WPI_PORT, OUTPUT );

    /* initial state */
    unsigned short int state = HIGH;

    puts ( "blinking Pin 5" );
    while ( 1 )
    {
        /* blink */
        digitalWrite ( WPI_PORT, state );

        /* waiting */
        delay ( T );

        /* switch state */
        state = !state;
    } /* end of while */

    return 0;
}

