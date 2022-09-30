#define F_CPU 8000000UL
#include "MemMap.h"
#include <util//delay.h>


void init ()
{


	RESET_BIT(DDRA,1,1); 
	RESET_BIT(PORTA,1,1);
	
	SET_BIT(DDRB,1,1);

	RESET_BIT(DDRA,1,7);
	RESET_BIT(PORTA,1,7);
	
	SET_BIT(DDRB,1,7);

	SET_BIT(SFIOR,1,2);
}

void wait(unsigned int t)
{
	unsigned int i,j;
	for( i = 0; i < t ; i++)
		for( j = 0; j < 255 ; j++);
}

int main(void)
{
	init ();
	
	while(1){

		if ( READ_BIT(PINA,1,1) == 0) {
			TOGGLE_BIT(PORTB,1,1);
			while ( READ_BIT(PINA,1,1) == 0);
		}

		if ( READ_BIT(PINA,1,7) == 1) {
			TOGGLE_BIT(PORTB,1,7); 
			_delay_ms(50);
		}
		_delay_ms(10);

	}
	return 0;
}


