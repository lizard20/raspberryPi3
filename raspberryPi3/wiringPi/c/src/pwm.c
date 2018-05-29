/**
** Program: pwm.c
** Description: PWM output on
** 				wiringPi library
** Author: Aldo Nunez
**/

#include <stdio.h>
#include <wiringPi.h>

int
main ( void )
{
	/* Port number */
	const int PWM_PORT = 1;
	const int PWM_FREQ = 12;
	
    if ( wiringPiSetup () )
	{
		fprintf ( stderr,  "Failing to setup wiringPi\n" );
		return 1;
	}

	/* set the port as output */
    pinMode ( PWM_PORT, PWM_OUTPUT );

	puts ( "PWM output in pin 12" );
    while ( 1 )
    {
        pwmWrite ( PWM_PORT, PWM_FREQ );
    }

    return 0;
}

