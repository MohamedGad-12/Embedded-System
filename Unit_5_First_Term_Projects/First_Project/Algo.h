/* Eng. Mohamed Gamal */

#ifndef ALGO_H_
#define ALGO_H_

#include "state.h"

enum {
	High_Pressure_Detection
}algo;


STATE_define(High_Pressure_Detection);


void (* Algo_STATE) (); // = Algo_STATE = STATE(High_Pressure_Detection);

#endif /* ALGO_H_ */
