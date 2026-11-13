/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	   EXTI_program.c 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : MCAL
* Sw     : EXTI
*
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"


#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/* 
	Global Pointer to Function => Carry The Adress of ISR func in the main 
	Hint : I Made an array of pointers to carry EXTI 0,1,2 according to its index
	
*/

void (*EXTI_CallBackPtr[25]) (void) = {NULL};
	
//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function Init THE EXTI ( Prebuild Function)
 * Parameters : Nothing
 * return : Nothing
 */

void EXTI_voidInit (void)
{
	
		
		
		
	
		/*  Check for EXTI line  */
   		#if EXTI_LINE1_State == EXTI_LINE_Enable
		
			/* Check for SenSe Mode  */
		
			#if EXTI_LINE1_SENSE_MODE == EXTI_LOW_LEVEL
			
				CLR_BIT(MCUCR_REG ,2);  CLR_BIT(MCUCR_REG ,3);
		
			#elif EXTI_LINE1_SENSE_MODE == EXTI_Any_Logical_Change
		
				SET_BIT(MCUCR_REG ,2);  CLR_BIT(MCUCR_REG ,3);
			
			#elif EXTI_LINE1_SENSE_MODE == EXTI_FALLING_EDGE
		
				CLR_BIT(MCUCR_REG ,2);  SET_BIT(MCUCR_REG ,3);
		
			#elif EXTI_LINE1_SENSE_MODE == EXTI_RISING_EDGE
		
				SET_BIT(MCUCR_REG ,2);  SET_BIT(MCUCR_REG ,3);		
	
			#endif
			
		#endif

	
		/*  Check for EXTI line  */
		#if EXTI_LINE0_State == EXTI_LINE_Enable
	
			/* Check for SenSe Mode  */
	
			#if EXTI_LINE0_SENSE_MODE == EXTI_LOW_LEVEL
	
				CLR_BIT(MCUCR_REG ,0);  CLR_BIT(MCUCR_REG ,1);
	
			#elif EXTI_LINE0_SENSE_MODE == EXTI_Any_Logical_Change
	
				SET_BIT(MCUCR_REG ,0);  CLR_BIT(MCUCR_REG ,1);
	
			#elif EXTI_LINE0_SENSE_MODE == EXTI_FALLING_EDGE
	
				CLR_BIT(MCUCR_REG ,0);  SET_BIT(MCUCR_REG ,1);
	
			#elif EXTI_LINE0_SENSE_MODE == EXTI_RISING_EDGE
	
				SET_BIT(MCUCR_REG ,0);  SET_BIT(MCUCR_REG ,1);
	
			#endif
			
		#endif

	
		/*  Check for EXTI line  */
		#if EXTI_LINE2_State == EXTI_LINE_Enable
	
			/* Check for SenSe Mode  */
			
			#if EXTI_LINE2_SENSE_MODE == EXTI_FALLING_EDGE
			
				CLR_BIT(MCUCSR_REG ,6);
			
			#elif EXTI_LINE2_SENSE_MODE == EXTI_RISING_EDGE
			
				SET_BIT(MCUCSR_REG ,6);
			
			#endif
			

		
#endif
	

}


u8	 EXTI_u8DisablePeripheralInterrput ( u8 Copy_u8Line)
{
	u8 Local_u8ErrorState = OK;
	if ( (Copy_u8Line >= EXTI_LINE2) && (Copy_u8Line <= EXTI_LINE1))		/* Check [5:7] */
	{
		/* Clear The Required BIT */
		CLR_BIT( GICR_REG , Copy_u8Line );
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}
	
	return Local_u8ErrorState;
}

u8	 EXTI_u8EnablePeripheralInterrput  ( u8 Copy_u8Line)
{
	u8 Local_u8ErrorState = OK;
	if ( (Copy_u8Line >= EXTI_LINE2) && (Copy_u8Line <= EXTI_LINE1))		/* Check [5:7] */
	{
		/* Set The Required BIT */
		SET_BIT( GICR_REG , Copy_u8Line );
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}
	
	return Local_u8ErrorState;
}


void EXTI_voidClearFlag( u8 Copy_u8Line)
{
	SET_BIT( GIFR_REG , Copy_u8Line );
}

void EXTI_u8DisableGlobalInterrput ()
{
		CLR_BIT( SREG_REG , Global_Interrupt_Bit );
}

