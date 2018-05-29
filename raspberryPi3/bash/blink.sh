#!/bin/bash

# Name: blink.sh
# Description: Blink a led
# Author: Aldo Nunez

GPIO=/sys/class/gpio
LED=4	# 4 ~ Pin 7 
ON=1
OFF=0
T=0.05

echo $LED > $GPIO/unexport
echo $LED > $GPIO/export
echo out > $GPIO/gpio$LED/direction

while true
do
	echo $ON > $GPIO/gpio$LED/value
	sleep $T 
	echo $OFF > $GPIO/gpio$LED/value
	sleep $T
done

