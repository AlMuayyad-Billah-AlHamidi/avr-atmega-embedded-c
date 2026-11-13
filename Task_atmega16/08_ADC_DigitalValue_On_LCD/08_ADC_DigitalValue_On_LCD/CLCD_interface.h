/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	   CLCD_interface.h 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : HAL
* Sw     : CLCD
*
*/


#ifndef _CLCD_INTERFACE_H_
#define _CLCD_INTERFACE_H_

/***********************************************************************************/
/***********************************  Macros  **************************************/
/***********************************************************************************/

/*********************/
//#if CLCD_MODE == 4
//#define  FOUR_BITS							0X28		// 4 bits mode initialization
//#elif CLCD_MODE == 8
#define  EIGHT_BITS							0X38		// 8 bits mode initialization (8-bit data , 2-line display , 5 x 7 font )
//#endif
/*********************/

/********************************* 8-bit mode **************************************/
//#if CLCD_MODE == 8
#define lcd_DisplayOn_CursorOff				0x0c		// display on, cursor off, don't blink character
#define lcd_DisplayOn_CursorOn				0x0e		// display on, cursor on, don't blink character
#define lcd_DisplayOff_CursorOff			0x08		// turn display off
#define lcd_Clear							0x01		// replace all characters with ASCII 'space'
#define lcd_EntryMode						0x06		// shift cursor from left to right on read/write
#define lcd_Home							0x02		// return cursor to first position on first line
#define lcd_CGRAM							0x40		// the first place/address at CGRAM
#define lcd_SetCursor						0x80		// set cursor position (the first place/address at DDRAM)
#define lcd_FunctionRest					0x30		// reset the LCD


/******************************* 4-bit mode ****************************************/ //YOU MUST TO VERFIE THIS CODE FOR 4_BIT MODE
/*#elif CLCD_MODE == 4
#define lcd_DisplayOn_CursorOff				0xc0		// display on, cursor off, don't blink character
#define lcd_DisplayOn_CursorOn				0xe0		// display on, cursor on, don't blink character
#define lcd_DisplayOff_CursorOff			0x80		// turn display off
#define lcd_Clear							0x10		// replace all characters with ASCII 'space'
#define lcd_EntryMode						0x60	*/	// shift cursor from left to right on read/write
//#endif

/***********************************************************************************/
#define	CLCD_ROW_1		0
#define	CLCD_ROW_2		1

#define CLCD_COL_1		0
#define CLCD_COL_2		1	
#define CLCD_COL_3		2
#define CLCD_COL_4		3
#define CLCD_COL_5		4
#define CLCD_COL_6		5
#define CLCD_COL_7		6
#define CLCD_COL_8		7
#define CLCD_COL_9		8
#define CLCD_COL_10		9
#define CLCD_COL_11		10
#define CLCD_COL_12		11
#define CLCD_COL_13		12
#define CLCD_COL_14		13
#define CLCD_COL_15		14
#define CLCD_COL_16		15

/***********************************************************************************/

void 	  CLCD_voidInit		   ( void						  );
void 	  CLCD_voidSendData	   ( u8 Copy_u8Data				  );
void 	  CLCD_voidSendCommand ( u8 Copy_u8Commend			  );
void 	  CLCD_voidSendString  (const u8 * Copy_u8PtrString	  );
void	  CLCD_voidClearScreen ( void						  );		
void	  CLCD_voidSetPosition  (u8 Copy_u8Row , u8 Copy_u8Col );
void      CLCD_voidSendExtraChar( u8 Copy_u8Row , u8 Copy_u8Col);
/***********************************************************************************/

#endif