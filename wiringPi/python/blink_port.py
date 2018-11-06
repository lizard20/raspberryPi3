#!/usr/bin/env python

'''
Name:    blink_port.py
Purpose: Blinks one of the 28 valid ports
Author:  Aldo Nunez
'''
# Import GPIO module
import wiringpi as wipi
import time 
import sys

def  check_port ( phys_port ):
    # number of ports plus one
    N = 41

    # checks if physical port number is between 0 - 40 
    if phys_port >= N or phys_port < 0:
        return -1

    # Initialize ports
    wipi_ports = [ -1 for i in range ( N )]

    # Valid physical pins 
    # [ Phys Pin ]  - wirinPi PIN 
    wipi_ports [ 3 ]  = 8
    wipi_ports [ 5 ]  = 9
    wipi_ports [ 7 ]  = 7
    wipi_ports [ 8 ]  = 15
    wipi_ports [ 10 ] = 16
    wipi_ports [ 11 ] = 0
    wipi_ports [ 12 ] = 1
    wipi_ports [ 13 ] = 2
    wipi_ports [ 15 ] = 3
    wipi_ports [ 16 ] = 4
    wipi_ports [ 18 ] = 5
    wipi_ports [ 19 ] = 12
    wipi_ports [ 21 ] = 13
    wipi_ports [ 22 ] = 6
    wipi_ports [ 23 ] = 14
    wipi_ports [ 24 ] = 10
    wipi_ports [ 26 ] = 11
    wipi_ports [ 27 ] = 30
    wipi_ports [ 28 ] = 31
    wipi_ports [ 29 ] = 21
    wipi_ports [ 31 ] = 22
    wipi_ports [ 32 ] = 26
    wipi_ports [ 33 ] = 23
    wipi_ports [ 35 ] = 24
    wipi_ports [ 36 ] = 27
    wipi_ports [ 37 ] = 25
    wipi_ports [ 38 ] = 28
    wipi_ports [ 40 ] = 29
    
    return wipi_ports [ phys_port ]

def main ( argv ):
    # checks number of arguments 
    if len ( argv ) != 1:
        print ( "{}: missing port".format ( sys.argv [ 0 ]) )
        print ( "Usage: {} PIN".format ( sys.argv [ 0 ] ) )
        print ( "PIN - Pin number" )
        sys.exit ( 1 )
    
    # checks if the argument is a number
    try:
        phys_port =  int ( sys.argv [ 1 ] )
    except:
        print ( "Port must be an integer and positive number" )
        sys.exit ()
    
    wipi_port =  check_port ( phys_port )
    if  wipi_port == -1:
        print ( "no valid port" )
        sys.exit ()

    # states
    STATES = {'OFF': 0, 'ON': 1 }
    
    # direction
    DIR = {'IN': 0, 'OUT': 1 }
    
    # time delay in milliseconds
    T = 0.05 	# 0.05 ~ 50 ms
    
    wipi.wiringPiSetup ()

    # config port as output
    wipi.pinMode ( wipi_port, DIR [ 'OUT' ] )

    # initial state
    state = STATES [ 'ON' ]

    print ( "blinking port {} ...".format ( phys_port ) )
    print ( "To finish press: 'Ctrl + c'" )
    try:
        while True:
            # blink
            wipi.digitalWrite ( wipi_port, state )

            # waiting
            time.sleep ( T )
    
            # switch state
            state = not state

    except KeyboardInterrupt:
        wipi.digitalWrite ( wipi_port, STATES [ 'OFF' ]  )
        print ( "\nprogram is closing ..." )
        sys.exit ( 0 )

if __name__  == "__main__":
    main ( sys.argv [ 1: ] )
