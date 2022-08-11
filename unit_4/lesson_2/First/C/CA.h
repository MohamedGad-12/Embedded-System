/*
 * CA.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng.Moahmed Gamal
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"

enum {
	CA_waiting,
	CA_driving
}state_id;

STATE_define(CA_waiting);
STATE_define(CA_driving);

void (* CA_STATE) ();

#endif /* CA_H_ */
