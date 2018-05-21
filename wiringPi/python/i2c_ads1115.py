#!/usr/bin/env python

'''
Name:    i2x_ads1115.py
Purpose: Read analog signal using DAC
         ADS1115 through i2c port
 Author:  Aldo Nunez
'''
# Import GPIO module
import wiringpi as wipi

def

def main ():
    # integer to float conversion constant
    VOLTS_PER_STEP =  6.144 / 32768.0

    '''
    ADS1115 configuration 
    OS   = 0x1       Single shot
    MUX  = 0x100     AINp = AIN0, AINn = GND
    PGA  = 0x000     Full Scale +-6.144 Volts
    MODE = 0x1       Power-down single shot
    DR   = 0x110     Data Rate 475 SPS
    COMP_MODE = 0x0  Traditional comparator with hysteresis
    COMP_POL  = 0x0  Active low
    COMP_LAT  = 0x0  Non-latching comparator
    COMP_QUE  = 0x0  Assert after one conversion
    '''
    config = 0x0
    config |= OS       | MUX2     | MUX1      | MUX0
    config |= PGA2     | PGA1     | PGA0      | MODE
    config |= DR2      | DR1      | DR0       | COMP_MODE
    config |= COMP_POL | COMP_LAT | COMP_QUE1 | COMP_QUE0

    # opens i2c-1 device
    int fd = wiringPiI2CSetup ( ADS_ADDRESS )
    if fd == -1:
        print ( stderr, "Couldn't open i2c-1 device\n" )
        return 1

    # writes config parameters
    if wiringPiI2CWriteReg16 ( fd, 1, config ):
        print ( stderr, "Error writing device\n" )
        return 1;

    # reads voltage as 16 bits integer
    input.data16 = wiringPiI2CReadReg16 ( fd, 4 )
    if input.data16 < 0:
        print ( stderr, "Error reading data\n" )
        return 1

    '''
    MSB in data8 [ 0 ] 
    LSB in data8 [ 1 ] 
    '''
    uint16_t int_val = 0x0;
    int_val |= input.data8 [ 0 ] << 8;
    int_val |= input.data8 [ 1 ];

    float_val = int_val * VOLTS_PER_STEP

    print ( "Input voltage: %4.3f Volts\n", float_val )

if __name__ == "__main__":
    main ()
