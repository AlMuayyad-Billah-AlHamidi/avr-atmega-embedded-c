/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	   BIT_MATH.h 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : LIB
* 
*
*/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(reg,bit)     reg|=(1<<bit)
#define CLR_BIT(reg,bit)     reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)     reg^=(1<<bit)
#define GIT_BIT(reg,bit)     (reg&(1<<bit))>>bit

#define IS_BIT_SET(reg,bit)  (reg&(1<<bit))>>bit
#define IS_BIT_CLR(reg,bit)  !((reg&(1<<bit))>>bit)
#define ROR(reg,num)		 reg=(reg<<(REGISTER_SIZE_num))|(reg>>(num))
#define ROL(reg,num)		 reg=(reg>>(REGISTER_SIZE_num))|(reg<<(num))


#endif /* BIT_MATH_H_ */
