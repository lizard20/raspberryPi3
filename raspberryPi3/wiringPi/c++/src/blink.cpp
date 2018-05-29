/**
** Program: blink.cpp
** Description: Blink led using 
** 				wiringPi library
** Author: Aldo Nunez
**/

#include <iostream>
#include <wiringPi.h>

using namespace std;

int
main ( void )
{
	/* Port number */
	const int PIN = 7;

	/* Delay in milliseconds */
    const int T = 50; 	
	
    if ( wiringPiSetup () )
	{
		cerr << "Failing to setup wiringPi" << endl;
		return 1;
	}

	/* set the port as output */
    pinMode ( PIN, OUTPUT );

	cout <<  "blinking" << endl;
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

