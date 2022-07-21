/*
 * main.c
 *
 *  Created on: ??‏/??‏/????
 *      Author: *********
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int factorial(int n);

int main(int argc, char *argv[]) {

	int Number;

	printf("Enter first No: ");
	fflush(stdin); fflush(stdout);
	scanf("%d" , &Number);

	printf("Factorial is %d" , factorial(Number) );

	return 0;
}

int factorial(int n){

	//Base Case
	if (n==0 || n==1){
		return 1 ;
	}
	else{
		return ( n * factorial(n-1) );
	}
}



