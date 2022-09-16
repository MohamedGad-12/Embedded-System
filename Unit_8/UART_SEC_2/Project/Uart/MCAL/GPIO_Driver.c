/*Eng. Mohamed Gamal*/

#include "GPIO_Driver.h"
#include <stdint.h>

//===============APIs================================================//

/**================================================================
 * @Fn              - MCAL_GPIO_Pin_Init
 * @brief           - initialized the GPIOx PINy according to specified parameters
 * @param [in]      - GPIOx:      Pointer to Address of selected GPIO Port
 * @param [in]      - pin_number: pin_number of selected port
 * @param [in] 		- MODE:       (Output, input_PullUp_inputFloating)  
 * @retval          - none
 * Note             - none
 *================================================================ */

void MCAL_GPIO_Pin_Init(uint8_t* GPIOx, uint8_t pin_number ,uint8_t MODE){
	
	if(MODE == Output)
	{
		//output Mode
		( (*(GPIOx-1)) |= (1<<pin_number) );
	}
	else
	{
		//Input Mode
		( (*(GPIOx-1)) &= ~(1<<pin_number) );
		//1- input pull_up
		if (MODE == input_PU){
			( (*(GPIOx)) |= (1<<pin_number) ) ;
			GPIO_SFIOR &= ~(1<<2);   //Pin_2 in SFIOR register: PUD->Pull-up disable
			// set 1 -> diasble pull_up
			// set 0 -> enable pull_up
		}
		//2- FLoting input
		else if (MODE == input_floating)
		{
			((*(GPIOx)) &= ~(1<<pin_number) );
		}
	}
}


/**================================================================
 * @Fn              - MCAL_GPIO_Init
 * @brief           - initialized the GPIOx according to specified parameters
 * @param [in]      - GPIOx: Pointer to Address of selected GPIO Port
 * @param [in] 		- MODE: (Output, input_PullUp_inputFloating)  
 * @retval          - none
 * Note             - none
 *================================================================ */

void MCAL_GPIO_Init(uint8_t* GPIOx,uint8_t MODE) {
	if(MODE == Output)
	{
		//output Mode
		( (*(GPIOx-1)) = (GPIOx_Full) );
	}
	else
	{
		//Input Mode
		( (*(GPIOx-1)) = (0x00) );
		//1- input pull_up
		if (MODE == input_PU){
			( (*(GPIOx)) ) = (GPIOx_Full) ;
			GPIO_SFIOR &= ~(1<<2);
			
			//Pin_2 in SFIOR register: PUD->Pull-up disable
			// set 1 -> diasble pull_up
			// set 0 -> enable pull_up
		}
		//2- FLoting input
		else if (MODE == input_floating)
		{
			( (*(GPIOx)) = (0x00) );
		}
	}
}



/**================================================================
 * @Fn              - MCAL_GPIO_DeInit
 * @brief           - RESET the GPIOx Port
 * @param [in]      - GPIOx: Pointer to Address of selected GPIO Port
 * @retval          - none
 * Note             - none
 *================================================================ */
void MCAL_GPIO_DeInit(uint8_t* GPIOx){
	
	(*(GPIOx))   = (uint8_t)0x00;
	(*(GPIOx-1)) = (uint8_t)0x00;
}


/**================================================================
 * @Fn              - MCAL_GPIO_ReadPin
 * @brief           - READ the GPIOx PINy
 * @param [in]      - GPIOx:      Pointer to Address of selected GPIO Port
 * @param [in]      - pin_number: pin_number of selected port 
 * @retval          - uint8_t:    PIN_Status (1,0);
 * Note             - none
 *================================================================ */

uint8_t MCAL_GPIO_ReadPin(uint8_t* GPIOx , uint8_t pin_number){
	
	uint8_t tmp ;
	if ( ( (*(GPIOx-2) ) & (pin_number) ) != ((uint8_t)GPIO_Pin_reset) ){
		tmp = GPIO_Pin_set;
	}
	else
	{
		tmp = GPIO_Pin_reset;
	}
	return tmp;
}


/**================================================================
 * @Fn              - MCAL_GPIO_ReadPin
 * @brief           - READ the GPIOx Port
 * @param [in]      - GPIOx:   Pointer to Address of selected GPIO Port
 * @retval          - uint8_t: Port_Status;
 * Note             - none
 *================================================================ */

uint8_t MCAL_GPIO_ReadPort (uint8_t* GPIOx){
	uint8_t tmp ;
	tmp = (*(GPIOx-1));
	return tmp;
}


/**================================================================
 * @Fn              - MCAL_GPIO_WritePin
 * @brief           - WRITE the GPIOx PINy
 * @param [in]      - GPIOx:      Pointer to Address of selected GPIO Port
 * @param [in]      - pin_number: pin_number of selected port 
 * @param [in]      - Value:      The Value should be written 
 * @retval          - none
 * Note             - none
 *================================================================ */

void MCAL_GPIO_WritePin(uint8_t* GPIOx , uint8_t pin_number , uint8_t Value){
	
	if(Value != GPIO_Pin_reset){
		(*(GPIOx)) |= (GPIO_Pin_set<<pin_number);
	}
	else
	{
		(*(GPIOx)) &= ~(GPIO_Pin_set<<pin_number);
	}
}


/**================================================================
 * @Fn              - MCAL_GPIO_WritePort
 * @brief           - WRITE the GPIOx Port
 * @param [in]      - GPIOx:      Pointer to Address of selected GPIO Port
 * @param [in]      - Value:      The Value should be written 
 * @retval          - none
 * Note             - none
 *================================================================ */

void MCAL_GPIO_WritePort(uint8_t* GPIOx , uint8_t Value)
{
	(*(GPIOx)) = Value;
}


/**================================================================
 * @Fn              - MCAL_GPIO_TogglePin
 * @brief           - Toggle the GPIOx PINy
 * @param [in]      - GPIOx:  Pointer to Address of selected GPIO Port
 * @param [in]      - Pin_No: GPIOx PIN Number
 * @retval          - none
 * Note             - none
 *================================================================ */

void MCAL_GPIO_TogglePin(uint8_t* GPIOx, uint8_t pin_number){
	(*(GPIOx)) ^= (1<<pin_number);
}
