/*
 * main.c
 *
 *  Created on: ??‏/??‏/????
 *      Author: *********
 */

#include "stdio.h"

int main(int argc, char *argv[]) {

	int m = 29;
	void* ab = &m;

	printf("Address of m: %p \n" , &m);
	fflush(stdin); fflush(stdout);

	printf("Value of m: %d \n" , m);
	fflush(stdin); fflush(stdout);

	printf("\nNow ab is assigned with the address of m.");
	ab = &m;
	printf("\nAddress of pointer ab: %p" , ab);
	printf("\nContent of pointer ab: %d \n" , *((int*)ab));

	printf("\nThe value of m assigned to 34 now.");
	m = 34 ;
	printf("\nAddress of pointer ab: %p" , ab);
	printf("\nContent of pointer ab: %d \n" , *((int*)ab));

	printf("\nThe pointer variable ab is assigned with the value 7 now.");
	(*(int*)ab) = 7;
	printf("\nAddress of pointer m: %p" , ab);
	printf("\nContent of pointer m: %d \n" , *((int*)ab));

	return 0 ;
}












