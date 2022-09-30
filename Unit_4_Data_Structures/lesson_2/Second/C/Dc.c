/*
 * Dc.c
 *
 *  	Created on: ??þ/??þ/????
 *     Author: Eng.Moahmed Gamal
 */

#include "Dc.h"
#include "state.h"


unsigned int Dc_speed = 0;


void init_Dc() {
	printf("Dc init \n");
}

void DC_motor_set_Dc_speed(int s){

	Dc_speed = s;
	Dc_STATE = STATE(Dc_busy);
	printf("CA - - - -> DC, set__speed=%d \n" ,Dc_speed);

}

STATE_define(Dc_busy){

	Dc_id = Dc_busy;
	Dc_STATE = STATE(Dc_idle);
	printf("Busy Dc: Dc_speed = %d  \n" , Dc_speed);

}


STATE_define(Dc_idle){

	Dc_id = Dc_idle;
	// Will  be in idle state till the event "DC_motor_set_Dc_speed()" Occurred ;
	Dc_STATE = STATE(Dc_idle);
	printf("Idle Dc: Dc_speed = %d  \n" , Dc_speed);

}
