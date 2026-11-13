/*
 * 07_3_SW_with_Interrupts.c
 *
 * Created: 10/9/2024 8:07:31 PM
 * Author : Al_Moaiyad Bellah Al_Hemadi
 */ 

#define F_CPU 1000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void ISR_INT0(void)
{
	DIO_enumSetPinValue(DIO_PORTA, DIO_PIN0, DIO_PIN_LOW);
	
	// Optionally clear the EXTI line interrupt flag
	//EXTI_voidClearFlag(EXTI_LINE0);
}

void ISR_INT1(void)
{
	DIO_enumSetPinValue(DIO_PORTA, DIO_PIN1, DIO_PIN_LOW);
	
	// Optionally clear the EXTI line interrupt flag
	//EXTI_voidClearFlag(EXTI_LINE1);
}

void ISR_INT2(void)
{
	DIO_enumSetPinValue(DIO_PORTA, DIO_PIN2, DIO_PIN_LOW);
	
	// Optionally clear the EXTI line interrupt flag
	//EXTI_voidClearFlag(EXTI_LINE2);
}







int main(void)
{
	// Set pin directions for LEDs
	DIO_enumSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTA, DIO_PIN1, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTA, DIO_PIN2, DIO_PIN_OUTPUT);
	
	
	DIO_enumSetPinValue(DIO_PORTA, DIO_PIN0, DIO_PIN_HIGH);
	DIO_enumSetPinValue(DIO_PORTA, DIO_PIN1, DIO_PIN_HIGH);
	DIO_enumSetPinValue(DIO_PORTA, DIO_PIN2, DIO_PIN_HIGH);

	// Set pin directions for switches (INT0 ,INT1 ,INT2)
	DIO_enumSetPinDirection(DIO_PORTD, DIO_PIN2, DIO_PIN_INPUT);
	DIO_enumSetPinDirection(DIO_PORTD, DIO_PIN3, DIO_PIN_INPUT);
	DIO_enumSetPinDirection(DIO_PORTB, DIO_PIN2, DIO_PIN_INPUT);
	
	// Initialize external interrupts
	EXTI_voidInit();
	
	

	
	// Set callback functions for the interrupts
	EXTI_voidSetCallBack(ISR_INT0, EXTI_LINE0);
	EXTI_voidSetCallBack(ISR_INT1, EXTI_LINE1);
	EXTI_voidSetCallBack(ISR_INT2, EXTI_LINE2);
	
	EXTI_u8EnablePeripheralInterrput (EXTI_LINE0);
	EXTI_u8EnablePeripheralInterrput (EXTI_LINE1);
	EXTI_u8EnablePeripheralInterrput (EXTI_LINE2);
	
	EXTI_u8EnableGlobalInterrput  ();


	
	while (1)
	{
		
	}
}


