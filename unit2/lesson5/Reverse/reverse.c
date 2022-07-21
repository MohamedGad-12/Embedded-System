/*
 * main.c
 *
 *  Created on: ??‏/??‏/????
 *      Author: *********
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void reverse(char n[] , int size);

int main(int argc, char *argv[]) {

	char n[100];

	printf("Enter String: ");
	fflush(stdin); fflush(stdout);
	gets(n);

	reverse(n , strlen(n));

	return 0;
}

void reverse(char n[] , int size){

	//Base Case
	if (size == 0){
		return;
	}
	else{
		printf("%c" , (n[size - 1]) );
		fflush(stdin); fflush(stdout);
		reverse(n, size-1);
	}
}



