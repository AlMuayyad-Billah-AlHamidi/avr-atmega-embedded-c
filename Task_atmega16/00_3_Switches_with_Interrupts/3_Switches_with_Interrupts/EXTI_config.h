/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	   EXTI_config.h 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : MCAL
* Sw     : EXTI
*
*/


#ifndef _EXTI_CONFIG_H_
#define _EXTI_CONFIG_H_

/*
	options :
	
		1-EXTI_LIN0
		2-EXTI_LIN1
		3-EXTI_LIN2

*/

#define EXTI_LINE		EXTI_LINE0

/*
	options :
	
		1-EXTI_FALING_EDGE
		2-EXTI_RISING_EDGE
		3-EXTI_LOW_LEVEL
		4-EXTI_ON_CHANGE

*/

#define EXTI_SENSE_MODE		EXTI_RISING_EDGE

#endif