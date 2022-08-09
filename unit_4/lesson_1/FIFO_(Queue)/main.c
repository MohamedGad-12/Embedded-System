/*Eng.Mohamed Gamal*/

#include "fifo.h"

#define size 5
element_type buffer [size];

int main(){

	fifo test;
	char input[5];
	element_type temp;

	fifo_init(&test ,buffer , size );

	for (int i =0 ; i< size ; i++){
		Mprint("Enter the (%d) element: \n" , i+1);
		gets(input);
		fifo_enqueue(&test,atoi(input));
	}

	print(&test);

	Mprint("===========================\n");

	fifo_dequeue(&test, &temp);
	fifo_dequeue(&test, &temp);
	fifo_dequeue(&test, &temp);
	print(&test);

	Mprint("===========================\n");
	fifo_enqueue(&test, 15);
	fifo_enqueue(&test, 4);
	fifo_enqueue(&test, 20);
	fifo_enqueue(&test, 7);
	fifo_enqueue(&test, 8);
	fifo_enqueue(&test, 9);
	print(&test);

	Mprint("===========================\n");
	fifo_dequeue(&test, &temp);
	fifo_dequeue(&test, &temp);
	fifo_dequeue(&test, &temp);
	fifo_dequeue(&test, &temp);
	fifo_dequeue(&test, &temp);
	fifo_dequeue(&test, &temp);
	print(&test);

	Mprint("===========================\n");


	return 0;
}
