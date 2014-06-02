/*
 * debugTiming.c
 *
 *  Created on: May 31, 2014
 *      Author: j3
 */
/**
 * Pretty self explanatory code here. Used for unique timing and logging purposes.
 * Designed to be timed and then printed each occurance rather than stored
 */

#include <stdio.h>
#include "dbgT.h"
#include "../mcu_periph/uart.h"
#include <sys/types.h>

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include "subsystems/datalink/transport.h"

//#include "system.h"
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/sockio.h>
#include "../../mcu_periph/uart.h"
#include "../../lib/ring_buf.h"

void dbgTinit(ts_dbgT* t, int id) {
	t->counter = 0;
	t->id = id;
}

void dbgTstart(ts_dbgT* t) {
	if (t->counter == 0) {
		t->counter++;
		struct timespec* tmr = &t->start;
		rtems_clock_get_uptime(tmr);
	} else
		t->counter++;
	return;
}

void dbgTstop(ts_dbgT* t) {
	if (t->counter >= ITERATIONS) {
		struct timespec* tmr = &t->finish;
		rtems_clock_get_uptime(tmr);
		dbgTdump(t);
		dbgTinit(t, t->id);
	}
	return;
}

void dbgTdump(ts_dbgT* t) {
	//long begin = t->start.tv_sec * 1000 * 1000 + t->start.tv_nsec / 1000;
	//long finish = t->finish.tv_sec * 1000 * 1000 + t->finish.tv_nsec / 1000;
	char buf[256];
	buf[0] = '\0';
	sprintf(buf, "$_%d,%ld,%ld,%ld,%ld,%ld,%d\r\n", t->id, t->counter,
			t->start.tv_sec, t->start.tv_nsec, t->finish.tv_sec,
			t->finish.tv_nsec, ITERATIONS);
	UART1Puts(buf);
}

