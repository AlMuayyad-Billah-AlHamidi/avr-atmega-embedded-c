/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	   74HC595_interface.h 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : HAL
* Sw     : 74HC595
*
*/



#ifndef _74HC595_INTERFACE_H_
#define _74HC595_INTERFACE_H_

typedef struct{
	u8 Port;
	u8 SHCP_Pin;
	u8 DS_Pin;
	u8 STCP_Pin;
	u8 Send_Number;
}SHIFT_REGISTER_Type;

void    SHIFT_REGISTER_voidSetDirection ( SHIFT_REGISTER_Type Copy_structConfig );
void	SHIFT_REGISTER_voidDisplayDigit ( SHIFT_REGISTER_Type Copy_structConfig );

#endif