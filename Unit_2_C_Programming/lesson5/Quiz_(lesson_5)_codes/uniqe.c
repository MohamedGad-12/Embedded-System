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

	int a[100];
	int b[100];
	int n = 0;

	for (int i =0 ; i <100 ; i++){
		a[i]=0;
		b[i]=0;
	}

	printf("Enter size: ");
	fflush(stdin); fflush(stdout);
	scanf("%d" , &n);
	printf("Enter element: ");
	fflush(stdin); fflush(stdout);

	for (int i=0 ; i <n ; i++){
		scanf("%d" , &a[i]);
	}

	for (int i=0 ; i <100 ; i++){
		b[a[i]]++;
	}
	
	printf("Uniqe Element: ");
	for (int i=0 ; i <100 ; i++){
		if (b[a[i]] == 1)
			printf("%d , ",a[i]);
	}
	if( (b[0]- (100-n)) == 1 ){
		printf("%d ", 0);
	}
	return 0;
}




