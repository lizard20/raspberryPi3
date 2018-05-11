/**
** Program: digital_input.c
** Purpose: Reads a digital input and displays its value
**          using wiringPi library
** Author:  Aldo Nunez
**/

#include <stdio.h>
#include <wiringPi.h>

int 
main ( void )
{
    const int PORT = 7;

    if ( wiringPiSetup () )
    {
        fprintf ( stderr, "Failing to setup wiringPi\n" );
        return 1;
    }

    /* sets the port as input */
    pinMode ( PORT, INPUT );

    /* reads input value */
    int value = digitalRead ( PORT );

    printf ( "Input port %d: %d\n", PORT, value );

    return 0;
}

