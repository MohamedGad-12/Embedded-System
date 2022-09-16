//Eng. Mohamed Gamal

#include <Stm32F_103C6_EXIT_Driver.h>
#include "stm32f103x6.h"
#include "Stm32F_103C6_Gpio_Driver.h"


//======================================================
// Generic Macros
//======================================================
#define AFIO_EXIT_MApping(x)  (  (x == GPIOA)? 0:\
								 (x == GPIOB)? 1:\
								 (x == GPIOC)? 2:\
								 (x == GPIOD)? 3:0 )
//======================================================


//======================================================
// Generic pointers
//======================================================

void (* G_Call_Back[15])(void);

//======================================================



//======================================================
// Generic Functions
//======================================================

void Enable(uint16_t IRQ)
{
	switch(IRQ){
	case 0:
		EXIT_IRQ0_NIVC_Enable();
		break;
	case 1:
		EXIT_IRQ1_NIVC_Enable();
		break;
	case 2:
		EXIT_IRQ2_NIVC_Enable() ;
		break;
	case 3:
		EXIT_IRQ3_NIVC_Enable();
		break;
	case 4:
		EXIT_IRQ4_NIVC_Enable();
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		EXIT_IRQ5_9_NIVC_Enable() ;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		EXIT_IRQ10_15_NIVC_Enable();
		break;
	}

}

//==============================================================================================//

void Disable(uint16_t IRQ)
{
	switch(IRQ){
	case 0:
		EXIT_IRQ0_NIVC_Disable();
		break;
	case 1:
		EXIT_IRQ1_NIVC_Disable();
		break;
	case 2:
		EXIT_IRQ2_NIVC_Disable() ;
		break;
	case 3:
		EXIT_IRQ3_NIVC_Disable();
		break;
	case 4:
		EXIT_IRQ4_NIVC_Disable();
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		EXIT_IRQ5_9_NIVC_Disable() ;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		EXIT_IRQ10_15_NIVC_Disable();
		break;
	}

}

//==============================================================================================//

void Update_Exit(Exit_Config_t* EXIT_config){

	//1- pin GPIO configuration as Alternative input -> floating input
	GPIOx_Config_t Pin_config;
	Pin_config.PinNumber = EXIT_config->Exit_pin.Exit_Port_PinNumber;
	Pin_config.MODE =  GPIO_MODE_AF_in;
	MCAL_GPIO_Init(EXIT_config->Exit_pin.Exit_Port, &Pin_config);

	//======================================================

	//2- AFIO select the  EXIT LINE FROM A,B,C,D Lines

	uint8_t AFIO_EXTICR_index = EXIT_config->Exit_pin.Exit_pin_Number / 4;

	uint8_t AFIO_EXTICR_position = (EXIT_config->Exit_pin.Exit_pin_Number % 4) * 4;

	//clear bits
	AFIO->AFIO_EXTICR[AFIO_EXTICR_index] &= ~( 0xF << AFIO_EXTICR_position );

	//set bits
	AFIO->AFIO_EXTICR[AFIO_EXTICR_index] |= ((AFIO_EXIT_MApping(EXIT_config->Exit_pin.Exit_Port) &0xF) << AFIO_EXTICR_position );

	//======================================================

	//3- select trigger case

	EXIT->EXTI_RTSR	&= ~(1 << EXIT_config->Exit_pin.Exit_pin_Number);
	EXIT->EXTI_FTSR &= ~(1 << EXIT_config->Exit_pin.Exit_pin_Number);

	if (EXIT_config->Exit_Trigger == rising_Trigger)
	{
		EXIT->EXTI_RTSR	|= (1 << EXIT_config->Exit_pin.Exit_pin_Number);
	}
	else if (EXIT_config->Exit_Trigger == falling_Trigger)
	{
		EXIT->EXTI_FTSR |= (1 << EXIT_config->Exit_pin.Exit_pin_Number);

	}
	else if (EXIT_config->Exit_Trigger == RisingAndFalling_Trigger)
	{
		EXIT->EXTI_RTSR	|= (1 << EXIT_config->Exit_pin.Exit_pin_Number);
		EXIT->EXTI_FTSR |= (1 << EXIT_config->Exit_pin.Exit_pin_Number);
	}

	//======================================================

	//4- Handling IRQ Call_Back
	G_Call_Back[EXIT_config->Exit_pin.Exit_pin_Number] =  EXIT_config->Call_back;

	//======================================================

	//5- Enable EXIT

	if(EXIT_config->Exit_Enable ==  EXIT_IRQ_Enable )
	{
		EXIT->EXTI_IMR |= (1<<EXIT_config->Exit_pin.Exit_pin_Number);
		Enable(EXIT_config->Exit_pin.Exit_pin_Number);
	}
	else
	{
		EXIT->EXTI_IMR &= ~(1<<EXIT_config->Exit_pin.Exit_pin_Number);
		Disable(EXIT_config->Exit_pin.Exit_pin_Number);
	}

	//======================================================


}

