//
// Program: blink_io.cpp
// Description: blink a LED and finish program
// 				catching the	"Ctrl +c" signal
// Author: Aldo Nunez
//

#include <iostream>
#include <bcm2835.h>
#include <signal.h>

using namespace std;

volatile sig_atomic_t  flag = 1;

//
// Name: manage_signal
// Input: Integer
// Output: None
// Description: Catch the signal interrupt,
// 				'Ctrl + c' signal  generated
// 				by the user  and  modify
// 				flag variable
//
void manage_signal ( int );

int
main ( int argc, char* argv [] )
{

	// Pin 7. Check bcm2835.h, line 842 
	const int PORT = RPI_BPLUS_GPIO_J8_07;

	// delay in milliseconds 
	const int T = 50;

	// setup
    if ( !bcm2835_init () )
	{
		cerr << "Failing to setup port" << endl;
		return 1;
	}

    // set the port as output
    bcm2835_gpio_fsel ( PORT, BCM2835_GPIO_FSEL_OUTP );

	signal ( SIGINT, manage_signal );
	cout <<  "To finish print \"Ctrl + c\"" << endl;
	// blink indefinitely until (Ctrl + c) 
	while ( flag )
	{
    	// Turn on
        bcm2835_gpio_set ( PORT );
        // wait
        bcm2835_delay ( T );
        
        // turn off 
        bcm2835_gpio_clr ( PORT );
        // wait 
        bcm2835_delay ( T );
	}

    bcm2835_close ();
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
	cout << "program is closing ..." << endl;
}
