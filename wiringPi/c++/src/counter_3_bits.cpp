//
// Program: counter_3_bits.cpp
// Purpose: 3 bits counter. 0 -> 7 or
//          000 -> 111
//          Ouptput pins: 11, 13 ,15
// Author: Aldo Nunez
//

#include <iostream>
#include <stdint.h>
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
    /* setup */
    if ( wiringPiSetupPhys () )
    {
        cerr << "Failing to setup wiringPi" << endl;
        return 1;
    }

    /* counter index */
    uint8_t i = 0;

    /* max count*/
    const uint8_t MAX_COUNT = 7;

    /* delay in milliseconds */
    const int T = 1000;

    /* output ports */
    const uint8_t BIT0 = 11;
    const uint8_t BIT1 = 12;
    const uint8_t BIT2 = 13;

    /* sets ports as ouputs  */
    pinMode ( BIT0, OUTPUT );
    pinMode ( BIT1, OUTPUT );
    pinMode ( BIT2, OUTPUT );

    /* patterns for blinking */
    const int ARR0 [] = { 0, 1, 0, 1, 0, 1, 0, 1 };
    const int ARR1 [] = { 0, 0, 1, 1, 0, 0, 1, 1 };
    const int ARR2 [] = { 0, 0, 0, 0, 1, 1, 1, 1 };

    signal ( SIGINT, manage_signal );
    cout <<  "To finish print \"ctrl + c\"" << endl ;

    while ( flag )
    {
        cout <<  "decimal " << unsigned ( i ) << " is " << ARR2 [ i ] \
        << ARR1 [ i ] << ARR0 [ i ] << " in binary" << endl;
        /* writes ports */
        digitalWrite ( BIT0, ARR0 [ i ] );
        digitalWrite ( BIT1, ARR1 [ i ] );
        digitalWrite ( BIT2, ARR2 [ i ] );

        ++i;
        /* restarts counter*/
        if ( i > MAX_COUNT )
        {
            i = 0;
        }
        delay ( T );
    } /* end of while */

    /* turns off outputs */
    digitalWrite ( BIT0, LOW );
    digitalWrite ( BIT1, LOW );
    digitalWrite ( BIT2, LOW );

    return 0;
} // end of main

void
manage_signal ( int sig )
{
    if ( sig == SIGINT )
    {
        flag = 0;
    }
    cout << "\nprogram is closing ..." <<  endl;
}

