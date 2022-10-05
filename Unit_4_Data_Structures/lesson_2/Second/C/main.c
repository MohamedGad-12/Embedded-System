/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *  Author: Eng.Moahmed Gamal
 */

#include "CA.h"
#include "Us.h"
#include "Dc.h"
#include "state.h"

void setup(){

	init_Us();
	init_Dc();
	Us_STATE = STATE(Us_busy);
	CA_STATE = STATE(CA_waiting);
	Dc_STATE = STATE(Dc_idle);
}


int main() {

	setup();

	while(1){

		Us_STATE();
		CA_STATE();
		Dc_STATE();
		//delay;
		for (volatile int  i = 0 ; i < 10000 ; i++);

	}

	return 0;
}
