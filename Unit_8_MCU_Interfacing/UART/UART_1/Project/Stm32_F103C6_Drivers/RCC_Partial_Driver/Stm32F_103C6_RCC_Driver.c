//Eng. Mohamed Gamal

#include "stm32f103x6.h"
#include "Stm32F_103C6_RCC_Driver.h"


/*
 * NOTE: PCLK2 & PCLK1 have Same Options
 *
Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
Set and cleared by software to control the division factor of the APB high-speed clock
(PCLK2).

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

const uint8_t APB_Prsec_Table[8U] = {0,0,0,0,1,2,3,4};


//Bits 7:4 HPRE: AHB prescaler
//Set and cleared by software to control the division factor of the AHB clock.
//0xxx: SYSCLK not divided
//1000: SYSCLK divided by 2
//1001: SYSCLK divided by 4
//1010: SYSCLK divided by 8
//1011: SYSCLK divided by 16
//1100: SYSCLK divided by 64
//1101: SYSCLK divided by 128
//1110: SYSCLK divided by 256
//1111: SYSCLK divided by 512
//Note: The prefetch buffer must be kept on when using a prescaler different from 1 on the
//AHB clock. Refer to Reading the Flash memory section for more details.

const uint8_t AHB_Prsec_Table[16U] = {0,0,0,0,0,0,0,0,1,2,3,4,6,7,8,9};





uint32_t  MCAl_RCC_Get_SysClk_Freq(void){

//Bits 1:0 SW: System clock switch
//Set and cleared by software to select SYSCLK source.
//Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of
//failure of the HSE oscillator used directly or indirectly as system clock (if the Clock Security
//System is enabled).
//00: HSI selected as system clock
//01: HSE selected as system clock
//10: PLL selected as system clock
//11: not allowed

	uint32_t CLK;

	switch ( (RCC->RCC_CFGR >> 2) &0b11 ) {

	case 0:
		CLK =  HSI;
		break;

	//to do need to calculate it // HSE User Should Specify it
	case 1:
		CLK = HSE;
		break;

	//to do need to calculate it // PLLCLK, PULLMUl and Source MUX
	case 2:
		CLK = 16000000;
		break;

	}
	return CLK ;
}



uint32_t  MCAl_RCC_Get_HCLK_Freq(void){

	return ( MCAl_RCC_Get_SysClk_Freq() >> ( AHB_Prsec_Table[ (RCC->RCC_CFGR >> 4) & 0xF] ) );
}




uint32_t  MCAl_RCC_Get_PCLK1_Freq(void){


	return ( MCAl_RCC_Get_HCLK_Freq() >> ( APB_Prsec_Table[ (RCC->RCC_CFGR >> 8) & 0b111] ) );
}

uint32_t  MCAl_RCC_Get_PCLK2_Freq(void){

	return ( MCAl_RCC_Get_HCLK_Freq() >> ( APB_Prsec_Table[ (RCC->RCC_CFGR >> 11) & 0b111] ) );
}
