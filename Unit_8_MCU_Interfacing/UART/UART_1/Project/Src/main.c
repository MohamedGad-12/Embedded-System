//Eng. Mohamed Gamal

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32f103x6.h"
#include "Stm32F_103C6_Gpio_Driver.h"
#include <Stm32F_103C6_EXIT_Driver.h>
#include "Stm32F_103C6_UART_Driver.h"
#include "LCD.h"
#include "KeyPad.h"

//===============================================================================//

uint16_t Data ;

//===============================================================================//

//Clock Enable
void clock_init()
{
	//Bit 2 IOPAEN: I/O port A clock enable
	GPIOA_Clock_Enable();

	//Bit 3 IOPBEN: I/O port B clock enable
	GPIOB_Clock_Enable();

	// Enable Alternative Function
	AFIO_Clock_Enable();

}

//===============================================================================//

//Delay
void wait (unsigned int t) {

	unsigned int i,j;
	for(i = 0 ; i < t ; i++)
		for(j = 0 ; j < 255 ; j++);
}

//===============================================================================//

void Mohamed_USART_IRQ_CallBack(void) {


	MCAL_UART_ReceiveData(USART1, &Data ,polling_Disable);

	MCAL_UART_SendData(USART1, &Data ,polling_Enable);
}

//===============================================================================//


int main(void) {

	clock_init();
	wait(25);

	//	Baudrate = 115200
	//	Parity = None
	//	Payload_width = 8 bit
	//	Stop = 1
	//	Flow Control = None

	USART_Config x;
	x.BaudRate       = USART_BaudRate_115200;
	x.HwFlowCtl      = USART_HwFlowCtl_NONE;

	x.IRQ_Enable	 = USART_IRQ_Enable_RXNEIE;           // USART_IRQ_Enable_RXNEIE
	x.P_IRQ_CallBack = Mohamed_USART_IRQ_CallBack;        // Mohamed_USART_IRQ_CallBack;


	x.Parity         = USART_Parity_NONE;
	x.Payload_Lenght = USART_Payload_Lenght_8B;
	x.StopBits       = USART_StopBits_1;
	x.USART_Mode     = USART_TX_RX;

	MCAL_UART_Init(USART1,&x);
	MCAL_UART_GPIO_Set_Pins(USART1);


	while(1){

		//MCAL_UART_ReceiveData(USART1, &Data ,polling_Enable);

		//MCAL_UART_SendData(USART1, &Data ,polling_Enable);
	}

}







