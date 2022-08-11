/*
 * state.h
 *
 *  Created on: ??þ/??þ/????
 *  Author: Eng.Moahmed Gamal
 */

#ifndef STATE_H_
#define STATE_H_

#define STATE_define(_statefunc_)  void ST_##_statefunc_()
#define STATE(_statefunc_)  ST_##_statefunc_

void DC_motor_set_speed(int s);

void US_Sensor_set_distance(int d);

#include <stdio.h>
#include <stdlib.h>

#endif /* STATE_H_ */
