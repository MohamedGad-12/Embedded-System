//Eng.Mohamed Gamal 

#define  F_CPU       8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "I2C.h"

int main(void)
{
	DDRA = 0XFF;                      //OutPut
    unsigned char Data = 0;
	I2C_init();
    while (1) 
    {
		_delay_ms(1000);
		I2C_Start();
		I2C_Write(0b11010000+1);     //SLA+R
		while( (TWSR) != 0x40);      // SLA+R has been transmitted, ACK has been received
		Data = I2C_Read();
		while( (TWSR) != 0x50);      // Data byte has been received,ACK has been returned
		I2C_Stop();
		PORTA = Data;
    }
	return 0;
}

