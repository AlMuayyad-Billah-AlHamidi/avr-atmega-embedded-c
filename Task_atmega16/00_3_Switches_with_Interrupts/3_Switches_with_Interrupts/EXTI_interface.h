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


#define EXTI_LINE0   6
#define EXTI_LINE1   7
#define EXTI_LINE2   5


#define EXTI_FALLING_EDGE  0
#define EXTI_RISING_EDGE   1
#define EXTI_LOW_LEVEL     2
#define EXTI_ON_CHANGE     3

#define GLOBAL_INTERRUPT_ENABLE_PIN		7

#define NULL 0

void EXTI_voidInit (void);
void EXTI_voidSetSignalLatch (u8 Copy_u8SenseMode , u8 Copy_u8Line );
u8	 EXTI_u8DisableInterrput ( u8 Copy_u8Line); 
u8	 EXTI_u8EnableInterrput  ( u8 Copy_u8Line);

void EXTI_voidClearFlag      ( u8 Copy_u8Line);
void EXTI_voidSetCallBack	 ( void (*Copy_pvoidCallBack)(void) , u8 Copy_u8EXTILine );

#endif