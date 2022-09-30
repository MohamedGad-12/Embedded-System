/*
 * main.c
 *
 *  Created on: ??‏/??‏/????
 *      Author: *********
 */

#include "stdio.h"
#include "stdlib.h"

void main() {

	float a[2][2];
	float b[2][2];
	float c[2][2];

	printf("Enter elements of first array.\n");
	fflush(stdin); fflush(stdout);

	for (int i =0 ; i < 2 ; i++){
		for (int j =0 ; j < 2 ; j++){
			printf("Enter a%d%d: " , i ,j );
			fflush(stdin); fflush(stdout);
			scanf("%f", &a[i][j]);
		}
	}

	printf("Enter elements of second array.\n");
	fflush(stdin); fflush(stdout);
	for (int i =0 ; i < 2 ; i++){
		for (int j =0 ; j < 2 ; j++){
			printf("Enter b%d%d: " , i ,j );
			fflush(stdin); fflush(stdout);
			scanf("%f", &b[i][j]);
		}
	}


	for (int i =0 ; i < 2 ; i++){
		for (int j =0 ; j < 2 ; j++){

			c[i][j] = a[i][j] + b[i][j];
		}
	}

	printf("The sum: \n");
	fflush(stdin); fflush(stdout);
	for (int i =0 ; i < 2 ; i++){
		for (int j =0 ; j < 2 ; j++){

			printf ("%f \t" , c[i][j]);
		}
		printf ("\n");
	}

}
