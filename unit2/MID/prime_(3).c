/*
 * main.c
 *
 *  Created on: ??‏/??‏/????
 *      Author: *********
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void interval(int first , int second);
int isprime(int no);

int main(int argc, char *argv[]) {

	int first; int second;

	printf("Enter first No: ");
	fflush(stdin); fflush(stdout);
	scanf("%d" , &first);

	printf("Enter second No: ");
	fflush(stdin); fflush(stdout);
	scanf("%d" , &second);

	interval(first, second);

	return 0;
}

int isprime(int no){
	for (int i=2 ; i<=(no/2) ; i++){
		if (no%i == 0){
			return 0;
		}
	}
	return 1 ;
}

void interval(int first , int second){
	for (int i=first ; i<second ; i++){
		if (isprime(i)){
			printf("%d \t" , i);
		}
	}
}


