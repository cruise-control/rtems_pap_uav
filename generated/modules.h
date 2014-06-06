/* This file has been generated from /home/j3/paparazzi/conf/airframes/examples/microjet_lisa_m.xml */
/* Please DO NOT EDIT */

#ifndef MODULES_H
#define MODULES_H

#define MODULES_IDLE  0
#define MODULES_RUN   1
#define MODULES_START 2
#define MODULES_STOP  3

#define MODULES_FREQUENCY 60

#ifdef MODULES_C
#define EXTERN_MODULES
#else
#define EXTERN_MODULES extern
#endif
#include "std.h"
#include "nav/nav_bungee_takeoff.h"
#include "nav/nav_line.h"
#include "nav/nav_line_border.h"
#include "nav/nav_line_osam.h"
#include "nav/nav_flower.h"
#include "nav/nav_smooth.h"
#include "nav/nav_survey_polygon.h"
#include "nav/nav_survey_poly_osam.h"
#include "nav/nav_vertical_raster.h"
#include "digital_cam/servo_cam_ctrl.h"

#define SERVO_CAM_CTRL_PERIODIC_PERIOD 0.250000
#define SERVO_CAM_CTRL_PERIODIC_FREQ 4.000000

EXTERN_MODULES uint8_t digital_cam_servo_servo_cam_ctrl_periodic_status;

#ifdef MODULES_C

static inline void modules_init(void) {
  servo_cam_ctrl_init();
  digital_cam_servo_servo_cam_ctrl_periodic_status = MODULES_START;
}

static inline void modules_periodic_task(void) {
  static uint8_t i15; i15++; if (i15>=15) i15=0;










  if (digital_cam_servo_servo_cam_ctrl_periodic_status == MODULES_START) { ; digital_cam_servo_servo_cam_ctrl_periodic_status = MODULES_RUN; }
  if (digital_cam_servo_servo_cam_ctrl_periodic_status == MODULES_STOP) { ; digital_cam_servo_servo_cam_ctrl_periodic_status = MODULES_IDLE; }

  if (i15 == 0 && digital_cam_servo_servo_cam_ctrl_periodic_status == MODULES_RUN) {
    servo_cam_ctrl_periodic();
  }
}

static inline void modules_event_task(void) {
}

#endif // MODULES_C

#ifdef MODULES_DATALINK_C

#include "messages.h"
#include "generated/airframe.h"
static inline void modules_parse_datalink(uint8_t msg_id __attribute__ ((unused))) {
}

#endif // MODULES_DATALINK_C

#endif // MODULES_H
