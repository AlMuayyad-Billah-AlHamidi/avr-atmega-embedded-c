/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	 CLCD_program.c 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : HAL
* Sw     : CLCD
*
*/
#define F_CPU 16000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "CLCD_private.h"
#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_ExtraChar.h"		
		
void CLCD_voidInit( void)
{
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 8 bit mode >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	//#if	CLCD_MODE == 8
	// 1- must wait more than 30 ms before any action (VDD rises to 4.5 v)
	_delay_ms(50);
	
	DIO_enumSetPortDirection(CLCD_DATA_PORT		, DIO_PORT_OUTPUT);
	DIO_enumSetPinDirection (CLCD_CONTROL_PORT  , CLCD_RS , DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection (CLCD_CONTROL_PORT  , CLCD_RW , DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection (CLCD_CONTROL_PORT  , CLCD_EN , DIO_PIN_OUTPUT);
	
	// return cursor to the first position on the first line 
	CLCD_voidSendCommand(lcd_Home);
	_delay_ms(1);
	
	// function set commend : 2 lines , 5*8 font size
	CLCD_voidSendCommand(EIGHT_BITS);
	_delay_ms(1);
	
	// display & cursor (on/off) control
	CLCD_voidSendCommand(lcd_DisplayOn_CursorOff);
	_delay_ms(1);

	//display clear
	CLCD_voidClearScreen();	
	
	//entry mode set
	CLCD_voidSendCommand(lcd_EntryMode);
	_delay_ms(1);
	
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 4 bit mode >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	//#elif	CLCD_MODE == 4
	// 1- must wait more than 30 ms before any action (VDD rises to 4.5 v)
	/*_delay_ms(50);
	
	DIO_voidSetHighNibbleDirection(CLCD_DATA_PORT , DIO_NIBBLE_OUTPUT);
	DIO_enumSetPinDirection (CLCD_CONTROL_PORT  , CLCD_RS , DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection (CLCD_CONTROL_PORT  , CLCD_RS , DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection (CLCD_CONTROL_PORT  , CLCD_RS , DIO_PIN_OUTPUT);
	
	// return cursor to the first position on the first line
	CLCD_voidSendCommand(lcd_Home);
	_delay_ms(1);
	
	// function set commend : 1 lines , 5*8 font size
	CLCD_voidSendCommand(FOUR_BITS);
	_delay_ms(1);
	
	// display & cursor (on/off) control
	CLCD_voidSendCommand(lcd_DisplayOn_CursorOff);
	_delay_ms(1);

	//display clear
	CLCD_voidClearScreen();
	
	//entry mode set
	CLCD_voidSendCommand(lcd_EntryMode);
	_delay_ms(1);*/
	//#endif
}

void CLCD_voidSendData( u8 Copy_u8Data )
{
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 8 bit mode >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	//#if		CLCD_MODE == 8
	DIO_enumSetPortValue	(CLCD_DATA_PORT  , Copy_u8Data);
	DIO_enumSetPinValue	    (CLCD_CONTROL_PORT  , CLCD_RS , DIO_PIN_HIGH);	// rs pin high means send data
	DIO_enumSetPinValue	    (CLCD_CONTROL_PORT  , CLCD_RW , DIO_PIN_LOW);	// rw pin low  means write
	CLCD_voidSendFallingEdge();												// for enable send data
	
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 4 bit mode >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	/*#elif	CLCD_MODE == 4
	DIO_voidWriteHighNibble	(CLCD_DATA_PORT  , Copy_u8Data);
	DIO_enumSetPinValue	    (CLCD_CONTROL_PORT  , CLCD_RS , DIO_PIN_HIGH);	// rs pin high means send data
	DIO_enumSetPinValue	    (CLCD_CONTROL_PORT  , CLCD_RW , DIO_PIN_LOW);	// rw pin low  means write
	CLCD_voidSendFallingEdge();												// for enable send data
	#endif*/
	_delay_ms(1);
}

void CLCD_voidSendString  (const u8 * Copy_u8PtrString )
{
	u8 Loc_Iterator = 0 ;
	while(Copy_u8PtrString[Loc_Iterator] != '\0')
	{
		CLCD_voidSendData( Copy_u8PtrString[Loc_Iterator] );
		Loc_Iterator++; 
	}
	
}


void 	  CLCD_voidSendCommand( u8 Copy_u8Commend )
{
		//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 8 bit mode >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		//#if		CLCD_MODE == 8
		
		DIO_enumSetPortValue	(CLCD_DATA_PORT  , Copy_u8Commend);
		DIO_enumSetPinValue	    (CLCD_CONTROL_PORT  , CLCD_RS , DIO_PIN_LOW);		// rs pin low means commend
		DIO_enumSetPinValue	    (CLCD_CONTROL_PORT  , CLCD_RW , DIO_PIN_LOW);		// rw pin low means write
		CLCD_voidSendFallingEdge();													// for enable send commend
		
		//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 4 bit mode >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		//#elif	CLCD_MODE == 4
		
		/*DIO_voidWriteHighNibble	(CLCD_DATA_PORT  , Copy_u8Commend);
		DIO_enumSetPinValue	    (CLCD_CONTROL_PORT  , CLCD_RS , DIO_PIN_LOW);	// rs pin high means send data
		DIO_enumSetPinValue	    (CLCD_CONTROL_PORT  , CLCD_RW , DIO_PIN_LOW);	// rw pin low  means write
		CLCD_voidSendFallingEdge();*/
			
		//#endif
		_delay_ms(1);
}



static void CLCD_voidSendFallingEdge(void)
{
	DIO_enumSetPinValue(CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_enumSetPinValue(CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_LOW);
}

void CLCD_voidClearScreen()
{
	CLCD_voidSendCommand(lcd_Clear);
	_delay_ms(10);
}


/*********************************************************************************************/

void	  CLCD_voidSetPosition  (u8 Copy_u8Row , u8 Copy_u8Col  )
{
	u8 LOC_u8data ;
	
	// in these cases will set at (0,0) ==> if the user enter invalid location 
	if ( Copy_u8Row > CLCD_ROW_2 || Copy_u8Row < CLCD_ROW_1 || Copy_u8Col > CLCD_COL_16 || Copy_u8Col < CLCD_COL_1)		//check
	{
		LOC_u8data = lcd_SetCursor ;
	}
	
	else if (Copy_u8Row == CLCD_ROW_1)
	{
		LOC_u8data = ( lcd_SetCursor + Copy_u8Col );				//ROW1 -> 0x80 + col
	}
	
	else if (Copy_u8Row == CLCD_ROW_2)
	{
		LOC_u8data = ( (lcd_SetCursor) + (64) + (Copy_u8Col) );		//ROW2 -> 0xc0 + col
	}
	CLCD_voidSendCommand(LOC_u8data);
	_delay_ms(1);
}

/* 
*Breif :The Function Send extra char
*Parameters :
			=> Copy_u8Row --> row number (CLCD_ROW_1 or CLCD_ROW_2)
			=> Copy_u8Col --> column number (CLCD_COL_1 .... CLCD_COL_16)
* return : nothing
* Hint :-
	Address Counter can refer to CGRAM and DDRAM
	
*/

void CLCD_voidSendExtraChar( u8 Copy_u8Row , u8 Copy_u8Col)
{
	u8 LOC_u8Iterator = 0;
	
	// 1- go to CGRAM
	CLCD_voidSendCommand(lcd_CGRAM); //Make Ac refers to the first place/Address at CGRAM
	
	// 2- draw character in CGRAM
	// Hint : it will be copied to DDRAM automatically
	for ( LOC_u8Iterator = 0 ; LOC_u8Iterator < ( sizeof(CLCD_u8ExtraChar) / sizeof(CLCD_u8ExtraChar[0]) ) ; LOC_u8Iterator++)
	{
		CLCD_voidSendData(CLCD_u8ExtraChar[LOC_u8Iterator]);
	}
	
	// 3- Back (AC) to DDRAM
	CLCD_voidSetPosition( Copy_u8Row , Copy_u8Col);
	
	// 4- Send Character Address
	for ( LOC_u8Iterator = 0 ; LOC_u8Iterator < 8 ; LOC_u8Iterator++)
	{
		CLCD_voidSendData(LOC_u8Iterator);
	}
}