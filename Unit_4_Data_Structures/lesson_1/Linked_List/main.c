//Eng.Mohamed Gamal

#include "list.h"

extern struct Sstudent* first_one;

int main(void){

	while(1){
		char text [40];

		Mprint("========================= \n");
		Mprint("\"Welcome Sir\" :) \n");
		Mprint("1. Add Student \n");
		Mprint("2. Remove Student \n");
		Mprint("3. View Students \n");
		Mprint("4. Remove ALl \n");
		Mprint("5. Length \n");
		Mprint("6. print_Back \n");
		Mprint("7. middle \n");
		Mprint("8. Loop \n");
		Mprint("9. Print_Reverse \n");
		Mprint("10. Reverse \n");
		Mprint("11. exit \n");
		Mprint("Chose Your Option: ");
		gets(text);
		Mprint("========================= \n");

		switch(atoi(text)){

		case 1:
			add_student();
			Mprint("========================= \n");
			Mprint("\n \"Chose New Option\" \n");
			break;
		case 2:
			delete_student();
			Mprint("========================= \n");
			Mprint("\n \"Chose New Option\" \n");
			break;
		case 3:
			view_student();
			//or view_student_2(first_one);
			Mprint("========================= \n");
			Mprint("\n \"Chose New Option\" \n");
			break;
		case 4:
			delete_all();
			Mprint("========================= \n");
			Mprint("\n \"Chose New Option\" \n");
			break;
		case 5:
			Mprint("the length of list is: %d \n" , lenght_Recursive(first_one));
			// or Mprint("the length of list is: %d \n" , lenght() );
			Mprint("========================= \n");
			Mprint("\n \"Chose New Option\" \n");
			break;
		case 6:
			print_back();
			Mprint("========================= \n");
			Mprint("\n \"Chose New Option\" \n");
			break;
		case 7:
			middle();
			Mprint("========================= \n");
			Mprint("\n \"Chose New Option\" \n");
			break;
		case 8:
			loop_detect();
			Mprint("========================= \n");
			Mprint("\n \"Chose New Option\" \n");
			break;
		case 9:
			Print_Reverse(first_one);
			Mprint("========================= \n");
			Mprint("\n \"Chose New Option\" \n");
			break;
		case 10:
			Reverse();
			Mprint("========================= \n");
			Mprint("\n \"Chose New Option\" \n");
			break;
		case 11:
			exit(0);
			break;
		default:
			Mprint("\n Invalid Option :( \n");
			break;
		}

	}
	return 0;
}
