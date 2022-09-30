//Eng. Mohamed Gamal

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32f103x6.h"
#include "Stm32F_103C6_Gpio_Driver.h"
//#include "LCD.h"

void clock_init()
{
	//Bit 2 IOPAEN: I/O port A clock enable
	GPIOA_Clock_Enable();

	//Bit 3 IOPBEN: I/O port B clock enable
	GPIOB_Clock_Enable();
}


void Gpio_init()
{
	GPIOx_Config_t config;

	//pinA1 as an input Floating
	config.PinNumber = GPIOx_PIN1;
	config.MODE =  GPIO_MODE_Fl_in;
	MCAL_GPIO_Init(GPIOA, &config);


	//pinB1 as an output push-pull
	config.PinNumber = GPIOx_PIN1;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
	MCAL_GPIO_Init(GPIOB, &config);



	//pinA13  as an input Floating
	config.PinNumber = GPIOx_PIN13;
	config.MODE =  GPIO_MODE_Fl_in;
	MCAL_GPIO_Init(GPIOA, &config);

	//pinB13 as an output push-pull
	config.PinNumber = GPIOx_PIN13;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
	MCAL_GPIO_Init(GPIOB, &config);

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

		if ( MCAL_GPIO_ReadPin(GPIOA, GPIOx_PIN1) == 0) {

			MCAL_GPIO_TogglePin(GPIOB, GPIOx_PIN1);
			while (MCAL_GPIO_ReadPin(GPIOA, GPIOx_PIN1) == 0);  //single press;
		}


		if (MCAL_GPIO_ReadPin(GPIOA, GPIOx_PIN13) == 1) {

			MCAL_GPIO_TogglePin(GPIOB, GPIOx_PIN13);           //multi press;

		}
		wait(1);

	}

}







