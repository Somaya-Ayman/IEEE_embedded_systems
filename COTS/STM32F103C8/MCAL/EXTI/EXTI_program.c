/****************************************************************/
/******* Author    : Somaya Ayman El Sayed      *****************/
/******* Date      : 28 Aug 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : EXTI_program.c              *****************/
/****************************************************************/


/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/***********************************************************************************************************************/
Std_ReturnType EXTI_Init (void){

}
Std_ReturnType EXTI_EN (u8 Copy_Line){
    Std_ReturnType Local_FunctionStatus =  E_NOT_OK ;
    if (Copy_Line < 16){
    SET_BIT(EXTI -> EXTI_IMR ,Copy_Line);
    Local_FunctionStatus = E_OK;
    }
    else{
    Local_FunctionStatus = E_NOT_OK;  
    }
    return Local_FunctionStatus;
}
Std_ReturnType EXTI_DisAble (u8 Copy_Line){
    Std_ReturnType Local_FunctionStatus =  E_NOT_OK ;
    if (Copy_Line < 16){
    CLR_BIT(EXTI -> EXTI_IMR ,Copy_Line);
    Local_FunctionStatus = E_OK;
    }
    else{
    Local_FunctionStatus = E_NOT_OK;  
    }
    return Local_FunctionStatus;
}
Std_ReturnType EXTI_SetPinTrigger (u8 Copy_Line, u8 Copy_Mode){ /**< choose the trigger to be : falling edge, rising edge */

}
