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

#define SREG_REG		*((volatile u8 *)0x5F)
#define MCUCR_REG		*((volatile u8 *)0x55)
#define MCUCSR_REG		*((volatile u8 *)0x54)
#define GICR_REG		*((volatile u8 *)0x5B)
#define GIFR_REG		*((volatile u8 *)0x5A)

#define NULL	0

#endif /* EXTI_PRIVATE_H_ */