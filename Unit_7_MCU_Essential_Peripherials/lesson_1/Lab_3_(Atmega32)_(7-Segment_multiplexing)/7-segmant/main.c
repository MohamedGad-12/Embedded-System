#define F_CPU 8000000UL
#include "MemMap.h"
#include <util//delay.h>

static unsigned char seven_segment[] = {0b0000,0b0001,0b0010,0b0011,0b0100,0b0101,0b0110,0b0111,0b1000,0b1001};

void init ()
{
	DDRC |= 0xFF;
}

int main(void)
{
	//int flag = 0;
	int i;
	init ();
	
	while(1){
		
		for (i = 0 ;i < 10 ; i++){
			RESET_BIT(PORTC,0b1111,4);
			SET_BIT(PORTC,seven_segment[i],4);
			SET_BIT(PORTC,1,3);
			_delay_ms(200);
			SET_BIT(PORTC,1,2);
			_delay_ms(200);
		}

			
		}
		_delay_ms(100);

	
	return 0;
}


