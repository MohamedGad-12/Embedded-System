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

#define PI 3.14159
#define area(R) (PI)*(R)*(R)



int main(int argc, char *argv[]) {

	float r;
	printf("Enter Radius: ");
	fflush(stdin); fflush(stdout);
	scanf("%f" , &r);

	printf("Area = %f" , area(r));

	return 0;

}









