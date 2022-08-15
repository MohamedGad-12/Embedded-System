/* Eng. Mohamed Gamal */

#include <stdint.h>
#include "Psensor.h"
#include "alarm_act.h"
#include "alarm_monitor.h"
#include "driver.h"
#include "Algo.h"
#include "state.h"

void setup() {

	init();
	Sensor_init();
	A_STATE =  STATE(AlarmOff);
	Sen_STATE = STATE(reading);
	Algo_STATE = STATE(High_Pressure_Detection);
	stop_alarm();
	Act_STATE = STATE(act_wait);
}

int main (){
	GPIO_INITIALIZATION();
	setup();
	while (1)
	{
		Sen_STATE();
		Algo_STATE();
		A_STATE();
		Act_STATE();
		Delay(10000);
	}
}
