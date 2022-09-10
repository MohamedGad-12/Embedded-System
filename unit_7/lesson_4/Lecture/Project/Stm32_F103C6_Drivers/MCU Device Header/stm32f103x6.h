//Eng. Mohamed Gamal

#ifndef MCU_DEVICE_HEADER_STM32F103X6_H_
#define MCU_DEVICE_HEADER_STM32F103X6_H_

//-----------------------------
//Includes
//-----------------------------
#include <stdlib.h>
#include <stdint.h>


//-----------------------------
//Base addresses for Memories
//-----------------------------
#define Flash_Memory_Bae   0x08000000UL
#define System_Memory_Base 0x1FFFF000UL
#define SRAM_Base          0x20000000UL
#define Peripherals_Base   0x40000000UL
#define Cortex_M3_Base     0xE0000000UL


//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------
#define RCC_Base  0x40021000


//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------
#define GPIOA_Base  0x40010800UL
#define GPIOB_Base  0x40010C00UL
#define GPIOC_Base  0x40011000UL
#define GPIOD_Base  0x40011400UL
#define GPIOE_Base  0x40011800UL

#define EXIT_Base   0x40010400UL

#define AFIO_Base   0x40010000UL

//-----------------------------
//Base address for NIVC Peripheral
//-----------------------------
#define NIVC_Base   0xE000E100UL
// NIVC Registers
#define NVIC_ISER0   *((volatile unsigned int*)(NIVC_Base+0x000))
#define NVIC_ISER1   *((volatile unsigned int*)(NIVC_Base+0x004))
#define NVIC_ISER2   *((volatile unsigned int*)(NIVC_Base+0x008))
#define NVIC_ICER0   *((volatile unsigned int*)(NIVC_Base+0x080))
#define NVIC_ICER1   *((volatile unsigned int*)(NIVC_Base+0x084))
#define NVIC_ICER2   *((volatile unsigned int*)(NIVC_Base+0x088))
//=================================================================//

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t RCC_CR;
	volatile uint32_t RCC_CFGR;
	volatile uint32_t RCC_CIR;
	volatile uint32_t RCC_APB2RSTR;
	volatile uint32_t RCC_APB1RSTR;
	volatile uint32_t RCC_AHBENR;
	volatile uint32_t RCC_APB2ENR;
	volatile uint32_t RCC_APB1ENR;
	volatile uint32_t RCC_BDCR;
	volatile uint32_t RCC_CSR;
}RCC_typeDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIOx
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t GPIOx_CRL;
	volatile uint32_t GPIOx_CRH;
	volatile uint32_t GPIOx_IDR;
	volatile uint32_t GPIOx_ODR;
	volatile uint32_t GPIOx_BSRR;
	volatile uint32_t GPIOx_BRR;
	volatile uint32_t GPIOx_LCKR;
}GPIO_typeDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXIT
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t EXTI_IMR;
	volatile uint32_t EXTI_EMR;
	volatile uint32_t EXTI_RTSR;
	volatile uint32_t EXTI_FTSR;
	volatile uint32_t EXTI_SWIER;
	volatile uint32_t EXTI_PR;
}EXIT_typeDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t AFIO_EVCR;
	volatile uint32_t AFIO_MAPR;
	volatile uint32_t AFIO_EXTICR[4];
	uint32_t Reserved;
	volatile uint32_t AFIO_MAPR2;
}AFIO_typeDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: GPIOx
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA   ((GPIO_typeDef*) GPIOA_Base)
#define GPIOB   ((GPIO_typeDef*) GPIOB_Base)
#define GPIOC   ((GPIO_typeDef*) GPIOC_Base)
#define GPIOD   ((GPIO_typeDef*) GPIOD_Base)
#define GPIOE   ((GPIO_typeDef*) GPIOE_Base)

//=================================================================//

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: RCC
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC    ((RCC_typeDef*) RCC_Base)

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: EXIT
//-*-*-*-*-*-*-*-*-*-*-*
#define EXIT   ((EXIT_typeDef*) EXIT_Base)

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: AFIO
//-*-*-*-*-*-*-*-*-*-*-*
#define AFIO   ((AFIO_typeDef*) AFIO_Base)

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define AFIO_Clock_Enable()    (RCC->RCC_APB2ENR |= 1<<0)
#define GPIOA_Clock_Enable()   (RCC->RCC_APB2ENR |= 1<<2)
#define GPIOB_Clock_Enable()   (RCC->RCC_APB2ENR |= 1<<3)
#define GPIOC_Clock_Enable()   (RCC->RCC_APB2ENR |= 1<<4)
#define GPIOD_Clock_Enable()   (RCC->RCC_APB2ENR |= 1<<5)
#define GPIOE_Clock_Enable()   (RCC->RCC_APB2ENR |= 1<<6)

//-*-*-*-*-*-*-*-*-*-*-*-
//NIVC enable and disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
//Enable
#define EXIT_IRQ0_NIVC_Enable()          (NVIC_ISER0 |= 1<<6)
#define EXIT_IRQ1_NIVC_Enable()          (NVIC_ISER0 |= 1<<7)
#define EXIT_IRQ2_NIVC_Enable()          (NVIC_ISER0 |= 1<<8)
#define	EXIT_IRQ3_NIVC_Enable()          (NVIC_ISER0 |= 1<<9)
#define EXIT_IRQ4_NIVC_Enable()  	     (NVIC_ISER0 |= 1<<10)
#define EXIT_IRQ5_9_NIVC_Enable()        (NVIC_ISER0 |= 1<<23)
#define EXIT_IRQ10_15_NIVC_Enable()      (NVIC_ISER1 |= 1<<8)

//Disable
#define EXIT_IRQ0_NIVC_Disable()          (NVIC_ICER0 |= 1<<6)
#define EXIT_IRQ1_NIVC_Disable()          (NVIC_ICER0 |= 1<<7)
#define EXIT_IRQ2_NIVC_Disable()          (NVIC_ICER0 |= 1<<8)
#define	EXIT_IRQ3_NIVC_Disable()          (NVIC_ICER0 |= 1<<9)
#define EXIT_IRQ4_NIVC_Disable()  	      (NVIC_ICER0 |= 1<<10)
#define EXIT_IRQ5_9_NIVC_Disable()        (NVIC_ICER0 |= 1<<23)
#define EXIT_IRQ10_15_NIVC_Disable()      (NVIC_ICER1 |= 1<<8) //40-32 = 8

//=================================================================//

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*-


#endif /* MCU_DEVICE_HEADER_STM32F103X6_H_ */
