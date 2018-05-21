/*
** ads1115.hpp
** Purpose: Configuration constants
** definition
** Author: Aldo Nunez
*/

#define ADS_ADDRESS  ( 0x48 )

/*
** Operational status
** OS
** 0: No effect
** 1: Begin a single conversion (when in power down mode)
** BIT 15
*/
#define OS 		( 1 << 15 )

/*
** Input multiplexer configuration
** MUX [ 2:0 ]
** BITS [ 14:12 ]
*/
#define MUX2 	( 1 << 14 )
#define MUX1 	( 0 << 13 )
#define MUX0 	( 0 << 12 )

/*
** Programmable Gain Amplifier
** PGA [ 2:0 ]
** BITS [ 11:9 ]
*/
#define PGA2 	( 0 << 11 )
#define PGA1 	( 0 << 10 )
#define PGA0 	( 0 << 9  )

/*
** MODE: Device Operation mode
** 0 - Continuous conversion
** 1 - Power down ,single shot (default)
** BIT 8
*/
#define MODE	( 1 << 8 )

/*
** Data rate 
** DR [ 2:0 ]
** 000 - 8SPS, 001 - 16SPS, 010 - 32SPS, 011 - 64SPS
** 100 - 128SPS, 101 - 250SPS, 110 - 475SPS, 111 - 860SPS
** BITS [ 7:5 ]
*/
#define DR2		( 1 << 7 )
#define DR1		( 1 << 6 )
#define DR0		( 0 << 5 )

/*
** COMP_MODE, comparator mode
** 0: traditional comp. with hysteresis (default)
** 1: Window comparator 
** BIT 4
*/
#define COMP_MODE ( 0 << 4 )
/*
** COMP_POL. Comparator polarity
** 0: active low (default)
** 1: active high
** BIT 3
*/
#define COMP_POL ( 0 << 3 )

/*
** COMP_LAT. Latching comparator
** 0: Non-latching comparator (default)
** 1: Latching comparator
** BIT 2
*/
#define COMP_LAT ( 0 << 2 )

/*
** COMP_QUE. Comparator queue and disable
** 00: Assert after one conversion
** 01: Assert after two conversions
** 10: Assert after four conversions
** 11: Disable comparator (default) 
** BITS [ 1:0 ]
*/
#define COMP_QUE1 ( 0 << 1 )
#define COMP_QUE0 ( 0 << 0 )

