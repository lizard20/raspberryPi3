import RPi.GPIO as GPIO
import time

def main ():
	PORT = 12
	GPIO.setmode ( GPIO.BCM )
	GPIO.setup ( PORT , GPIO.OUT )
	p = GPIO.PWM ( PORT, 50 )
#	p.start ( 5 )  # 5 ~ 1ms
#	p.start ( 10 )  # 10 ~ 2ms

	# python 2.7.9
	c = raw_input ( "Press \"Enter\" to finish." )
	# python 3.4.2
	#c = input ( "Press \"Enter\" to finish." )

if __name__ == "__main__":
	main ()




