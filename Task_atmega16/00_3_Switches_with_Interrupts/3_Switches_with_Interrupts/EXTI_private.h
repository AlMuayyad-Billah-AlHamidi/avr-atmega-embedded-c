/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	   EXTI_private.h 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : MCAL
* Sw     : EXTI
*
*/



#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_

#define MCUCR_REG		*((volatile u8 *)0x55)
#define MCUCSR_REG		*((volatile u8 *)0x54)		
#define GICR_REG		*((volatile u8 *)0x5B)		
#define GIFR_REG		*((volatile u8 *)0x5A)
#define SREG_REG		*((volatile u8 *)0x5F)

#define NULL	0		
				
#endif