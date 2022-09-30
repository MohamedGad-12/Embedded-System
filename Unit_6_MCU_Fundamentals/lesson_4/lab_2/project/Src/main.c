//Eng. Mohamed Gamal

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define RCC_BASE 	    0x40021000
#define RCC_APB2ENR 	*(volatile uint32_t*)(RCC_BASE + 0x18)
#define RCC_IOPAEN 		(1<<2)


#define GPIOA_BASE 	    0x40010800
#define GPIOA_CRH		*(volatile uint32_t*)(GPIOA_BASE + 0x04)
#define GPIOA_ODR		*(volatile uint32_t*)(GPIOA_BASE + 0x0c)
#define GPIOA_CRL		*(volatile uint32_t*)(GPIOA_BASE + 0x00)

#define EXTI	        0x40010400
#define EXTI_RTSR		*(volatile uint32_t*)(EXTI + 0x08)
#define EXTI_IMR		*(volatile uint32_t*)(EXTI + 0x00)
#define EXTI_PR		    *(volatile uint32_t*)(EXTI + 0x14)

#define AFIO	        0x40010000
#define AFIO_EXTICR1    *(volatile uint32_t*)(AFIO + 0x08)

#define NVIC_ISER0		*(volatile uint32_t*)(0xE000E100)



void clock_init()
{
	//Bit 2 IOPAEN: I/O port A clock enable
	RCC_APB2ENR |= RCC_IOPAEN;

	//Bit 0 AFIOEN: Alternate function I/O clock enable
	RCC_APB2ENR |= (1<<0);
}


void Gpio_init()
{
	//pinA0
	GPIOA_CRL = (1<<2);
	//pinA13
	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;
}

void interrupt_init()
{
	//AFIO_EXTICR1 = 0x0;


    //Rising trigger selection register
	EXTI_RTSR |= (1<<0);

	//Interrupt mask register
	EXTI_IMR |= (1<<0);

	//Enable NIVC Port 6 (Exti0)
	NVIC_ISER0 |= (1<<6);
}

int main(void) {

	clock_init();
	Gpio_init();
	interrupt_init();

	while(1);
}


void EXTI0_IRQHandler ()
{
	GPIOA_ODR ^= (1<<13);

	EXTI_PR |= (1<<0);
}