//EXIT0
void EXTI0_IRQHandler(void) {

	//This bit is set when the selected edge event arrives on the external interrupt line.
	//This bit is cleared by writing a ‘1’ into the bit.
	EXIT->EXTI_PR |= (1<<0);

	G_Call_Back[0]();
}

//EXIT1
void EXTI1_IRQHandler(void) {

	EXIT->EXTI_PR |= (1<<1);

	G_Call_Back[1]();
}

//EXIT2
void EXTI2_IRQHandler(void) {

	EXIT->EXTI_PR |= (1<<2);

	G_Call_Back[2]();
}

//EXIT3
void EXTI23_IRQHandler(void) {

	EXIT->EXTI_PR |= (1<<3);

	G_Call_Back[3]();
}

//EXIT4
void EXTI4_IRQHandler(void) {

	EXIT->EXTI_PR |= (1<<4);

	G_Call_Back[4]();
}

//EXIT5
void EXTI9_5_IRQHandler(void) {

	if(EXIT->EXTI_PR & 1<<5) { EXIT->EXTI_PR |= (1<<5); G_Call_Back[5]();}
	if(EXIT->EXTI_PR & 1<<6) { EXIT->EXTI_PR |= (1<<6); G_Call_Back[6]();}
	if(EXIT->EXTI_PR & 1<<7) { EXIT->EXTI_PR |= (1<<7); G_Call_Back[7]();}
	if(EXIT->EXTI_PR & 1<<8) { EXIT->EXTI_PR |= (1<<8); G_Call_Back[8]();}
	if(EXIT->EXTI_PR & 1<<9) { EXIT->EXTI_PR |= (1<<9); G_Call_Back[9]();}

}

//EXIT6
void EXTI15_10_IRQHandler(void) {

	if(EXIT->EXTI_PR & 1<<10) { EXIT->EXTI_PR |= (1<<10); G_Call_Back[10]();}
	if(EXIT->EXTI_PR & 1<<11) { EXIT->EXTI_PR |= (1<<11); G_Call_Back[11]();}
	if(EXIT->EXTI_PR & 1<<12) { EXIT->EXTI_PR |= (1<<12); G_Call_Back[12]();}
	if(EXIT->EXTI_PR & 1<<13) { EXIT->EXTI_PR |= (1<<13); G_Call_Back[13]();}
	if(EXIT->EXTI_PR & 1<<14) { EXIT->EXTI_PR |= (1<<14); G_Call_Back[14]();}
	if(EXIT->EXTI_PR & 1<<15) { EXIT->EXTI_PR |= (1<<15); G_Call_Back[15]();}
}

//==============================================================================================//


/**================================================================
 * @Fn              - EXIT_GPIO_Init
 * @brief           - initialize the External Interrupt GPIOx PINy according to specified parameters in Exit_Config_t
 * @param [in]      - EXIT_config: configure External Interrupt
 * @retval          - none
 * Note             - Stm32F103C6 MCU Has GPIO (A,B,C,D,E) modules
 * 					  But LQFP48 has only GPIO A,B,Part of C\D exported as external PINS from MCU
 *================================================================ */
void MCAL_EXIT_GPIO_Init   (Exit_Config_t* EXIT_config){

	Update_Exit(EXIT_config);
}


/**================================================================
 * @Fn              - EXIT_GPIO_DEInit
 * @brief           - Reset the External Interrupt GPIOx PINy according to specified parameters in Exit_Config_t
 * @retval          - none
 * Note             - none
 *================================================================ */
void MCAL_EXIT_GPIO_DEInit (){

	//Reset EXIT_Registers
	EXIT->EXTI_EMR   =  0x00000000;
	EXIT->EXTI_FTSR  =  0x00000000;
	EXIT->EXTI_IMR   =  0x00000000;
	EXIT->EXTI_RTSR  =  0x00000000;
	EXIT->EXTI_SWIER =  0x00000000;
	//reset: clear by writing one
	EXIT->EXTI_PR    =  0xFFFFFFFF;

	//Reset NIVC in Cortex-M3
	EXIT_IRQ0_NIVC_Disable();
	EXIT_IRQ1_NIVC_Disable();
	EXIT_IRQ2_NIVC_Disable();
	EXIT_IRQ3_NIVC_Disable();
	EXIT_IRQ4_NIVC_Disable();
	EXIT_IRQ5_9_NIVC_Disable();
	EXIT_IRQ10_15_NIVC_Disable();
}


/**================================================================
 * @Fn              - EXIT_GPIO_Update
 * @brief           - Update the External Interrupt GPIOx PINy according to specified parameters in Exit_Config_t
 * @param [in]      - EXIT_config: configure External Interrupt
 * @retval          - none
 * Note             - none
 *================================================================ */
void MCAL_EXIT_GPIO_Update (Exit_Config_t* EXIT_config){
	Update_Exit(EXIT_config);
}


