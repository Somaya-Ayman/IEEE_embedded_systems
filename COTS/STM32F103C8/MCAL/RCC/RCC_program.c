/****************************************************************/
/******* Author    : Somaya Ayman El Sayed      *****************/
/******* Date      : 28 Aug 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : RCC_program.c              *****************/
/****************************************************************/


/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


Std_ReturnType MCAL_RCC_InitSysCLK (void) {
    Std_ReturnType Local_FunctionStatus = E_NOT_OK ;
    /**< IF CHOICE OF RCC_SYS_CLK WAS HSI CHECK ALSO THE CLOCK SOURCE*/
    #if RCC_SYS_CLK == RCC_HSI
        /**< ENABLE HSI CLOCK*/
        SET_BIT(RCC_CR,RCC_CR_HSION);
        /**< WAIT TILL CLOCK IS READY*/
        while(!GET_BIT(RCC_CR,RCC_CR_HSIRDY));
        RCC_CFGR = 0x00000000;
        Local_FunctionStatus = E_OK;
        
    #elif RCC_SYS_CLK == RCC_HSE
        #if   RCC_CLK_BYPASS == RCC_CRYSTAL_CLK
              CLR_BIT(RCC_CR, RCC_CR_HSEBYP);
        #elif RCC_CLK_BYPASS == RCC_RC_CLK
              SET_BIT(RCC_CR, RCC_CR_HSEBYP);
        #else 
             Local_FunctionStatus = E_NOT_OK;
        #endif
        /**< ENABLE HSE CLOCK*/
        SET_BIT(RCC_CR,RCC_CR_HSEON);
        /**< WAIT TILL CLOCK IS READY*/
        while(!GET_BIT(RCC_CR,RCC_CR_HSERDY));
        RCC_CFGR = 0x00000001;
        Local_FunctionStatus = E_OK;
    
    #elif RCC_SYS_CLK == RCC_PLL
       #if PLLSRC == PLL_HSI_DIV2
           CLR_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);
        #elif PLLSRC == PLL_HSE
           SET_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);
           #if PLL_HSE_DIV == DIV1
           CLR_BIT(RCC_CFGR,RCC_CFGR_PLLXTPRE);
           #if PLL_HSE_DIV == DIV2
           SET_BIT(RCC_CFGR,RCC_CFGR_PLLXTPRE);
           #else
           Local_FunctionStatus = E_NOT_OK;
           #endif
        #else
           Local_FunctionStatus = E_NOT_OK;
        #endif 
       switch (RCC_PLL_MUL)
       {
       case BY2:
                RCC_CFGR = RCC_CFGR & ~(0x00000000); /**clear bits*/
                Local_FunctionStatus = E_OK;
                break;
        case BY3:
                RCC_CFGR = RCC_CFGR & ~(0x00000000); /**clear bits*/
                RCC_CFGR = RCC_CFGR |  0x00040000;   /*set bits*/
                Local_FunctionStatus = E_OK;
                break;
        case BY4:
                RCC_CFGR = RCC_CFGR & ~(0x00000000); /**clear bits*/
                RCC_CFGR = RCC_CFGR |  0x00080000;   /*set bits*/
                Local_FunctionStatus = E_OK;
                break;
        case BY5:
                RCC_CFGR = RCC_CFGR & ~(0x00000000); /**clear bits*/
                RCC_CFGR = RCC_CFGR |  0x000C0000;   /*set bits*/
                Local_FunctionStatus = E_OK;
                break;
        case BY6:
                RCC_CFGR = RCC_CFGR & ~(0x00000000); /**clear bits*/
                RCC_CFGR = RCC_CFGR |  0x000100000;   /*set bits*/
                Local_FunctionStatus = E_OK;
                break;
        case BY7:
                RCC_CFGR = RCC_CFGR & ~(0x00000000); /**clear bits*/
                RCC_CFGR = RCC_CFGR |  0x000140000;   /*set bits*/
                Local_FunctionStatus = E_OK;
                break;
        case BY8:
                RCC_CFGR = RCC_CFGR & ~(0x00000000); /**clear bits*/
                RCC_CFGR = RCC_CFGR |  0x000180000;   /*set bits*/
                Local_FunctionStatus = E_OK;
                break;
        case BY9:
                RCC_CFGR = RCC_CFGR & ~(0x00000000); /**clear bits*/
                RCC_CFGR = RCC_CFGR |  0x0001C0000;   /*set bits*/
                Local_FunctionStatus = E_OK;
                break;
        case BY10:
                RCC_CFGR = RCC_CFGR & ~(0x00000000); /**clear bits*/
                RCC_CFGR = RCC_CFGR |  0x000200000;   /*set bits*/
                Local_FunctionStatus = E_OK;
                break;
        case BY11:
                RCC_CFGR = RCC_CFGR & ~(0x00000000); /**clear bits*/
                RCC_CFGR = RCC_CFGR |  0x000240000;   /*set bits*/
                Local_FunctionStatus = E_OK;
                break;
        case BY12:
                RCC_CFGR = RCC_CFGR & ~(0x00000000); /**clear bits*/
                RCC_CFGR = RCC_CFGR |  0x000280000;   /*set bits*/
                Local_FunctionStatus = E_OK;
                break;
        case BY13:
                RCC_CFGR = RCC_CFGR & ~(0x00000000); /**clear bits*/
                RCC_CFGR = RCC_CFGR |  0x0002C0000;   /*set bits*/
                Local_FunctionStatus = E_OK;
                break;
        case BY14:
                RCC_CFGR = RCC_CFGR & ~(0x00000000); /**clear bits*/
                RCC_CFGR = RCC_CFGR |  0x000300000;   /*set bits*/
                Local_FunctionStatus = E_OK;
                break;
        case BY15:
                RCC_CFGR = RCC_CFGR & ~(0x00000000); /**clear bits*/
                RCC_CFGR = RCC_CFGR |  0x000340000;   /*set bits*/
                Local_FunctionStatus = E_OK;
                break;
        case BY16:
                RCC_CFGR = RCC_CFGR & ~(0x00000000); /**clear bits*/
                RCC_CFGR = RCC_CFGR |  0x000380000;   /*set bits*/
                Local_FunctionStatus = E_OK;
                break;
       default:
                Local_FunctionStatus = E_NOT_OK;
                break;
       }
        /**< ENABLE PLL CLOCK*/
        SET_BIT(RCC_CR,RCC_CR_PLLON);
        /**< WAIT TILL CLOCK IS READY*/
        while(!GET_BIT(RCC_CR,RCC_CR_PLLRDY));
        RCC_CFGR = 0x00000010;
        Local_FunctionStatus = E_OK;

    #else
         Local_FunctionStatus = E_NOT_OK; 
    #endif
    return Local_FunctionStatus;

}

Std_ReturnType MCAL_RCC_EnablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch(Copy_BusId)
    {
        /**< Enable the peripheral on the AHB bus. */
        case RCC_AHB:
            SET_BIT(RCC_AHBENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Enable the peripheral on the APB1 bus. */
        case RCC_APB1:
            SET_BIT(RCC_APB1ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Enable the peripheral on the APB2 bus. */
        case RCC_APB2:
            SET_BIT(RCC_APB2ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        default:
            Local_FunctionStatus = E_NOT_OK;
            break;
    }

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_RCC_DisablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch(Copy_BusId)
    {
        /**< Disable the peripheral on the AHB bus. */
        case RCC_AHB:
            CLR_BIT(RCC_AHBENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Disable the peripheral on the APB1 bus. */
        case RCC_APB1:
            CLR_BIT(RCC_APB1ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Disable the peripheral on the APB2 bus. */
        case RCC_APB2:
            CLR_BIT(RCC_APB2ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        default:
            Local_FunctionStatus = E_NOT_OK;
            break;
    }

    return Local_FunctionStatus;
}


