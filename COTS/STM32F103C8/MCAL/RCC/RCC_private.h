/****************************************************************/
/******* Author    : Somaya Ayman El Sayed      *****************/
/******* Date      : 28 Aug 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : RCC_private.h                *****************/
/****************************************************************/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_


#define RCC_Base   (*((volatile u32 *)0x40021000)) /**< BASE ADDRESS FOR RCC PERIPHERAL*/
         #define RCC_CR        (*((volatile u32 *) RCC_Base + 0X00))   /**< 1ST REGISTER FOR RCC PERIPHERAL */
         /**<BITS IN RCC REGISTER AND THEIR FUNCTIONALITY*/
                #define RCC_CR_HSION  0   /**< INTERNAL HIGH SPEED CLOCK ENABLE*/
                #define RCC_CR_HSIRDY 1   /**< THIS BIT IS FOR CHECKING STABILITY OF CLOCK 0 -> NOT READY, 1 -> READY*/
                #define RCC_CR_HSEON  16  /**< EXTERNAL HIGH SPEED CLOCK ENABLE*/
                #define RCC_CR_HSERDY 17  /**< THIS BIT IS FOR CHECKING STABILITY OF CLOCK 0 -> NOT READY, 1 -> READY*/
                #define RCC_CR_HSEBYP 18
                #define RCC_CR_CSSON  19
                #define RCC_CR_PLLON  24
                #define RCC_CR_PLLRDY 25
         #define RCC_CFGR      (*((volatile u32 *) RCC_Base + 0X04)) /**< 2ND REGISTER FOR RCC PERIPHERAL*/
         #define RCC_CIR       (*((volatile u32 *) RCC_Base + 0X08)) /**< 3RD REGISTER FOR RCC PERIPHERAL*/    
         #define RCC_APB2RSTR  (*((volatile u32 *) RCC_Base + 0X0C)) /**< 4TH REGISTER FOR RCC PERIPHERAL*/
         #define RCC_APB1RSTR  (*((volatile u32 *) RCC_Base + 0X10)) /**< 5TH REGISTER FOR RCC PERIPHERAL*/
         #define RCC_AHBENR    (*((volatile u32 *) RCC_Base + 0X14)) /**< 6TH REGISTER FOR RCC PERIPHERAL*/
         #define RCC_APB2ENR   (*((volatile u32 *) RCC_Base + 0X18)) /**< 7TH REGISTER FOR RCC PERIPHERAL*/
         #define RCC_APB1ENR   (*((volatile u32 *) RCC_Base + 0X1C)) /**< 8TH REGISTER FOR RCC PERIPHERAL*/
         #define RCC_BDCR      (*((volatile u32 *) RCC_Base + 0X20)) /**< 9TH REGISTER FOR RCC PERIPHERAL*/
         #define RCC_CSR       (*((volatile u32 *) RCC_Base + 0X24)) /**< 10TH REGISTER FOR RCC PERIPHERAL*/
         #define RCC_AHBRSTR   (*((volatile u32 *) RCC_Base + 0X28)) /**< 11TH REGISTER FOR RCC PERIPHERAL*/
         #define RCC_CFGR2     (*((volatile u32 *) RCC_Base + 0X2C)) /**< 12TH REGISTER FOR RCC PERIPHERAL*/

/**< CHOICES TO CONFIG RCC_SYS_CLK*/
#define RCC_HSI             0   /**< High-Speed Internal Clock Source */
#define RCC_HSE             1   /**< High-Speed External Clock Source */
#define RCC_PLL             2   /**< Phase-Locked Loop Clock Source   */

/**< CHOICES TO CONFIG RCC_CLK_BYPASS*/
#define RCC_CRYSTAL_CLK     0   /**< Crystal Oscillator Clock Type */
#define RCC_RC_CLK          1   /**< RC Oscillator Clock Type */

#endif /* RCC_PRIVATE_H_ */
