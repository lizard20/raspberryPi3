#!/usr/bin/env python

'''
Program: blink_2.py
Description: Blinking led
			 using wiringPi library
			 with controlled ending
Author: Aldo Nunez
'''

# Import GPIO module
import wiringpi as wipi
import time
import sys

def main ():
	# states
	STATES = {'OFF': 0, 'ON': 1 }

	# wPi 9 corresponds to Pin 5
	WPI_PORT = 9;

	# time delay in milliseconds
	T = 0.05 	# 0.05 ~ 50 ms

	wipi.wiringPiSetup ()

	# '1' means output 
 	wipi.pinMode ( WPI_PORT, 1 )

	# initial state
	state = STATES [ 'ON' ]

	print ( "blinking pin 5" )
	print ( "To finish press: 'Ctrl + c'" )
	try:
		while True:
			# blink
			wipi.digitalWrite ( WPI_PORT, state )

			# waiting
			time.sleep ( T )

			# switch state
			state = not state
	
	except KeyboardInterrupt:
		wipi.digitalWrite ( WPI_PORT, STATES [ 'OFF' ]  )
		print ( "\nprogram is closing..." )
		sys.exit ( 0 )

if __name__  == "__main__":
	main ()
	
