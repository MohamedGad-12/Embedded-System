//Eng.Mohamed Gamal 

#define  F_CPU       8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "I2C.h"

int main(void)
{
    DDRA = 0xFF;  //Output
	I2C_Set_Address(0b11010000);
    while (1) 
    {
		_delay_ms(500);
		PORTA = I2C_Read();
    }
	return 0;
}

