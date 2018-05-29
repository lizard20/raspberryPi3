'''
Program: blink.py
Description: Blinking led
Author: Aldo Nunez
'''
# Import GPIO module
import RPi.GPIO as GPIO
import time 

def main ():
	# 
	GPIO.setmode ( GPIO.BOARD )
	mode = GPIO.getmode ()
	print ( mode )

	# Don't show warnings
	#GPIO.setwarnings ( False )
	
	# set pin number
	led = 7;

	# set sleep time
	T = 0.5;

	# Use board pin numbering
	GPIO.setmode ( GPIO.BOARD )

	# Assign port as output
	GPIO.setup ( led, GPIO.OUT )

	while ( 1 ):
		GPIO.output ( led, GPIO.HIGH )
		time.sleep ( T )
		GPIO.output (led, GPIO.LOW )
		time.sleep ( T )
	
	GPIO.cleanup ( led )

if __name__  == "__main__":
	main ()
