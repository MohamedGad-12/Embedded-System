/*
 * main.c
 *
 *  Created on: ??‏/??‏/????
 *      Author: *********
 */

#include "stdio.h"

int main(int argc, char *argv[]) {

	char a = 'A';
	int count = 1;
	char* Pa = &a;

	printf("Capital Alphabets: \n");
	printf("%c\t" , *Pa);
	fflush(stdin); fflush(stdout);

	while (1){

		count++;
		((*Pa)++);

		printf("%c\t" , *Pa);
		fflush(stdin); fflush(stdout);

		if(count == 4){
			count = 0;
			printf("\n");
		}
		if( (*Pa) == 'Z' ){
			*Pa = *Pa + 6;
			printf("\nSmall Alphabets: \n");
			count = 0;
		}
		if( (*Pa) == 'z' ){
			break;
		}
	}
	return 0 ;
}












