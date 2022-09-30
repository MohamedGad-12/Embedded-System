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

	printf("Enter string: \n");
	fflush(stdin); fflush(stdout);
	gets(a);

	printf("reverse is: ");
	for (int i = strlen(a)-1 ; i >= 0  ; i--){
		printf("%c" , a[i]);
	}

}
