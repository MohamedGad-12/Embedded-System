/*
 * main.c
 *
 *  Created on: ??‏/??‏/????
 *      Author: *********
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

struct Sdis {

	float real;
	float comp;

};

struct Sdis sum (struct Sdis a , struct Sdis b);

int main(int argc, char *argv[]) {


	struct Sdis a;
   	struct Sdis b;

	printf("Enter 1st Complex Number.\n");
	fflush(stdin); fflush(stdout);
	printf("Enter Real Part: ");
	fflush(stdin); fflush(stdout);
	scanf("%f" , &a.real);
	printf("Enter Imaginary Part: ");
	fflush(stdin); fflush(stdout);
	scanf("%f" , &a.comp);

	printf("\nEnter 2nd Complex Number.\n");
	fflush(stdin); fflush(stdout);
	printf("Enter Real Part: ");
	fflush(stdin); fflush(stdout);
	scanf("%f" , &b.real);
	printf("Enter Imaginary Part: ");
	fflush(stdin); fflush(stdout);
	scanf("%f" , &b.comp);


	printf("\nTotal = %f + %f i ",sum(a,b).real,sum(a,b).comp);

	return 0;

}

struct Sdis sum (struct Sdis a , struct Sdis b){

	struct Sdis s;
	s.real = a.real + b.real;
	s.comp = a.comp + b.comp;

	return s;
}








