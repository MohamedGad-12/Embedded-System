/*Eng. Mohamed Gamal*/

#ifndef APP_LAYER_CALCULATOR_H_
#define APP_LAYER_CALCULATOR_H_

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

void divide(char op1[], char op2[]);
void multiplay(char op1[], char op2[]);
void subtract(char op1[], char op2[]);
void sum(char op1[], char op2[]);

#endif /* APP_LAYER_CALCULATOR_H_ */