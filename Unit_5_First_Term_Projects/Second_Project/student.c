//Eng.Mohamed Gamal

#include "student.h"
#include "queue.h"

//------------------------------------------------------//

fifo std;
char text[50];
static int total = 0;

//-------------------------------------------------------//

void init (){
	fifo_init(&std,student,size);
}

int check_ID(int id){
	for (int i = 0 ; i < std.count ; i++){
		if(id == (student[i].S_ID)){
			Mprint("[Error]: ID Already Exist :( \n");
			Mprint("-------------------------------------\n");
			return 0;
		}
	}
	return 1;
}

void print(struct Sstd* s){

	Mprint("Student roll Number:%d \n",	(*s).S_ID);
	Mprint("Student first Name:%s \n",(*s).first);
	Mprint("Student second Name:%s \n" ,(*s).last);
	Mprint("Student GPA:%.2f \n",(*s).gpa);
	for (int k = 0; k < 5 ; k++){
		Mprint("Course %d: %d \n",(k+1),(*s).C_ID[k]);
	}

}
//------------------------------------------------------//

void add_std_file(){


	FILE* ptr = fopen("test.txt", "r");
	if (ptr == NULL) {
		printf("no such file.");
		return;
	}

	struct Sstd s;

	fscanf(ptr, "%*s %s",text);
	s.S_ID = atoi(text);
	Mprint("Insert Student Roll Number:%d \n",s.S_ID);
	if (check_ID(s.S_ID) == 0) return;

	fscanf(ptr, "%*s %s",s.first);
	Mprint("Insert Student first Name:%s \n", s.first);

	fscanf(ptr, "%*s %s",s.last);
	Mprint("Insert Student second Name:%s \n" ,s.last);



	fscanf(ptr, "%*s %s",text);
	s.gpa = atof(text);
	Mprint("Insert Student GPA:%2f \n" ,s.gpa);


	Mprint("Insert Course ID of each Course:\n");
	for (int i = 0; i < 5 ; i++){
		fscanf(ptr, "%*s %s",text);
		s.C_ID[i] = atoi(text);
		Mprint("Course %d:%d \n",(i+1),s.C_ID[i]);
	}

	fifo_enqueue(&std,s);

	total++;
	Mprint("[INFO]:Data Inserted Successfully From File :) \n");
	Mprint("-------------------------------------\n");
}

void add_std_manually(){

	struct Sstd s;

	Mprint("Enter Student Roll Number:");
	if (check_ID(atoi(gets(text))) == 0) return;
	s.S_ID = atoi(text);

	Mprint("Enter Student first Name:");
	gets(s.first);

	Mprint("Enter Student second Name:");
	gets(s.last);


	Mprint("Enter Student GPA:");
	s.gpa = atof(gets(text));

	Mprint("Enter Course ID of each Course:\n");
	for (int i = 0; i < 5 ; i++){
		Mprint("Course %d:",(i+1));
		s.C_ID[i] =atoi(gets(text));
	}

	fifo_enqueue(&std,s);

	total++;
	Mprint("[INFO]:Data Inserted Successfully :) \n");
	Mprint("-------------------------------------\n");
}

void find_ID(){

	struct Sstd s;

	Mprint("Enter Student Roll Number To Find Data:");
	s.S_ID = atoi(gets(text));
	int flag = 0;
	for (int i = 0 ; i < total ; i++){
		if(s.S_ID == (student[i].S_ID)){
			s = student[i];
			flag = 1;
			break;
		}
	}
	if(flag == 1){

		print(&s);

		Mprint("[INFO]:Search Done Successfully :) \n");
		Mprint("-------------------------------------\n");
	}
	else{
		Mprint("[Error]: ID Not Exist :( \n");
		Mprint("-------------------------------------\n");
	}

}

void find_first(){

	Mprint("Enter Student First Name To Find Data:");
	gets(text);
	int flag = 0;
	for (int i = 0 ; i < total ; i++){
		if(strcmpi(text,student[i].first) == 0){
			flag = 1;
			print(&(student[i]));
		}
		Mprint("\n");
	}

	if(flag == 1){
		Mprint("[INFO]:Search Done Successfully :) \n");
		Mprint("-------------------------------------\n");
	}
	else{
		Mprint("[Error]: Student Not Exist :( \n");
		Mprint("-------------------------------------\n");
	}
}

