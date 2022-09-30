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

int check(char m[] ,char n[]);

int main(int argc, char *argv[]) {

	char m[100];
	char n[100];

	printf("Enter string:");
	fflush(stdin); fflush(stdout);
	scanf("%s" , m);

	printf("Enter name:");
	fflush(stdin); fflush(stdout);
	scanf("%s" , n);

	if (check(m,n))
		printf("same");
	else
		printf("not same");


	return 0;
}

int check(char m[] ,char n[]){

	if (stricmp(m,n))
		return 0;
	else
		return 1;

}



