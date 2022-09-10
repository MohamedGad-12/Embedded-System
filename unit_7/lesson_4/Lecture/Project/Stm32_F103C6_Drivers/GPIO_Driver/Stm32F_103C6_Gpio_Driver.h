//Eng. Mohamed Gamal

#ifndef GPIO_DRIVER_STM32F_103C6_GPIO_DRIVER_H_
#define GPIO_DRIVER_STM32F_103C6_GPIO_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "stm32f103x6.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct
{
	volatile uint16_t PinNumber;    //@ref GPIO_PINs to select the pin
	volatile uint8_t MODE;			//@ref GPIO_MODE to select the mode
	volatile uint8_t OutPut_Speed;	//@ref GPIO_OutPut_Speed to select the output speed

}GPIOx_Config_t;

//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref GPIO_PINs
#define GPIOx_PIN0   ((uint16_t)0x0001)
#define GPIOx_PIN1   ((uint16_t)0x0002)
#define GPIOx_PIN2   ((uint16_t)0x0004)
#define GPIOx_PIN3   ((uint16_t)0x0008)
#define GPIOx_PIN4   ((uint16_t)0x0010)
#define GPIOx_PIN5   ((uint16_t)0x0020)
#define GPIOx_PIN6   ((uint16_t)0x0040)
#define GPIOx_PIN7   ((uint16_t)0x0080)
#define GPIOx_PIN8   ((uint16_t)0x0100)
#define GPIOx_PIN9   ((uint16_t)0x0200)
#define GPIOx_PIN10  ((uint16_t)0x0400)
#define GPIOx_PIN11  ((uint16_t)0x0800)
#define GPIOx_PIN12  ((uint16_t)0x1000)
#define GPIOx_PIN13  ((uint16_t)0x2000)
#define GPIOx_PIN14  ((uint16_t)0x4000)
#define GPIOx_PIN15  ((uint16_t)0x8000)
#define GPIOx_Full   ((uint16_t)0xFFFF)

//@ref GPIO_MODE
#define GPIO_MODE_Analog_in   0x00000000u
#define GPIO_MODE_Fl_in   	  0x00000001u
#define GPIO_MODE_In_PU 	  0x00000002u
#define GPIO_MODE_In_PD 	  0x00000003u
#define GPIO_MODE_out_PP  	  0x00000004u
#define GPIO_MODE_out_OD      0x00000005u
#define GPIO_MODE_AF_out_PP   0x00000006u
#define GPIO_MODE_AF_out_OD   0x00000007u
#define GPIO_MODE_AF_in       0x00000008u

//@ref GPIO_OutPut_Speed
#define GPIO_Out_max_Speed_10_MHz    0x00000001u
#define GPIO_Out_max_Speed_2_MHz 	 0x00000002u
#define GPIO_Out_max_Speed_50_MHz 	 0x00000003u

//@ref GPIO_PIN_State
#define GPIO_Pin_set                1
#define GPIO_Pin_reset              0


//@ref GPIO_Lock_State
#define GPIO_Pin_Locked             1
#define GPIO_Pin_unlocked           0

/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_GPIO_Init(GPIO_typeDef* GPIOx , GPIOx_Config_t* Pin_config);
void MCAL_GPIO_DeInit(GPIO_typeDef* GPIOx);

uint8_t MCAL_GPIO_ReadPin(GPIO_typeDef* GPIOx , uint16_t Pin_No);
uint16_t MCAL_GPIO_ReadPort (GPIO_typeDef* GPIOx);

void MCAL_GPIO_WritePin(GPIO_typeDef* GPIOx , uint16_t Pin_No , uint8_t Value);
void MCAL_GPIO_WritePort(GPIO_typeDef* GPIOx , uint16_t Value);

void MCAL_GPIO_TogglePin(GPIO_typeDef* GPIOx , uint16_t Pin_No);

uint8_t MCAL_GPIO_LockPin(GPIO_typeDef* GPIOx , uint16_t Pin_No);

#endif /* GPIO_DRIVER_STM32F_103C6_GPIO_DRIVER_H_ */
