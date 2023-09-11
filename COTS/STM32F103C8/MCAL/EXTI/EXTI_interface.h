/****************************************************************/
/******* Author    : Somaya Ayman El Sayed      *****************/
/******* Date      : 29 Aug 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : EXTI_interface.h                *****************/
/****************************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/**< choices for Copy_Mode*/
#define FallingEdge 0
#define RisingEdge  1
#define BothEdge    2

#define EXTI0   0
#define EXTI1   1
#define EXTI2   2
#define EXTI3   3
#define EXTI4   4
#define EXTI5   5
#define EXTI6   6
#define EXTI7   7
#define EXTI8   8
#define EXTI9   9
#define EXTI10  10
#define EXTI11  11
#define EXTI12  12
#define EXTI13  13
#define EXTI4   14
#define EXTI4   15


Std_ReturnType EXTI_Init (void);
Std_ReturnType EXTI_EN (u8 Copy_Line);
Std_ReturnType EXTI_DisAble (u8 Copy_Line);
/**< choose the trigger to be : 
                               0 - falling edge
                               1 - rising edge
                               2 - both falling and rising 
**************************************************************************************************************************************************/
Std_ReturnType EXTI_SetPinTrigger (u8 Copy_Port, u8 Copy_Line, u8 Copy_Mode);


#endif /* EXTI_INTERFACE_H_ */