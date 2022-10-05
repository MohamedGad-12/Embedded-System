//Eng.Mohamed Gamal 

#define  F_CPU       8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "I2C.h"

int main(void)
{
	unsigned char Data = 0; 
	I2C_Set_Address(0b11010000);
    while (1) 
    {
		I2C_Read();
		I2C_Write(Data++);
    }
	return 0;
}

