/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	   BCD_interface.h 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : HAL
* Sw     : BCD
*
*/



#ifndef _BCD_INTERFACE_H_
#define _BCD_INTERFACE_H_


//Port Defines
#define BCD_PORTA 0
#define BCD_PORTB 1
#define BCD_PORTC 2
#define BCD_PORTD 3


#define LOW_NIBBLE  0
#define HIGH_NIBBLE 1

typedef struct 
{
	u8 NibblePort;
	u8 NibbleType;
	u8 NibbleValue;
}BCD_Type;

void	BCD_voidInitialDataNibble ( BCD_Type Copy_structConfig );

#endif