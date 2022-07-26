/*
 * main.c
 *
 *  Created on: ??‏/??‏/????
 *      Author: *********
 */

#include "stdio.h"
#include "string.h"

char g_n[100];
char* n (char a[] , int size);

int main(int argc, char *argv[]) {

	char a[100];
	printf("Enter The String: ");
	fflush(stdin); fflush(stdout);
	gets(a);
	printf("Reverse of the string is: %s" , (n (a ,strlen(a))));

	return 0 ;
}
char* n (char a[] , int size){

	static int count = 0;
	int index = size-1;

	if(size == 0)
		return g_n;

	g_n[index] = a[count];
	count++;
	n( a , (size-1));

	return g_n;
}









