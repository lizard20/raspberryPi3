#!/usr/bin/env python

'''
Program: blink.py
Description: Blinking led
			 using wiringPi library
Author: Aldo Nunez
'''

# Import GPIO module
import wiringpi as wipi
import time 

def main ():
	# setup wiringpi
	wipi.wiringPiSetup ()

	# wPi 9 corresponds to Pin 5
	WPI_PORT = 9;

	# time delay in milliseconds
	T = 0.05 	# 0.05 ~ 50 ms


	# '1' means output 
 	wipi.pinMode ( WPI_PORT, 1 )

	# initial state
	state = 1
	print ( "blinking Pin 5" )
	while True:
		# blink
		wipi.digitalWrite ( WPI_PORT, state )

		# waiting
		time.sleep ( T )

		# switch state
		state = not state

if __name__  == "__main__":
	main ()
