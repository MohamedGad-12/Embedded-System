


/*Eng.Mohamed Gamal*/

#include "queue.h"
#include "student.h"

int main(){

	init ();
	Mprint("Welcome to Student Mamagment System\n")

		while(1){
			char text [50];
			Mprint("1. Add Student Details manually \n");
			Mprint("2. Add Student Details manually from file \n");
			Mprint("3. Find Student Details by Roll Number \n");
			Mprint("4. Find Student Details by First Name \n");
			Mprint("5. Find Students Details by Course ID \n");
			Mprint("6. Find Total Number of Students \n");
			Mprint("7. Delete Student Details by Roll Number \n");
			Mprint("8. Update Student Details by Roll Number \n");
			Mprint("9. Show all Students \n");
			Mprint("10. Exit \n");
			Mprint("Chose Your Option: ");
			gets(text);
			Mprint("\n");

			switch(atoi(text)){

			case 1:
				add_std_manually();
				Mprint("\"Welcome Sir\" [:)] \n");
				Mprint("\"Chose New Option\" \n");
				break;
			case 2:
				add_std_file();
				Mprint("\"Welcome Sir\" [:)] \n");
				Mprint("\"Chose New Option\" \n");
				break;
			case 3:
				find_ID();
				Mprint("\"Welcome Sir\" [:)] \n");
				Mprint("\"Chose New Option\" \n");
				break;
			case 4:
				find_first();
				Mprint("\"Welcome Sir\" [:)] \n");
				Mprint("\"Chose New Option\" \n");
				break;
			case 5:
				find_C_std();
				Mprint("\"Welcome Sir\" [:)] \n");
				Mprint("\"Chose New Option\" \n");
				break;
			case 6:
				total_number();
				Mprint("\"Welcome Sir\" [:)] \n");
				Mprint("\"Chose New Option\" \n");
				break;
			case 7:
				Delete_ID();
				Mprint("\"Welcome Sir\" [:)] \n");
				Mprint("\"Chose New Option\" \n");
				break;
			case 8:
				Updata_ID();
				Mprint("\"Welcome Sir\" [:)] \n");
				Mprint("\"Chose New Option\" \n");
				break;
			case 9:
				Show_all();
				Mprint("\"Welcome Sir\" [:)] \n");
				Mprint("\"Chose New Option\" \n");
				break;
			case 10:
				exit(0);
				break;
			default:
				Mprint("\"Welcome Sir\" [:)] \n");
				Mprint("Invalid Option [:(] \n");
				break;
			}

		}
	return 0;
}

