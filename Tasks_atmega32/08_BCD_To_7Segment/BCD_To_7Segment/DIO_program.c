/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	   DIO_program.c 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : MCAL
* Sw     : DIO/GPIO
*
*/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


DIO_ErrorStatus DIO_enumSetPinDirection(u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8DIRECTION)
{
	DIO_ErrorStatus LOC_enumStatus = DIO_OK ;
	
	if( (Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7) )
	{
		if(Copy_u8DIRECTION ==  DIO_PIN_OUTPUT)
		{
			switch(Copy_u8PORT)
			{
				case DIO_PORTA : SET_BIT(DDRA_Register,Copy_u8PIN);break;
				case DIO_PORTB : SET_BIT(DDRB_Register,Copy_u8PIN);break;
				case DIO_PORTC : SET_BIT(DDRC_Register,Copy_u8PIN);break;
				case DIO_PORTD : SET_BIT(DDRD_Register,Copy_u8PIN);break;
			}
		}
		
		else if(Copy_u8DIRECTION ==  DIO_PIN_INPUT)
		{
			switch(Copy_u8PORT)
			{
				case DIO_PORTA : CLR_BIT(DDRA_Register,Copy_u8PIN);break;
				case DIO_PORTB : CLR_BIT(DDRB_Register,Copy_u8PIN);break;
				case DIO_PORTC : CLR_BIT(DDRC_Register,Copy_u8PIN);break;
				case DIO_PORTD : CLR_BIT(DDRD_Register,Copy_u8PIN);break;
			}
		}
		
		else
		{
			LOC_enumStatus = DIO_NOK ;
		}
	}
	
	else
	{
		LOC_enumStatus = DIO_NOK ;
	}
	
	return LOC_enumStatus;
	
}

DIO_ErrorStatus DIO_enumSetPinValue    (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8VALUE    )
{
	DIO_ErrorStatus LOC_enumStatus = DIO_OK ;
	
	if( (Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7) )
	{
		if(Copy_u8VALUE  ==  DIO_PIN_HIGH)
		{
			switch(Copy_u8PORT)
			{
				case DIO_PORTA : SET_BIT(PORTA_Register,Copy_u8PIN);break;
				case DIO_PORTB : SET_BIT(PORTB_Register,Copy_u8PIN);break;
				case DIO_PORTC : SET_BIT(PORTC_Register,Copy_u8PIN);break;
				case DIO_PORTD : SET_BIT(PORTD_Register,Copy_u8PIN);break;
			}
		}
		
		else if(Copy_u8VALUE ==  DIO_PIN_LOW)
		{
			switch(Copy_u8PORT)
			{
				case DIO_PORTA : CLR_BIT(PORTA_Register,Copy_u8PIN);break;
				case DIO_PORTB : CLR_BIT(PORTB_Register,Copy_u8PIN);break;
				case DIO_PORTC : CLR_BIT(PORTC_Register,Copy_u8PIN);break;
				case DIO_PORTD : CLR_BIT(PORTD_Register,Copy_u8PIN);break;
			}                                 
		}
		
		else
		{
			LOC_enumStatus = DIO_NOK ;
		}
		
	}
	
	else
	{
		LOC_enumStatus = DIO_NOK ;
	}
	
	return LOC_enumStatus;
	
}

DIO_ErrorStatus DIO_enumGitPinValue    (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 *Copy_PtrData   )
{
	DIO_ErrorStatus LOC_enumStatus = DIO_OK ;
	
	if( (Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7) )
	{
		switch(Copy_u8PORT)
			{
				case DIO_PORTA : *Copy_PtrData = GIT_BIT(PINA_Register,Copy_u8PIN);break;
				case DIO_PORTB : *Copy_PtrData = GIT_BIT(PINB_Register,Copy_u8PIN);break;
				case DIO_PORTC : *Copy_PtrData = GIT_BIT(PINC_Register,Copy_u8PIN);break;
				case DIO_PORTD : *Copy_PtrData = GIT_BIT(PIND_Register,Copy_u8PIN);break;
			}
	}
	
	else
	{
		LOC_enumStatus = DIO_NOK ;
	}
	
	return LOC_enumStatus;
}

DIO_ErrorStatus DIO_enumTogglePinValue (u8 Copy_u8PORT , u8 Copy_u8PIN 					 )
{
	DIO_ErrorStatus LOC_enumStatus = DIO_OK ;
	
	if( (Copy_u8PIN <= DIO_PIN7) )
	{
		switch(Copy_u8PORT)
		{
			case DIO_PORTA : TOG_BIT(PORTA_Register,Copy_u8PIN);break;
			case DIO_PORTB : TOG_BIT(PORTB_Register,Copy_u8PIN);break;
			case DIO_PORTC : TOG_BIT(PORTC_Register,Copy_u8PIN);break;
			case DIO_PORTD : TOG_BIT(PORTD_Register,Copy_u8PIN);break;
		}
	}
	
	else
	{
		LOC_enumStatus = DIO_NOK ;
	}
	
	return LOC_enumStatus;
}


