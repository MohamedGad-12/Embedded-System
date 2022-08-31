#define F_CPU 8000000UL
#include "MemMap.h"
#include <util//delay.h>


void init ()
{


	RESET_BIT(DDRD,1,0);
	SET_BIT(PORTD,1,0);
	
	SET_BIT(DDRD,1,7);
	SET_BIT(DDRD,1,6);
	SET_BIT(DDRD,1,5);
	SET_BIT(DDRD,1,4);
	

}

int main(void)
{
	int flag = 0;
	init ();
	
	while(1){

		if ( READ_BIT(PIND,1,0) == 1) {
			
			if (flag == 0) {
			TOGGLE_BIT(PORTD,1,7);
			flag++;
			_delay_ms(100);
			}
						
			if (flag == 1) {
			TOGGLE_BIT(PORTD,1,6);
			flag++;
			_delay_ms(100);
			}
						
			if (flag == 2) {
			TOGGLE_BIT(PORTD,1,5);
			flag++;
			_delay_ms(100);
			}
						
			if (flag == 3) {
			SET_BIT(PORTD,1,4);
			_delay_ms(1000);
			RESET_BIT(PORTD,1,4);
			_delay_ms(1000);
			flag=0;
			}
			 
		}
		_delay_ms(100);

	}
	return 0;
}


