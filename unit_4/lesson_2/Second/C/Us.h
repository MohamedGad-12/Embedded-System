/*
 * Us.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng.Moahmed Gamal
 */

#ifndef Us_H_
#define Us_H_

#include "state.h"

enum {
	Us_busy
}Us_id;

void init_Us();

int generate (int l ,int r , int count);

STATE_define(Us_busy);

void (* Us_STATE) ();

#endif /* Us_H_ */
