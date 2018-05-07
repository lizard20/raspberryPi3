#!/usr/bin/env python

'''
Program: counter_3_bits.py
Description: 3 bits counter. 0 -> 7 or
			 000 -> 111
			Ouptput pins: 11, 13 ,15
 Author: Aldo Nunez
'''

# Import GPIO module
import wiringpi as wipi
import time 

def main ():
	# setup wiringpi
	wipi.wiringPiSetup ()
	
	# Ports numbers a
	BIT = [0, 2, 3 ]

	# wiPi port : Pin number
	PORTS = { 0:0, 1:2. 2:3 }

	# max count
	MAX_COUNT = 7;

	# delay in milliseconds 
	T = 1000;
	
	# '1' means output 
 	wipi.pinMode ( BIT [ 0 ], 1 )
 	wipi.pinMode ( BIT [ 1 ], 1 )
 	wipi.pinMode ( BIT [ 2 ], 1 )


	# Initialize pattern for blinking
	BIT0 = [ 0, 1, 0, 1, 0, 1, 0, 1 ];
	BIT1 = [ 0, 0, 1, 1, 0, 0, 1, 1 ];
	BIT2 = [ 0, 0, 0, 0, 1, 1, 1, 1 ];

	printf ( "To finish print \"ctrl + c\" \n" );

while ( flag )
	{
		printf ( "decimal %d is %d%d%d in binary\n", i, bit2 [ i ], bit1 [ i ], bit0 [ i ] );
		/* write to ports */
		wipi.digitalWrite ( BIT [0], BIT0 [ i ] );
		digitalWrite ( BIT [ 1 ], bit1 [ i ] );
		digitalWrite ( BIT2, bit2 [ i ] );
		
		++i;
		if ( i > max_count )
		{
			i = 0;
		}
		delay ( T );
	} /* end of while */

	/* turn off outputs */
	digitalWrite ( BIT0, LOW );
	digitalWrite ( BIT1, LOW );
	digitalWrite ( BIT2, LOW );

	return 0;
}

void
manage_signal ( int sig )
{
	if ( sig == SIGINT )
	{
		flag = 0;
	}
	printf ("\nprogram is closing ... \n" );
}

