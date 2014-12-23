/*
 * dbg.c
 *
 *  Created on: Dec 16, 2014
 *      Author: j3
 */

/*Debug includes, remove when finished*/
#include "../includes/messages.h"
#include "../firmwares/fixedwing/autopilot.h"
#include "../state.h"
#include "../subsystems/datalink/telemetry.h"
#include "../firmwares/fixedwing/nav.h"
#include "../generated/settings.h"

#ifndef DefaultChannel
#define DefaultChannel DOWNLINK_TRANSPORT
#endif

#ifndef DefaultDevice
#define DefaultDevice DOWNLINK_DEVICE
#endif

void debug_pprz_msg(const char* c) {
	char buf[256];
	int index = 0;
	while (*c != '\0') {
		if (index > 128)
			break;
		buf[index++] = *c;
		*c++;
	}
	DOWNLINK_SEND_DEBUG(DefaultChannel, DefaultDevice, index, buf);
}
