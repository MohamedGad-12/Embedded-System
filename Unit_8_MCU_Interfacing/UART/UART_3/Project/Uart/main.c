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
	
	//MCAL_UART_SendString("READY For Receiving Data\r");
	//MCAL_UART_SendString("Enter Data: \r");
	
	interrupt_Enable_RX();
	
	
    while (1) 
    {
		//p = MCAL_UART_ReceiveString();
		//LCD_WRITE_STRING(p);
		//_delay_ms(250);
		//LCD_clear_screen();
		//_delay_ms(25);
    }
}


//===========USART_ISR==========================//

//===========USART_RXC_VEctor_13==========//

ISR (USART_RXC_vect){
	
	Data = UDR;
	if (Data == '\r'){
		
		//Indicate about Receiving
		LCD_WRITE_STRING("Acknowledge:");
		LCD_GOTO_XY(2,0);
		LCD_WRITE_STRING("RXIE Enable :)");
		_delay_ms(50);
		LCD_clear_screen();
		
		//Write Receiving Data On LCD
		Data_Buffer[count] = '\0';
		LCD_WRITE_STRING("Receiving Data: ");
		//LCD_GOTO_XY(2,0);
		LCD_WRITE_STRING(Data_Buffer);
		//reset();
		count = 0;
		
		//Enable Send interrupt
		//@ref -> USART_RXC_VEctor_15
		//lCD Will Print -> Acknowledge: TX Enable
		interrupt_Enable_TX();
		_delay_ms(100);
		UDR = 'A';
		_delay_ms(100);
		UDR = 'C';
		_delay_ms(100);
		UDR = 'K';
		
		
	}
	else 
	{
		Data_Buffer[count] = Data;
		count++;
	}
	
	UCSRA|=(1<<RXC);
}

//===========USART_RXC_VEctor_15==========//

ISR(USART_TXC_vect){
	
	LCD_clear_screen();
	_delay_ms(50);
	LCD_WRITE_STRING("Acknowledge:");
	LCD_GOTO_XY(2,0);
	LCD_WRITE_STRING("TXIE Enable :)");
	_delay_ms(50);
	
	UCSRA|=(1<<TXC);
}

//=========================================//




