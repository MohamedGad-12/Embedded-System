#define F_CPU 8000000UL
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

void init ()
{
	MCUCR |= (0b01 << 0);

	GICR |= (1<<6);

	sei();
}


int main(void)
{
	init ();
	DDRD |= (1<<7);

	while(1){
		PORTD &= ~(1<<7);
		_delay_ms(1000);
	}
	return 0;
}

ISR(INT0_vect)
{
	PORTD |= (1<<7);
	_delay_ms(1000);
	
	GIFR |= (1<<6);
}
