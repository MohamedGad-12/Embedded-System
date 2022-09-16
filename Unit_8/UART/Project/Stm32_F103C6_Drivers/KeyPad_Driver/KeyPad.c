/*Eng. Mohamed Gamal*/

#include "KeyPad.h"
#include "stm32f103x6.h"
#include "Stm32F_103C6_Gpio_Driver.h"

int Key_padRow[] = {R0, R1, R2, R3}; //rows of the keypad
int Key_padCol[] = {C0, C1, C2, C3};//columns



void Keypad_init(){

	GPIOx_Config_t config;

	config.PinNumber = R0;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_50_MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &config);

	config.PinNumber = R1;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed =  GPIO_Out_max_Speed_50_MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &config);

	config.PinNumber = R2;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed =  GPIO_Out_max_Speed_50_MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &config);

	config.PinNumber = R3;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed =  GPIO_Out_max_Speed_50_MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &config);

	config.PinNumber = C0;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed =  GPIO_Out_max_Speed_50_MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &config);

	config.PinNumber = C1;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed =  GPIO_Out_max_Speed_50_MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &config);

	config.PinNumber = C2;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed =  GPIO_Out_max_Speed_50_MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &config);

	config.PinNumber = C3;
	config.MODE =  GPIO_MODE_out_PP;
	config.OutPut_Speed = GPIO_Out_max_Speed_50_MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &config);

	MCAL_GPIO_WritePort(KEYPAD_PORT, 0xFF);

}

char Keypad_getkey(){
	int i,j;
	for (i = 0; i < 4; i++){
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[0], 1);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[1], 1);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[2], 1);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[3], 1);

		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[i], 0);


		for(j = 0; j < 4; j++){
			if ( MCAL_GPIO_ReadPin(KEYPAD_PORT, Key_padRow[j]) == 0)
			{
				while( MCAL_GPIO_ReadPin(KEYPAD_PORT, Key_padRow[j]) == 0);
				switch(i){
					case (0):
						if (j == 0) return '7';
						else if (j == 1) return '4';
						else if (j == 2) return '1';
						else if (j == 3) return '?';
						break;
					case (1):
						if (j == 0) return '8';
						else if (j == 1) return '5';
						else if (j == 2) return '2';
						else if (j == 3) return '0';
						break;
					case (2):
						if (j == 0) return '9';
						else if (j == 1) return '6';
						else if (j == 2) return '3';
						else if (j == 3) return '=';
						break;
					case (3):
						if (j == 0) return '/';
						else if (j == 1) return '*';
						else if (j == 2) return '-';
						else if (j == 3) return '+';
						break;
				}
			}
		}
	}
	return 'A';
}
