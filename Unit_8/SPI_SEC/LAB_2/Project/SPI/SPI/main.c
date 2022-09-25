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


void execute (unsigned char cmd , unsigned char Data) {
	
	PORTB &= ~(1 << SS);
	SPDR = cmd;
	while(!(READ_BIT(SPSR,1,SPIF)));
	SPDR = Data;
	while(!(READ_BIT(SPSR,1,SPIF)));
	PORTB |= (1 << SS);
	
}

int main(void)
{
	unsigned char counter = 0;
	unsigned char D1 = 0;
	unsigned char D2 = 0;
	unsigned char index_display = 8;
	SPI_Master_INIT();
	execute(0x09, 0xFF);
	execute(0x0A, 0xFF);
	execute(0x0B, 0xF7);
	execute(0x0C, 0x01);
	
	while (1)
	{
		
		while(D1 < 10)
		{
		for (counter = 0; counter <= 9; counter++){
		execute(index_display,D1);
		}
		D1++;
		_delay_ms(500);
		}
		
		
		for (int i = 0; i <= 9; i++){
		execute(index_display,D2);
		execute((index_display-1),1);
		}
		D2++;
		


		while( (D1==10) && (D2==10)){
		_delay_ms(500);
		execute(index_display,0);
		execute((index_display-1),2);
		}
		
		_delay_ms(500);
		
	}
}

