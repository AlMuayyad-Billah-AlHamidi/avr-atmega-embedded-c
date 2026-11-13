/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	   EXTI_interface.h 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : MCAL
* Sw     : EXTI
*
*/



#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_

#define NOK		0
#define OK		1
/* 
	Hint : I assume those values 6,7,5 because the position of each INT bits in the Reg (GICR,GIFR ....)	
	I will use That for SET and CLR BITS

 */

#define EXTI_LINE_Disable	0
#define EXTI_LINE_Enable	1

#define EXTI_LINE0   6
#define EXTI_LINE1   7
#define EXTI_LINE2   5

#define EXTI_LOW_LEVEL				0
#define EXTI_Any_Logical_Change     1
#define EXTI_FALLING_EDGE			2
#define EXTI_RISING_EDGE			3


#define Global_Interrupt_Bit   7

#define NULL	0

void EXTI_voidInit (void);
u8	 EXTI_u8DisablePeripheralInterrput ( u8 Copy_u8Line);
u8	 EXTI_u8EnablePeripheralInterrput  ( u8 Copy_u8Line);

void EXTI_u8DisableGlobalInterrput ();
void EXTI_u8EnableGlobalInterrput  ();


void EXTI_voidSetSignalLatch (u8 Copy_u8SenseMode , u8 Copy_u8Line );
void EXTI_voidClearFlag      ( u8 Copy_u8Line);

void EXTI_voidSetCallBack	 ( void (*Copy_pvoidCallBack)(void) , u8 Copy_u8EXTILine );

#endif