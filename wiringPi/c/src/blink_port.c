/*
** Name:    blink_port.c
** Purpose: Blinks one of the 26 valid ports
** Author:  Aldo Nunez
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>
#include <ctype.h>
#include <wiringPi.h>

typedef enum { false = 0, true = 1 } bool;
volatile sig_atomic_t  flag = 1;

/*
** Function: manage_signal
** Purpose:  Catchs the signal interrupt, 'Ctrl + c',
**           generated by the user and modify the 
**           flag variable
** Input:    signal interrupt
** Output:   void
*/
void manage_signal ( int );

/*
** Function: check_port
** Purpose:  Checks if the input parameter is 
**           a valid port. Returns a valid
**           port number, otherwise it returns
**           zero.
** Input:    - port number
**           - pointer to array
**           - size array
** Output:   8 bits integer
**           returns a valid port number.
**           returns -1 if it's not a valid port number
*/
int8_t check_port ( int, int8_t*,  const uint8_t );

/*
** Function: is_number
** Purpose:  Checks if the input string is an integer number.
** 		     		
** Input:    char pointer (string)
** Output:   boolean
**           returns true - if the input is an integer number.
**           returns false - if the input is not an integer number
*/
bool is_number ( char* );

/*
** Function:   write_port
** Purpose:    Checks if the input is a valid port; if it is
**             blink it.
** Parameters: string, the input port number
** Output:     boolean
**             true - if the input is a valid port
**             and blink it
**             false - if the input is an invalid port
*/
bool  write_port ( char * );

/*
** Name:       print_message
** Purpose:    Prints usage message
** Parameters: char pointer (string)
** Output:     void
*/
void print_message ( char* );

/* main */
int
main ( int argc, char* argv [] )
{
    char* program_name = argv [ 0 ];

    if ( argc != 2 )
    {
        print_message (  program_name );
        return 1;
    }

    if ( !write_port ( argv [ 1 ] ) )
    {
        return 1;
    }

    return 0;
}
/* end of main */

void
manage_signal ( int sig )
{
    if ( sig == SIGINT )
    {
        flag = 0;
    }
    printf ("\nprogram is closing ... \n" );
}

bool
is_number ( char* str )
{
    while ( *str != 0 )
    {
        if ( !isdigit ( *str ) )
        {
            return false;
        }
        str++;
    }
    return true;
}

bool
write_port ( char* phys_port )
{
    if ( !is_number ( phys_port ) )
    {
        fprintf ( stderr, "Port must be an integer and positive number\n\n" );
        return false;	
    }

    /* Allocates room for the ports array  */
    /* number of ports plus one */
    const uint8_t N = 41;
    int8_t* wipi_ports = malloc ( N * sizeof ( int8_t ) );
    if ( wipi_ports == NULL )
    {
        fprintf ( stderr, "Memory allocation failed\n\n" );
        return false;	
    }
    int  wpi_port = check_port ( atoi ( phys_port ), wipi_ports, N );
    if ( wpi_port == -1 )
    {
        fprintf ( stderr, "Port number is not valid!\n\n" );
        return false;	
    }

    const int T = 50;

    /* setup */
    if ( wiringPiSetup () )
    {
        fprintf ( stderr,  "Failing to setup wiringPi\n" );
        return 1;
    }

  /* sets the port as output*/
    pinMode ( wpi_port, OUTPUT );

    printf ( "blinking port %s ...\n", phys_port );

    signal ( SIGINT, manage_signal );
    printf ( "To finish type: \"Ctrl + c\" \n" );

    uint8_t state = 0;

    while ( flag  )
    {
        /* blink */
        digitalWrite ( wpi_port, state = !state );

        /* wait */
        delay ( T );
    }

    digitalWrite ( wpi_port, 0 );
    free ( wipi_ports );

    return true;
}

int8_t
check_port ( int phys_port, int8_t* wipi_ports,  const uint8_t size)
{
    /* checks if physical port number is between 0 - 40 */
    if ( phys_port >= size  || phys_port < 0 )
    {
        return -1;
    }

    /* initialize ports array */
    uint8_t i;
    for ( i = 0; i < size; i++ )
    {
        *( wipi_ports + i ) = -1;
    }

    /* Valid physical pins */
    /* [ Phys Pin ] - wirinPi PIN */
    wipi_ports [ 3 ]  = 8;
    wipi_ports [ 5 ]  = 9;
    wipi_ports [ 7 ]  = 7;
    wipi_ports [ 8 ]  = 15;
    wipi_ports [ 10 ] = 16;
    wipi_ports [ 11 ] = 0;
    wipi_ports [ 12 ] = 1;
    wipi_ports [ 13 ] = 2;
    wipi_ports [ 15 ] = 3;
    wipi_ports [ 16 ] = 4;
    wipi_ports [ 18 ] = 5;
    wipi_ports [ 19 ] = 12;
    wipi_ports [ 21 ] = 13;
    wipi_ports [ 22 ] = 6;
    wipi_ports [ 23 ] = 14;
    wipi_ports [ 24 ] = 10;
    wipi_ports [ 26 ] = 11;
    wipi_ports [ 29 ] = 21;
    wipi_ports [ 31 ] = 22;
    wipi_ports [ 32 ] = 26;
    wipi_ports [ 33 ] = 23;
    wipi_ports [ 35 ] = 24;
    wipi_ports [ 36 ] = 27;
    wipi_ports [ 37 ] = 25;
    wipi_ports [ 38 ] = 28;
    wipi_ports [ 40 ] = 29;

    return ( int ) wipi_ports [ phys_port ];
}

void
print_message (  char* file )
{
    fprintf ( stdout, "%s: missing port \n\n", file );
    fprintf ( stdout, "Usage: %s PIN\n", file );
    fprintf ( stdout, "PIN - Pin number\n" );
}

