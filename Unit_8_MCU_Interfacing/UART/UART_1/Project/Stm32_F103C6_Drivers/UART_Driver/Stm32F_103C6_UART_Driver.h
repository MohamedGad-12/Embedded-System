//Eng. Mohamed Gamal

#ifndef UART_DRIVER_STM32F_103C6_UART_DRIVER_H_
#define UART_DRIVER_STM32F_103C6_UART_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "stm32f103x6.h"
#include "Stm32F_103C6_Gpio_Driver.h"


//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct {

	uint8_t  USART_Mode;            //@ref  USART_Mode


	uint32_t  BaudRate;			    //@ref  BaudRate


	uint8_t  Payload_Lenght;	    //@ref  Payload_Lenght


	uint8_t  Parity;			    //@ref  Parity


	uint8_t  StopBits;			    //@ref  StopBits


	uint8_t  HwFlowCtl;			    //@ref  HwFlowCtl


	uint8_t  IRQ_Enable;			 //@ref  IRQ_Enable


	void(* P_IRQ_CallBack)(void);	 //set the c Function which will be called once IRQ Happened

}USART_Config;

//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref  USART_Mode
#define USART_RX           	           (uint32_t)(1<<2)
#define USART_TX			           (uint32_t)(1<<3)
#define USART_TX_RX			           ((uint32_t)(1<<2 | 1<<3))


 //@ref  BaudRate
#define USART_BaudRate_2400           	2400
#define USART_BaudRate_9600           	9600
#define USART_BaudRate_19200           	19200
#define USART_BaudRate_57600           	57600
#define USART_BaudRate_115200           115200
#define USART_BaudRate_230400          	230400
#define USART_BaudRate_460800           460800
#define USART_BaudRate_921600          	921600
#define USART_BaudRate_2250000          2250000
#define USART_BaudRate_4500000          4500000


 //@ref  Payload_Lenght
#define USART_Payload_Lenght_8B       	(uint32_t)(0)
#define USART_Payload_Lenght_9B			(uint32_t)(1<<12)


//@ref  Parity
#define USART_Parity_NONE              (uint32_t)(0)
#define USART_Parity_EVEN 			   ((uint32_t)1<<10)
#define USART_Parity_ODD 			   ((uint32_t)(1<<10 | 1<<9))


//@ref  StopBits
#define USART_StopBits_Half        	    (uint32_t)(1<<12)
#define USART_StopBits_1   		        (uint32_t)(0)
#define USART_StopBits_1_Half 		    (uint32_t)(3<<12)
#define USART_StopBits_2			    (uint32_t)(2<<12)


//@ref  HwFlowCtl
#define USART_HwFlowCtl_NONE        	 (uint32_t)(0)
#define USART_HwFlowCtl_RTS 		     ((uint32_t)1<<8)
#define USART_HwFlowCtl_CTS 		     ((uint32_t)1<<9)
#define USART_HwFlowCtl_CTS_RTS			 ((uint32_t)(1<<8 | 1<<9))


 //@ref  IRQ_Enable
#define USART_IRQ_Enable_NONE        	 (uint32_t)(0)
#define USART_IRQ_Enable_TXEIE 		     (uint32_t)(1<<7)   //Transmit data register empty
#define USART_IRQ_Enable_TCIE	         (uint32_t)(1<<6)	//Transmission Complete
#define USART_IRQ_Enable_RXNEIE			 (uint32_t)(1<<5)	//Received data ready to be read & Overrun Error Detected
#define USART_IRQ_Enable_PEIE			 (uint32_t)(1<<8)	// parity error


//=======================================================================================================================================//


enum polling_mechism {
	polling_Enable,
	polling_Disable
};


// USARTDIV = fclk / (16 * Baudrate)
// DIV_Mantissa = Integer Part (USARTDIV)
// DIV_Fraction = ( USARTDIV - DIV_Mantissa ) * 16
// USARTDIV_MUL100 =
// uint32((100 *fclk ) / (16 * Baudrate) == (25 *fclk ) / (4* Baudrate) )
// DIV_Mantissa_MUL100 = Integer Part (USARTDIV ) * 100
// DIV_Mantissa = Integer Part (USARTDIV )
// DIV_Fraction = (( USARTDIV_MUL100 - DIV_Mantissa_MUL100 ) * 16 ) / 100

#define USARTDIV(_PCLK_, _BAUD_)            (uint32_t) (_PCLK_/(16 * _BAUD_ ))
#define USARTDIV_MUL100(_PCLK_, _BAUD_)		(uint32_t) ((25 * _PCLK_) / (4 *_BAUD_))
#define Mantissa_MUL100(_PCLK_, _BAUD_)		(uint32_t) (USARTDIV(_PCLK_, _BAUD_) * 100)
#define Mantissa(_PCLK_, _BAUD_)			(uint32_t) (USARTDIV(_PCLK_, _BAUD_) )
#define DIV_Fraction(_PCLK_, _BAUD_)		(uint32_t) (((USARTDIV_MUL100(_PCLK_, _BAUD_) - Mantissa_MUL100(_PCLK_, _BAUD_) )* 16 ) / 100)
#define UART_BRR_Register(_PCLK_, _BAUD_)	(( Mantissa (_PCLK_, _BAUD_) ) <<4 )|( (DIV_Fraction(_PCLK_, _BAUD_)) & 0xF )



//=======================================================================================================================================//



/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/


void MCAL_UART_Init(UART_typeDef* USARTx ,USART_Config* Config);
void MCAL_UART_DeInit(UART_typeDef* USARTx);

void MCAL_UART_GPIO_Set_Pins(UART_typeDef* USARTx);

void MCAL_UART_SendData(UART_typeDef* USARTx, uint16_t* pTxBuffer ,enum polling_mechism pollingEN);
void MCAL_UART_ReceiveData(UART_typeDef* USARTx, uint16_t* pRxBuffer ,enum polling_mechism pollingEN);

void MCAL_UART_WAIT_TC(UART_typeDef* USARTx);




#endif /* UART_DRIVER_STM32F_103C6_UART_DRIVER_H_ */
