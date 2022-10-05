//Eng. Mohamed Gamal

#include "Stm32F_103C6_UART_Driver.h"
#include "stm32f103x6.h"
#include "Stm32F_103C6_RCC_Driver.h"
#include "Stm32F_103C6_Gpio_Driver.h"


//======================================================
// Generic Macros
//======================================================

USART_Config* G_Config = NULL;

//======================================================


//======================================================
// Generic Functions
//======================================================

//==============================================================================================//




//======================================================
// APIs
//======================================================


/**================================================================
 * @Fn              - MCAL_UART_Init
 * @brief           - initialize the USART according to specified parameters in USART_Config
 * @param [in]      - UART_typeDef:  USART Registers
 * @param [in]      - USART_Config:  configure USART
 * @retval          - none
 * Note             - none
 *================================================================ */


void MCAL_UART_Init(UART_typeDef* USARTx ,USART_Config* Config)
{
	uint32_t pclk , BRR;

	G_Config = Config;

	if (USARTx == USART1){
		USART1_Clock_Enable();
	}
	else if (USARTx == USART2){
		USART2_Clock_Enable();
	}
	else if (USARTx == USART3){
		USART3_Clock_Enable();
	}

	//Enable USART
	USARTx->USART_CR1 |= 1<<13;

	//Enable USART_Mode (TX,RX)
	USARTx->USART_CR1 |= Config->USART_Mode ;

	//Select Payload_Lenght (8B,9B)
	USARTx->USART_CR1 |= Config->Payload_Lenght ;

	//Select Parity_mode (none,even,odd)
	USARTx->USART_CR1 |= Config->Parity ;

	//Enable HwFlowCtl (RTS,CTS)
	USARTx->USART_CR3 |= Config->HwFlowCtl ;

	//Select BaudRate
	//PCLK_1 OR PCLK_2

	if (USARTx == USART1){
		pclk = 	MCAl_RCC_Get_PCLK2_Freq();
	}
	else
	{
		pclk = MCAl_RCC_Get_PCLK1_Freq();
	}

	BRR =  UART_BRR_Register(pclk, Config->BaudRate);
	USARTx->USART_BRR = BRR;



	//IRQ_Enable_Mode

	if(Config->IRQ_Enable != USART_IRQ_Enable_NONE){

		USARTx->USART_CR1 |= Config->IRQ_Enable;

		//Enable UART NIVC
		if (USARTx == USART1){
			UART1_IRQ37_NIVC_Enable;
		}
		else if (USARTx == USART2){
			UART2_IRQ38_NIVC_Enable;
		}
		else if (USARTx == USART3){
			UART3_IRQ39_NIVC_Enable;
		}

	}
}



/**================================================================
 * @Fn              - MCAL_UART_DeInit
 * @brief           - RESET the USART according to specified parameters in USART_Config
 * @param [in]      - UART_typeDef:  USART Registers
 * @retval          - none
 * Note             - none
 *================================================================ */
void MCAL_UART_DeInit(UART_typeDef* USARTx){

	if (USARTx == USART1){
		USART1_Clock_Disable();
		UART1_IRQ37_NIVC_Disable;
	}
	if (USARTx == USART2){
		USART2_Clock_Disable();
		UART2_IRQ38_NIVC_Disable;
	}
	if (USARTx == USART3){
		USART3_Clock_Disable();
		UART3_IRQ39_NIVC_Disable;
	}

}


/**================================================================
 * @Fn              - MCAL_UART_SendData
 * @brief           - RESET the USART according to specified parameters in USART_Config
 * @param [in]      - UART_typeDef:          USART Registers
 * @param [in]      - uint16_t:              transmission Buffer
 * @param [in]      - enum polling_mechism:  USART polling enable or disable
 * @retval          - none
 * Note             - none
 *================================================================ */

void MCAL_UART_SendData(UART_typeDef* USARTx, uint16_t* pTxBuffer ,enum polling_mechism  pollingEN)
{

	if( pollingEN  == polling_Enable)
		while( ! ( (USARTx->USART_SR) & (1<<7)) );


	if(G_Config->Payload_Lenght == USART_Payload_Lenght_9B){

		USARTx->USART_DR = ( (*pTxBuffer) & (uint16_t)0x1FF);

	}
	else
	{
		USARTx->USART_DR = ( (*pTxBuffer) & (uint8_t)0xFF);
	}

}





/**================================================================
 * @Fn              - MCAL_UART_WAIT_TC
 * @brief           - RESET the USART according to specified parameters in USART_Config
 * @param [in]      - UART_typeDef:          USART Registers
 * @retval          - none
 * Note             - Wait till transmit Complete
 *================================================================ */

void MCAL_UART_WAIT_TC(UART_typeDef* USARTx){

	while( ! ( (USARTx->USART_SR) & (1<<6)) );
}






/**================================================================
 * @Fn              - MCAL_UART_ReceiveData
 * @brief           - RESET the USART according to specified parameters in USART_Config
 * @param [in]      - UART_typeDef:          USART Registers
 * @param [in]      - uint16_t:              Receiving Buffer
 * @param [in]      - enum polling_mechism:  USART polling enable or disable
 * @retval          - none
 * Note             - none
 *================================================================ */

