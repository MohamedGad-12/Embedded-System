//Eng. Mohamed Gamal

#ifndef EXIT_DRIVER_STM32F_103C6_EXIT_DRIVER_H_
#define EXIT_DRIVER_STM32F_103C6_EXIT_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include <stdint.h>
#include <stdlib.h>
#include "stm32f103x6.h"
#include "Stm32F_103C6_Gpio_Driver.h"


//-----------------------------
//User type definitions (structures)
//-----------------------------

//@ref EXIT_Mapping
typedef struct
{
	//@ref EXIT_pin_Number
	uint16_t          Exit_pin_Number;

	GPIO_typeDef*     Exit_Port;

	uint16_t          Exit_Port_PinNumber;

	uint8_t           Exit_Irq;

}EXIT_Mapping_t;



typedef struct
{
	//@ref EXIT_Mapping
	EXIT_Mapping_t  Exit_pin;

	//@ref Exit_Trigger
	uint8_t         Exit_Trigger;

	//@ref Exit_Enable
	uint8_t         Exit_Enable;

	void(* Call_back)(void);

}Exit_Config_t;





//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref EXIT_pin_Number
#define EXIT0    0
#define EXIT1    1
#define EXIT2    2
#define EXIT3    3
#define EXIT4    4
#define EXIT5    5
#define EXIT6    6
#define EXIT7    7
#define EXIT8    8
#define EXIT9    9
#define EXIT10   10
#define EXIT11   11
#define EXIT12   12
#define EXIT13   13
#define EXIT14   14
#define EXIT15   15
//===============================//

//@ref EXIT_Mapping
//EXIT0
#define EXIT0_A_PIN0  (EXIT_Mapping_t){EXIT0,GPIOA,GPIOx_PIN0,EXIT_IRQ0}
#define EXIT0_B_PIN0  (EXIT_Mapping_t){EXIT0,GPIOB,GPIOx_PIN0,EXIT_IRQ0}
#define EXIT0_C_PIN0  (EXIT_Mapping_t){EXIT0,GPIOC,GPIOx_PIN0,EXIT_IRQ0}
#define EXIT0_D_PIN0  (EXIT_Mapping_t){EXIT0,GPIOD,GPIOx_PIN0,EXIT_IRQ0}


//EXIT1
#define EXIT1_A_PIN1  (EXIT_Mapping_t){EXIT1,GPIOA,GPIOx_PIN1,EXIT_IRQ1}
#define EXIT1_B_PIN1  (EXIT_Mapping_t){EXIT1,GPIOB,GPIOx_PIN1,EXIT_IRQ1}
#define EXIT1_C_PIN1  (EXIT_Mapping_t){EXIT1,GPIOC,GPIOx_PIN1,EXIT_IRQ1}
#define EXIT1_D_PIN1  (EXIT_Mapping_t){EXIT1,GPIOD,GPIOx_PIN1,EXIT_IRQ1}


//EXIT2
#define EXIT2_A_PIN2  (EXIT_Mapping_t){EXIT2,GPIOA,GPIOx_PIN2,EXIT_IRQ2}
#define EXIT2_B_PIN2  (EXIT_Mapping_t){EXIT2,GPIOB,GPIOx_PIN2,EXIT_IRQ2}
#define EXIT2_C_PIN2  (EXIT_Mapping_t){EXIT2,GPIOC,GPIOx_PIN2,EXIT_IRQ2}
#define EXIT2_D_PIN2  (EXIT_Mapping_t){EXIT2,GPIOD,GPIOx_PIN2,EXIT_IRQ2}


//EXIT3
#define EXIT3_A_PIN3  (EXIT_Mapping_t){EXIT3,GPIOA,GPIOx_PIN3,EXIT_IRQ3}
#define EXIT3_B_PIN3  (EXIT_Mapping_t){EXIT3,GPIOB,GPIOx_PIN3,EXIT_IRQ3}
#define EXIT3_C_PIN3  (EXIT_Mapping_t){EXIT3,GPIOC,GPIOx_PIN3,EXIT_IRQ3}
#define EXIT3_D_PIN3  (EXIT_Mapping_t){EXIT3,GPIOD,GPIOx_PIN3,EXIT_IRQ3}


