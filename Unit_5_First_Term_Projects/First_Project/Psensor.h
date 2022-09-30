/* Eng. Mohamed Gamal */

#ifndef PSENSOR_H_
#define PSENSOR_H_

#include "state.h"

enum {
	reading,
	waiting,
}sensor;


STATE_define(reading);
STATE_define(waiting);

void Sensor_init();

void (* Sen_STATE) (); // = A_STATE = STATE(waiting,reading);

#endif /* PSENSOR_H_ */
