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

void binary(int n);

int main(int argc, char *argv[]) {

	int x = 0 ;
	printf ("Enter The Number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d" , &x);
	printf( "The Reverse Number: ");
	binary(x);
	return 0;

}


void binary(int  n){

	if(n == 0){
		return;

	}
	printf("%d" ,(n % 10));
	binary(n/10);
}



