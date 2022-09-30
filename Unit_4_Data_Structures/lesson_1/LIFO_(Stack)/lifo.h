/* Eng.Mohamed Gamal */

#ifndef LIFO_H_
#define LIFO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <conio.h>

#define Mprint(...)  { fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}
//used type
#define element_type uint8_t

typedef struct {
	element_type* head;
	element_type* base;
	unsigned int length;
	unsigned int count;
}lifo;


typedef enum {

	lifo_no_error,
	lifo_null,

	lifo_empty,
	lifo_not_empty,

	lifo_full,
	lifo_not_full,
}buffer_status;


buffer_status lifo_init (lifo* fo , element_type* buf, unsigned int length);
buffer_status lifo_add (lifo* fo , element_type item);
buffer_status lifo_get (lifo* fo , element_type* item);
buffer_status lifo_check_full (lifo* fo);
void print (lifo* fo);
void print_pop (lifo* fo);


#endif /* LIFO_H_ */
