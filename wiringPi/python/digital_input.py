#!/usr/bin/env python

'''
Program: blink.py
Purpose: reads a digital input and 
         displays its value using
         wiringPi library
Author:  Aldo Nunez
'''

# Import GPIO module
import wiringpi as wipi

def main ():
    # setup wiringpi
    wipi.wiringPiSetup ()

    # wPi 7 corresponds to Pin 7
    WPI_PORT = 7;


    # '0' means input
    wipi.pinMode ( WPI_PORT, 0 )

    value = wipi.digitalRead ( WPI_PORT )
    print ( 'Input port {}: {}'.format ( WPI_PORT, value ) )

if __name__  == "__main__":
    main ()