//EXIT4
#define EXIT4_A_PIN4  (EXIT_Mapping_t){EXIT4,GPIOA,GPIOx_PIN4,EXIT_IRQ4}
#define EXIT4_B_PIN4  (EXIT_Mapping_t){EXIT4,GPIOB,GPIOx_PIN4,EXIT_IRQ4}
#define EXIT4_C_PIN4  (EXIT_Mapping_t){EXIT4,GPIOC,GPIOx_PIN4,EXIT_IRQ4}
#define EXIT4_D_PIN4  (EXIT_Mapping_t){EXIT4,GPIOD,GPIOx_PIN4,EXIT_IRQ4}


//EXIT5
#define EXIT5_A_PIN5  (EXIT_Mapping_t){EXIT5,GPIOA,GPIOx_PIN5,EXIT_IRQ5_9}
#define EXIT5_B_PIN5  (EXIT_Mapping_t){EXIT5,GPIOB,GPIOx_PIN5,EXIT_IRQ5_9}
#define EXIT5_C_PIN5  (EXIT_Mapping_t){EXIT5,GPIOC,GPIOx_PIN5,EXIT_IRQ5_9}
#define EXIT5_D_PIN5  (EXIT_Mapping_t){EXIT5,GPIOD,GPIOx_PIN5,EXIT_IRQ5_9}


//EXIT6
#define EXIT6_A_PIN6  (EXIT_Mapping_t){EXIT6,GPIOA,GPIOx_PIN6,EXIT_IRQ5_9}
#define EXIT6_B_PIN6  (EXIT_Mapping_t){EXIT6,GPIOB,GPIOx_PIN6,EXIT_IRQ5_9}
#define EXIT6_C_PIN6  (EXIT_Mapping_t){EXIT6,GPIOC,GPIOx_PIN6,EXIT_IRQ5_9}
#define EXIT6_D_PIN6  (EXIT_Mapping_t){EXIT6,GPIOD,GPIOx_PIN6,EXIT_IRQ5_9}


//EXIT7
#define EXIT7_A_PIN7  (EXIT_Mapping_t){EXIT7,GPIOA,GPIOx_PIN7,EXIT_IRQ5_9}
#define EXIT7_B_PIN7  (EXIT_Mapping_t){EXIT7,GPIOB,GPIOx_PIN7,EXIT_IRQ5_9}
#define EXIT7_C_PIN7  (EXIT_Mapping_t){EXIT7,GPIOC,GPIOx_PIN7,EXIT_IRQ5_9}
#define EXIT7_D_PIN7  (EXIT_Mapping_t){EXIT7,GPIOD,GPIOx_PIN7,EXIT_IRQ5_9}


//EXIT8
#define EXIT8_A_PIN8  (EXIT_Mapping_t){EXIT8,GPIOA,GPIOx_PIN8,EXIT_IRQ5_9}
#define EXIT8_B_PIN8  (EXIT_Mapping_t){EXIT8,GPIOB,GPIOx_PIN8,EXIT_IRQ5_9}
#define EXIT8_C_PIN8  (EXIT_Mapping_t){EXIT8,GPIOC,GPIOx_PIN8,EXIT_IRQ5_9}
#define EXIT8_D_PIN8  (EXIT_Mapping_t){EXIT8,GPIOD,GPIOx_PIN8,EXIT_IRQ5_9}


//EXIT9
#define EXIT9_A_PIN9  (EXIT_Mapping_t){EXIT9,GPIOA,GPIOx_PIN9,EXIT_IRQ5_9}
#define EXIT9_B_PIN9  (EXIT_Mapping_t){EXIT9,GPIOB,GPIOx_PIN9,EXIT_IRQ5_9}
#define EXIT9_C_PIN9  (EXIT_Mapping_t){EXIT9,GPIOC,GPIOx_PIN9,EXIT_IRQ5_9}
#define EXIT9_D_PIN9  (EXIT_Mapping_t){EXIT9,GPIOD,GPIOx_PIN9,EXIT_IRQ5_9}


//EXIT10
#define EXIT10_A_PIN10  (EXIT_Mapping_t){EXIT10,GPIOA,GPIOx_PIN10,EXIT_IRQ10_15}
#define EXIT10_B_PIN10  (EXIT_Mapping_t){EXIT10,GPIOB,GPIOx_PIN10,EXIT_IRQ10_15}
#define EXIT10_C_PIN10  (EXIT_Mapping_t){EXIT10,GPIOC,GPIOx_PIN10,EXIT_IRQ10_15}
#define EXIT10_D_PIN10  (EXIT_Mapping_t){EXIT10,GPIOD,GPIOx_PIN10,EXIT_IRQ10_15}


