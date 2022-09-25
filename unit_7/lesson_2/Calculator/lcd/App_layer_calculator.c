/*Eng. Mohamed Gamal*/

#include "lcd.h"
#include "App_layer_calculator.h"
#include <string.h>
#include <stdlib.h>

void sum (char op1[], char op2[]){
	LCD_GOTO_XY(2,0);
	dipaly_number(atol(op1) + atol(op2));
}

void subtract (char op1[], char op2[]){
	LCD_GOTO_XY(2,0);
	dipaly_number(atol(op1)-atol(op2));
}

void multiplay (char op1[], char op2[]){	
	LCD_GOTO_XY(2,0);
	dipaly_number(atol(op1)*atol(op2));
}

void divide (char op1[], char op2[]){
	float total = ( atof(op1) / atof(op2) );
	LCD_GOTO_XY(2,0);
	dipaly_real_number(total);
}

