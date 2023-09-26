/*<************ LIB******/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
/*<************ MCAL******/
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "AFIO_interface.h"
#include "EXTI_interface.h"
#include "NVIC_Interface.h"
#include "STK_interface.h"
/*<************ App******/
u8 BlinkingLoop,F;
u8 ReturnValue;
int main(void){
	
	/********************<SysClk***********/
	MCAL_RCC_InitSysClock();
	
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPAEN);
	MCAL_RCC_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPBEN);
	
	/************************< Init_Interupt*****************/
	MCAL_NVIC_EnableIRQ(NVIC_EXTI4_IRQn);
	EXTI_vInit();
	EXTI_SetTrigger(EXTI_LINE4,EXTI_FALLING_EDGE);
	
	/************<PinSetMode*************/
	/****< InputInteruptPin***/
	MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN4,GPIO_INPUT_PULL_UP);
	/****< LEDsPin************/
	MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN3,GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN1,GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN2,GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN3,GPIO_OUTPUT_PUSH_PULL_2MHZ);
	
	while(1)
{
	
	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_HIGH);
	
    /*SET CAR RED*/
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
    MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_HIGH);
    MCAL_STK_SetDelay_ms(5000);
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
    MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);
    MCAL_STK_Reset();

    /*****SET CAR YELLOW****/
        MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_HIGH);
        MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);
        MCAL_STK_SetDelay_ms(5000);
        MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
        MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
        MCAL_STK_Reset();
    /**********SET CAR GREEN*******/
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_HIGH);
    MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_HIGH);
    MCAL_STK_SetDelay_ms(5000);
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
    MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
    MCAL_STK_Reset();

    /*SET CAR Yellow and HUMAN Yellow */
        MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_HIGH);
        MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);
        MCAL_STK_SetDelay_ms(5000);
        MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
        MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
        MCAL_STK_Reset();    
		
			
			
			
			
			

		}
	return 0;
}

void EXTI4_IRQHandler(void){
	
 for(u32 i = 2000; i >= 0; i--){
	u8 pushbutton;
	 u8 ReturnValue_G, ReturnValue_R,ReturnValue_Y;
	MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN4,&ReturnValue);
	if(!pushbutton){
				
  MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN4,&ReturnValue);
				if(ReturnValue != 0){
		ReturnValue_G = 0; ReturnValue_R = 0; ReturnValue_Y = 0;
		MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN1,&ReturnValue_R);
		MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN2,&ReturnValue_Y);
		MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN3,&ReturnValue_G);
			if(ReturnValue_G == 1){
				MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
				MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
				for(BlinkingLoop = 0; BlinkingLoop < 4; BlinkingLoop++)
			{
					MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_HIGH);
					MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);
					for(u32 i = 25000; i >= 0; i--){
						if(i == 0){
							break;
						}
					}  
					MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
					MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
					for(i = 25000; i >= 0; i--){
						if(i == 0){
							break;
						}
					}    
			}
			MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_HIGH);
			for(u32 i = 100000; i >= 0; i--){
						if(i == 0){
							break;
						}
					}  
			MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);
			EXTI_CLR_PendingFLag(EXTI_LINE4);
			MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI4_IRQn);
				
			}
			else if(ReturnValue_R == 1){
				EXTI_CLR_PendingFLag(EXTI_LINE4);
			MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI4_IRQn);
			}
			else if(ReturnValue_Y == 1){
				
				for(BlinkingLoop = 0; BlinkingLoop < 4; BlinkingLoop++)
			{
					MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_HIGH);
					MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);
					for(u32 i = 25000; i >= 0; i--){
						if(i == 0){
							break;
						}
					}  
					MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
					MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
					for(i = 25000; i >= 0; i--){
						if(i == 0){
							break;
						}
					} 
			 }
					MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
					MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_HIGH);
					for(u32 i = 100000; i >= 0; i--){
						if(i == 0){
							break;
						}
					}  
					MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);
					MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
					EXTI_CLR_PendingFLag(EXTI_LINE4);
					MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI4_IRQn);
		} 
	}
}
	if(i == 0){
						break;
					}
	EXTI_CLR_PendingFLag(EXTI_LINE4);
	MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI4_IRQn);
				}
			} 
	
	/*else{
					EXTI_CLR_PendingFLag(EXTI_LINE4);
		MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI4_IRQn);
				}
	}*/
