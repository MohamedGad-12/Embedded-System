//Eng. Mohamed Gamal

#include "Stm32F_103C6_Gpio_Driver.h"
#include "stm32f103x6.h"

uint8_t get_CRLH_position (uint16_t Pin_No){

	switch(Pin_No){

	case GPIOx_PIN0 :
		return 0;
		break;

	case GPIOx_PIN1 :
		return 4;
		break;

	case GPIOx_PIN2 :
		return 8;
		break;

	case GPIOx_PIN3 :
		return 12;
		break;

	case GPIOx_PIN4 :
		return 16;
		break;

	case GPIOx_PIN5 :
		return 20;
		break;

	case GPIOx_PIN6 :
		return 24;
		break;

	case GPIOx_PIN7 :
		return 28;
		break;

	case GPIOx_PIN8 :
		return 0;
		break;

	case GPIOx_PIN9 :
		return 4;
		break;

	case GPIOx_PIN10 :
		return 8;
		break;

	case GPIOx_PIN11 :
		return 12;
		break;

	case GPIOx_PIN12 :
		return 16;
		break;

	case GPIOx_PIN13 :
		return 20;
		break;

	case GPIOx_PIN14 :
		return 24;
		break;

	case GPIOx_PIN15 :
		return 28;
		break;

	}
	return 0;
}




/**================================================================
 * @Fn              - MCAL_GPIO_Init
 * @brief           - initialized the GPIOx PINy according to specified parameters in Pin_config
 * @param [in]      - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
 * @param [in]      - Pin_config: pointer to  GPIOx_Config_t struct that contains
 * 					  the configuration information for specified GPIO PIN
 * @retval          - none
 * Note             - Stm32F103C6 MCU Has GPIO (A,B,C,D,E) modules
 * 					  But LQFP48 has only GPIO A,B,Part of C\D exported as external PINS from MCU
 *================================================================ */
void MCAL_GPIO_Init(GPIO_typeDef* GPIOx , GPIOx_Config_t* Pin_config)
{
	volatile uint32_t* config = NULL;
	uint8_t PIN_Config = 0;

	config = (Pin_config->PinNumber < GPIOx_PIN8 )? &GPIOx->GPIOx_CRL : &GPIOx->GPIOx_CRH;

	(*config) &= ~(0xf << get_CRLH_position(Pin_config->PinNumber) );

	if ( ((Pin_config->MODE)== GPIO_MODE_AF_out_OD) ||  ((Pin_config->MODE)== GPIO_MODE_AF_out_PP) || ((Pin_config->MODE)== GPIO_MODE_out_OD) || ( (Pin_config->MODE)== GPIO_MODE_out_PP) )
	{

		PIN_Config =  ( (((Pin_config->MODE - 4)  << 2) | (Pin_config->OutPut_Speed)) & 0x0f);
	}
	else
	{
		if ( (Pin_config->MODE == GPIO_MODE_Analog_in) || (Pin_config->MODE == GPIO_MODE_Fl_in) )
		{
			PIN_Config =  ( (((Pin_config->MODE)  << 2) | 0x0 ) & 0x0f);
		}
		else if ( Pin_config->MODE == GPIO_MODE_AF_in)
		{
			PIN_Config =  ( (((GPIO_MODE_Fl_in)  << 2) | 0x0 ) & 0x0f);
		}
		else
		{
			PIN_Config =  ( (((GPIO_MODE_In_PU)  << 2) | 0x0 ) & 0x0f);

			if ( Pin_config->MODE == GPIO_MODE_In_PU)
			{
				GPIOx->GPIOx_ODR |= 1 << Pin_config->PinNumber;
			}
			else
			{
				GPIOx->GPIOx_ODR &= ~(1 << Pin_config->PinNumber);
			}
		}
	}
	(*config) |=  ( (PIN_Config) << get_CRLH_position(Pin_config->PinNumber) );
}




/**================================================================
 * @Fn              - MCAL_GPIO_DeInit
 * @brief           - Reset the GPIOx PINy according to specified parameters in Pin_config
 * @param [in]      - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
 * @retval          - none
 * Note             - Stm32F103C6 MCU Has GPIO (A,B,C,D,E) modules
 * 					  But LQFP48 has only GPIO A,B,Part of C\D exported as external PINS from MCU
 *================================================================ */
void MCAL_GPIO_DeInit(GPIO_typeDef* GPIOx) {

	/*
	// GPIOx->GPIOx_IDR (Read-Ony)
	GPIOx->GPIOx_BRR = 0x00000000;
	GPIOx->GPIOx_BSRR = 0x00000000;
	GPIOx->GPIOx_CRH = 0x44444444;
	GPIOx->GPIOx_CRL = 0x44444444;
	GPIOx->GPIOx_LCKR = 0x00000000;
	GPIOx->GPIOx_ODR = 0x00000000;
	 */
	if(GPIOx == GPIOA){
		RCC->RCC_APB2RSTR |= (1<<2);
		RCC->RCC_APB2RSTR &= ~(1<<2);
	}
	else if(GPIOx == GPIOB){
		RCC->RCC_APB2RSTR |= (1<<3);
		RCC->RCC_APB2RSTR &= ~(1<3);
	}
	else if(GPIOx == GPIOC){
		RCC->RCC_APB2RSTR |= (1<<4);
		RCC->RCC_APB2RSTR &= ~(1<<4);
	}
	else if(GPIOx == GPIOD){
		RCC->RCC_APB2RSTR |= (1<<5);
		RCC->RCC_APB2RSTR &= ~(1<<5);
	}
	else if(GPIOx == GPIOE){
		RCC->RCC_APB2RSTR |= (1<<6);
		RCC->RCC_APB2RSTR &= ~(1<<6);
	}
}




