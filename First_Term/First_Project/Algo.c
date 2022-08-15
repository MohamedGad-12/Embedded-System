/* Eng. Mohamed Gamal */

#include "Algo.h"
#include "driver.h"
#include "state.h"

int pVal = 0;
int threshold = 20;

void set_pval() {
	pVal = getPressureVal();
}

STATE_define(High_Pressure_Detection){

	set_pval();

	if(pVal <= threshold){
		set_pval();
		Algo_STATE = STATE(High_Pressure_Detection);
	}
	else
	{
		detect_high_pressure();
		set_pval();
		Algo_STATE = STATE(High_Pressure_Detection);
	}

}
