/* Eng. Mohamed Gamal */

#ifndef ALARM_ACT_H_
#define ALARM_ACT_H_

#include "state.h"

void init();

enum {
	act_wait,
	act_off,
	act_on
}act;

STATE_define(act_wait);
STATE_define(act_off);
STATE_define(act_on);

void (* Act_STATE) (); // = A_STATE = STATE(act_wait,act_off,act_on);


#endif /* ALARM_ACT_H_ */
