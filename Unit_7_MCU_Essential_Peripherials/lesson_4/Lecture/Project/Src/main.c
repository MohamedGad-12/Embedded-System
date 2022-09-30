//Eng. Mohamed Gamal

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32f103x6.h"
#include "Stm32F_103C6_Gpio_Driver.h"
#include "Stm32F_103C6_EXIT_Gpio_Driver.h"
#include "LCD.h"
#include "KeyPad.h"

//Clock Enable
void clock_init()
{
	//Bit 2 IOPAEN: I/O port A clock enable
	GPIOA_Clock_Enable();

	//Bit 3 IOPBEN: I/O port B clock enable
	GPIOB_Clock_Enable();

	// Enable Alternative Function
	AFIO_Clock_Enable();
}

//===============================================================================//

//Delay
void wait (unsigned int t) {

	unsigned int i,j;
	for(i = 0 ; i < t ; i++)
		for(j = 0 ; j < 255 ; j++);
}

//===============================================================================//

void print(void) {

	LCD_clear_screen();
	LCD_WRITE_STRING("=> IRQ EXIT_9 Is   Happened _|-");
	wait(250);
}

//===============================================================================//

void EXIT_GPIO_EXIT_9()
{
	Exit_Config_t x;
	x.Exit_pin = EXIT9_B_PIN9;
	x.Exit_Trigger = rising_Trigger;
	x.Call_back = print ;
	x.Exit_Enable = EXIT_IRQ_Enable;
	MCAL_EXIT_GPIO_Init(&x);

}

//===============================================================================//


int main(void) {

	clock_init();
	LCD_INIT();
	wait(25);
	LCD_WRITE_STRING("LCD IS READY");
	EXIT_GPIO_EXIT_9();

	while(1){}

}







