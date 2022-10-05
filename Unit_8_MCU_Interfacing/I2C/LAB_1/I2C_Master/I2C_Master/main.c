//Eng.Mohamed Gamal 

#define  F_CPU       8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "I2C.h"

int main(void)
{
    unsigned char Data = 0;
	I2C_init();
    while (1) 
    {
		_delay_ms(500);
		I2C_Start();
		I2C_Write(0b11010000+0);     //SLA+W
		while( (TWSR) != 0x18);      //SLA+W has been transmitted, ACK has been received
		I2C_Write(Data++);
		while( (TWSR) != 0x28);      //Data byte has been transmitted, ACK has been received
		I2C_Stop();
    }
	return 0;
}

