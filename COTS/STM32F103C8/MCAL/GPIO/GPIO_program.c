/****************************************************************/
/******* Author    : Somaya Ayman El Sayed      *****************/
/******* Date      : 28 Aug 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : GPIO_program.c                *****************/
/****************************************************************/


/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL_GPIO *****************************/
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"
/***********************************************************************************************************************/

Std_ReturnType MCAL_GPIO_SetPinMode (u8 Copy_PortID,u8 Copy_PinID,u8 Copy_PinMode) {
    Std_ReturnType Local_FunctionStatus =  E_NOT_OK ;
    switch (Copy_PortID)
    {
    case GPIO_PortA:
        if      ( Copy_PinID < 8 ){ /**< PINS THAT ARE CONTROLLED BY CRL REGISTER*/
            GPIO_A_CRL &= ~((0b1111) << (Copy_PinID*4)) ; /**< CLEAR FOUR BITS BEFORE SETTING THEM*/
            GPIO_A_CRL |= ( Copy_PinMode << (Copy_PinID*4)) ; /**< SET THE DESIRED PIN MODE */
            Local_FunctionStatus = E_OK;
        }
        else if ( Copy_PinID < 16){ /**< PINS THAT ARE CONTROLLED BY CRH REGISTER*/
            GPIO_A_CRH &= ~((0b1111) << (Copy_PinID*4)) ; /**< CLEAR FOUR BITS BEFORE SETTING THEM*/
            GPIO_A_CRH |= ( Copy_PinMode << (Copy_PinID*4)) ; /**< SET THE DESIRED PIN MODE */
            Local_FunctionStatus = E_OK;
        }
        else {
            Local_FunctionStatus = E_NOT_OK ;
        }
        break;
    case GPIO_PortB:
        if      ( Copy_PinID < 8 ){ /**< PINS THAT ARE CONTROLLED BY CRL REGISTER*/
            GPIO_B_CRL &= ~((0b1111) << (Copy_PinID*4)) ; /**< CLEAR FOUR BITS BEFORE SETTING THEM*/
            GPIO_B_CRL |= ( Copy_PinMode << (Copy_PinID*4)) ; /**< SET THE DESIRED PIN MODE */
            Local_FunctionStatus = E_OK;
        }
        else if ( Copy_PinID < 16){ /**< PINS THAT ARE CONTROLLED BY CRH REGISTER*/
            GPIO_B_CRH &= ~((0b1111) << (Copy_PinID*4)) ; /**< CLEAR FOUR BITS BEFORE SETTING THEM*/
            GPIO_B_CRH |= ( Copy_PinMode << (Copy_PinID*4)) ; /**< SET THE DESIRED PIN MODE */
            Local_FunctionStatus = E_OK;
        }
        else {
            Local_FunctionStatus = E_NOT_OK ;
        }
        break;
    case GPIO_PortC:
        if      ( Copy_PinID < 8 ){ /**< PINS THAT ARE CONTROLLED BY CRL REGISTER*/
            GPIO_C_CRL &= ~((0b1111) << (Copy_PinID*4)) ; /**< CLEAR FOUR BITS BEFORE SETTING THEM*/
            GPIO_C_CRL |= ( Copy_PinMode << (Copy_PinID*4)) ; /**< SET THE DESIRED PIN MODE */
            Local_FunctionStatus = E_OK;
        }
        else if ( Copy_PinID < 16){ /**< PINS THAT ARE CONTROLLED BY CRH REGISTER*/
            GPIO_C_CRH &= ~((0b1111) << (Copy_PinID*4)) ; /**< CLEAR FOUR BITS BEFORE SETTING THEM*/
            GPIO_C_CRH |= ( Copy_PinMode << (Copy_PinID*4)) ; /**< SET THE DESIRED PIN MODE */
            Local_FunctionStatus = E_OK;
        }
        else {
            Local_FunctionStatus = E_NOT_OK ;
        }
        break;
    default:
        Local_FunctionStatus = E_NOT_OK ;
        break;
    }
    return Local_FunctionStatus;
}

Std_ReturnType MCAL_GPIO_GetPinValue (u8 Copy_PortID,u8 Copy_PinID,u8 *Copy_PinReturnValue) {
    Std_ReturnType Local_FunctionStatus =  E_NOT_OK ;
    if (Copy_PinReturnValue != NULL){
    switch (Copy_PortID)
    {
    case GPIO_PortA:
        *Copy_PinReturnValue = GET_BIT(GPIO_A_IDR,Copy_PinID);
        Local_FunctionStatus = E_OK;
        break;
    
    case GPIO_PortB:
        *Copy_PinReturnValue = GET_BIT(GPIO_B_IDR,Copy_PinID);
        Local_FunctionStatus = E_OK;
        break;

    case GPIO_PortC:
        *Copy_PinReturnValue = GET_BIT(GPIO_C_IDR,Copy_PinID);
        Local_FunctionStatus = E_OK;
        break;
    default:
        Local_FunctionStatus = E_NOT_OK ;
        break;
    }
    }
    else{
       Local_FunctionStatus = E_NOT_OK ;
    }
    return Local_FunctionStatus;
} 

Std_ReturnType MCAL_GPIO_SetPinValue (u8 Copy_PortID,u8 Copy_PinID,u8 Copy_PinValue) {
    Std_ReturnType Local_FunctionStatus =  E_NOT_OK ;
    switch (Copy_PortID)
    {
    case GPIO_PortA:
        switch (Copy_PinValue)
        {
        case GPIO_HIGH:
            SET_BIT(GPIO_A_ODR,Copy_PinID);
            Local_FunctionStatus = E_OK;
            break;
        case GPIO_LOW:
            CLR_BIT(GPIO_A_ODR,Copy_PinID);
            Local_FunctionStatus = E_OK;
            break;
        default:
            Local_FunctionStatus = E_NOT_OK;
            break;
        }
    
    case GPIO_PortB:
        switch (Copy_PinValue)
        {
        case GPIO_HIGH:
            SET_BIT(GPIO_B_ODR,Copy_PinID);
            Local_FunctionStatus = E_OK;
            break;
        case GPIO_LOW:
            CLR_BIT(GPIO_B_ODR,Copy_PinID);
            Local_FunctionStatus = E_OK;
            break;
        default:
            Local_FunctionStatus = E_NOT_OK;
            break;
        }

    case GPIO_PortC:
        switch (Copy_PinValue)
        {
        case GPIO_HIGH:
            SET_BIT(GPIO_C_ODR,Copy_PinID);
            Local_FunctionStatus = E_OK;
            break;
        case GPIO_LOW:
            CLR_BIT(GPIO_C_ODR,Copy_PinID);
            Local_FunctionStatus = E_OK;
            break;
        default:
            Local_FunctionStatus = E_NOT_OK;
            break;
        }
    default:
        Local_FunctionStatus = E_NOT_OK ;
        break;
    }
    return Local_FunctionStatus;
}


/***********************************************************************************************************************/
