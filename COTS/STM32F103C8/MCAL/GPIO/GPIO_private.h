/****************************************************************/
/******* Author    : Somaya Ayman El Sayed      *****************/
/******* Date      : 29 Aug 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : GPIO_private.h                *****************/
/****************************************************************/
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define GPIO_A_Base   0x40010800U
        #define GPIO_A_CRL   (*((volatile u32 *)(GPIO_A_Base + 0x00))) 
        #define GPIO_A_CRH   (*((volatile u32 *)(GPIO_A_Base + 0x04))) 
        #define GPIO_A_IDR   (*((volatile u32 *)(GPIO_A_Base + 0x08)))
        #define GPIO_A_ODR   (*((volatile u32 *)(GPIO_A_Base + 0x0C)))  
        #define GPIO_A_BSRR  (*((volatile u32 *)(GPIO_A_Base + 0x10))) 
        #define GPIO_A_BRR   (*((volatile u32 *)(GPIO_A_Base + 0x14))) 
        #define GPIO_A_LCKR  (*((volatile u32 *)(GPIO_A_Base + 0x18))) 
#define GPIO_B_Base   0x40010C00
        #define GPIO_B_CRL   (*((volatile u32 *)(GPIO_B_Base + 0x00))) 
        #define GPIO_B_CRH   (*((volatile u32 *)(GPIO_B_Base + 0x04))) 
        #define GPIO_B_IDR   (*((volatile u32 *)(GPIO_B_Base + 0x08)))
        #define GPIO_B_ODR   (*((volatile u32 *)(GPIO_B_Base + 0x0C)))  
        #define GPIO_B_BSRR  (*((volatile u32 *)(GPIO_B_Base + 0x10))) 
        #define GPIO_B_BRR   (*((volatile u32 *)(GPIO_B_Base + 0x14))) 
        #define GPIO_B_LCKR  (*((volatile u32 *)(GPIO_B_Base + 0x18))) 
#define GPIO_C_Base   0x40011000
        #define GPIO_C_CRL   (*((volatile u32 *)(GPIO_C_Base + 0x00))) 
        #define GPIO_C_CRH   (*((volatile u32 *)(GPIO_C_Base + 0x04))) 
        #define GPIO_C_IDR   (*((volatile u32 *)(GPIO_C_Base + 0x08)))
        #define GPIO_C_ODR   (*((volatile u32 *)(GPIO_C_Base + 0x0C)))  
        #define GPIO_C_BSRR  (*((volatile u32 *)(GPIO_C_Base + 0x10))) 
        #define GPIO_C_BRR   (*((volatile u32 *)(GPIO_C_Base + 0x14))) 
        #define GPIO_C_LCKR  (*((volatile u32 *)(GPIO_C_Base + 0x18))) 


#endif /* GPIO_PRIVATE_H_ */
