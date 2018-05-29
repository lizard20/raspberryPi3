//
// Program: blink.cpp
// Description: Blink led using 
// 				bcm2835 library
// Author: Aldo Nunez
//
//
#include <iostream>
#include <bcm2835.h>

using namespace std;

int
main ()
{
	// J8_07 ~ Pin 7. Check bcm2835.h, line 842 
	const int PORT = RPI_BPLUS_GPIO_J8_07;

	// delay in milliseconds 
	const int T = 50;

	// setup 
    if ( !bcm2835_init () )
	{
		cerr <<  "Failing to setup port" << endl ;
		return 1;
	}

    // set the port as output 
    bcm2835_gpio_fsel ( PORT, BCM2835_GPIO_FSEL_OUTP );
	
	cout << "blinking..." << endl;

	while ( 1  )
    {
        // Turn on 
        bcm2835_gpio_set ( PORT );
        // wait 
        bcm2835_delay ( T );
        
        // turn off
        bcm2835_gpio_clr ( PORT );
	    //  wait 
	    bcm2835_delay ( T );
    }

    bcm2835_close ();
    return 0;
 }

