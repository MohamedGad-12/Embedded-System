//Eng. Mohamed Gamal

#ifndef RCC_PARTIAL_DRIVER_STM32F_103C6_RCC_DRIVER_H_
#define RCC_PARTIAL_DRIVER_STM32F_103C6_RCC_DRIVER_H_

#include <stdint.h>

#define HSE   (uint32_t)16000000
#define HSI   (uint32_t)8000000

uint32_t  MCAl_RCC_Get_SysClk_Freq(void);
uint32_t  MCAl_RCC_Get_HCLK_Freq(void);
uint32_t  MCAl_RCC_Get_PCLK1_Freq(void);
uint32_t  MCAl_RCC_Get_PCLK2_Freq(void);

#endif /* RCC_PARTIAL_DRIVER_STM32F_103C6_RCC_DRIVER_H_ */
