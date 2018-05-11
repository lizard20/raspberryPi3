#!/usr/bin/env python

'''
Program: pwm.py
Purpose: Generates a PWM signal on Pin 35
         using wiringPi library.
         frequency:  20 KHz
         duty cycle: 40 %
         Executes as root!
Author:  Aldo Nunez
'''

import wiringpi as wipi

def main ():
    # setup wiringpi 
    if wipi.wiringPiSetup ():
        print ( "Failing to setup wiringPi" )
        sys.exit ()

    # wPi Port 24 corresponds to Phys Pin 35
    PWM_PORT = 24

    # parameters to compute frequency 
    RANGE= 480
    DIVISOR = 2

    # duty cycle percentage
    PERCENTAGE_DUTY_CYCLE = 40

    # duty_cycle = ( range * duty_cycle(%) ) / 100 
    DUTY_CYCLE = ( RANGE * PERCENTAGE_DUTY_CYCLE ) / 100

    #*** setting PWM parameters **
    # sets port to ALT MODE-5
    FSEL_ALT5 = 0b010;
    wipi.pinModeAlt ( PWM_PORT, FSEL_ALT5 )

    # sets Mark/Space mode 
    wipi.pwmSetMode ( wipi.GPIO.PWM_MODE_MS )

    # frequency = 19.2e6 / ( DIVISOR x RANGE )
    wipi.pwmSetRange ( RANGE )
    wipi.pwmSetClock ( DIVISOR )
    #***

    # generates PWM at a determined duty cycle
    wipi.pwmWrite ( PWM_PORT, DUTY_CYCLE )

    F_BASE = 19.2e6
    FREQUENCY_OUT = F_BASE / ( RANGE * DIVISOR )
    print ( "PWM output pin: 35" )
    print ( "PWM frequency: {} Hz".format ( FREQUENCY_OUT ) )
    print ( "PWM duty cycle: {}".format ( ( DUTY_CYCLE * 100 ) / RANGE ) )

    c = raw_input ( "To finish, press \'Enter\'" )
    # turns off pwm output
    wipi.pwmWrite ( PWM_PORT, 0 )

if __name__ == "__main__":
    main ()