//EXIT11
#define EXIT11_A_PIN11  (EXIT_Mapping_t){EXIT11,GPIOA,GPIOx_PIN11,EXIT_IRQ10_15}
#define EXIT11_B_PIN11  (EXIT_Mapping_t){EXIT11,GPIOB,GPIOx_PIN11,EXIT_IRQ10_15}
#define EXIT11_C_PIN11  (EXIT_Mapping_t){EXIT11,GPIOC,GPIOx_PIN11,EXIT_IRQ10_15}
#define EXIT11_D_PIN11  (EXIT_Mapping_t){EXIT11,GPIOD,GPIOx_PIN11,EXIT_IRQ10_15}


//EXIT12
#define EXIT12_A_PIN12  (EXIT_Mapping_t){EXIT12,GPIOA,GPIOx_PIN12,EXIT_IRQ10_15}
#define EXIT12_B_PIN12  (EXIT_Mapping_t){EXIT12,GPIOB,GPIOx_PIN12,EXIT_IRQ10_15}
#define EXIT12_C_PIN12  (EXIT_Mapping_t){EXIT12,GPIOC,GPIOx_PIN12,EXIT_IRQ10_15}
#define EXIT12_D_PIN12  (EXIT_Mapping_t){EXIT12,GPIOD,GPIOx_PIN12,EXIT_IRQ10_15}


//EXIT13
#define EXIT13_A_PIN13  (EXIT_Mapping_t){EXIT13,GPIOA,GPIOx_PIN13,EXIT_IRQ10_15}
#define EXIT13_B_PIN13  (EXIT_Mapping_t){EXIT13,GPIOB,GPIOx_PIN13,EXIT_IRQ10_15}
#define EXIT13_C_PIN13  (EXIT_Mapping_t){EXIT13,GPIOC,GPIOx_PIN13,EXIT_IRQ10_15}
#define EXIT13_D_PIN13  (EXIT_Mapping_t){EXIT13,GPIOD,GPIOx_PIN13,EXIT_IRQ10_15}


//EXIT14
#define EXIT14_A_PIN14  (EXIT_Mapping_t){EXIT14,GPIOA,GPIOx_PIN14,EXIT_IRQ10_15}
#define EXIT14_B_PIN14  (EXIT_Mapping_t){EXIT14,GPIOB,GPIOx_PIN14,EXIT_IRQ10_15}
#define EXIT14_C_PIN14  (EXIT_Mapping_t){EXIT14,GPIOC,GPIOx_PIN14,EXIT_IRQ10_15}
#define EXIT14_D_PIN14  (EXIT_Mapping_t){EXIT14,GPIOD,GPIOx_PIN14,EXIT_IRQ10_15}


//EXIT15
#define EXIT15_A_PIN15  (EXIT_Mapping_t){EXIT15,GPIOA,GPIOx_PIN15,EXIT_IRQ10_15}
#define EXIT15_B_PIN15  (EXIT_Mapping_t){EXIT15,GPIOB,GPIOx_PIN15,EXIT_IRQ10_15}
#define EXIT15_C_PIN15  (EXIT_Mapping_t){EXIT15,GPIOC,GPIOx_PIN15,EXIT_IRQ10_15}
#define EXIT15_D_PIN15  (EXIT_Mapping_t){EXIT15,GPIOD,GPIOx_PIN15,EXIT_IRQ10_15}
//===========================


//@ref Exit_Trigger
#define rising_Trigger              0
#define falling_Trigger             1
#define RisingAndFalling_Trigger    2

//@ref Exit_Enable
#define EXIT_IRQ_Enable             1
#define EXIT_IRQ_Disable            0


/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/
//initialize EXIT: {EXITx ,GPIOx ,GPIO_PIN ,EXIT_IRQx}, trigger and enable
void MCAL_EXIT_GPIO_Init   (Exit_Config_t* EXIT_config);
//Reset EXIT;
void MCAL_EXIT_GPIO_DEInit ();
//Update EXIT: {EXITx ,GPIOx ,GPIO_PIN ,EXIT_IRQx}, trigger and enable
void MCAL_EXIT_GPIO_Update (Exit_Config_t* EXIT_config);




#endif /* EXIT_DRIVER_STM32F_103C6_EXIT_DRIVER_H_ */
