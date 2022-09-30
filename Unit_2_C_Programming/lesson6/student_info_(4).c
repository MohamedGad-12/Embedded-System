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

} ;

int g_count = 0;
struct Sinfo* insert (struct Sinfo s[]);
void print (struct Sinfo p[]);

int main(int argc, char *argv[]) {

	struct Sinfo student[100];
	print(insert(student));
	return 0;

}

struct Sinfo* insert (struct Sinfo s[]){

	char  c ;
	printf("Inserting Informations of Student.\n\n");
	fflush(stdin); fflush(stdout);
	for(int i = 0 ; i < 100 ; i++){

		s[i].roll = i+1;
		printf("Enter Info of Student Number %d.", s[i].roll);
		fflush(stdin); fflush(stdout);

		printf("\nEnter Your Name: ");
		fflush(stdin); fflush(stdout);
		gets(s[i].name);

		printf("Enter Marks: ");
		fflush(stdin); fflush(stdout);
		scanf("%f" , &s[i].mark);

		printf("\n");

		printf("Do You Want To Exit (Y OR N): ");
		fflush(stdin); fflush(stdout);
		scanf("%c" , &c);

		printf("\n");

		g_count++;
		if ( (c == 'y') || (c == 'Y') )
			break;
	}
	return s;
}

void print (struct Sinfo p[]){

	printf("Displaying Informations of Student.\n\n");
	fflush(stdin); fflush(stdout);
	for(int i = 0 ; i < g_count ; i++) {
		printf("Student Roll Number %d. Info.", p[i].roll);
		printf("\nName: %s" , p[i].name);
		printf("\nMark: %f" , p[i].mark);
		printf("\n\n");
	}
}