void EXTI_u8EnableGlobalInterrput  ()
{
	SET_BIT( SREG_REG , Global_Interrupt_Bit );
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
/*  Description:  A function to set the required sense control of INT0 & INT1 &  using (postbuild configuration)
 * 	Input:	Copy_u8SenseMode , options are: 1-  LOW_LEVEL
 * 											2-  ON_CHANGE
 * 											3-  FALLING_EDGE
 * 											4-  RISING_EDGE
 * for INT2 There is only last two options
 * 	 output: Error status with type u8
 * 	*/
void EXTI_voidSetSignalLatch (u8 Copy_u8SenseMode , u8 Copy_u8Line )
{
	/* For EXTI0 & EXTI1 */
	if (Copy_u8Line >= EXTI_LINE0 && Copy_u8Line <= EXTI_LINE1)
	{
		/* To Chose INT Sense Control bit  */
		Copy_u8Line =( 6 - Copy_u8Line ) * -2;
		
		switch(Copy_u8SenseMode)
		{
			case EXTI_LOW_LEVEL				: CLR_BIT( MCUCR_REG , Copy_u8Line ); CLR_BIT( MCUCR_REG , Copy_u8Line + 1 ); break;
			case EXTI_Any_Logical_Change    : SET_BIT( MCUCR_REG , Copy_u8Line ); CLR_BIT( MCUCR_REG , Copy_u8Line + 1 ); break;
			case EXTI_FALLING_EDGE		    : CLR_BIT( MCUCR_REG , Copy_u8Line ); SET_BIT( MCUCR_REG , Copy_u8Line + 1 ); break;
			case EXTI_RISING_EDGE			: SET_BIT( MCUCR_REG , Copy_u8Line ); SET_BIT( MCUCR_REG , Copy_u8Line + 1 ); break;
			
		}
	} 
	
	/* For EXTI2 */
	else
	{
		switch(Copy_u8SenseMode)
		{
			
			case EXTI_FALLING_EDGE : CLR_BIT( MCUCSR_REG, 6 ); break;
			case EXTI_RISING_EDGE  : SET_BIT( MCUCSR_REG, 6 ); break;
			
		}
	}
}



u8 EXTI_u8GetFlag( u8 Copy_u8Line ){

	return GIT_BIT( GIFR_REG , Copy_u8Line );

}

//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function Init THE EXTI
 * Parameters : 
				=> The Adress of ISR Func (its name)
				=> EXTI Line --> [EXTI_LINE0 , EXTI_LINE1 , EXTI_LINE2]
 * return : Nothing
 */
void EXTI_voidSetCallBack	 ( void (*Copy_pvoidCallBack)(void) , u8 Copy_u8EXTILine )
{
	
	if( Copy_pvoidCallBack != NULL ){

		EXTI_CallBackPtr[Copy_u8EXTILine] = Copy_pvoidCallBack ;

	}
}

/* ISR --> Implementation */
void __vector_1(void)__attribute__((signal));			// don't remove this function i will use it later (don't make optimization ).
void __vector_1(void)
{
	
	if (EXTI_CallBackPtr[EXTI_LINE0] != NULL)
	{
	
		EXTI_CallBackPtr[EXTI_LINE0]();	/*  Call The Global Pointer to Func   */
		EXTI_voidClearFlag(EXTI_LINE0);
	}
}

/* ISR --> Implementation */
void __vector_2(void)__attribute__((signal));			// don't remove this function i will use it later (don't make optimization ).
void __vector_2(void)
{
		
	if (EXTI_CallBackPtr[EXTI_LINE1] != NULL)
	{
		EXTI_CallBackPtr[EXTI_LINE1]();	/*  Call The Global Pointer to Func   */
		EXTI_voidClearFlag(EXTI_LINE1);
	}
}

/* ISR --> Implementation */
void __vector_3(void)__attribute__((signal));		// don't remove this function i will use it later (don't make optimization ).
void __vector_3(void)
{
	if (EXTI_CallBackPtr[EXTI_LINE2] != NULL)
	{
		
		EXTI_CallBackPtr[EXTI_LINE2]();	/*  Call The Global Pointer to Func   */
		EXTI_voidClearFlag(EXTI_LINE2);
	}
}