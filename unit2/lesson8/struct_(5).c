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

struct Semp {

	char name[100];
	int id;

};

int main(int argc, char *argv[]) {

	struct Semp e[100];      //array of struct;
	struct Semp(* n[100]);	 //array of pointer (Type_struct);
	int size;				 //The Size;
	struct Semp** p = n;	 //	Pointer to array of pointers;

	printf("Enter Number Of Employees: ");
	fflush(stdin); fflush(stdout);
	scanf("%d" , &size);

	// insert Data
	for(int i=0 ; i<size ; i++){
		printf("\nEnter Name Of Employee No_%d: " , (i+1));
		fflush(stdin); fflush(stdout);
		scanf("%s" , (e[i].name));
		printf("Enter ID Of Employee No_%d: " , (i+1));
		fflush(stdin); fflush(stdout);
		scanf("%d" , &(e[i].id)  );
	}

	// pointers to struct
	for(int i=0 ; i<size ; i++){
		n[i] = (&e[i]);
	}

	// print data
	for(int i=0 ; i<size ; i++){
		printf("\nName Of Employee No_%d: %s\n" , (i+1), (**p).name);
		fflush(stdin); fflush(stdout);
		printf("ID Of Employee No_%d: %d\n\n" , (i+1), (**p).id);
		fflush(stdin); fflush(stdout);
		p++;
	}

	return 0;
}








