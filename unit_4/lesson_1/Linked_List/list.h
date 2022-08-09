//Eng.Mohamed Gamal

#ifndef LIST_H_
#define LIST_H_


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <conio.h>

#define Mprint(...)  { fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}

struct Sdata {
	int Id;
	char name[40];
	float height;
};

struct Sstudent {
	struct Sdata data ;
	struct Sstudent* next;
};

int check_id(int id);
void fill_data(struct Sstudent* student);

void add_student();
void delete_student();

void view_student();
void view_student_2(struct Sstudent* student);

void delete_all();

int lenght();
int lenght_Recursive();

//function for n’th node from the end of a Linked List
void print_back();

void middle();

void loop_detect();

void Print_Reverse(struct Sstudent* student);

void Reverse();

#endif /* LIST_H_ */
