/*Eng. Mohamed Gamal*/

#include "lcd.h"
#include "UART.h"
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

//============Generic Varibles==========//
char* p = '\0';
char Data = 0;
char Data_Buffer[50];
unsigned char count = 0;

//===========Generic Functions==========//

void reset() {
	
	for (int i = 0 ; i < 50 ; i++){
		Data_Buffer[i] = '\0';
		Data = 0;
		count = 0;
	}
}

//=======================================//

int main(void)
{	
	LCD_INIT();
	
    MCAL_UART_Init();

	_delay_ms(50);
	
	LCD_WRITE_STRING("READY");
	_delay_ms(100);
	LCD_clear_screen();
	
	MCAL_UART_SendString("READY For Receiving Data\r");
	MCAL_UART_SendString("Enter Data: \r");
	
	
    while (1) 
    {
		p = MCAL_UART_ReceiveString();
		LCD_WRITE_STRING(p);
		_delay_ms(200);
		LCD_clear_screen();
		_delay_ms(20);
    }
	
	
}





