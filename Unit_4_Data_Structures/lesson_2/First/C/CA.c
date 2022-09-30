/*
 * CA.c
 *
 *  	Created on: ??ş/??ş/????
 *     Author: Eng.Moahmed Gamal
 */

#include "CA.h"
#include "state.h"

unsigned int speed;
unsigned int distance;
unsigned int threshlod = 50 ;


int generate (int l ,int r , int count) {
	int i;
	int rand_num =0;
	for(i=0 ; i<count ; i++){
		rand_num =(rand() % (r - l + 1 )) + 45;
		return rand_num;
	}
	return rand_num;
}

STATE_define(CA_waiting){

	state_id = CA_waiting;
	speed = 0;

	distance = generate(45,55,1);

	(distance <= threshlod) ? (CA_STATE = STATE(CA_waiting)) : (CA_STATE = STATE(CA_driving));

	printf("Waiting State: Speed = %d , Distance = %d \n" , speed, distance);
}


STATE_define(CA_driving){

	state_id = CA_driving;
	speed = 30;

	distance = generate(45,55,1);

	(distance <= threshlod) ? ( CA_STATE = STATE(CA_waiting) ) : (CA_STATE = STATE(CA_driving) ) ;

	printf("Driving State: Speed = %d , Distance = %d \n" , speed, distance);
}
