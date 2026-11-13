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
	
		1-EXTI_LINE_Disable
		2-EXTI_LINE_Enable	

*/

#define EXTI_LINE0_State		 EXTI_LINE_Enable
#define EXTI_LINE1_State		 EXTI_LINE_Enable
#define EXTI_LINE2_State		 EXTI_LINE_Enable


/*
	options :
	
		1-EXTI_FALLING_EDGE
		2-EXTI_RISING_EDGE
		3-EXTI_LOW_LEVEL
		4-EXTI_Any_Logical_Change

*/

#define EXTI_LINE0_SENSE_MODE		EXTI_FALLING_EDGE
#define EXTI_LINE1_SENSE_MODE		EXTI_FALLING_EDGE
#define EXTI_LINE2_SENSE_MODE		EXTI_RISING_EDGE
#endif