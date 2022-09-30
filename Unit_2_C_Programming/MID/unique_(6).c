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

	int a[100] = {0};
	int b[100] = {0};
	int n = 0;

	// Just for inserting inputs;
	printf("Enter size: ");
	fflush(stdin); fflush(stdout);
	scanf("%d" , &n);
	printf("Enter element: ");
	fflush(stdin); fflush(stdout);

	for (int i=0 ; i <n ; i++){
		scanf("%d" , &a[i]);
	}

	//Freq_Array.....
	for (int i=0 ; i < 100 ; i++){
		b[a[i]]++;
	}

	// just for print;
	printf("The unique: ");
	for (int i=0 ; i <100 ; i++){
		if (b[a[i]] == 1){
			printf("%d ",a[i]);
		}
	}

	// slove of: zero will increase in freq arr as arr initial = 0;
	if( (b[0]- (100-n)) == 1 ){
		printf("%d ", 0);
	}

	return 0;
}



