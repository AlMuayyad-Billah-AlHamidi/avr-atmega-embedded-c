/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	   PORT_program.c 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : MCAL
* Sw     : PORT
*
*/


#include "PORT_interface.h"
#include "PORT_private.h"
#include "PORT_config.h"

void PORT_voidInit(void)
{
	DDRA_Register = PORTA_DIR;
	DDRB_Register = PORTB_DIR;
	DDRC_Register = PORTC_DIR;
	DDRD_Register = PORTD_DIR;
	
	/*
		Hint : will  set 1 if the pin input pullup
	*/
	PORTA_Register = PORTA_INITIAL_VALUE;
	PORTB_Register = PORTB_INITIAL_VALUE;
	PORTC_Register = PORTC_INITIAL_VALUE;
	PORTD_Register = PORTD_INITIAL_VALUE;
	
}