/* Eng. Mohamed Gamal */

#include "state.h"
#include "alarm_act.h"
#include "driver.h"

extern int Alarm_flag;

void init(){
	GPIO_INITIALIZATION();
}

void start_alarm (){
	Set_Alarm_actuator(0);
}


void stop_alarm (){
	Set_Alarm_actuator(1);
}

STATE_define(act_wait){

	if(Alarm_flag == 0){
		stop_alarm();
	}
	if (Alarm_flag == 1)
	{
		start_alarm();
	}

}

STATE_define(act_off){

	Act_STATE = STATE(act_wait);

}

STATE_define(act_on){

	Act_STATE = STATE(act_wait);
}
