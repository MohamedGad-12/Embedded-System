/* Eng. Mohamed Gamal */

#ifndef STATE_H_
#define STATE_H_

#define STATE_define(_statefunc_)  void ST_##_statefunc_()
#define STATE(_statefunc_)  ST_##_statefunc_

void set_pval();
void detect_high_pressure();
void start_alarm();
void stop_alarm();

#endif /* STATE_H_ */
