#include "Uart.h"

unsigned char string_buffer[100] = "Learn-in-depth:<Mohamed Gamal>";

void main(void)
{

	uart_send(string_buffer);

}