DIO_ErrorStatus DIO_enumSetPortDirection(u8 Copy_u8PORT , u8 Copy_u8DIRECTION)
{
	DIO_ErrorStatus LOC_enumStatus = DIO_OK ;
	
	if( (Copy_u8PORT <= DIO_PORTD) )
	{
		switch(Copy_u8PORT)
			{
				case DIO_PORTA : DDRA_Register = Copy_u8DIRECTION;break;
				case DIO_PORTB : DDRB_Register = Copy_u8DIRECTION;break;
				case DIO_PORTC : DDRC_Register = Copy_u8DIRECTION;break;
				case DIO_PORTD : DDRD_Register = Copy_u8DIRECTION;break;
				default: LOC_enumStatus = DIO_NOK ;break;
			}
	}
	
	else
	{
		LOC_enumStatus = DIO_NOK ;
	}
	
	return LOC_enumStatus;
}

DIO_ErrorStatus DIO_enumSetPortValue    (u8 Copy_u8PORT , u8 Copy_u8VALUE    )
{
	DIO_ErrorStatus LOC_enumStatus = DIO_OK ;
	
	if( (Copy_u8PORT <= DIO_PORTD) )
	{
		switch(Copy_u8PORT)
			{
				case DIO_PORTA : PORTA_Register = Copy_u8VALUE;break;
				case DIO_PORTB : PORTB_Register = Copy_u8VALUE;break;
				case DIO_PORTC : PORTC_Register = Copy_u8VALUE;break;
				case DIO_PORTD : PORTD_Register = Copy_u8VALUE;break;
				default: LOC_enumStatus = DIO_NOK ;break;
			}
	}
	
	else
	{
		LOC_enumStatus = DIO_NOK ;
	}
	
	return LOC_enumStatus;
}

DIO_ErrorStatus DIO_enumTogglePortValue (u8 Copy_u8PORT 					  )
{
	DIO_ErrorStatus LOC_enumStatus = DIO_OK ;
	
	if( (Copy_u8PORT <= DIO_PORTD) )
	{
		switch(Copy_u8PORT)
			{
				case DIO_PORTA : PORTA_Register = ~ PORTA_Register;break;
				case DIO_PORTB : PORTB_Register = ~ PORTB_Register;break;
				case DIO_PORTC : PORTC_Register = ~ PORTC_Register;break;
				case DIO_PORTD : PORTD_Register = ~ PORTD_Register;break;
			
			}
	}
	else
	{
		LOC_enumStatus = DIO_NOK ;
	}
	
	return LOC_enumStatus;
}

DIO_ErrorStatus DIO_enumGitPortValue      (u8 Copy_u8PORT , u8 *Copy_PtrData )
{
	
	DIO_ErrorStatus LOC_enumStatus = DIO_OK ;
	
	if( (Copy_u8PORT <= DIO_PORTD) )
	{
		switch(Copy_u8PORT)
			{
				case DIO_PORTA : *Copy_PtrData = PINA_Register;break;
				case DIO_PORTB : *Copy_PtrData = PINB_Register;break;
				case DIO_PORTC : *Copy_PtrData = PINC_Register;break;
				case DIO_PORTD : *Copy_PtrData = PIND_Register;break;
				default: LOC_enumStatus = DIO_NOK ;break;
			}
	}
	
	else
	{
		LOC_enumStatus = DIO_NOK ;
	}
	
	return LOC_enumStatus;
}

void DIO_voidWriteLowNibble( u8 Copy_u8PORT , u8 Copy_u8Vlue  )
{
	Copy_u8Vlue &= 0x0F;
	if( (Copy_u8PORT <= DIO_PORTD) )
	{
		switch(Copy_u8PORT)
			{
				case DIO_PORTA :
				PORTA_Register   &= 0xF0;
				PORTA_Register   |= Copy_u8Vlue;
				break;

				case DIO_PORTB :
				PORTB_Register   &= 0xF0;
				PORTB_Register   |= Copy_u8Vlue;
				break;

				case DIO_PORTC :
				PORTC_Register   &= 0xF0;
				PORTC_Register   |= Copy_u8Vlue;
				break;

				case DIO_PORTD :
				PORTD_Register   &= 0xF0;
				PORTD_Register   |= Copy_u8Vlue;
				break;
				
			}
	}
}

void DIO_voidWriteHighNibble( u8 Copy_u8PORT , u8 Copy_u8Vlue  )
{
	Copy_u8Vlue = (Copy_u8Vlue & 0x0F) << 4;
	if( (Copy_u8PORT <= DIO_PORTD) )
	{
		switch(Copy_u8PORT)
			{
				case DIO_PORTA :
				PORTA_Register   &= 0x0F;
				PORTA_Register   |= Copy_u8Vlue;
				break;

				case DIO_PORTB :
				PORTB_Register   &= 0x0F;
				PORTB_Register   |= Copy_u8Vlue;
				break;

				case DIO_PORTC :
				PORTC_Register   &= 0x0F;
				PORTC_Register   |= Copy_u8Vlue;
				break;

				case DIO_PORTD :
				PORTD_Register   &= 0x0F;
				PORTD_Register   |= Copy_u8Vlue;
				break;
				
			}
	}
}
