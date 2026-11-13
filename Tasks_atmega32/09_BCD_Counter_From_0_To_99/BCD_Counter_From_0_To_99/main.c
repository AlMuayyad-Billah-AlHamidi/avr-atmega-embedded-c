/*
 * BCD_To_7Segment.c
 *
 * Created: 9/8/2024 7:01:17 PM
 * Author : MouhannadlrX
 */ 
#define  F_CPU 16000000UL
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "BCD_interface.h"
#include <util/delay.h>


int main(void)
{
    BCD_Type BCD1 = {BCD_PORTC , LOW_NIBBLE };
	BCD_Type BCD2 = {BCD_PORTC , HIGH_NIBBLE };
	DIO_voidSetLowNibbleDirection( BCD1.NibblePort , DIO_NIBBLE_OUTPUT );
	DIO_voidSetHighNibbleDirection( BCD2.NibblePort , DIO_NIBBLE_OUTPUT );
	u8 counter = 0;
	
    while (1) 
    {
		BCD2.NibbleValue = counter;
		BCD_voidInitialDataNibble ( BCD2);
		for (u8 i=0 ; i<=9 ; i++)
		{
			BCD1.NibbleValue = i;
			BCD_voidInitialDataNibble ( BCD1);
			_delay_ms(150);
		}
		counter++;
		if (counter >= 10){counter = 0;}
    }
}

