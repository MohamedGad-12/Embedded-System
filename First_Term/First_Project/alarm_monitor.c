/* Eng. Mohamed Gamal */

#include "state.h"
#include "alarm_monitor.h"
#include "driver.h"
#include "Algo.h"

int Alarm_flag = 0;
unsigned int A_timer = 0;

void detect_high_pressure(){

	A_STATE = STATE(AlarmOn);
}

STATE_define(AlarmOff){

	Alarm_flag = 0;
	stop_alarm();
	STATE(High_Pressure_Detection)();

}


STATE_define(AlarmOn){

	Alarm_flag = 1;
	start_alarm();
	A_timer = 60;
	A_STATE = STATE(A_waiting);
}

STATE_define(A_waiting){

	while(A_timer){A_timer--;};

	A_timer = 0;

	stop_alarm();

	A_STATE = STATE(AlarmOff);
}
