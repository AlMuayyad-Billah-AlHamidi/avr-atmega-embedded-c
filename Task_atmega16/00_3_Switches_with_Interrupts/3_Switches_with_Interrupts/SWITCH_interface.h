/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	   SWITCH_interface.h 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : HAL
* Sw     : SWITCH
*
*/

/*
	options of state :
	1-SW_Int_PULL_UP
	2_SW_Ext_PULL_UP
	3_SW_Ext_PULL_DOWN
	4_SW_FLOATING
	
*/
#ifndef _SWITCH_INTERFACE_H_
#define _SWITCH_INTERFACE_H_


/******************/
#define SW_Int_PULL_UP		0
#define SW_Ext_PULL_UP		1
#define	SW_Ext_PULL_DOWN	2
#define	SW_FLOATING			3
/******************/

typedef struct{
	u8 PORT;
	u8 PIN;
	u8 Pull_State;
}SW_Type;

typedef enum{
	SW_NotPressed,
	SW_Pressed
}SW_Status;


void 	  SWITCH_voidInit		(SW_Type Copy_structConfig   );
SW_Status SWITCH_emumGetPressed (SW_Type Copy_structConfig   );

#endif