/*
 * main.c
 *
 *  Created on: ??‏/??‏/????
 *      Author: *********
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void main() {

	char a[100];
	char  c;   int sum =0;

	printf("Enter string: \n");
	fflush(stdin); fflush(stdout);
	gets(a);

	printf("Enter the char: \n");
	fflush(stdin); fflush(stdout);
	scanf("%c" , &c);

	for (int i =0 ; i < strlen(a)  ; i++){
			if (a[i] == c){
				sum++;
			}
	}
	printf("freq of %c : %d " , c , sum);
}
