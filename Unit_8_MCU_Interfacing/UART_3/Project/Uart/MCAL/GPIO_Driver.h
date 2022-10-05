/*Eng. Mohamed Gamal*/

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "MemMap.h"
#include <stdint.h>
//#include <avr/io.h>

//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct
{
	volatile uint8_t PinNumber;     //@ref GPIO_PINs to select the pin
	volatile uint8_t MODE;			//@ref GPIO_MODE to select the mode
	
}GPIOx_Config_t;

//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref GPIO_PINs
#define GPIOx_PIN0   ((uint8_t)0x01)
#define GPIOx_PIN1   ((uint8_t)0x02)
#define GPIOx_PIN2   ((uint8_t)0x04)
#define GPIOx_PIN3   ((uint8_t)0x08)
#define GPIOx_PIN4   ((uint8_t)0x10)
#define GPIOx_PIN5   ((uint8_t)0x20)
#define GPIOx_PIN6   ((uint8_t)0x40)
#define GPIOx_PIN7   ((uint8_t)0x80)
#define GPIOx_Full   ((uint8_t)0xFF)

//@ref GPIO_MODE
#define Output           1
#define input_PU         0
#define input_floating   2

//@ref GPIO_PIN_State
#define GPIO_Pin_set                1
#define GPIO_Pin_reset              0

/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_GPIO_Pin_Init(uint8_t* GPIOx, uint8_t pin_number ,uint8_t MODE);
void MCAL_GPIO_Init(uint8_t* GPIOx,uint8_t MODE);
void MCAL_GPIO_DeInit(uint8_t* GPIOx);

uint8_t MCAL_GPIO_ReadPin(uint8_t* GPIOx, uint8_t pin_number);
uint8_t MCAL_GPIO_ReadPort (uint8_t* GPIOx);

void MCAL_GPIO_WritePin(uint8_t* GPIOx , uint8_t pin_number , uint8_t Value);
void MCAL_GPIO_WritePort(uint8_t* GPIOx , uint8_t Value);

void MCAL_GPIO_TogglePin(uint8_t* GPIOx, uint8_t pin_number);

#endif /* GPIO_DRIVER_H_ */