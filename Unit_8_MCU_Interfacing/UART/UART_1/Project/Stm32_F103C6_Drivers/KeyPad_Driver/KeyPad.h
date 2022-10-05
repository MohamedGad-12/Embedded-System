/*Eng. Mohamed Gamal*/

#ifndef KEYPAD_DRIVER_KEYPAD_H_
#define KEYPAD_DRIVER_KEYPAD_H_

#include "stm32f103x6.h"
#include "Stm32F_103C6_Gpio_Driver.h"

#define R0 GPIOx_PIN0
#define R1 GPIOx_PIN1
#define R2 GPIOx_PIN2
#define R3 GPIOx_PIN3

#define C0 GPIOx_PIN4
#define C1 GPIOx_PIN5
#define C2 GPIOx_PIN6
#define C3 GPIOx_PIN7


#define KEYPAD_PORT   GPIOB

void Keypad_init();
char Keypad_getkey();

#endif /* KEYPAD_DRIVER_KEYPAD_H_ */
