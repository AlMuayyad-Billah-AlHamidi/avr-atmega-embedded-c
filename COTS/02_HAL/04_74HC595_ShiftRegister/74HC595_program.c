/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	 74HC595_program.c 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : HAL
* Sw     : 74HC595
*
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "74HC595_private.h"
#include "74HC595_interface.h"
#include "74HC595_config.h"

//Common Cathode
static u8 Local_u8_74HC595Numbers [10][8] = {
	{0,1,1,1,1,1,1,0},  // digit 0
	{0,0,1,1,0,0,0,0},  // digit 1
	{0,1,1,0,1,1,0,1},  // digit 2
	{0,1,1,1,1,0,0,1},  // digit 3
	{0,0,1,1,0,0,1,1},  // digit 4
	{0,1,0,1,1,0,1,1},  // digit 5
	{0,1,0,1,1,1,1,1},  // digit 6
	{0,1,1,1,0,0,0,0},  // digit 7
	{0,1,1,1,1,1,1,1},  // digit 8
	{0,1,1,1,1,0,1,1}   // digit 9
};

//
void    SHIFT_REGISTER_voidSetDirection ( SHIFT_REGISTER_Type Copy_structConfig )
{
	 DIO_enumSetPinDirection(Copy_structConfig.Port , Copy_structConfig.DS_Pin   , DIO_PIN_OUTPUT);
	 DIO_enumSetPinDirection(Copy_structConfig.Port , Copy_structConfig.SHCP_Pin , DIO_PIN_OUTPUT);
	 DIO_enumSetPinDirection(Copy_structConfig.Port , Copy_structConfig.STCP_Pin , DIO_PIN_OUTPUT);
}

//
void	SHIFT_REGISTER_voidDisplayDigit ( SHIFT_REGISTER_Type Copy_structConfig )
{
	DIO_enumSetPinValue(Copy_structConfig.Port, Copy_structConfig.STCP_Pin , DIO_PIN_LOW); 
	for(s8 i = 7 ; i>=0 ; i--)
	{
		
		DIO_enumSetPinValue(Copy_structConfig.Port , Copy_structConfig.SHCP_Pin ,DIO_PIN_LOW);
		
		if(Local_u8_74HC595Numbers[Copy_structConfig.Send_Number][i] == 1)
		{
			DIO_enumSetPinValue(Copy_structConfig.Port , Copy_structConfig.DS_Pin ,DIO_PIN_HIGH);// For Common Anode SSD Replace DIO_PIN_HIGH with DIO_PIN_LOW
		}
		
		if(Local_u8_74HC595Numbers[Copy_structConfig.Send_Number][i] == 0)
		{
			DIO_enumSetPinValue(Copy_structConfig.Port , Copy_structConfig.DS_Pin ,DIO_PIN_LOW);// For Common Anode SSD Replace DIO_PIN_LOW with DIO_PIN_HIGH
		}
		
		DIO_enumSetPinValue(Copy_structConfig.Port , Copy_structConfig.SHCP_Pin ,DIO_PIN_HIGH);
		
	}
	
	DIO_enumSetPinValue(Copy_structConfig.Port , Copy_structConfig.STCP_Pin ,DIO_PIN_HIGH);
}


