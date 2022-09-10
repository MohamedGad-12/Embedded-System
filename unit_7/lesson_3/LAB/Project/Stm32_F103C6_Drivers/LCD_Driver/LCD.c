/*Eng. Mohamed Gamal*/

#include "lcd.h"
#include <stdio.h>
#include <string.h>
#include "stm32f103x6.h"
#include "Stm32F_103C6_Gpio_Driver.h"
#include "LCD.h"

int curser = 0;
GPIOx_Config_t config;

void _delay_ms (unsigned int t) {

	unsigned int i,j;
	for(i = 0 ; i < t ; i++)
		for(j = 0 ; j < 255 ; j++);
}

void LCD_clear_screen(){
	curser = 0;
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_lcd_kick(){

	MCAL_GPIO_WritePin(GPIOA, EN_SWITCH , 1);

	_delay_ms(50);

	MCAL_GPIO_WritePin(GPIOA, EN_SWITCH , 0);
}

void LCD_GOTO_XY(unsigned char line, unsigned char position){
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW+position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			curser = 16;
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW+position);
		}
	}
}

void LCD_INIT(){

	_delay_ms(20);

	config.PinNumber = EN_SWITCH;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = RS_SWITCH;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = RW_SWITCH;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
	MCAL_GPIO_Init(GPIOA, &config);

	///===========================================


	MCAL_GPIO_WritePin(GPIOA, EN_SWITCH , 0);
	MCAL_GPIO_WritePin(GPIOA, RS_SWITCH , 0);
	MCAL_GPIO_WritePin(GPIOA, RW_SWITCH , 0);


	config.PinNumber = GPIOx_PIN0;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = GPIOx_PIN1;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = GPIOx_PIN2;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = GPIOx_PIN3;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = GPIOx_PIN4;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = GPIOx_PIN5;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = GPIOx_PIN6;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = GPIOx_PIN7;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
	MCAL_GPIO_Init(GPIOA, &config);

	_delay_ms(15);
	LCD_clear_screen();

#ifdef EIGHT_BIT_MODE
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
#endif

#ifdef FOUR_BIT_MODE
	//LCD_WRITE_COMMAND(0x02);		        /* send for 4 bit initialization of LCD  */
	//LCD_WRITE_COMMAND(0x28);              /* 2 line, 5*7 matrix in 4-bit mode */
	//LCD_WRITE_COMMAND(0x0c);              /* Display on cursor off*/
	//LCD_WRITE_COMMAND(0x06);              /* Increment cursor (shift cursor to right)*/
	//LCD_WRITE_COMMAND(0x01);
	LCD_WRITE_COMMAND(0x02);
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
#endif

	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_check_lcd_isbusy(){

	config.PinNumber = GPIOx_PIN0;
	config.MODE =  GPIO_MODE_Fl_in;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = GPIOx_PIN1;
	config.MODE =  GPIO_MODE_Fl_in;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = GPIOx_PIN2;
	config.MODE =  GPIO_MODE_Fl_in;;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = GPIOx_PIN3;
	config.MODE =  GPIO_MODE_Fl_in;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = GPIOx_PIN4;
	config.MODE =  GPIO_MODE_Fl_in;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = GPIOx_PIN5;
	config.MODE =  GPIO_MODE_Fl_in;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = GPIOx_PIN6;
	config.MODE =  GPIO_MODE_out_PP;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = GPIOx_PIN7;
	config.MODE =  GPIO_MODE_Fl_in;
	MCAL_GPIO_Init(GPIOA, &config);


	MCAL_GPIO_WritePin(GPIOA, RW_SWITCH , 1);
	MCAL_GPIO_WritePin(GPIOA, RS_SWITCH , 0);

	LCD_lcd_kick();

	config.PinNumber = GPIOx_PIN0;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = GPIOx_PIN1;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = GPIOx_PIN2;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = GPIOx_PIN3;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = GPIOx_PIN4;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = GPIOx_PIN5;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = GPIOx_PIN6;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
	MCAL_GPIO_Init(GPIOA, &config);

	config.PinNumber = GPIOx_PIN7;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
	MCAL_GPIO_Init(GPIOA, &config);

	MCAL_GPIO_WritePin(GPIOA, RW_SWITCH , 0);

}


void LCD_WRITE_COMMAND(unsigned char command){
#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();
	MCAL_GPIO_WritePort(GPIOA,command);

	MCAL_GPIO_WritePin(GPIOA, RS_SWITCH , 0);
	MCAL_GPIO_WritePin(GPIOA, RW_SWITCH , 0);

	_delay_ms(1);
	LCD_lcd_kick();
#endif
	/*
	#ifdef FOUR_BIT_MODE
		LCD_check_lcd_isbusy();
		LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
		LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
		LCD_lcd_kick ();
		LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);
		LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
		LCD_lcd_kick();
	#endif */
}

void check_position (){
	curser++;
	if (curser == 16)
	{
		LCD_GOTO_XY(2,0);
	}
	else if (curser == 32)
	{
		LCD_clear_screen();
		LCD_GOTO_XY(1,0);
		curser = 0;
	}

}

void LCD_WRITE_CHAR(unsigned char character){
#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();

	MCAL_GPIO_WritePort(GPIOA,((uint8_t)character));

	MCAL_GPIO_WritePin(GPIOA, RW_SWITCH , 0);
	MCAL_GPIO_WritePin(GPIOA, RS_SWITCH , 1);

	_delay_ms(1);
	LCD_lcd_kick();
	_delay_ms(1);
	check_position();
	_delay_ms(1);
#endif
	/*
	#ifdef FOUR_BIT_MODE
		//LCD_check_lcd_isbusy();
		LCD_PORT = (LCD_PORT & 0x0F) | (character & 0xF0);
		LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
		LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
		LCD_lcd_kick();
		LCD_PORT = (LCD_PORT & 0x0F) | (character << 4);
		LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
		LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
		LCD_lcd_kick ();
	#endif
	 */
}

void LCD_WRITE_STRING(char* string){
	while (*string > 0) {
		LCD_WRITE_CHAR(*string++);
	}
}

void dipaly_number(int number)
{
	char str[16];
	sprintf(str,"%d",number);
	LCD_WRITE_STRING(str);
}

void dipaly_real_number(float number)
{
	char strr[16];

	char *tmpsign = (number < 0) ? "-" : "";
	float tmpval = (number < 0) ? -number : number;

	int tmpint1 = tmpval;
	float tmpfrac = tmpval - tmpint1;
	int tmpint2 = tmpfrac * 1000;

	sprintf(strr,"%s%d.%03d",tmpsign,tmpint1,tmpint2);

	LCD_WRITE_STRING(strr);
}


