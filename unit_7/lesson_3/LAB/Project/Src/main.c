//Eng. Mohamed Gamal

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32f103x6.h"
#include "Stm32F_103C6_Gpio_Driver.h"
#include "LCD.h"
#include "KeyPad.h"

//===============================================================================//

static unsigned char seven_segment[] = {0x01,0x79,0x24,0x30,0x58,0x12,0x02,0x19,0x00,0x10};

//===============================================================================//
//Clock Enable
void clock_init()
{
	//Bit 2 IOPAEN: I/O port A clock enable
	GPIOA_Clock_Enable();

	//Bit 3 IOPBEN: I/O port B clock enable
	GPIOB_Clock_Enable();
}

//===============================================================================//
//Delay
void wait (unsigned int t) {

	unsigned int i,j;
	for(i = 0 ; i < t ; i++)
		for(j = 0 ; j < 255 ; j++);
}

//===============================================================================//

void seven_seg_init(){

	unsigned int i;
	uint16_t pin = GPIOx_PIN8;
	GPIOx_Config_t config;

	for (i = 0 ; i < 7 ; i++){
		config.PinNumber = pin;
		config.MODE =  GPIO_MODE_out_PP;
		config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
		MCAL_GPIO_Init(KEYPAD_PORT, &config);
		pin = pin * 2;
	}
}

//===============================================================================//

int main(void) {

	char x[] = {'0'};
	int y ;

	clock_init();
	LCD_INIT();
	seven_seg_init();
	wait(50);

	LCD_WRITE_STRING("Hello Sir :)");
	LCD_clear_screen();

	for (unsigned char i = 0 ; i < 10; i++) {
		LCD_WRITE_CHAR(x[0]);
		MCAL_GPIO_WritePort(GPIOB, (seven_segment[i] << 8));
		y = atoi(x) + 1 ;
		itoa(y, x, 10);
	}

	LCD_clear_screen();
	LCD_WRITE_STRING("KeyPad Is Ready");
	LCD_clear_screen();

	Keypad_init();
	wait(50);

	unsigned char key_pressed;
	while(1){
		key_pressed = Keypad_getkey();
		switch(key_pressed){
		case 'A':
			break;
		case '?':
			LCD_clear_screen();
			break;
		default:
			LCD_WRITE_CHAR(key_pressed);
			break;
		}
	}


}







