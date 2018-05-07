//
// Program:	pwm.cpp
// Purpose:	PWM output on Pin 35
//			using wiringPi library
//			frequency:  20 KHz
//			duty cycle: 40 %
// Author: Aldo Nunez
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
		cerr <<  "Failing to setup wiringPi" << endl;
		return 1;
	}

	// wPi Port 24 corresponds to Phys Pin 35 
	const int PWM_PORT = 24;
	
	// parameters to compute frequency
	const int RANGE= 480;
	const int DIVISOR = 2;

	// duty cycle percentage 
	const int PERCENTAGE_DUTY_CYCLE = 40; 

	// duty_cycle = ( range * duty_cycle(%) ) / 100 
	const int DUTY_CYCLE = ( RANGE * PERCENTAGE_DUTY_CYCLE ) / 100;

	//  setting PWM parameters 
	
	// set port to ALT MODE-5
	const int FSEL_ALT5 = 0b010;
	pinModeAlt (PWM_PORT, FSEL_ALT5 );

	// set Mark/Space mode 
    pwmSetMode ( PWM_MODE_MS );

	// frequency = 19.2e6 / ( DIVISOR x RANGE )
    pwmSetRange ( RANGE );
    pwmSetClock ( DIVISOR );


	// generate PWM at a determined duty cycle
    pwmWrite ( PWM_PORT, DUTY_CYCLE );
	
	const float F_BASE = 19.2e6; 
	const float FREQUENCY_OUT = F_BASE / ( RANGE * DIVISOR );
	cout << "PWM output pin: 35" << endl;
	cout << "PWM frequency: " << FREQUENCY_OUT  << " Hz" <<  endl;
	cout << "PWM duty cycle: " <<  ( DUTY_CYCLE * 100 ) / RANGE  << " %" << endl;
	
	cout << "\nTo finish, press \'Enter\'" << endl;

	cin.get ();
	// turn off pwm output
    pwmWrite ( PWM_PORT, 0 );

    return 0;
}


