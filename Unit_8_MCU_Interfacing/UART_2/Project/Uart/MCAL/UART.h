/*Eng. Mohamed Gamal*/

#ifndef UART_H_
#define UART_H_

//-----------------------------
//Includes
//-----------------------------
#include "MemMap.h"
#include <stdint.h>
#include <avr/io.h>

/*
* ===============================================
* APIs Supported by "MCAL UART DRIVER"
* ===============================================
*/

void MCAL_UART_Init();
void MCAL_UART_Send (uint8_t Data);
uint8_t MCAL_UART_Receive ();
//================================//
void MCAL_UART_SendString(char *data);
char* MCAL_UART_ReceiveString();

#endif /* UART_H_ */