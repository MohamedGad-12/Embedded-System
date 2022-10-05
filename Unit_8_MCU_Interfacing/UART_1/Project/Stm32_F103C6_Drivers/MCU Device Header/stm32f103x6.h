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
#define GPIOA_Base   0x40010800UL
#define GPIOB_Base   0x40010C00UL
#define GPIOC_Base   0x40011000UL
#define GPIOD_Base   0x40011400UL
#define GPIOE_Base   0x40011800UL

#define EXIT_Base     0x40010400UL

#define AFIO_Base     0x40010000UL

#define AFIO_Base     0x40010000UL

#define USART1_Base   0x40013800UL


//-----------------------------
//Base addresses for APB1 Peripherals
//-----------------------------

#define USART2_Base   0x40004400UL

#define USART3_Base   0x40004800UL




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
//Peripheral register: UART
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t USART_SR;
	volatile uint32_t USART_DR;
	volatile uint32_t USART_BRR;
	volatile uint32_t USART_CR1;
	volatile uint32_t USART_CR2;
	volatile uint32_t USART_CR3;
	volatile uint32_t USART_GTPR;

}UART_typeDef;



//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: GPIOx
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA   ((GPIO_typeDef*) GPIOA_Base)
#define GPIOB   ((GPIO_typeDef*) GPIOB_Base)
#define GPIOC   ((GPIO_typeDef*) GPIOC_Base)
#define GPIOD   ((GPIO_typeDef*) GPIOD_Base)
#define GPIOE   ((GPIO_typeDef*) GPIOE_Base)


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
//Peripheral Instants: GPIOx
//-*-*-*-*-*-*-*-*-*-*-*
#define USART1  ((UART_typeDef*) USART1_Base)
#define USART2  ((UART_typeDef*) USART2_Base)
#define USART3  ((UART_typeDef*) USART3_Base)



//===============================================================================//

//IVT

//EXIT
#define EXIT_IRQ0       6
#define EXIT_IRQ1       7
#define EXIT_IRQ2       8
#define EXIT_IRQ3       9
#define EXIT_IRQ4       10
#define EXIT_IRQ5_9     23
#define EXIT_IRQ10_15   40

//UART_IT
#define UART_IRQ1       37
#define UART_IRQ2       38
#define UART_IRQ3       39

//===============================================================================//

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

//AFIO
#define AFIO_Clock_Enable()    (RCC->RCC_APB2ENR |= 1<<0)

//GPIO
#define GPIOA_Clock_Enable()   (RCC->RCC_APB2ENR |= 1<<2)
#define GPIOB_Clock_Enable()   (RCC->RCC_APB2ENR |= 1<<3)
#define GPIOC_Clock_Enable()   (RCC->RCC_APB2ENR |= 1<<4)
#define GPIOD_Clock_Enable()   (RCC->RCC_APB2ENR |= 1<<5)
#define GPIOE_Clock_Enable()   (RCC->RCC_APB2ENR |= 1<<6)

//UART_Enable
#define USART1_Clock_Enable()    (RCC->RCC_APB2ENR |= 1<<14)
#define USART2_Clock_Enable()    (RCC->RCC_APB1ENR |= 1<<17)
#define USART3_Clock_Enable()    (RCC->RCC_APB1ENR |= 1<<18)

//UART_Disable
#define USART1_Clock_Disable()   (RCC->RCC_APB2RSTR |= 1<<14)
#define USART2_Clock_Disable()   (RCC->RCC_APB1RSTR |= 1<<17)
#define USART3_Clock_Disable()   (RCC->RCC_APB1RSTR |= 1<<18)



//-*-*-*-*-*-*-*-*-*-*-*-
//NIVC enable and disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

//EXIT

//Enable
#define EXIT_IRQ0_NIVC_Enable()           (NVIC_ISER0 |= 1<<6)
#define EXIT_IRQ1_NIVC_Enable()           (NVIC_ISER0 |= 1<<7)
#define EXIT_IRQ2_NIVC_Enable()           (NVIC_ISER0 |= 1<<8)
#define	EXIT_IRQ3_NIVC_Enable()           (NVIC_ISER0 |= 1<<9)
#define EXIT_IRQ4_NIVC_Enable()  	      (NVIC_ISER0 |= 1<<10)
#define EXIT_IRQ5_9_NIVC_Enable()         (NVIC_ISER0 |= 1<<23)
#define EXIT_IRQ10_15_NIVC_Enable()       (NVIC_ISER1 |= 1<<8)

//Disable
#define EXIT_IRQ0_NIVC_Disable()          (NVIC_ICER0 |= 1<<6)
#define EXIT_IRQ1_NIVC_Disable()          (NVIC_ICER0 |= 1<<7)
#define EXIT_IRQ2_NIVC_Disable()          (NVIC_ICER0 |= 1<<8)
#define	EXIT_IRQ3_NIVC_Disable()          (NVIC_ICER0 |= 1<<9)
#define EXIT_IRQ4_NIVC_Disable()  	      (NVIC_ICER0 |= 1<<10)
#define EXIT_IRQ5_9_NIVC_Disable()        (NVIC_ICER0 |= 1<<23)
#define EXIT_IRQ10_15_NIVC_Disable()      (NVIC_ICER1 |= 1<<8) //40-32 = 8

//UART

//Enable
#define UART1_IRQ37_NIVC_Enable          (NVIC_ISER1 |= 1<<(UART_IRQ1 - 32))
#define UART2_IRQ38_NIVC_Enable          (NVIC_ISER1 |= 1<<(UART_IRQ2 - 32))
#define UART3_IRQ39_NIVC_Enable          (NVIC_ISER1 |= 1<<(UART_IRQ3 - 32))

#define UART1_IRQ37_NIVC_Disable         (NVIC_ICER1 |= 1<<(UART_IRQ1 - 32))
#define UART2_IRQ38_NIVC_Disable         (NVIC_ICER1 |= 1<<(UART_IRQ2 - 32))
#define UART3_IRQ39_NIVC_Disable         (NVIC_ICER1 |= 1<<(UART_IRQ3 - 32))

//=================================================================//


//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*-


#endif /* MCU_DEVICE_HEADER_STM32F103X6_H_ */
