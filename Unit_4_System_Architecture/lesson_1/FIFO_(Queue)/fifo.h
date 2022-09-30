/*Eng.Mohamed Gamal*/

#ifndef fifo_H_
#define fifo_H_

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
	element_type* tail;
	unsigned int length;
	unsigned int count;
}fifo;


typedef enum {

	fifo_no_error,
	fifo_null,

	fifo_empty,
	fifo_not_empty,

	fifo_full,
	fifo_not_full,

}buffer_status;


buffer_status fifo_init (fifo* fo , element_type* buf, unsigned int length);
buffer_status fifo_enqueue (fifo* fo , element_type item);
buffer_status fifo_dequeue (fifo* fo , element_type* item);
buffer_status fifo_check_full (fifo* fo);
void print (fifo* fo);



#endif /* fifo_H_ */
