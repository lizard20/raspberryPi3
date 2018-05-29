/**
** Program: blink.c
** Description: Blink led using 
** 				wiringPi library
** Author: Aldo Nunez
**/

#include <stdio.h>
#include <wiringPi.h>

int
main ( void )
{
	/* Port number */
	const int PIN = 7;

	/* Delay in milliseconds */
    const int T = 50; 	
	
    if ( wiringPiSetup () )
	{
		fprintf ( stderr,  "Failing to setup wiringPi\n" );
		return 1;
	}

	/* set the port as output */
    pinMode ( PIN, OUTPUT );

	puts ( "blinking" );
    while ( 1 )
    {
		/* Turn on */
        digitalWrite ( PIN, HIGH );
		/* waiting */
        delay ( T );

		/* Turn off */
        digitalWrite ( PIN, LOW );
		/* waiting */
        delay ( T );
    }

    return 0;
}

