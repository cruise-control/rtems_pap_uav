/*
 * Copyright (C) 2005 Pascal Brisset, Antoine Drouin
 *
 * This file is part of paparazzi.
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/**
 * @file firmwares/fixedwing/main.c
 * Main loop used both on single and dual MCU configuration.
 */

#if defined TARGET_PLATFORM && TARGET_PLATFORM == RPI
#else
#include <amba.h>
#include <drvmgr/ambapp_bus.h>

#endif
#include <stdio.h>
#include <system.h>
#include <rtems/termiostypes.h>
#include "../../lib/dbgT.h"

#if defined TARGET_PLATFORM && TARGET_PLATFORM == RPI
//No need for the driver manager stuff for the RPI
#include "uart.h"
#else
#include <drvmgr/drvmgr.h>

/*set the uart resource as input driven and set this resource when uart get initialised.*/
struct drvmgr_key grlib_drv_res_apbuart0[] = { {"mode", KEY_TYPE_INT,
		((unsigned int) TERMIOS_IRQ_DRIVEN)}, {"syscon", KEY_TYPE_INT,
		((unsigned int) 0)}, {"dbgcon", KEY_TYPE_INT, ((unsigned int) 0)},
	KEY_EMPTY};

struct drvmgr_key grlib_drv_res_apbuart1[] = { {"mode", KEY_TYPE_INT,
		((unsigned int) TERMIOS_IRQ_DRIVEN)}, {"syscon", KEY_TYPE_INT,
		((unsigned int) 0)}, {"dbgcon", KEY_TYPE_INT, ((unsigned int) 0)},
	KEY_EMPTY};

/*it will override the grlib_drv_resources in the amba.c*/
struct drvmgr_bus_res grlib_drv_resources = {.next = NULL, .resource = { {
			DRIVER_AMBAPP_GAISLER_APBUART_ID, 0, &grlib_drv_res_apbuart0[0]},
//{DRIVER_AMBAPP_GAISLER_APBUART_ID, 1,&grlib_drv_res_apbuart1[0]},
		RES_EMPTY}};
#endif

#ifdef FBW
#include "firmwares/fixedwing/main_fbw.h"
#define Fbw(f) f ## _fbw()
#else
#define Fbw(f)
#endif

#ifdef AP
#include "firmwares/fixedwing/main_ap.h"
#define Ap(f) f ## _ap()
#else
#define Ap(f)
#endif

#if DEBUG_TIMING_MAIN_LOOP>0
ts_dbgT mainLoop_dbgT;
#endif

/*Debug includes, remove when finished*/
#include "messages.h"
#include "firmwares/fixedwing/autopilot.h"
#include "state.h"
#include "subsystems/datalink/telemetry.h"
#include "firmwares/fixedwing/nav.h"
#include "generated/settings.h"

#ifndef DefaultChannel
#define DefaultChannel DOWNLINK_TRANSPORT
#endif

#ifndef DefaultDevice
#define DefaultDevice DOWNLINK_DEVICE
#endif

void debug_uart_float() {
#ifdef __IEEE_BIG_ENDIAN
	UART1Puts("__IEEE_BIG_ENDIAN Defined!!! \r\n\r\n");
#endif
#ifdef __VFP_FP__
	UART1Puts("__VFP_FP__ Defined!!! \r\n\r\n");
#endif
#ifdef	__ARMEL__
	UART1Puts("__ARMEL__ Defined!!! \r\n\r\n");
#endif
#ifdef __IEEE_LITTLE_ENDIAN
	UART1Puts("__IEEE_LITTLE_ENDIAN Defined!!! \r\n\r\n");
#endif
#ifdef __sparc__
	UART1Puts("__sparc__ Defined!!! \r\n\r\n");
#endif

	float phi = 0.001;
	float psi = 0.002;
	float theta = 0.003;

	DOWNLINK_SEND_ATTITUDE(DefaultChannel, DefaultDevice, &phi, &psi, &theta);
	float *fptr;
	char buf[256];
	buf[0] = '\0';
	fptr = &phi;
	sprintf(buf, "&phi -> Float: %f\r\n", *fptr);
	UART1Puts(buf);
	buf[0] = '\0';
	fptr = &psi;
	sprintf(buf, "&psi -> Float: %f\r\n", *fptr);
	UART1Puts(buf);
	buf[0] = '\0';
	fptr = &theta;
	sprintf(buf, "&theta -> Float: %f\r\n", *fptr);
	UART1Puts(buf);

	UART1Puts("Uart Float Test \r\n\r\n");

	buf[0] = '\0';
	sprintf(buf, "1.0002 -> Float: %f\r\n", 1.0002);
	UART1Puts(buf);
	buf[0] = '\0';
	sprintf(buf, "0 -> Float: %f\r\n", 0);
	UART1Puts(buf);
	buf[0] = '\0';
	sprintf(buf, "0.0000 -> Float: %f\r\n", 0.0000);
	UART1Puts(buf);
	buf[0] = '\0';
	sprintf(buf, "0x00- -> Float: %f\r\n", 0x00);
	UART1Puts(buf);
	buf[0] = '\0';
	sprintf(buf, "1.0001f- -> Float: %f\r\n", 1.0001f);
	UART1Puts(buf);

	int counter = 0;

	while (counter < 100) {
		u_int8_t c = UART1Getch();
		if (UART1ChAvailable()) {
			UART1Putc(c);
			counter++;
		}
	}

}

rtems_task Init(rtems_task_argument ignored) {

#if DEBUG_TIMING_MAIN_LOOP > 0
	dbgTinit(&mainLoop_dbgT, MAIN_LOOP_ID);
#endif

	Fbw(init);
	Ap(init);

	dbgGpioInit();

	UART1Puts("\r\r****************************************\r\n\r\n\r\n");
	UART1Puts("Hello World\r\n");
	debug_uart_float();

	debug_pprz_msg("First Debug Message\r\n");

	uint16_t value = 0;
	while (1) {
		dbgGpioSet(GPIO_PORT_A);
//#if DEBUG_TIMING_MAIN_LOOP > 0
//		dbgTstart(&mainLoop_dbgT);
//#endif

		update_bat(12.0);
		Fbw(handle_periodic_tasks);
		Ap(handle_periodic_tasks);
		Fbw(event_task);
		Ap(event_task);

		dbgGpioClear(GPIO_PORT_A);
//#if DEBUG_TIMING_MAIN_LOOP > 0
//		dbgTstop(&mainLoop_dbgT);
//#endif
	}

	return;
}
