/*Eng.Mohamed Gamal*/

/*
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
 */

typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


// clock enable
#define RCC 0x40021000
#define RCC_APB2ENR *(volatile uint32_t*)(RCC + 0x18)

//enable HSI
#define RCC_CR *(volatile uint32_t *)(RCC+ 0x00)

//SW Multiplexer
#define RCC_CFGR *(volatile uint32_t*)(RCC + 0x04)

// register address
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0C)


void Clock_Init(){

	/*
	Bit 2 IOPAEN: I/O port A clock enable
	Set and cleared by software.
	0: I/O port A clock disabled
	1:I/O port A clock enabled
	 */
	RCC_APB2ENR |= (1 << 2) ;

	/*
	Bit 0 HSION: Internal high-speed clock enable
	Set and cleared by software.
	Set by hardware to force the internal 8 MHz RC oscillator ON when leaving Stop or Standby
	mode or in case of failure of the external 3-25 MHz oscillator used directly or indirectly as
	system clock. This bit can not be cleared if the internal 8 MHz RC is used directly or
	indirectly as system clock or is selected to become the system clock.
	0: Internal 8 MHz RC oscillator OFF
	1: Internal 8 MHz RC oscillator ON
	 */
	RCC_CR |= (1 << 0) ;

	/*
	Bit 16 PLLSRC: PLL entry clock source
	Set and cleared by software to select PLL clock source.
	This bit can be written only when PLL is disabled.
	0: HSI oscillator clock / 2 selected as PLL input clock
	1: HSE oscillator clock selected as PLL input clock
	 */
	RCC_CFGR |= (0 << 16);

	/*
	Bits 1:0 SW: System clock switch
	Set and cleared by software to select SYSCLK source.
	Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of
	failure of the HSE oscillator used directly or indirectly as system clock (if the Clock Security
	System is enabled).
	00: HSI selected as system clock
	01: HSE selected as system clock
	10: PLL selected as system clock
	11: not allowed
	 */
	RCC_CFGR |= (0b10 << 0);

	/*
	Bits 21:18 PLLMUL: PLL multiplication factor
	These bits are written by software to define the PLL multiplication factor. These bits can be
	written only when PLL is disabled.
	Caution: The PLL output frequency must not exceed 72 MHz.
	0000: PLL input clock x 2
	0001: PLL input clock x 3
	0010: PLL input clock x 4
	0011: PLL input clock x 5
	0100: PLL input clock x 6
	0101: PLL input clock x 7
	0110: PLL input clock x 8
	0111: PLL input clock x 9
	1000: PLL input clock x 10
	1001: PLL input clock x 11
	1010: PLL input clock x 12
	1011: PLL input clock x 13
	1100: PLL input clock x 14
	1101: PLL input clock x 15
	1110: PLL input clock x 16
	1111: PLL input clock x 16
	 */
	RCC_CFGR |= (0b0110 << 18);

	/*
	Bits 7:4 HPRE: AHB prescaler
	Set and cleared by software to control the division factor of the AHB clock.
	0xxx: SYSCLK not divided
	1000: SYSCLK divided by 2
	1001: SYSCLK divided by 4
	1010: SYSCLK divided by 8
	1011: SYSCLK divided by 16
	1100: SYSCLK divided by 64
	1101: SYSCLK divided by 128
	1110: SYSCLK divided by 256
	1111: SYSCLK divided by 512
	Note: The prefetch buffer must be kept on when using a prescaler different from 1 on the
	AHB clock. Refer to Reading the Flash memory section for more details
	 */
	RCC_CFGR |= (0b0000 << 4);

	/*
	Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
	Set and cleared by software to control the division factor of the APB low-speed clock
	(PCLK1).
	Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16
	 */
	RCC_CFGR |= (0b100 << 8);

	/*
	Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
	Set and cleared by software to control the division factor of the APB high-speed clock
	(PCLK2).
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16
	 */
	RCC_CFGR |= (0b101 << 11);

	/*
	Bit 24 PLLON: PLL enable
	Set and cleared by software to enable PLL.
	Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
	PLL clock is used as system clock or is selected to become the system clock.
	0: PLL OFF
	1: PLL ON
	 */
	RCC_CR |= (1 << 24) ;
}

void GPIOA_Init() {
	//Init GPIOA
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
}

int main(void)
{

	Clock_Init();
	GPIOA_Init();

	while(1)
	{
		GPIOA_ODR |= 1<<13 ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
		GPIOA_ODR &= ~(1<<13) ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
	}
}
