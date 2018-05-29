/*
** Name: blink_port
** Description: Blink one of the 26 valid ports
** Author: Aldo Nunez
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <getopt.h>
#include <ctype.h>
#include <bcm2835.h>

typedef enum { false = 0, true = 1 } bool;
volatile sig_atomic_t  flag = 1;

const char* program_name;

/*
** Function: manage_signal
** Purpose:  Catch the signal interrupt, 'Ctrl + c',
**		     generated by the user and modify the 
**			 flag variable
** Input:    signal interupt
** Output:   None
*/
void manage_signal ( int );

/*
** Function: check_port
** Purpose:  Check if the input parameter is 
**           a valid port. Returns a valid
**           port number, otherwise it returns
**           zero.
** Input:    port number
** Output:   returns a valid port number.
**           returns zero if it's not a valid port number
*/
int check_port ( int );

/*
** Function: is_number
** Purpose:	 Check if the input string is an integer number.
** 		     		
** Input:	 string
** Output:	 return true - if the input is an integer number.
**			 return false - if the input is not an integer number
*
*/
bool is_number ( char* );

/*
** Name:		write_port
** Parameters:	string 
** Output:		Boolean
** 				true - if the input is a valid port
** 				and blink it
**				false - if the input is an invalid port
** Description: Check if the input is a valid port and
** 				blink it.
*/
bool  write_port ( char * );

/*
** Name:		print_help
** Parameters:	File pointer: progam name
** Output:		None
** Description: Print help
** 				
*/
void print_help ( FILE* );

/* main */
int
main ( int argc, char* argv [] )
{
	program_name = argv [ 0 ];
	
	if ( argc <  2 || argc > 3 )
	{
		print_help ( stdout );
		return 1;
	}

	int next_option;
	const char* const short_options = "+hp:";
	const struct option long_options [] =
	{
		{ "+help",	no_argument, 0, 'h' },
		{ "port", 	required_argument, 0, 'p' },
		{ NULL,   		0, NULL, 0   }
	};

	const char* output_port = NULL;
	int option_index = 0;
	do
	{
		next_option = getopt_long ( argc, argv, short_options,
									long_options, &option_index );
		switch ( next_option )
		{
			case 'h':
				print_help ( stdout );
				break;
			case 'p':
				if ( !write_port ( argv [ 2 ] ) )
				{
					fprintf ( stderr, "Port %s is  invalid \n", argv [ 2 ] );
					break;	
				}
				break;
			case '?':
				if ( optopt == 'p' )
				{
					fprintf ( stderr, "Option '-%c' requires an argument.\n", optopt );
				}
				else if ( isprint ( optopt ) )
				{
					fprintf ( stderr, "Unknown option `-%c'.\n", optopt);
					fprintf ( stderr, "Try '%s --help' for more information\n", program_name );
				}
				else
				{
					fprintf (stderr, "Unknown option character `%c'.\n", optopt);
				}
				return 1;
				break;
			case -1: 
				print_help ( stdout );
				break;
		//	default:
		//		abort ();
		}
	}
	while ( next_option != -1 );

	return 0;
}
/* end of main */

void
manage_signal ( int sig )
{
	if ( sig == SIGINT )
	{
		flag = 0;
	}
	printf ("\nprogram is closing ... \n" );
}

bool
is_number ( char* str )
{
    while ( *str != 0 )
    {
        if ( !isdigit ( *str ) )
        {
            return false;
        }
        str++;
    }
    return true;
}

bool
write_port ( char* port )
{
	if ( !is_number ( port ) )
	{
		fprintf ( stderr, "Port must be a number\n" );
		return false;	
	}

	int  PORT = check_port ( atoi ( port ) );
	if ( !check_port ( PORT ) )
	{
		return false;	
	}

	const int T = 50;

	/* setup */
    if ( !bcm2835_init () )
	{
		fprintf ( stderr, "Failing to setup port\n" );
		return false;
	}

    /* set the port as output*/
    bcm2835_gpio_fsel ( PORT, BCM2835_GPIO_FSEL_OUTP );
	
	puts ( "blinking..." );

	signal ( SIGINT, manage_signal );
	printf ( "To finish type: Ctrl + c \n" );

	while ( flag  )
    {
        /* Turn on */
        bcm2835_gpio_set ( PORT );
        /* wait */
        bcm2835_delay ( T );
        
        /* turn off */
        bcm2835_gpio_clr ( PORT );
        /* wait */
        bcm2835_delay ( T );
    }

    bcm2835_close ();
	return true;
}

int
check_port ( int pin )
{
	/* number of ports */
	const uint8_t N = 40;

	uint8_t* ports = ( uint8_t* ) calloc ( N, sizeof ( uint8_t ) );

	ports [ 3 ]  = ( uint8_t ) RPI_BPLUS_GPIO_J8_03;
	ports [ 5 ]  = ( uint8_t ) RPI_BPLUS_GPIO_J8_05;
	ports [ 7 ]  = ( uint8_t ) RPI_BPLUS_GPIO_J8_07;
	ports [ 8 ]  = ( uint8_t ) RPI_BPLUS_GPIO_J8_08;
	ports [ 10 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_10;
	ports [ 11 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_11;
	ports [ 12 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_12;
	ports [ 13 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_13;
	ports [ 15 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_15;
	ports [ 16 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_16;
	ports [ 18 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_08;
	ports [ 19 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_19;
	ports [ 21 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_21;
	ports [ 22 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_22;
	ports [ 23 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_23;
	ports [ 24 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_24;
	ports [ 26 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_26;
	ports [ 29 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_29;
	ports [ 31 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_31;
	ports [ 32 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_32;
	ports [ 33 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_33;
	ports [ 35 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_35;
	ports [ 36 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_36;
	ports [ 37 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_37;
	ports [ 38 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_38;
	ports [ 40 ] = ( uint8_t ) RPI_BPLUS_GPIO_J8_40;

	return ( int ) ports [ pin ];
}

void
print_help ( FILE* stream )
{
	fprintf ( stream, "Usage:   %s option [PORT]\n", program_name );
	fprintf ( stream,
			"option:\n"
			"        -h --help  Display this help information\n"
			"        -p --port  output port  \n" );
}

