/*********************< LIB *********************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*********************< MCAL *********************/
/**< MCAL_RCC interfacce file */
#include "RCC_interface.h"
/**< MCAL_GPIO interface file*/
#include "GPIO_interface.h"
/**< MCAL_STK interface file*/
#include "STK_interface.h"

#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "SCB_interface.h"
/*********************< APP *********************/
u8 ReturnValue;
u8 j ;
int main(void)
{
	/**< Init for SYSCLK */
	Mcal_Rcc_InitSysClock();
	/**< Init for STK */
	MCAL_STK_Init(0);
	
	/**< Enable for wanted peripheral */
	Mcal_Rcc_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPAEN);
	
	/**< Set PORT A PIN 1 2 3 4 5 6 to be OUTPUT PUSH PULL with Freq = 2MHZ */
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN1, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN2, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN3, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN4, GPIO_OUTPUT_PUSH_PULL_2MHZ);	
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN5, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN6, GPIO_OUTPUT_PUSH_PULL_2MHZ);	
	/**< Input PUSH BUTTON*/
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT_PULL_UP_MOD);

	/**< The Return Value of Push Button */
	u8 Local_ReturnValue_1;
	
	/**< NVIC AND EXTI INIT*/
	MCAL_NVIC_EnableIRQ(NVIC_EXTI0_IRQn);
  EXTI_vInit();
	
	
	for(;;)
	{
   	MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);

		/*CASE CAR RED*/
		
		MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN6, GPIO_HIGH); /*CAR RED*/
		MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH); /*HUMAN GREEN*/
		MCAL_STK_SetDelay_ms(5000);
		MCAL_STK_Reset();	
		MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN6, GPIO_LOW); /*CAR RED*/
		MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_LOW); /*HUMAN GREEN*/	
		
		/*CASE CAR YELLOW*/
		
		//MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_HIGH); /*HUMAN RED*/
		//MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_HIGH); /*CAR YELLOW*/
		//MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH); /*HUMAN YELLOW*/
		//for (u8 j = 0; j<5; j++){
		//MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_HIGH); /*CAR YELLOW*/
		//MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH); /*HUMAN YELLOW*/
		//MCAL_STK_SetDelay_ms(500);
		//MCAL_STK_Reset();
		//MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_LOW); /*CAR YELLOW*/
		//MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_LOW); /*HUMAN YELLOW*/
		//MCAL_STK_SetDelay_ms(500);
		//MCAL_STK_Reset();
	//}
		//MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_LOW); /*CAR YELLOW*/
	  //MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_LOW); /*HUMAN YELLOW*/
		//MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_LOW); /*HUMAN RED*/
	
	  MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH); /*HUMAN YELLOW*/		
	  MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_HIGH); /*CAR YELLOW*/
		MCAL_STK_SetDelay_ms(5000);		
		MCAL_STK_Reset();
	  MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_LOW); /*HUMAN YELLOW*/		
	  MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_LOW); /*CAR YELLOW*/
	
		/*CASE CAR GREEN*/
	
  	MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_HIGH); /*HUMAN RED*/
		MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_HIGH); /*CAR GREEN*/
		MCAL_STK_SetDelay_ms(5000);		
		MCAL_STK_Reset();
    MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_LOW); /*HUMAN RED*/
		MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_LOW); /*CAR GREEN*/

	
	}
}

void EXTI0_IRQHandler(void){
	 u8 PUSH_BUTTON_Value;
	 u8  CASE_RED = 0, CASE_YELLOW = 0, CASE_GREEN = 0;
	 MCAL_GPIO_GetPinValue(GPIO_PORTA, GPIO_PIN0, &PUSH_BUTTON_Value);
	 if (!PUSH_BUTTON_Value){
	 for(u32 k = 7000; k >= 0; k--){
	 //	if(k == 0){
			//			break;
		//}}
   MCAL_GPIO_GetPinValue(GPIO_PORTA, GPIO_PIN0, &PUSH_BUTTON_Value);	 
	   if (PUSH_BUTTON_Value){
			 //MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN0,&ReturnValue);
			//	if(ReturnValue != 0){
		 CASE_RED = 0; CASE_YELLOW = 0; CASE_GREEN = 0;
		 MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_LOW); /*HUMAN RED*/
	   MCAL_GPIO_GetPinValue(GPIO_PORTA, GPIO_PIN6, &CASE_RED); 
		 MCAL_GPIO_GetPinValue(GPIO_PORTA, GPIO_PIN5, &CASE_YELLOW);
     MCAL_GPIO_GetPinValue(GPIO_PORTA, GPIO_PIN4, &CASE_GREEN); 
		 if(CASE_RED == 1){
		 EXTI_CLR_PendingFLag(EXTI_LINE0);
     MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI0_IRQn);			 
		 }
		 else if(CASE_YELLOW == 1){
		 MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_LOW); /*HUMAN RED*/
		 MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN6, GPIO_LOW); /*CAR RED*/
		 for(j =0; j<4;j++){
				     MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_HIGH); /*CAR YELLOW*/
					   MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH); /*HUMAN YELLOW*/
					   for(u32 i = 25000; i >= 0; i--){
						 if(i == 0){
						 break;
						}
					 }
					   MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_LOW); /*CAR YELLOW*/
					   MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_LOW); /*HUMAN YELLOW*/
					  for(i = 25000; i >= 0; i--){
						if(i == 0){
							break;
						}
					  }
				    }
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_LOW); /*CAR YELLOW*/
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_LOW); /*HUMAN YELLOW*/
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN6, GPIO_HIGH); /*CAR RED*/
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH); /*HUMAN GREEN*/	
				for(u32 i = 100000; i >= 0; i--){
						if(i == 0){
							break;
						}
					}  
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN6, GPIO_LOW); /*CAR RED*/
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_LOW); /*HUMAN GREEN*/
		 EXTI_CLR_PendingFLag(EXTI_LINE0);
     MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI0_IRQn);			 
	}
		if(CASE_GREEN == 1){
		    MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_LOW); /*CAR GREEN*/	
			  MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_LOW); /*HUMAN RED*/
				for(j =0; j<5;j++){
				     MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_HIGH); /*CAR YELLOW*/
					   MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH); /*HUMAN YELLOW*/
					   for(u32 i = 25000; i >= 0; i--){
						if(i == 0){
							break;
						}
					  }  
					   MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_LOW); /*CAR YELLOW*/
					   MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_LOW); /*HUMAN YELLOW*/
					   for(i = 25000; i >= 0; i--){
						if(i == 0){
							break;
						}
					  }  
				    }
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_LOW); /*CAR YELLOW*/
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_LOW); /*HUMAN YELLOW*/
						
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH); /*HUMAN GREEN*/	
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN6, GPIO_HIGH); /*CAR RED*/
				for(u32 i = 100000; i >= 0; i--){
						if(i == 0){
							break;
						}
					}  
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_LOW); /*HUMAN GREEN*/
				MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN6, GPIO_LOW); /*CAR RED*/
		 EXTI_CLR_PendingFLag(EXTI_LINE0);
     MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI0_IRQn);			 
		 }
	 }
		 else{
		 	EXTI_CLR_PendingFLag(EXTI_LINE0);
	    MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI0_IRQn);
		 }
		 //}	
	   if(k == 0){
		 				break;
		 			}}
	//EXTI_CLR_PendingFLag(EXTI_LINE0);
//	MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI0_IRQn);
			//	}
			}		 
}