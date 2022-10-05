//Eng.Mohamed Gamal 

#include <avr/io.h>
#include "I2C.h"

#define  ACK   1 

void I2C_Set_Address(unsigned char Address)
{
	TWAR = Address;
}

unsigned char I2C_Read(){
	
	  // Own SLA+R has been received, ACK has been returned
	  TWCR= (1<<TWINT)|(ACK<<TWEA)|(1<<TWEN);
	  while(!(TWCR & (1<<TWINT))); 
	  //while((TWSR)!= 0xA8);       
	  
	 //Data byte in TWDR has been transmitted, ACK has been received
	 //TWCR= (1<<TWINT)|(ACK<<TWEA)|(1<<TWEN);
	 //while(!(TWCR & (1<<TWINT)));
	 //while((TWSR)!= 0xB8);
	  
	  return TWDR;
}


void I2C_Write(unsigned char Data)
{
	TWDR = Data;
	TWCR= (1<<TWINT)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
}