void find_C_std(){

	int c ;
	int con = 0;
	Mprint("Enter Course ID:");
	c = atoi(gets(text));
	for (int i = 0 ; i < total ; i++){
		for (int j = 0 ; j < 5 ; j++){
			if(c == (student[i].C_ID[j])){
				con++;
				Mprint("Record Number:%d \n", con);
				Mprint("Student roll Number:%d \n",student[i].S_ID);
				Mprint("Student first Name:%s \n",student[i].first);
				Mprint("Student second Name:%s \n" ,student[i].last);
				Mprint("Student GPA:%.2f \n\n",student[i].gpa);
			}
		}
	}
	if(con == 0){
		Mprint("[Error]: There Are No Students :( \n");
		Mprint("[Error]: Course ID Not Found   :( \n");
		Mprint("-------------------------------------\n");
	}
	else{
		Mprint("[INFO]: Total Students register Course: %d \n",con);
		Mprint("-------------------------------------\n");
	}
}

void total_number(){

	Mprint("[INFO]: Total Students: %d \n",total);
	Mprint("[INFO]: You Can Add Up To %d Students. \n",100);
	Mprint("[INFO]: You Can Add %d More Students. \n",(100-total));
	Mprint("-------------------------------------\n");
}

void Delete_ID(){

	int id ;
	int flag = 0;
	Mprint("Enter Student Roll Number To Delete Data:");
	id = atoi(gets(text));

	for (int i = 0 ; i < std.count ; i++){
		if(id == (student[i].S_ID)){
			print(&(student[i]));
			Mprint("Do You Want to Continue: 1.Yes 2.No \n");
			Mprint("Select Option: ");
			gets(text);
			if( atoi(text) == 1){
				flag = 1;
				for (int j = i ; j < std.count ; j++){
					student[j] = student[j+1];
				}
				std.tail--;
				std.count--;
			}
			if( atoi(text) == 2){
				flag = -1;
				break;
			}
		}
	}

	if (flag == 0)
	{
		Mprint("[Error]: ID Not Exist :( \n");
		Mprint("-------------------------------------\n");
		return;
	}
	if (flag == -1)
	{
		Mprint("Deleted Process Stopped.\n")
		Mprint("-------------------------------------\n");
		return;
	}
	else{
		total--;
		Mprint("[INFO]:Data Deleted Successfully :) \n");
		Mprint("-------------------------------------\n");
	}
}

void Updata_ID(){

	struct Sstd* s;
	int select;
	int id ;
	int flag = 0;
	Mprint("Enter Student Roll Number To Update Data:");
	id = atoi(gets(text));

	for (int i = 0 ; i < total ; i++){
		if(id == (student[i].S_ID)){
			print(&(student[i]));
			s = &(student[i]);
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		Mprint("[Error]: Student ID Not Exist :( \n");
		Mprint("-------------------------------------\n");
		return;
	}

	Mprint("1.First Name.\n");
	Mprint("2.Second Name.\n");
	Mprint("3.Roll Number.\n");
	Mprint("4.Courses.\n");
	Mprint("5.Exit.\n");
	Mprint("Select Update Option:");
	select = atoi(gets(text));

	switch(select){
	case 1:
		Mprint("Enter Student first Name:");
		gets((*s).first);
		Mprint("[INFO]:Data Updated Successfully :) \n");
		Mprint("-------------------------------------\n");
		break;
	case 2:
		Mprint("Enter Student second Name:");
		gets((*s).last);
		Mprint("[INFO]:Data Updated Successfully :) \n");
		Mprint("-------------------------------------\n");
		break;
	case 3:
		Mprint("Enter Student Roll Number:");
		if (check_ID(atoi(gets(text))) == 0) break;
		(*s).S_ID = atoi(text);
		Mprint("[INFO]:Data Updated Successfully :) \n");
		Mprint("-------------------------------------\n");
		break;
	case 4:
		Mprint("Enter Course ID of each Course:\n");
		for (int i = 0; i < 5 ; i++){
			Mprint("Course %d:",(i+1));
			(*s).C_ID[i] =atoi(gets(text));
		}
		Mprint("[INFO]:Data Updated Successfully :) \n");
		Mprint("-------------------------------------\n");
		break;
	case 5:
		Mprint("\n")
		break;
	default:
		Mprint("Invalid Option :( \n");
		Mprint("-------------------------------------\n");
		break;
	}
}

void Show_all(){

	int con = 0;

	for (int i = 0 ; i < total ; i++){
		con++;
		Mprint("Record Number:%d \n", con);
		print(&(student[i]));
		Mprint("\n");
	}
	Mprint("-------------------------------------\n");
	if (con == 0){
		Mprint("There are no students Exist :(");
	}
}

//------------------------------------------------------//

