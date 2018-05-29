'''
Program: blink.py
Description: Blinking led
			using bcm2835 library
Author: Aldo Nunez
'''
# Import GPIO module
import RPi.GPIO as GPIO
import time 

def main ():
	# port number
	PORT = 7;
	# time delay in milliseconds
	T = 0.05 	# 0.05 ~ 50 ms
	
	GPIO.setup ( PORT, GPIO.OUT )
	while True:
		GPIO.output ( PORT, HIGH )
		time.sleep ( T )
		GPIO.output ( PORT, LOW ) 
		time.sleep ( T )

if __name__  == "__main__":
	main ()
