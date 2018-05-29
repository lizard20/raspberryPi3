import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BOARD)

PORT = 7
GPIO.setup ( PORT, GPIO.OUT )

while True:
	GPIO.output ( PORT, HIGH )
	time.sleep ( 0.1)
	GPIO.output ( PORT, LOW )
	time.sleep ( 0.1)


        
