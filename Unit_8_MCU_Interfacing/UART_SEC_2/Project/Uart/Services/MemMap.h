/*Eng. Mohamed Gamal*/

#ifndef MEMOMAP_H_
#define MEMOMAP_H_

#include <stdint.h>

// macros to set , reset , toggle and read bits from pins
#define SET_BIT(ADDRESS,VALUE,BIT_NUMBER)      ADDRESS |= (VALUE << BIT_NUMBER)
#define RESET_BIT(ADDRESS,VALUE,BIT_NUMBER)    ADDRESS &=~(VALUE << BIT_NUMBER)
#define TOGGLE_BIT(ADDRESS,VALUE,BIT_NUMBER)   ADDRESS ^= (VALUE << BIT_NUMBER)
#define READ_BIT(ADDRESS,VALUE,BIT_NUMBER)     ((ADDRESS & (VALUE << BIT_NUMBER))>> BIT_NUMBER)

/*
// GPIO port A Registers
#define DDRA  *((volatile unsigned char *)(0x3A))
#define PORTA *((volatile unsigned char *)(0x3B))
#define PINA  *((volatile unsigned char *)(0x39))

// GPIO port B Registers
#define DDRB  *((volatile unsigned char *)(0x37))
#define PORTB *((volatile unsigned char *)(0x38))
#define PINB  *((volatile unsigned char *)(0x36))

// GPIO port C Registers
#define DDRC  *((volatile unsigned char *)(0x34))
#define PORTC *((volatile unsigned char *)(0x35))
#define PINC  *((volatile unsigned char *)(0x33))

// GPIO port D Registers
#define DDRD  *((volatile unsigned char *)(0x31))
#define PORTD *((volatile unsigned char *)(0x32))
#define PIND  *((volatile unsigned char *)(0x30))
*/
// Special Function I/O Register – SFIOR
#define GPIO_SFIOR  *((volatile unsigned char *)(0x50))


//BIG NOTE: Just address
#define portA (uint8_t*)0x3B
#define portB (uint8_t*)0x38
#define portC (uint8_t*)0x35
#define portD (uint8_t*)0x32

//=============================================================//

//UART Registers Values
#define UDR_V    *((volatile unsigned char *)(0x2C))
#define UCSRA_V  *((volatile unsigned char *)(0x2B))
#define UCSRB_V  *((volatile unsigned char *)(0x2A))
#define UBRRL_V  *((volatile unsigned char *)(0x29))
#define UBRRH_V  *((volatile unsigned char *)(0x40))
#define UCSRC_V  *((volatile unsigned char *)(0x40))

//=============================================================//


#endif /* MEMOMAP_H_ */