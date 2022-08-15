/* Eng. Mohamed Gamal */

#include "state.h"
#include "Psensor.h"
#include "driver.h"

int s_pval = 0;
int s_timer = 0;

void Sensor_init () {
	GPIO_INITIALIZATION();
}

STATE_define(reading){

	s_pval = getPressureVal();
	s_timer = 100;
	Sen_STATE = STATE(waiting);
}


STATE_define(waiting){

	while(s_timer){s_timer--;};

	s_timer = 0;

	Sen_STATE = STATE(reading);

}
