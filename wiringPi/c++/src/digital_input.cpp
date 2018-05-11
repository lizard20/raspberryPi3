//
// Program: digital_input.cpp
// Purpose: Reads a digital input and displays its value
//          using wiringPi library
// Author:  Aldo Nunez
//

#include <iostream>
#include <wiringPi.h>

using namespace std;

int
main ( void )
{
    const int PORT = 7;

    if ( wiringPiSetup () )
    {
        cerr <<  "Failing to setup wiringPi" << endl;
        return 1;
    }

    // sets the port as input
    pinMode ( PORT, INPUT );

    // reads input value
    int value = digitalRead ( PORT );

    cout << "Input port " <<  PORT << ": " << value << endl;

    return 0;
}

