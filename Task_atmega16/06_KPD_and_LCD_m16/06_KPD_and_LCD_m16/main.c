/*
 * 06_KPD_and_LCD_m16.c
 *
 * Created: 10/1/2024 8:12:09 PM
 * Author : MouhannadlrX
 */ 
#define F_CPU 1000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

//#include "PORT_interface.h"
#include "KPD_interface.h"
#include "CLCD_interface.h"


int main(void)
{
	u8 pressed_number;
	u8 counter=0;
	
   // PORT_voidInit();
    KPD_voidInit();
    
	CLCD_voidInit();
	CLCD_voidSetPosition  (CLCD_ROW_1, CLCD_COL_1 );
	
    while (1) 
    {
		
		pressed_number = kpd_u8GetPressed();
		if (pressed_number != NOT_PRESSED)
		{
			counter++;
			CLCD_voidSendData( pressed_number );
			if (counter == 16)
			{
				CLCD_voidSetPosition  (CLCD_ROW_2 , CLCD_COL_1 );
			}
			
		}
		
		
		
    }
}

