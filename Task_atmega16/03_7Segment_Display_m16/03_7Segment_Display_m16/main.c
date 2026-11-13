/*
 * 7Segment_Display.c
 *
 * Created: 9/8/2024 4:19:43 PM
 * Author : MouhannadlrX
 */ 

#define  F_CPU 1000000UL
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
#include <util/delay.h>


int main(void)
{
	SSD_Type SSD1 = {SSD_COMMON_CATHODE , SSD_PORTA , SSD_PORTB ,SSD_PIN0 };
    SSD_voidInitialDataPort ( SSD1 );
	
    while (1) 
    {
		//Show Numbers From [0:9]
		SSD_voidEnable( SSD1 );
		for (u8 i=0 ; i<=9 ; i++)
		{
			SSD_voidSendNumber( SSD1 , i );
			_delay_ms(2000);
		}
		
		/*SSD_voidDisable( SSD1 );
		_delay_ms(500);*/
		
		//Show Characters From [a:f]
		/*for (u8 i=0 ; i<=5 ; i++)
		{
			SSD_voidSendCharacter( SSD , i );
			_delay_ms(500);
		}
		
		SSD_voidDisable( SSD );
		_delay_ms(500);*/
	}
}

