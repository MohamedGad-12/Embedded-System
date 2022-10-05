//Eng.Mohamed Gamal 

#include <avr/io.h>
#include "I2C.h"

#define  ACK   1 

void I2C_Set_Address(unsigned char Address)
{
	TWAR = Address;
}

unsigned char I2C_Read(){
	
	  // Own SLA+W has been received and ACK has been returned
	  TWCR= (1<<TWINT)|(ACK<<TWEA)|(1<<TWEN);
	  while(!(TWCR & (1<<TWINT))); 
	  while((TWSR)!= 0x60);       
	  
	  //Previously addressed with own SLA+W, 
	  //data has been received and ACK has been returned
	  TWCR= (1<<TWINT)|(ACK<<TWEA)|(1<<TWEN);
	  while(!(TWCR & (1<<TWINT)));
	  while((TWSR)!= 0x80);
	  
	  return TWDR;
}