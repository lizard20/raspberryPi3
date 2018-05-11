//
// Program: blink_2.cpp
// Purpose: Blinks led connected to Pin 5
//          using wiringPi library.
//          Pressing "Ctrl + c" this program
//          ends in controlled manner.
// Author:  Aldo Nunez
//

#include <iostream>
#include <signal.h>
#include <wiringPi.h>

using namespace std;

volatile sig_atomic_t  flag = 1;

//
// Name:    manage_signal
// Purpose: Catchs the signal interrupt,
//          'Ctrl + c' signal  generated
//          by the user  and  modifies
//          flag variable
// Input:   Integer
// Output:  None
//
void manage_signal ( int );

int
main ( void )
{
    // setup
    if ( wiringPiSetup () )
    {
        cerr <<  "Failing to setup wiringPi\n";
        return 1;
    }

    // wPi port 9 corresponds to PIN 5
    const int WPI_PORT = 9;

    // delay in milliseconds */
    const int T = 50;

    // sets the port as output
    pinMode ( WPI_PORT, OUTPUT );

    unsigned int state = HIGH;

    signal ( SIGINT, manage_signal );

    cout <<  "blinking Pin 5" << endl;
    cout << "To finish enter: \'Ctrl + c\'" << endl;
    while ( flag )
    {
        // blink
        digitalWrite ( WPI_PORT, state );

        // waiting
        delay ( T );

        // switch state
        state = !state;
    } // end of while

    digitalWrite ( WPI_PORT, 0 );

    return 0;
} // end of main

void
manage_signal ( int sig )
{
    if ( sig == SIGINT )
    {
        flag = 0;
    }
    cout << "\nprogram is closing ..." << endl;
    return;
}

