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

float sq(float n);

int main(int argc, char *argv[]) {

	float n = 0 ;
	printf("Please Enter Number:");
	fflush(stdin); fflush(stdout);
	scanf("%f" , &n);
	printf("The Square Root: %f",sq(n));

	return 0;
}

float sq(float n){

	return sqrt(n);
}







