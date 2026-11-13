/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	   ADC_interface.h 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : MCAL
* Sw     : ADC
*
*/



#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_

#define ADC_Voltage_Reference_AREF					0
#define ADC_Voltage_Reference_AVCC					1	
#define ADC_Voltage_Reference_INTERNAL				3

/* ADMUX_REGISTER'S BITS*/
#define ADC_MUX0	0
#define ADC_MUX1	1
#define ADC_MUX2	2
#define ADC_MUX3	3
#define ADC_MUX4	4
#define ADC_ADLAR	5  
#define ADC_REFS0	6
#define ADC_REFS1	7 

/* ADCSRA_REGISTERS'S BITS*/
#define ADC_ADPS0	0
#define ADC_ADPS1	1
#define ADC_ADPS2	2
#define ADC_ADIE	3
#define ADC_ADIF	4
#define ADC_ADATE	5
#define ADC_ADSC	6
#define ADC_ADEN	7

typedef enum {
	ADC_Channel_0,
	ADC_Channel_1,
	ADC_Channel_2,
	ADC_Channel_3,
	ADC_Channel_4,
	ADC_Channel_5,
	ADC_Channel_6,
	ADC_Channel_7,
	}ADC_Channel_TYPE;

void ADC_voidInit(void);
void ADC_voidStartConversion(ADC_Channel_TYPE ADC_Channel);
u16 ADC_u16GitRead(void);


#endif