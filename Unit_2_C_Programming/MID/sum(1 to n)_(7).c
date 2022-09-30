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

int sum(int n);

int main(int argc, char *argv[]) {

	int n = 0 ;
	printf("Please Enter Number:");
	fflush(stdin); fflush(stdout);
	scanf("%d" , &n);
	printf("The Sum From 1 to %d: %d", n ,sum(n));

	return 0;

}

int sum(int n){

	static int count = 1;
	static int end = 0;

	if(n == 0)
		return 0;
	else{
		end += count;
		n--;
		count++;
		sum(n);
		return end;
	}
}







