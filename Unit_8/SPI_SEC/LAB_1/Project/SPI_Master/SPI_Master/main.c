//Eng. Mohamed Gamal

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

#define  SS     4
#define  SCK    7
#define  MISO   6
#define  MOSI   5

#define SET_BIT(ADDRESS,VALUE,BIT_NUMBER)      ADDRESS |= (VALUE << BIT_NUMBER)
#define RESET_BIT(ADDRESS,VALUE,BIT_NUMBER)    ADDRESS &=~(VALUE << BIT_NUMBER)
#define TOGGLE_BIT(ADDRESS,VALUE,BIT_NUMBER)   ADDRESS ^= (VALUE << BIT_NUMBER)
#define READ_BIT(ADDRESS,VALUE,BIT_NUMBER)     ((ADDRESS & (VALUE << BIT_NUMBER))>> BIT_NUMBER)


static unsigned char seven_segment[] = {0b0000,0b0001,0b0010,0b0011,0b0100,0b0101,0b0110,0b0111,0b1000,0b1001,
										0b00010000,0b00010001,0b00010010,0b00010011,0b00010100,0b00010101,0b00010110,0b00010111,0b00011000,0b00011001,
										0b00100000 };

void SPI_Master_INIT(){
	
	SET_BIT(DDRB,1,SS);
	SET_BIT(DDRB,1,SCK);
	SET_BIT(DDRB,1,MOSI);
	
	RESET_BIT(DDRB,1,MISO);
	
	
	/*
	SET_BIT(SPCR,1,SPE);
	SET_BIT(SPCR,1,SPIE);
	SET_BIT(SPCR,1,MSTR);
	SET_BIT(SPCR,1,SPR0);
	*/

	SPCR = (1<<SPE) | (1<<MSTR) |  (1<<SPR0) ;
}


unsigned char Master_transmit (unsigned char Data) {
	
	SPDR = Data;
	while(!(READ_BIT(SPSR,1,SPIF)));
	return SPDR;	
}

int main(void)
{
	unsigned char Data = 0;
	DDRA = 0xFF;
	SPI_Master_INIT();
	
	for (Data = 0 ; Data <= 20 ; Data++)
	{
	_delay_ms(1000);
	PORTA = Master_transmit(seven_segment[Data]);
	}
}

