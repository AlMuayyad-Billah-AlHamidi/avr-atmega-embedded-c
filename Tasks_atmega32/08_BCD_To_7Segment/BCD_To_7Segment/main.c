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
	
    BCD_Type BCD = {BCD_PORTC , LOW_NIBBLE };
	//This Configuration TO Using button to count up from 0:9, One count with one click
	/*u8 *Git_Vlue_Pin ;
	u8 counter = 0;
	DIO_enumSetPinDirection(DIO_PORTD , DIO_PIN0 , DIO_PIN_INPUT);*/
    while (1) 
    {
		/*for (u8 i=0 ; i<=9 ; i++)
		{
			BCD.NibbleValue = i;
			BCD_voidInitialDataNibble ( BCD);
			_delay_ms(250);
		}
		
		for (s8 i=9 ; i>=0 ; i--)
		{
			BCD.NibbleValue = i;
			BCD_voidInitialDataNibble ( BCD);
			_delay_ms(250);
		}*/
		
		
		//Using button to count up from 0:9, One count with one click
		/*DIO_enumGitPinValue    (DIO_PORTD , DIO_PIN0 , Git_Vlue_Pin   );
		u8 Read_PinD0 = *Git_Vlue_Pin;
		BCD.NibbleValue = counter;
		BCD_voidInitialDataNibble ( BCD);
		_delay_ms(250);
			
		if(Read_PinD0 == DIO_PIN_HIGH)
		{
			counter++;
			if (counter >= 10){counter = 0;}
		}*/
		
		 
			
    }
}

