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

void sq(int n[] ,int szie);

int main(int argc, char *argv[]) {

	int n [100];
	int size;
	printf("Please Enter Size:");
	fflush(stdin); fflush(stdout);
	scanf("%d" , &size);

	printf("Please Elements:");
	fflush(stdin); fflush(stdout);

	for(int i=0 ; i<size ; i++){
		scanf("%d" , &n[i] );
	}

	sq(n,size);

	return 0;
}

void sq(int n[] , int size){

	for(int i=(size-1) ; i>=0 ; i--){
		printf("%d " , n[i]);
	}

}







