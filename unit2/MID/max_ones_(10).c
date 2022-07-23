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

int binary(int n);

int max = 0 ;
int count = 0;

int main(int argc, char *argv[]) {


	int n = 0;


	printf("Enter Number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d" , &n);

	printf("the max number of ones between two zeros: %d", binary(n));

	return 0;
}


int binary(int  n){

	//base case
	if(n == 0){
		if(count > max){
			max = count;
		}
		return 0;
	}

	if((n%2) == 0){
		if(count > max){
			max = count;
		}
		count = 0;
	}

	if((n%2) == 1)
		count++;

	binary(n/2);
	return max;
}



