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

	void check();
	check();
	printf("\n");
	return 0;

}

void check(){

	char c;
	if ((c = getchar()) != '\n')
		check();
	printf("%c" , c);
}



