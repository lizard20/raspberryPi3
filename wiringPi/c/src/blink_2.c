/**
** Program: blink_2.c
** Purpose: Blink led connected to Pin 5
** 			using wiringPi library 
** 			with controlled ending
** Author: Aldo Nunez
**/

#include <stdio.h>
#include <signal.h>
#include <wiringPi.h>

volatile sig_atomic_t  flag = 1;

/*
** Name: 	manage_signal
** Purpose: Catch the signal interrupt,
** 				'Ctrl + c' signal  generated
** 				by the user  and  modify
** 				flag variable
** Input:	Integer
** Output: 	None
*/
void manage_signal ( int );

int
main ( void )
{
    /* setup */
    if ( wiringPiSetup () )
    {
        fprintf ( stderr,  "Failing to setup wiringPi\n" );
        return 1;
    }

    /* wPi port 9 corresponds to PIN 5 */
    const int WPI_PORT = 9;

    /* Delay in milliseconds */
    const int T = 50; 	

    /* set the port as output */
    pinMode ( WPI_PORT, OUTPUT );

    unsigned int state = HIGH;

    signal ( SIGINT, manage_signal );

    puts ( "blinking Pin 5" );
    puts ( "To finish enter: \'Ctrl + c\'" );
    while ( flag )
    {
        /* blink */
        digitalWrite ( WPI_PORT, state );

        /* waiting */
        delay ( T );

        /* switch state */
        state = !state;
    } /* end of while */

    digitalWrite ( WPI_PORT, 0 );

    return 0;
} /* end of main */

void
manage_signal ( int sig )
{
    if ( sig == SIGINT )
    {
        flag = 0;
    }
    printf ("\nprogram is closing ... \n" );
    return;
}