void MCAL_UART_ReceiveData(UART_typeDef* USARTx, uint16_t* pRxBuffer ,enum polling_mechism pollingEN)
{
	if( pollingEN  == polling_Enable)
		while( ! ( (USARTx->USART_SR) & (1<<5)) );



	// When the parity control is enabled,
	// the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit if M=0)
	// and parity is checked on the received data. This bit is set and cleared by software.
	// Once it is set, PCE is active after the current byte (in reception and in transmission).


	if(G_Config->Payload_Lenght == USART_Payload_Lenght_9B){

		if (G_Config->Parity == USART_Parity_NONE){


			(*(uint16_t*)pRxBuffer ) = (USARTx->USART_DR);
		}

		else
		{
			(*(uint16_t*)pRxBuffer ) = (USARTx->USART_DR & (uint8_t)0xFF);
		}


	}

	else
	{

		if (G_Config->Parity == USART_Parity_NONE){

			(*(uint16_t*)pRxBuffer ) = (USARTx->USART_DR);
		}

		else
		{
			(*(uint16_t*) pRxBuffer ) = (USARTx->USART_DR & (uint8_t)0x7F);
		}

	}
}





/**================================================================
 * @Fn              - MCAL_UART_GPIO_Set_Pins
 * @brief           - RESET the USART according to specified parameters in USART_Config
 * @param [in]      - UART_typeDef:          USART Registers
 * @retval          - none
 * Note             - Set UART PIns Based on GPIO_Configration
 *================================================================ */


void MCAL_UART_GPIO_Set_Pins(UART_typeDef* USARTx){


	GPIOx_Config_t uart_pin;

	if (USARTx == USART1){

		//PA9 as TX
		uart_pin.PinNumber = GPIOx_PIN9;
		uart_pin.MODE = GPIO_MODE_AF_out_PP;
		uart_pin.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
		MCAL_GPIO_Init(GPIOA, &uart_pin);

		//PA10 as RX
		uart_pin.PinNumber = GPIOx_PIN10;
		uart_pin.MODE = GPIO_MODE_AF_in;
		MCAL_GPIO_Init(GPIOA, &uart_pin);

		if(G_Config->HwFlowCtl == USART_HwFlowCtl_CTS || G_Config->HwFlowCtl == USART_HwFlowCtl_CTS_RTS){

			//PA11 as CTS
			uart_pin.PinNumber = GPIOx_PIN9;
			uart_pin.MODE = GPIO_MODE_Fl_in;
			MCAL_GPIO_Init(GPIOA, &uart_pin);

		}
		if(G_Config->HwFlowCtl == USART_HwFlowCtl_RTS || G_Config->HwFlowCtl == USART_HwFlowCtl_CTS_RTS){

			//PA12 as RTS
			uart_pin.PinNumber = GPIOx_PIN12;
			uart_pin.MODE = GPIO_MODE_AF_out_PP;
			uart_pin.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
			MCAL_GPIO_Init(GPIOA, &uart_pin);
		}
	}

	else if (USARTx == USART2){

		//PA2 as TX
		uart_pin.PinNumber = GPIOx_PIN2;
		uart_pin.MODE = GPIO_MODE_AF_out_PP;
		uart_pin.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
		MCAL_GPIO_Init(GPIOA, &uart_pin);

		//PA3 as RX
		uart_pin.PinNumber = GPIOx_PIN3;
		uart_pin.MODE = GPIO_MODE_AF_in;
		MCAL_GPIO_Init(GPIOA, &uart_pin);

		if(G_Config->HwFlowCtl == USART_HwFlowCtl_CTS || G_Config->HwFlowCtl == USART_HwFlowCtl_CTS_RTS){

			//PA0 as CTS
			uart_pin.PinNumber = GPIOx_PIN0;
			uart_pin.MODE = GPIO_MODE_Fl_in;
			MCAL_GPIO_Init(GPIOA, &uart_pin);

		}
		if(G_Config->HwFlowCtl == USART_HwFlowCtl_RTS || G_Config->HwFlowCtl == USART_HwFlowCtl_CTS_RTS){

			//PA1 as RTS
			uart_pin.PinNumber = GPIOx_PIN1;
			uart_pin.MODE = GPIO_MODE_AF_out_PP;
			uart_pin.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
			MCAL_GPIO_Init(GPIOA, &uart_pin);
		}
	}

	else if (USARTx == USART3){

		//PB10 as TX
		uart_pin.PinNumber = GPIOx_PIN10;
		uart_pin.MODE = GPIO_MODE_AF_out_PP;
		uart_pin.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
		MCAL_GPIO_Init(GPIOB, &uart_pin);

		//PB11 as RX
		uart_pin.PinNumber = GPIOx_PIN11;
		uart_pin.MODE = GPIO_MODE_AF_in;
		MCAL_GPIO_Init(GPIOB, &uart_pin);

		if(G_Config->HwFlowCtl == USART_HwFlowCtl_CTS || G_Config->HwFlowCtl == USART_HwFlowCtl_CTS_RTS){

			//PB13 as CTS
			uart_pin.PinNumber = GPIOx_PIN13;
			uart_pin.MODE = GPIO_MODE_Fl_in;
			MCAL_GPIO_Init(GPIOB, &uart_pin);

		}
		if(G_Config->HwFlowCtl == USART_HwFlowCtl_RTS || G_Config->HwFlowCtl == USART_HwFlowCtl_CTS_RTS){

			//PB14 as RTS
			uart_pin.PinNumber = GPIOx_PIN14;
			uart_pin.MODE = GPIO_MODE_AF_out_PP;
			uart_pin.OutPut_Speed = GPIO_Out_max_Speed_10_MHz;
			MCAL_GPIO_Init(GPIOB, &uart_pin);
		}
	}
}


//==============================================================================================//

/* USART1 global interrupt */
void USART1_IRQHandler (void) {

	G_Config->P_IRQ_CallBack();

}


/* USART2 global interrupt */
void USART2_IRQHandler (void) {

	G_Config->P_IRQ_CallBack();

}


/* USART3 global interrupt */
void USART3_IRQHandler (void) {

	G_Config->P_IRQ_CallBack();

}


//==============================================================================================//


