/*
 * main.c
 *
 *  Created on: ??‏/??‏/????
 *      Author: محمد
 */

#include "stdio.h"
#include "stdlib.h"

int main (int argc, char *argv){

	int x = 0 ;
	int y = 0 ;

	printf ("Enter Two Number.\n");

	fflush(stdin); fflush(stdout);

	scanf("%d",&x);

	scanf("%d",&y);

	x = x + y;
	y = x - y;
	x = x - y;

	printf ("%d", x);
	fflush(stdin); fflush(stdout);
	printf ("\n");
	printf ("%d", y);

	return 0;
}

