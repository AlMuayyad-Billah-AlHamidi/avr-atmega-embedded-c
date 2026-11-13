/*
 * 08_ADC_DigitalValue_On_LCD.c
 *
 * Created: 11/2/2024 10:56:01 PM
 * Author : Al_Moaiyad Bellah Al_Hemadi
 */ 
#define  F_CPU 1000000UL
#include <util/delay.h>
#include  "BIT_MATH.h"
#include  "STD_TYPES.h"

#include  "DIO_interface.h"
#include  "CLCD_interface.h"
#include  "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

#define STEP	0.0048828125


int main(void)
{
	u16 Digital_Value = 0;
	f32 Analog_Value = 0;
	u8 String[] = "Analog=";
	u8 Arr_Analog_Val_String[16];
	DIO_enumSetPinDirection(DIO_PORTA,DIO_PIN2,DIO_PIN_OUTPUT);
    ADC_voidInit();
	CLCD_voidInit();
	ADC_voidStartConversion(ADC_Channel_6);
	CLCD_voidSetPosition  (CLCD_ROW_1 ,CLCD_COL_1);
	CLCD_voidSendString(String);
    while (1) 
    {
		
		if ( IS_BIT_SET(ADCSRA_REG,ADC_ADIF))
		{
			Digital_Value = ADC_u16GitRead();
			Analog_Value  = Digital_Value * STEP ;
			
			ftos(Analog_Value, Arr_Analog_Val_String, 3); 
			
			CLCD_voidSetPosition  (CLCD_ROW_1 ,CLCD_COL_8);
			CLCD_voidSendString  (Arr_Analog_Val_String);
			
			DIO_enumSetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
			/* Clear ADC Flag*/
			SET_BIT(ADCSRA_REG,ADC_ADIF);
			ADC_voidStartConversion(ADC_Channel_6);
			_delay_ms(500);
		}
		
		DIO_enumSetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
    }
}



// Reverses a string 'str' of length 'len'
void reverse(u8* str, u8 len)
{
	int i = 0, j = len - 1, temp;
	while (i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

// Converts a given integer x to string str[].
// d is the number of digits required in the output.
// If d is more than the number of digits in x,
// then 0s are added at the beginning.
u8 intToStr(u32 x, u8 str[], u8 d)
{
	u8 i = 0;
	while (x) {
		//take the last digit on the right
		str[i++] = (x % 10) + '0';
		//remove the last digit on the right
		x = x / 10;
	}
	
	// If number of digits required is more, then
	// add 0s at the beginning
	while (i < d)
	str[i++] = '0';
	
	reverse(str, i);
	str[i] = '\0';
	return i;
}

// Converts a floating-point/double number to a string.
void ftos(f32 n, u8* res, u8 afterpoint)
{
	// Extract integer part
	u8 ipart = (u8)n;
	
	// Extract floating part
	f32 fpart = n - ipart;
	
	// convert integer part to string
	u8 i = intToStr(ipart, res, 1);
	
	// check for display option after point
	if (afterpoint != 0) {
		res[i] = '.'; // add dot
		
		// Get the value of fraction part upto given no.
		// of points after dot. The third parameter
		// is needed to handle cases like 233.007
		fpart = fpart * pow(10, afterpoint);
		
		intToStr((u32)fpart, res + i + 1, afterpoint);
	}
}

