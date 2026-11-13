/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	   ADC_private.h 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : MCAL
* Sw     : ADC
*
*/



#ifndef _ADC_PRIVATE_H_
#define _ADC_PRIVATE_H_

#define ADMUX_REG		*((volatile u8 *)0x27)
#define ADCSRA_REG		*((volatile u8 *)0x26)		
#define ADCH_REG		*((volatile u8 *)0x25)		
#define ADCL_REG		*((volatile u8 *)0x24)

#define ADCLH_REG		*((volatile u16 *)0x24) //U16 means will read first 8bits then will read second 8bits(read 0x24 ,0x25)

#define SFIOR_REG		*((volatile u8 *)0x50)

				
#endif /* ADC_PRIVATE_H_ */