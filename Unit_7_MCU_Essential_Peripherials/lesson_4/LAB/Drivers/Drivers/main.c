/*Eng. Mohamed Gamal*/

#include "MemoMap.h"
#include "lcd.h"
#include "GPIO_Driver.h"
#include <stdint.h>
#include <avr/io.h>

#define F_CPU 8000000UL

int main(void)
{
	MCAL_GPIO_Pin_Init(portB,RS_SWITCH,Output);
	MCAL_GPIO_Pin_Init(portB,RW_SWITCH,Output);
	MCAL_GPIO_Pin_Init(portB,EN_SWITCH,Output);
	MCAL_GPIO_Init(portA,Output);
	LCD_INIT();
	_delay_ms(250);
	LCD_WRITE_STRING("Welcome To Learn In Depth :)");
    while (1) 
    {
    }
}

