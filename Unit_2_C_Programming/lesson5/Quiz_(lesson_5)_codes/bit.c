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

int clear(int x,int b);

int main(int argc, char *argv[]) {

	int x;
	int b;

	printf("Enter number:");
	fflush(stdin); fflush(stdout);
	scanf("%d" , &x);

	printf("Enter bit position:");
	fflush(stdin); fflush(stdout);
	scanf("%d" , &b);

	printf("%d" ,clear (x,b));


	return 0;
}

int clear(int x ,int b){

	 x &= ~(1<<b);

	 return x;
}



