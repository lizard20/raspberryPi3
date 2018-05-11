//
// Name:    blink_port
// Purpose: Blinks one of the 26 valid ports
// Author:  Aldo Nunez
//

#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>
#include <wiringPi.h>

using namespace std;

volatile sig_atomic_t  flag = 1;

//
// Function: manage_signal
// Purpose:  Catchs the signal interrupt, 'Ctrl + c',
//           generated by the user and modify the 
//           flag variable
// Input:    signal interrupt
// Output:   void
void manage_signal ( int );

//
// Function: check_port
// Purpose:  Checks if the input parameter is 
//           a valid port. Returns a valid
//           port number, otherwise it returns
//           zero.
// Input:    -port number
//           - pointer to array
//           - size array
// Output:   8 bits integer
//           returns a valid port number.
//           returns -1 if it's not a valid port number
int8_t check_port ( int, int8_t*, const uint8_t );

//
// Function: is_number
// Purpose:  Checks if the input string is an integer number.
// 		     		
// Input:    char pointer (string)
// Output:   boolean
//           returns true - if the input is an integer number.
//           returns false - if the input is not an integer number
//
bool is_number ( char* );

//
// Function:   write_port
// Purpose:    Checks if the input is a valid port; if it is
//             blink it.
// Parameters: string, the input port number
// Output:     boolean
//             true - if the input is a valid port
//             and blink it
//             false - if the input is an invalid port
bool  write_port ( char * );

//
// Name:       print_message
// Purpose:    Prints usage message
// Parameters: char pointer (string)
// Output:     void
void print_message ( char* );

// main
int
main ( int argc, char* argv [] )
{
    char* program_name = argv [ 0 ];

    if ( argc != 2 )
    {
        print_message (  program_name );
        return 1;
    }

    write_port ( argv [ 1 ] );

    return 0;
}
// end of main 

void
manage_signal ( int sig )
{
    if ( sig == SIGINT )
    {
        flag = 0;
    }
    cout << "\nprogram is closing ... \n";
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
write_port ( char* port )
{
    if ( !is_number ( port ) )
    {
        cerr <<  "Port must be an integer and positive number\n\n";
        return false;	
    }
    // Allocates room to the ports array
    //  number of ports plus one 
    const uint8_t N = 41;
    int8_t* ports = new int8_t [ N ];

    int  wpi_port = check_port ( atoi ( port ), ports, N );
    if ( wpi_port == -1 )
    {
        cerr <<  "Pin number is not valid!\n\n";
        return false;	
    }

    const int T = 50;

    // setup 
    if ( wiringPiSetup () )
    {
        cerr << "Failing to setup wiringPi\n";
        return 1;
    }

    // sets the port as output
    pinMode ( wpi_port, OUTPUT );

    cout <<  "blinking port %s ..." << port << endl;

    signal ( SIGINT, manage_signal );
    cout << "To finish type: \"Ctrl + c\"" << endl;

    uint8_t state = 0;

    while ( flag  )
    {
        // blink 
        digitalWrite ( wpi_port, state = !state );

        // wait 
        delay ( T );
    }

    digitalWrite ( wpi_port, 0 );
    delete ( ports );
    return true;
}

int8_t
check_port ( int pin, int8_t* ports, const uint8_t N )
{
    // initialize ports array 
    for ( uint8_t i = 0; i < N; i++ )
    {
        ports [ i ] = -1;
    }

    // Valid physical pins 
    // Phys Pin - wirinPi PIN 
    ports [ 3 ]  = 8;
    ports [ 5 ]  = 9;
    ports [ 7 ]  = 7;
    ports [ 8 ]  = 15;
    ports [ 10 ] = 16;
    ports [ 11 ] = 0;
    ports [ 12 ] = 1;
    ports [ 13 ] = 2;
    ports [ 15 ] = 3;
    ports [ 16 ] = 4;
    ports [ 18 ] = 5;
    ports [ 19 ] = 12;
    ports [ 21 ] = 13;
    ports [ 22 ] = 6;
    ports [ 23 ] = 14;
    ports [ 24 ] = 10;
    ports [ 26 ] = 11;
    ports [ 29 ] = 21;
    ports [ 31 ] = 22;
    ports [ 32 ] = 26;
    ports [ 33 ] = 23;
    ports [ 35 ] = 24;
    ports [ 36 ] = 27;
    ports [ 37 ] = 25;
    ports [ 38 ] = 28;
    ports [ 40 ] = 29;

    return ( int ) ports [ pin ];
}

void
print_message (  char* file )
{
    cout << "%s: missing port" << file << endl;
    cout << "Usage: %s PIN" <<  file << endl;
    cout << "PIN - Pin number" << endl;
}
