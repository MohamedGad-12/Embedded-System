//Eng.Mohamed Gamal 

#include <avr/io.h>
#include "I2C.h"

//#define  Prescaler   1      // 1 , 4 , 16 , 64


void I2C_init()
{
	  // SCL freq= F_CPU/(16+2(TWBR).4^TWPS)     //MIN=0 , MAX=400KHZ  
	  TWBR=0x01;                               // Bit rate
	  TWSR=(0<<TWPS1)|(0<<TWPS0);             // Setting Prescaler bits
}


void I2C_Start(void)
{
	    // Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
	    TWCR= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	    while(!(TWCR & (1<<TWINT)));          // Wait till start condition is transmitted
	    while( (TWSR) != 0x08);               // start condition has been transmitted
}


void I2C_Write(unsigned char  D_Byte)
{
	 TWDR=D_Byte;                     // put data in TWDR
	 TWCR=(1<<TWINT)|(1<<TWEN);      // Clear TWI interrupt flag,Enable TWI
	 while((TWCR & 0x80) == 0); 
}

void I2C_Stop()
{
	TWCR= (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}
