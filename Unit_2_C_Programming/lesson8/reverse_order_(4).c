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

int main(int argc, char *argv[]) {

	int n[15]; int size;
	int* p_n = n;

	//insert size;
	printf("Please Enter Size (MAX 15):");
	fflush(stdin); fflush(stdout);
	scanf("%d" , &size);

	printf("\nPlease Enter %d Elements.\n\n" ,size);
	fflush(stdin); fflush(stdout);

	for(int i=0 ; i<size ; i++){
		printf("Elements - %d:" , (i+1));
		fflush(stdin); fflush(stdout);
		scanf("%d" , p_n );
		p_n++;
	}

	//print reverse
	printf("\nReverse:\n");
	for(int i=size ; i>0 ; i--){
		p_n--;
		printf("Elements - %d: %d \n" , (i+1) , *p_n);
	}
	return 0;
}







