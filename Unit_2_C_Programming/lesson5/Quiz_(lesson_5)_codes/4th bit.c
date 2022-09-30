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

	int x = 0 ;
	printf ("enter no:");
	fflush(stdin); fflush(stdout);
	scanf("%d" , &x);
	printf( "\nNumber of bits: %d \n" , binary(x));
	return 0;

}


int binary(int  n){

	static int count = 0;
	if(count == 3){
		printf("4th is %d \nthe Number: " ,(n % 2));
	}
	if(n == 0){
		return 0;

	}
	count++;
	binary(n/2);
	printf("%d " ,(n % 2));
	return count;
}



