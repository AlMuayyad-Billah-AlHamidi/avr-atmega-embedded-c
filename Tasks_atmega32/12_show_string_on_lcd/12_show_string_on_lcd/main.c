/*
 * 12_show_string_on_lcd.c
 *
 * Created: 9/21/2024 6:25:04 PM
 * Author : MouhannadlrX
 */ 
#define  F_CPU 1000000UL
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"

//#include "CLCD_config.h"
//#include "CLCD_ExtraChar.h"
#include "CLCD_interface.h"
//#include "CLCD_private.h"

#include <util/delay.h>


int main(void)
{
    CLCD_voidInit();
	CLCD_voidSetPosition  (CLCD_ROW_1 ,CLCD_COL_1);
	//CLCD_voidSendExtraChar(CLCD_ROW_1 ,CLCD_COL_6);
	u8 string[16] ="Almoaiyad Bellah";

	CLCD_voidSendString  (string);
	u8 string1[]  = "<<<ALhemadi<<<   ";
	
	
	u8 space [] = "  >>>ALhemadi>>>";
	
	
    while (1) 
    {
		
		
		CLCD_voidSetPosition  (CLCD_ROW_2 ,CLCD_COL_1);
		CLCD_voidSendString  (string1);
		_delay_ms(1000);
		CLCD_voidSetPosition  (CLCD_ROW_2 ,CLCD_COL_1);
		CLCD_voidSendString  (space);
		_delay_ms(1000);
    }
}

