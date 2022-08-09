

/*Eng.Mohamed Gamal*/

#include "lifo.h"

#define size 5
element_type buffer [size];

int main(){

	lifo test;
	char input[5];
	element_type temp;

	lifo_init(&test ,buffer , size );

	for (int i =0 ; i< size ; i++){
		Mprint("Enter the (%d) element: \n" , i+1);
		gets(input);
		lifo_add(&test,atoi(input));
	}

	print(&test);

	Mprint("===========================\n");

	lifo_get(&test, &temp);
	print(&test);

	Mprint("===========================\n");

	lifo_add(&test,15);
	lifo_add(&test,10);
	print(&test);

	Mprint("===========================\n");


	print_pop(&test);
	print(&test);

	Mprint("===========================\n");


	return 0;
}
