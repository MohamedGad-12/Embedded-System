/*
 * main.c
 *
 *  Created on: ??‏/??‏/????
 *      Author: *********
 */

#include "stdio.h"
#include "stdlib.h"

void main() {

	float a[100];
	int n = 0;
	float aver = 0;

	printf("Enter no. of data.\n");
	fflush(stdin); fflush(stdout);
	scanf("%d", &n);

	for (int i =0 ; i < n ; i++){
		printf("Enter %d: " , i+1 );
		fflush(stdin); fflush(stdout);
		scanf("%f", &a[i]);
	}

	aver = 0 ;
	for (int i = 0 ; i < n ; i++){
		aver = aver + a[i];
	}
	aver = aver/n;
	printf("The Average: %f \n" , aver);

}
