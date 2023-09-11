/****************************************************************/
/******* Author    : Somaya Ayman El Sayed      *****************/
/******* Date      : 29 Aug 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : EXTI_private.h                *****************/
/****************************************************************/
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define EXTI_BASE 0x40010400U

/// @brief 
typedef struct
{
    u32 IMR;
    u32 EMR;
    u32 RSTR;
    u32 FTSR;
    u32 SWIER;
    u32 PR;

} volatile EXTI_RegDef_t;

#define EXTI ((EXTI_RegDef_t *)EXTI_BASE);

#endif /* EXTI_PRIVATE_H_ */