/**================================================================
 * @Fn              - MCAL_GPIO_ReadPin
 * @brief           - Read the GPIOx PINy according to specified parameters in Pin_config
 * @param [in]      - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
 * @param [in]      - Pin_No: GPIOx PIN Number
 * @retval          - uint8_t -> @ref GPIO_PIN_State
 * Note             - none
 *================================================================ */
uint8_t MCAL_GPIO_ReadPin(GPIO_typeDef* GPIOx , uint16_t Pin_No){

	uint8_t tmp ;
	if ( ( GPIOx->GPIOx_IDR & (Pin_No) ) != ((uint32_t)GPIO_Pin_reset) ){
		tmp = GPIO_Pin_set;
	}
	else
	{
		tmp = GPIO_Pin_reset;
	}
	return tmp;
}




/**================================================================
 * @Fn              - MCAL_GPIO_ReadPort
 * @brief           - Read the GPIOx according to specified parameters in Pin_config
 * @param [in]      - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
 * @retval          - uint16_t
 * Note             - none
 *================================================================ */
uint16_t MCAL_GPIO_ReadPort (GPIO_typeDef* GPIOx){

	uint16_t tmp ;
	tmp = (uint16_t)(GPIOx->GPIOx_IDR);
	return tmp;
}




/**================================================================
 * @Fn              - MCAL_GPIO_WritePin
 * @brief           - Write the GPIOx PINy according to specified parameters in Pin_config
 * @param [in]      - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
 * @param [in]      - Pin_No: GPIOx PIN Number
 * @param [in]      - Value: The Input Value
 * @retval          - none
 * Note             - none
 *================================================================ */
void MCAL_GPIO_WritePin(GPIO_typeDef* GPIOx , uint16_t Pin_No , uint8_t Value){

	if(Value != GPIO_Pin_reset){
		//GPIOx->GPIOx_ODR |= Pin_No;

		/* GPIOx_BSRR:
		Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
		These bits are write-only and can be accessed in Word mode only.
		0: No action on the corresponding ODRx bit
		1: Set the corresponding ODRx bit
		 */

		GPIOx->GPIOx_BSRR = (uint32_t)Pin_No;
	}
	else
	{
		//GPIOx->GPIOx_ODR &= ~(Pin_No);

		/* GPIOx_BRR:
		Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
		These bits are write-only and can be accessed in Word mode only.
		0: No action on the corresponding ODRx bit
		1: Reset the corresponding ODRx bit
		 */

		GPIOx->GPIOx_BRR = (uint32_t)Pin_No;
	}

}




/**================================================================
 * @Fn              - MCAL_GPIO_WritePort
 * @brief           - Write the GPIOx according to specified parameters in Pin_config
 * @param [in]      - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
 * @param [in]      - Value: The Input Value
 * @retval          - none
 * Note             - none
 *================================================================ */
void MCAL_GPIO_WritePort(GPIO_typeDef* GPIOx , uint16_t Value){

	GPIOx->GPIOx_ODR = (uint16_t)Value;
}




/**================================================================
 * @Fn              - MCAL_GPIO_TogglePin
 * @brief           - Toggle the GPIOx PINy according to specified parameters in Pin_config
 * @param [in]      - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
 * @param [in]      - Pin_No: GPIOx PIN Number
 * @retval          - none
 * Note             - none
 *================================================================ */
void MCAL_GPIO_TogglePin(GPIO_typeDef* GPIOx , uint16_t Pin_No){

	GPIOx->GPIOx_ODR ^= Pin_No;
}




/**================================================================
 * @Fn              - MCAL_GPIO_LockPin
 * @brief           - Lock the GPIOx PINy according to specified parameters in Pin_config
 * @param [in]      - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
 * @param [in]      - Pin_No: GPIOx PIN Number
 * @retval          - uint8_t -> @ref GPIO_Lock_State
 * Note             - none
 *================================================================ */
uint8_t MCAL_GPIO_LockPin(GPIO_typeDef* GPIOx , uint16_t Pin_No){

	/*
	 LOCK key writing sequence:
	Write 1
	Write 0
	Write 1
	Read 0
	Read 1 (this read is optional but confirms that the lock is active)
	 */

	uint32_t tmp = (1<<16);

	tmp |= Pin_No;

	//Write 1
	GPIOx->GPIOx_LCKR = tmp;

	//Write 0
	GPIOx->GPIOx_LCKR = Pin_No;

	//Write 1
	GPIOx->GPIOx_LCKR = tmp;

	//Read 0
	tmp = GPIOx->GPIOx_LCKR;

	//Read 1
	if( ((uint32_t)(GPIOx->GPIOx_LCKR & 1<<16)) ) {

		return GPIO_Pin_Locked;
	}
	else
	{

		return GPIO_Pin_unlocked;
	}



}

