/*Eng. Mohamed Gamal*/

#include "lcd.h"
#include "keypad.h"
#include "App_layer_calculator.h"
#include <string.h>
#include <stdlib.h>

char op1[16] = {};
char op2[16] = {};
char op = '\0';

void reset() {
	
	for (int i = 0 ; i < 16 ; i++){
		op1[i] = '\0';
		op2[i] = '\0';
	}
	
}

int main()
{
	int flag = 0;
	int count = 0;
	
	LCD_INIT();
	Keypad_init();
	_delay_ms(50);
	unsigned char key_pressed;
	while(1){
		key_pressed = Keypad_getkey();
		switch(key_pressed){
			case 'A':
				break;
			case '?':
				LCD_clear_screen();
				reset();
				op = '\0';
				count = 0;
				flag = 0;
				break;
			default:
				LCD_WRITE_CHAR(key_pressed);
				if (key_pressed == '+' || key_pressed == '-'  || key_pressed == '*' || key_pressed =='/') {
					flag = 1;
					op = key_pressed;
					count = 0;
				}				
				else if(flag == 0){
					op1[count] = key_pressed;
					count++;
				}
				else if(flag == 1 && (key_pressed != '=')){
					op2[count] = key_pressed;
					count++;
				}
				if ((key_pressed == '=') && (op == '+') ){
					sum(op1,op2);
					op = '\0';
					count = 0;
					flag = 0;
				}
				if ((key_pressed == '=') && (op == '-') ){
					subtract(op1,op2);
					op = '\0';
					count = 0;
					flag = 0;
				}
				if ((key_pressed == '=') && (op == '*') ){
					multiplay(op1,op2);
					op = '\0';
					count = 0;
					flag = 0;
				}
				if ((key_pressed == '=') && (op == '/') ){
					divide(op1,op2);
					op = '\0';
					count = 0;
					flag = 0;
				}												
				break;
		}
	}
}


