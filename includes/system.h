/*
 * system.h
 *
 *  Created on: May 29, 2013
 *      Author: manish
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_
#include <rtems.h>
#include <bsp.h> /* for device driver prototypes */

#define CONFIGURE_INIT

#if defined TARGET_PLATFORM && TARGET_PLATFORM == RPI
#else
#define CONFIGURE_APPLICATION_NEEDS_TIMER_DRIVER
#define ENABLE_NETWORK
#define CONFIGURE_INIT_TASK_ATTRIBUTES RTEMS_FLOATING_POINT
#endif

#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER


#define CONFIGURE_RTEMS_INIT_TASKS_TABLE
#define CONFIGURE_MAXIMUM_TASKS            4
#define CONFIGURE_MAXIMUM_TIMERS 20
#define CONFIGURE_MAXIMUM_DRIVERS 20 //Some Large number

//TODO What is this about????
//#define  CONFIGURE_MICROSECONDS_PER_TICK (1000000/SYS_TIME_FREQUENCY)

//This current implementation does not appear to be able to handle 1 ms per tick
//Working with courser grain resolution instead
#define  CONFIGURE_MICROSECONDS_PER_TICK 5000 //5 millisecond per tick
#define CONFIGURE_LIBIO_MAXIMUM_FILE_DESCRIPTORS 10

//#define CONFIGURE_USE_MINIIMFS_AS_BASE_FILESYSTEM

#define CONFIGURE_INIT_TASK_STACK_SIZE    (10*1024)

#define CONFIGURE_INIT_TASK_PRIORITY    254
#define CONFIGURE_INIT_TASK_INITIAL_MODES (RTEMS_PREEMPT | \
                                           RTEMS_NO_TIMESLICE | \
                                           RTEMS_NO_ASR | \
                                           RTEMS_INTERRUPT_LEVEL(0))

#include <rtems/confdefs.h>

#if defined TARGET_PLATFORM && TARGET_PLATFORM == RPI
#else
/*
 * The timer appears to be running at half speed. I suspect there are incorrect settings
 * between this driver and whatever default mechanism gets configured with the default
 * CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER mechanism. Commenting this out to see if the
 * system timer works by default... Not sure why there would be contention though if there indeed is..
 */
#ifdef  CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER
#	define CONFIGURE_DRIVER_AMBAPP_GAISLER_GPTIMER
#endif
#ifdef USE_UART1
#	define	CONFIGURE_DRIVER_AMBAPP_GAISLER_APBUART
#endif
#ifdef USE_RTEMS_GPIO
#	define CONFIGURE_DRIVER_AMBAPP_GAISLER_GRGPIO  /* GRGPIO driver */
#endif

#include <drvmgr/drvmgr_confdefs.h>
#endif

#endif /* SYSTEM_H_ */
