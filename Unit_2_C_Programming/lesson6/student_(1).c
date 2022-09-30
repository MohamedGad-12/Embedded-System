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

struct Sinfo {

	char name [100];
	int roll;
	float mark;

} student;

int main(int argc, char *argv[]) {

	printf("Enter Your Name: ");
	fflush(stdin); fflush(stdout);
	gets(student.name);

	printf("Enter Roll Number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d" , &student.roll);

	printf("Enter Marks: ");
	fflush(stdin); fflush(stdout);
	scanf("%f" , &student.mark);

	printf("\n");

	printf("Name: %s" ,student.name );
	printf("\nRoll: %d"  , student.roll );
	printf("\nMarks: %f" ,student.mark );

	return 0;

}








