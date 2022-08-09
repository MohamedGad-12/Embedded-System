//Eng.Mohamed Gamal

#include "list.h"

struct Sstudent* first_one = NULL;

// id is unique;
int check_id(int id){

	struct Sstudent* student= first_one;

	while(student){

		if(student->data.Id == id){
			Mprint("Error: ID already exist :( \nPlease Select another one :) \n");
			return 0;
		}
		else
			student = student->next;
	}
	return 1;
}

void fill_data(struct Sstudent* student){

	char text[40];
	int id_check = 0 ;

	Mprint("Enter student name: ");
	gets(student->data.name);

	Mprint("Enter student id: ");
	gets(text);
	id_check = atoi(text);
	while ( check_id(id_check) == 0 ){
		Mprint("Enter student id: ");
		gets(text);
		id_check = atoi(text);
	}
	student->data.Id = atoi(text);

	Mprint("Enter student height: ");
	gets(text);
	student->data.height = atof(text);
}

void add_student(){

	struct Sstudent* last_student;
	struct Sstudent* new_student;

	if(first_one == NULL){
		new_student= (struct Sstudent*)(malloc(sizeof(struct Sstudent)));
		first_one= new_student;
		new_student->next =NULL;
	}
	else{

		last_student = first_one;
		while(last_student->next){
			last_student= last_student->next;
		}
		new_student= (struct Sstudent*)(malloc(sizeof(struct Sstudent)));
		last_student->next = new_student;
		new_student->next =NULL;
	}

	fill_data(new_student);
}

void delete_student(){

	char text[40];
	struct Sstudent* student = first_one;
	struct Sstudent* prev_student = NULL;

	if (student == NULL){
		Mprint("Empty List :(");
		return;
	}

	Mprint("Enter student id to be deleted: ");
	gets(text);

	while(student) {

		if ( student->data.Id == atoi(text) ){

			Mprint("Information of deleted student:\n")
			Mprint("student name: %s \n" , student->data.name);
			Mprint("student id: %d \n" ,student->data.Id );
			Mprint("student height: %f \n" , student->data.height);

			if(prev_student)
				prev_student->next= student->next;
			else
				first_one = student->next;


			Mprint("Delete Done :) \n");
			free(student);
			return;
		}
		else{
			prev_student = student;
			student= student->next;
		}
	}
	Mprint("NOT exist :( \n");

}


void view_student(){

	struct Sstudent* student = first_one;
	int index = 0;
	if (student == NULL){
		Mprint("Empty List :( \n");
		return;
	}
	while(student){
		Mprint("Record Number: %d \n" , index+1);
		Mprint("student name: %s \n" , student->data.name);
		Mprint("student id: %d \n" ,student->data.Id );
		Mprint("student height: %f \n" , student->data.height);
		Mprint("=========================\n");
		index++;
		student = student->next;
	}
}

// pass first student to func:view_student;
//another soln for  func:view_student;
void view_student_2(struct Sstudent* student){

	if (student == NULL){
		if(lenght() == 0){
			Mprint("Empty List :( \n");
			return;
		}
		else
			return;
	}
	else{
		Mprint("student name: %s \n" , student->data.name);
		Mprint("student id: %d \n" ,student->data.Id );
		Mprint("student height: %f \n" , student->data.height);
		Mprint("=========================\n");
		view_student_2(student->next);
	}
}

void delete_all(){

	struct Sstudent* student =first_one;


	if (student == NULL){
		Mprint("Empty List :( \n");
		return;
	}
	while(student){
		struct Sstudent* temp = student;
		student = student->next;
		free(temp);
	}
	Mprint("Delete Done :) \n");
	first_one = NULL;
}

int lenght(){
	struct Sstudent* student = first_one;
	int index = 0;
	if (student == NULL){
		return index;
	}
	while(student){
		index++;
		student = student->next;
	}
	return index;
}

// pass first student to func:view_student;
int lenght_Recursive(struct Sstudent* student){

	if (student == NULL){
		return 0;
	}
	student = student->next;
	return (1+lenght_Recursive(student));
}

void print_back(){

	struct Sstudent* ref = first_one ;
	struct Sstudent* ptr = first_one ;
	char text[40];
	int position = 0;
	Mprint("Enter student Position from back: ");
	gets(text);
	position = atoi(text);

	while (position > lenght() ){
		Mprint("Error: Invalid position, list length is:%d \nSo Enter Number Not greater than %d: ",lenght(),lenght());
		gets(text);
		Mprint("\n=========================\n");
		position = atoi(text);
	}

	if (ref == NULL){
		Mprint("Empty List :( \n");
		return;
	}

	while(ref){
		if (position > 0){
			ref = ref->next;
			position--;
		}
		else{
			ref = ref->next;
			ptr= ptr->next;
		}
	}
	Mprint("Information of student number %d from back:\n",atoi(text));
	Mprint("student name: %s \n" , ptr->data.name);
	Mprint("student id: %d \n" ,ptr->data.Id );
	Mprint("student height: %f \n" , ptr->data.height);
}

void middle(){

	struct Sstudent* ref = first_one ;
	struct Sstudent* ptr = first_one ;

	int type = lenght();

	if (ref == NULL || !type ){
		Mprint("Empty List :( \n");
		return;
	}

	if( (type%2)==0 ){
		while(ref){
			ref = ref->next->next;
			ptr= ptr->next;
		}
	}
	else{
		while((ref->next)){
			ref = ref->next->next;
			ptr= ptr->next;
		}
	}

	Mprint("the middle\n");
	Mprint("student name: %s \n" , ptr->data.name);
	Mprint("student id: %d \n" ,ptr->data.Id );
	Mprint("student height: %f \n" , ptr->data.height);
}

void loop_detect(){

	struct Sstudent* ref = first_one ;
	struct Sstudent* ptr = first_one ;

	while(ref && ptr && ref->next){
		ref = ref->next->next;
		ptr= ptr->next;
		if (ref == ptr){
			Mprint("Loop Exist :( \n");
		}
	}
	Mprint("NO Loop Exist :) \n");
}

void Print_Reverse(struct Sstudent* student){

	int record = lenght_Recursive(student);

	if (student == NULL){
		if(lenght() == 0){
			Mprint("Empty List :( \n");
			return;
		}
		else
			return;
	}

	Print_Reverse(student->next);
	Mprint("Record Number From Back: %d \n" , record);
	Mprint("student name: %s \n" , student->data.name);
	Mprint("student id: %d \n" ,student->data.Id );
	Mprint("student height: %f \n" , student->data.height);
	Mprint("=========================\n");

}

void Reverse(){

	struct Sstudent* prev = NULL;
	struct Sstudent* forward = first_one;
	struct Sstudent* current= first_one;

	while(current != NULL){
		forward = current->next;
		current->next = prev;
		prev = current;
		current = forward;
	}
	first_one = prev;
	Mprint("Reverse Done :) \n");
}
