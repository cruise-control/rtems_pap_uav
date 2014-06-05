/*
 * debugTiming.h
 *
 *  Created on: May 31, 2014
 *      Author: j3
 */

#ifndef DEBUGTIMING_H_
#define DEBUGTIMING_H_

#include <stdio.h>
#include <sys/types.h>

#define NO_OUTPUT 0
#define DEBUG_TIMING_AUTOPILOT 0
#define DEBUG_TIMING_MAIN_LOOP 0
#define SENSOR_ID 1
#define NAVIGATION_ID 2
#define ATTITUDE_ID 3
#define TELEMETRY_ID 4
#define MONITOR_ID 5
#define MAIN_LOOP_ID 6
#define DEBUG_ID 10
#define SENSOR_ID 1
#define ITERATIONS 500

#define GPIO_PORT_A 0
#define GPIO_PORT_B 1

typedef struct {
	struct timespec start;
	struct timespec finish;
	int id;
	long counter;
} ts_dbgT;

void dbgTinit(ts_dbgT* t, int id);
void dbgTstart(ts_dbgT* t);
void dbgTstop(ts_dbgT* t);
void dbgTdump(ts_dbgT* t);

void dbgGpioInit();
void dbgGpioClear(int chan);
void dbgGpioSet(int chan);

#endif /* DEBUGTIMING_H_ */
