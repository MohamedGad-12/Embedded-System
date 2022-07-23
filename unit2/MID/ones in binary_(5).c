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

int binary(int n);

int main(int argc, char *argv[]) {


	int n = 0;


	printf("Enter Number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d" , &n);

	printf("number of ones in binary: %d", binary(n));
	
	return 0;
}


int binary(int  n){

	static int count = 0;
	if(n == 0){
		return 0;

	}
	if((n%2) == 1)
		count++;

	binary(n/2);
	return count;
}



