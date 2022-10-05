/*
 * Dc.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng.Moahmed Gamal
 */

#ifndef Dc_H_
#define Dc_H_

#include "state.h"

enum {
	Dc_idle,
	Dc_busy
}Dc_id;

void init_Dc();

STATE_define(Dc_idle);
STATE_define(Dc_busy);

void (* Dc_STATE) ();

#endif /* Dc_H_ */
