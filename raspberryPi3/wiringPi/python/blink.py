'''
Program: blink.py
Description: Blinking led
			using wiringPi library
Author: Aldo Nunez
'''
# Import GPIO module
import wiringpi
import time 

def main ():
	# port number
	PIN = 7;
	# time delay in milliseconds
	t = 0.05 	# 0.05 ~ 50 ms

	wiringpi.wiringPiSetup()
 	wiringpi.pinMode ( PIN, 1 )

	while True:
		wiringpi.digitalWrite ( PIN, 1)
		time.sleep ( t )
		wiringpi.digitalWrite ( PIN, 0) 
		time.sleep (0.5)

if __name__  == "__main__":
	main ()
