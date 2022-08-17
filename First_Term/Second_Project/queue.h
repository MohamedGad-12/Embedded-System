//Eng.Mohamed Gamal

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <conio.h>
#include <string.h>

#define Mprint(...)  { fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}

/*---------------------------*/

#define size 100

//used type
struct Sstd{
	char first[50];
	char last[50];
	float gpa;
	int C_ID[5];
	int S_ID;
}student[size];

/*---------------------------*/

#define element_type struct Sstd

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
buffer_status fifo_check_full (fifo* fo);


#endif /* QUEUE_H_ */
