/*
 * CA.c
 *
 *  	Created on: ??þ/??þ/????
 *     Author: Eng.Moahmed Gamal
 */

#include "CA.h"
#include "state.h"

unsigned int CA_speed = 0;
unsigned int CA_distance = 0;
unsigned int CA_threshlod = 50 ;


void US_Sensor_set_distance(int d){

	CA_distance = d;
	(CA_distance <= CA_threshlod) ? (CA_STATE = STATE(CA_waiting)) : (CA_STATE = STATE(CA_driving));
	printf("Us - - - -> CA, set__distance=%d \n" , CA_distance);

}

STATE_define(CA_waiting){

	state_id = CA_waiting;
	printf("Waiting State: CA_speed = %d , CA_distance = %d \n" , CA_speed, CA_distance);
	CA_speed = 0;
	DC_motor_set_Dc_speed(CA_speed);
}


STATE_define(CA_driving){

	state_id = CA_driving;
	printf("Driving State: CA_speed = %d , CA_distance = %d \n" , CA_speed, CA_distance);
	CA_speed = 30;
	DC_motor_set_Dc_speed(CA_speed);

}
