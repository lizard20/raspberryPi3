#!/bin/bash

LED=2
ON=1
OFF=0
T=0.05

gpio -g mode ${LED} output

while true
do
	gpio -g write $LED $ON
	sleep $T
	gpio -g write $LED $OFF
	sleep $T
done

