/* Eng. Mohamed Gamal */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "state.h"

enum {
	AlarmOff,
	AlarmOn,
	A_waiting,
}alarm;

STATE_define(AlarmOff);
STATE_define(AlarmOn);
STATE_define(A_waiting);

void (* A_STATE) (); // = A_STATE = STATE(AlarmOff,AlarmOn,A_waiting);


#endif /* ALARM_MONITOR_H_ */
