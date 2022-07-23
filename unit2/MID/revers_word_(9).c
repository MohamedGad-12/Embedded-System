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

void back (char x[] ,int size);

int main(int argc, char *argv[]) {


	char x[100];
	printf("Enter The String (Your Name): ");
	fflush(stdin); fflush(stdout);
	gets(x);

	back(x , strlen(x));
	return 0;
}

void back (char x[] , int size){

	int c = size - 1;

	int count = 0;

	for (int i=c ; i>=0 ;i--){
		count++;
		if ( x[i] == ' '){
			for (int j = i; j<((count-1)+i);j++){
				printf("%c" , (x[j+1]));
				fflush(stdin); fflush(stdout);
			}
			printf(" ");
			count = 0;
		}
		if (i == 0){
			for (int j = i; j<(count+i);j++){
				printf("%c" , (x[j]));
				fflush(stdin); fflush(stdout);
			}
			count = 0;
		}

	}

}






