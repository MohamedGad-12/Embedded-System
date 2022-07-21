/*
 * main.c
 *
 *  Created on: ??‏/??‏/????
 *      Author: *********
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

float power( float n , int p);

int main(int argc, char *argv[]) {

	float n; int p;

	printf("Enter the number: ");
	fflush(stdin); fflush(stdout);
	scanf("%f" , &n);

	printf("Enter the power: ");
	fflush(stdin); fflush(stdout);
	scanf("%d" , &p);

	printf( "The Result: %f" , power(n,p) );

	return 0;
}

float power( float n , int p){

	//Base Case
	if (p == 0){
		return 1;
	}
	else{
		return  n * (power(n ,p-1));
	}
}



