/*
 * Us.c
 *
 *  	Created on: ??þ/??þ/????
 *     Author: Eng.Moahmed Gamal
 */

#include "Us.h"
#include "state.h"

unsigned int Us_distance = 0;

void init_Us() {
	printf("Us init \n");
}

int generate (int l ,int r , int count) {
	int i;
	int rand_num =0;
	for(i=0 ; i<count ; i++){
		rand_num =(rand() % (r - l + 1 )) + 45;
		return rand_num;
	}
	return rand_num;
}


STATE_define(Us_busy){

	Us_id = Us_busy;

	Us_distance = generate(45,55,1);
	printf("Busy Us: Us_distance = %d  \n" , Us_distance);

	US_Sensor_set_distance(Us_distance);

	Us_STATE = STATE(Us_busy);
}


