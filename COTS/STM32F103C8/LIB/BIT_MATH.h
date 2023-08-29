/****************************************************************/
/******* Author    : Somaya Ayman El Sayed      *****************/
/******* Date      : 28 Aug 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : STD_TYPES.h                *****************/
/****************************************************************/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG, BIT_NUMBER)  REG |= (1 << BIT_NUMBER)               
#define CLR_BIT(REG, BIT_NUMBER)  REG &= ~(1 << BIT_NUMBER)               
#define TOG_BIT(REG, BIT_NUMBER)  REG ^= (1 << BIT_NUMBER)               
#define GET_BIT(REG, BIT_NUMBER)  ((REG & (1 << BIT_NUMBER)) >> BIT_NUMBER)              



#endif /* BIT_MATH_H_ */
