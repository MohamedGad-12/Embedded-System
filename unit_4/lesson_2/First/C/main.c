/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *  Author: Eng.Moahmed Gamal
 */

#include "CA.h"
#include "state.h"

void setup(){

	CA_STATE = STATE(CA_waiting);
}


void main() {

	setup();

	while(1){

		CA_STATE();
		//delay;
		for (volatile int  i = 0 ; i < 2000 ; i++);

	}

}
