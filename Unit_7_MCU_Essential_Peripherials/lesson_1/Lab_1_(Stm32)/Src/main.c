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
#define RCC_IOPBEN 		(1<<3)

#define GPIOA_BASE 	    0x40010800
#define GPIOA_CRH		*(volatile uint32_t*)(GPIOA_BASE + 0x04)
#define GPIOA_ODR		*(volatile uint32_t*)(GPIOA_BASE + 0x0c)
#define GPIOA_CRL		*(volatile uint32_t*)(GPIOA_BASE + 0x00)
#define GPIOA_IDR		*(volatile uint32_t*)(GPIOA_BASE + 0x08)


#define GPIOB_BASE 	    0x40010C00
#define GPIOB_CRH		*(volatile uint32_t*)(GPIOB_BASE + 0x04)
#define GPIOB_ODR		*(volatile uint32_t*)(GPIOB_BASE + 0x0c)
#define GPIOB_CRL		*(volatile uint32_t*)(GPIOB_BASE + 0x00)
#define GPIOB_IDR		*(volatile uint32_t*)(GPIOB_BASE + 0x08)



void clock_init()
{
	//Bit 2 IOPAEN: I/O port A clock enable
	RCC_APB2ENR |= RCC_IOPAEN;

	//Bit 3 IOPBEN: I/O port B clock enable
	RCC_APB2ENR |= RCC_IOPBEN;
}


void Gpio_init()
{
	// by default pinA1 has correct configuration

	//pinB1 as an output push-pull
	GPIOB_CRL |= (0b0010 << 4);

	//pinA13 input
	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00400000;

	//pinB13 output
	GPIOB_CRH   &= 0xFF0FFFFF;
	GPIOB_CRH   |= 0x00200000;

}

void wait (unsigned int t) {

	unsigned int i,j;
	for(i = 0 ; i < t ; i++)
		for(j = 0 ; j < 255 ; j++);
}


int main(void) {

	clock_init();
	Gpio_init();

	while(1){

		if (((GPIOA_IDR & (1<<1)) >> 1) == 0) {

			GPIOB_ODR ^= 1<<1 ;
			while (((GPIOA_IDR & (1<<1)) >> 1) == 0);
		}


		if (((GPIOA_IDR & (1<<13)) >> 13) == 1) {

			GPIOB_ODR ^= 1<<13 ;

		}
		wait(1);

	}

}







