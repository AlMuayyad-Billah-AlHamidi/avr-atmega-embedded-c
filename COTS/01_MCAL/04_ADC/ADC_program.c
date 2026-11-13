/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	   ADC_program.c 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : MCAL
* Sw     : ADC
*
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


void ADC_voidInit (void)
{
	#if ADC_Voltage_Reference == ADC_Voltage_Reference_AREF
		CLR_BIT(ADMUX_REG ,ADC_REFS0);  CLR_BIT(ADMUX_REG ,ADC_REFS1);

	#elif ADC_Voltage_Reference == ADC_Voltage_Reference_AVCC
		SET_BIT(ADMUX_REG ,ADC_REFS0);  CLR_BIT(ADMUX_REG ,ADC_REFS1);

	#elif ADC_Voltage_Reference == ADC_Voltage_Reference_INTERNAL
		SET_BIT(ADMUX_REG ,ADC_REFS0);  SET_BIT(ADMUX_REG ,ADC_REFS1);

	#endif

	/* Left Adjust Result */
	SET_BIT(ADMUX_REG , ADC_ADLAR);

	/* ADC Prescaler Select (Division Factor 8) */
	SET_BIT(ADCSRA_REG , ADC_ADPS0);
	SET_BIT(ADCSRA_REG , ADC_ADPS1);
	CLR_BIT(ADCSRA_REG , ADC_ADPS2);

	/* ADC Enable */
	SET_BIT(ADCSRA_REG , ADC_ADEN);
}

u16 ADC_u16GitRead(void)
{
	u16 Converted_Value = 0;
	Converted_Value = ADCLH_REG;
	Converted_Value = (Converted_Value >> 6);
	return Converted_Value;
}

void ADC_voidStartConversion(ADC_Channel_TYPE ADC_Channel)
{
	switch(ADC_Channel)
	{
		case ADC_Channel_0:
		CLR_BIT(ADMUX_REG ,ADC_MUX0);
		CLR_BIT(ADMUX_REG ,ADC_MUX1);
		CLR_BIT(ADMUX_REG ,ADC_MUX2);
		CLR_BIT(ADMUX_REG ,ADC_MUX3);
		CLR_BIT(ADMUX_REG ,ADC_MUX4);
		break;

		case ADC_Channel_1:
		SET_BIT(ADMUX_REG ,ADC_MUX0);
		CLR_BIT(ADMUX_REG ,ADC_MUX1);
		CLR_BIT(ADMUX_REG ,ADC_MUX2);
		CLR_BIT(ADMUX_REG ,ADC_MUX3);
		CLR_BIT(ADMUX_REG ,ADC_MUX4);
		break;

		case ADC_Channel_2:
		CLR_BIT(ADMUX_REG ,ADC_MUX0);
		SET_BIT(ADMUX_REG ,ADC_MUX1);
		CLR_BIT(ADMUX_REG ,ADC_MUX2);
		CLR_BIT(ADMUX_REG ,ADC_MUX3);
		CLR_BIT(ADMUX_REG ,ADC_MUX4);
		break;

		case ADC_Channel_3:
		SET_BIT(ADMUX_REG ,ADC_MUX0);
		SET_BIT(ADMUX_REG ,ADC_MUX1);
		CLR_BIT(ADMUX_REG ,ADC_MUX2);
		CLR_BIT(ADMUX_REG ,ADC_MUX3);
		CLR_BIT(ADMUX_REG ,ADC_MUX4);
		break;

		case ADC_Channel_4:
		CLR_BIT(ADMUX_REG ,ADC_MUX0);
		CLR_BIT(ADMUX_REG ,ADC_MUX1);
		SET_BIT(ADMUX_REG ,ADC_MUX2);
		CLR_BIT(ADMUX_REG ,ADC_MUX3);
		CLR_BIT(ADMUX_REG ,ADC_MUX4);
		break;

		case ADC_Channel_5:
		SET_BIT(ADMUX_REG ,ADC_MUX0);
		CLR_BIT(ADMUX_REG ,ADC_MUX1);
		SET_BIT(ADMUX_REG ,ADC_MUX2);
		CLR_BIT(ADMUX_REG ,ADC_MUX3);
		CLR_BIT(ADMUX_REG ,ADC_MUX4);
		break;

		case ADC_Channel_6:
		CLR_BIT(ADMUX_REG ,ADC_MUX0);
		SET_BIT(ADMUX_REG ,ADC_MUX1);
		SET_BIT(ADMUX_REG ,ADC_MUX2);
		CLR_BIT(ADMUX_REG ,ADC_MUX3);
		CLR_BIT(ADMUX_REG ,ADC_MUX4);
		break;

		case ADC_Channel_7:
		SET_BIT(ADMUX_REG ,ADC_MUX0);
		SET_BIT(ADMUX_REG ,ADC_MUX1);
		SET_BIT(ADMUX_REG ,ADC_MUX2);
		CLR_BIT(ADMUX_REG ,ADC_MUX3);
		CLR_BIT(ADMUX_REG ,ADC_MUX4);
		break;
	}

	SET_BIT(ADCSRA_REG , ADC_ADSC);
}
