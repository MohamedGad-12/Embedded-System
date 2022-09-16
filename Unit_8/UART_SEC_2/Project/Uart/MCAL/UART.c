/*Eng. Mohamed Gamal*/

#include "UART.h"
#include <avr/interrupt.h>

//============Generic Varibles==========//

static char R_Data[50] = {' '};
static char R_Buffer = 0;
static unsigned char R_count = 0;

//===========APIs================================//

void interrupt_Enable_RX(){
	UCSRB = (1<<RXCIE) | (1<<RXEN);
}

void interrupt_Enable_TX(){
	UCSRB  = (1<<TXCIE) |(1<<TXEN);
}

void interrupt_Disable_RX(){
	UCSRB = (0<<RXCIE);
}

void interrupt_Disable_TX(){
	UCSRB = (0<<TXCIE);
}

//==============================================//

void MCAL_UART_Init()
{

	RESET_BIT (UCSRA,1,U2X);
	
	UCSRB  = (1<<RXEN)|(1<<TXEN);

	UCSRC  =(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);

	UBRRH  = 0x00;
	UBRRL  = 51;

	sei();
	
	//UCSR B_V =0x86;
	//UCSRB_V = 0xF8;
}

//==============================================//

void MCAL_UART_Send (uint8_t Data){
		
	while(!READ_BIT(UCSRA,1,UDRE));
	UDR = Data;
	
}

//==============================================//

uint8_t MCAL_UART_Receive(){
	
	while(!READ_BIT(UCSRA,1,RXC));
	return UDR;
}


//==============================================//


void MCAL_UART_SendString(char *data){
	
	 while(*data){
		MCAL_UART_Send(*data++);
	 }
	 
}


//==============================================//


char* MCAL_UART_ReceiveString(){
	
	while(!READ_BIT(UCSRA,1,RXC));

	R_Buffer = UDR;
	
	if (R_Buffer == '\r'){
		R_Data[R_count] = '\0';
		R_count = 0;
		return R_Data;
	}
	else
	{
	R_Data[R_count] = R_Buffer;
	R_count++;
	}	
	
	return ' ';
}


//==============================================//