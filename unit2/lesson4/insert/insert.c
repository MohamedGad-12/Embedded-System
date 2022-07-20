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
	float el = 0 ;
	int pos = 0;


	printf("Enter no. of data.\n");
	fflush(stdin); fflush(stdout);
	scanf("%d", &n);

	for (int i =0 ; i < n ; i++){
		printf("Enter %d: " , i+1 );
		fflush(stdin); fflush(stdout);
		scanf("%f", &a[i]);
	}

	printf("Enter inserted element.\n");
	fflush(stdin); fflush(stdout);
	scanf("%f", &el);
	printf("Enter position inserted element.\n");
	fflush(stdin); fflush(stdout);
	scanf("%d", &pos);

	if (pos < 0){
		printf("Position can not be -ve.\n");
		fflush(stdin); fflush(stdout);
	}
	else if ( pos > 100){
		printf("Position out of range.\n");
		fflush(stdin); fflush(stdout);
	}
	else if ((pos>n) && (pos<100) && (pos>0)){
		a[pos-1] = el;
	}
	else{
		for (int i = n ; i >= (pos-1) ; i--){
			a[i+1] = a[i];
			if (i == pos-1){
				a[i] = el;
			}
		}
	}
	for (int i = 0 ; i < (n+1) ; i++){
		printf("%f " , a[i]);
		fflush(stdin); fflush(stdout);
	}
}
