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

struct Sdis {

	int ft;
	float in;

};

struct Sdis itf (struct Sdis m);
struct Sdis sum (struct Sdis a , struct Sdis b);

int main(int argc, char *argv[]) {


	struct Sdis a;
   	struct Sdis b;

	printf("Enter info of 1st distance.\n");
	fflush(stdin); fflush(stdout);
	printf("Enter Feet: ");
	fflush(stdin); fflush(stdout);
	scanf("%d" , &a.ft);
	printf("Enter Inch: ");
	fflush(stdin); fflush(stdout);
	scanf("%f" , &a.in);

	printf("\nEnter info of 2nd distance.\n");
	fflush(stdin); fflush(stdout);
	printf("Enter Feet: ");
	fflush(stdin); fflush(stdout);
	scanf("%d" , &b.ft);
	printf("Enter Inch: ");
	fflush(stdin); fflush(stdout);
	scanf("%f" , &b.in);


	printf("\nTotal Distance =  %d\' - %f\" ",itf(sum(a,b)).ft,itf(sum(a,b)).in);

	return 0;

}

struct Sdis sum (struct Sdis a , struct Sdis b){

	struct Sdis s;
	s.ft = a.ft + b.ft;
	s.in = a.in + b.in;

	return s;
}

// inch to feet converter;
struct Sdis itf (struct Sdis m){

	if ( (m.in) < 12){
		return m;
	}
	else{
		m.ft++;
		m.in = m.in - 12;
		itf (m);
	}
	return m;
}






