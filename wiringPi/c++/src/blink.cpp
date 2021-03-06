//
// Program: blink.cpp
// Purpose: Blinks led conncected to Pin 5
//          using wiringPi library
// Author:  Aldo Nunez
//

#include <iostream>
#include <wiringPi.h>

using namespace std;

int
main ( void )
{
    // setup 
    if ( wiringPiSetup () )
    {
        cerr <<   "Failing to setup wiringPi" << endl;
        return 1;
    }

    // wPi 9 corresponds to Pin 5 
    const int WPI_PORT = 9;

    // delay in milliseconds 
    const int T = 50; 	

    // sets the port as output
    pinMode ( WPI_PORT, OUTPUT );

    // initial state 
    unsigned short int state = HIGH;

    cout << "blinking Pin 5" << endl;
    while ( 1 )
    {
        // blink 
        digitalWrite ( WPI_PORT, state );

        // waiting 
        delay ( T );

        // switch state
        state = !state;
    } // end of while

    return 0;
}

