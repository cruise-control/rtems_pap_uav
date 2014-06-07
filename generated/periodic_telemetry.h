/* This file has been generated from /home/j3/paparazzi/conf/messages.xml and /home/j3/paparazzi/conf/telemetry/default_fixedwing_imu.xml */
/* Please DO NOT EDIT */

#ifndef _VAR_PERIODIC_H_
#define _VAR_PERIODIC_H_

#include "std.h"
#include "generated/airframe.h"
#include "subsystems/datalink/telemetry_common.h"

#define TELEMETRY_FREQUENCY 60


/* Periodic telemetry: Ap process */
#define TELEMETRY_PROCESS_Ap 0
#define TELEMETRY_MODE_Ap_default 0
#define PERIOD_AIRSPEED_Ap_0 (1)
#define PERIOD_ALIVE_Ap_0 (5.1)
#define PERIOD_GPS_Ap_0 (0.25)
#define PERIOD_NAVIGATION_Ap_0 (1.)
#define PERIOD_ATTITUDE_Ap_0 (0.1)
#define PERIOD_ESTIMATOR_Ap_0 (0.5)
#define PERIOD_ENERGY_Ap_0 (2.4)
#define PERIOD_WP_MOVED_Ap_0 (0.5)
#define PERIOD_CIRCLE_Ap_0 (1.05)
#define PERIOD_DESIRED_Ap_0 (0.2)
#define PERIOD_BAT_Ap_0 (1.1)
#define PERIOD_SEGMENT_Ap_0 (1.2)
#define PERIOD_CALIBRATION_Ap_0 (2.1)
#define PERIOD_NAVIGATION_REF_Ap_0 (9.)
#define PERIOD_PPRZ_MODE_Ap_0 (4.9)
#define PERIOD_SETTINGS_Ap_0 (5.)
#define PERIOD_STATE_FILTER_STATUS_Ap_0 (2.2)
#define PERIOD_DOWNLINK_Ap_0 (5.1)
#define PERIOD_DL_VALUE_Ap_0 (1.5)
#define PERIOD_IR_SENSORS_Ap_0 (1.2)
#define PERIOD_SURVEY_Ap_0 (2.1)
#define PERIOD_GPS_SOL_Ap_0 (2.0)
#define PERIOD_IMU_ACCEL_Ap_0 (.8)
#define PERIOD_IMU_GYRO_Ap_0 (.6)
#define PERIOD_IMU_MAG_Ap_0 (1.3)
#define PERIOD_CAM_Ap_0 (0.5)
#define PERIOD_CAM_POINT_Ap_0 (1.0)
#define TELEMETRY_MODE_Ap_minimal 1
#define PERIOD_ALIVE_Ap_1 (5)
#define PERIOD_ATTITUDE_Ap_1 (4)
#define PERIOD_GPS_Ap_1 (1.05)
#define PERIOD_ESTIMATOR_Ap_1 (1.3)
#define PERIOD_WP_MOVED_Ap_1 (1.4)
#define PERIOD_CIRCLE_Ap_1 (3.05)
#define PERIOD_DESIRED_Ap_1 (4.05)
#define PERIOD_BAT_Ap_1 (1.1)
#define PERIOD_SEGMENT_Ap_1 (3.2)
#define PERIOD_CALIBRATION_Ap_1 (5.1)
#define PERIOD_NAVIGATION_REF_Ap_1 (9.)
#define PERIOD_NAVIGATION_Ap_1 (3.)
#define PERIOD_PPRZ_MODE_Ap_1 (5.)
#define PERIOD_STATE_FILTER_STATUS_Ap_1 (5.)
#define PERIOD_DOWNLINK_Ap_1 (5.1)
#define PERIOD_DL_VALUE_Ap_1 (1.5)
#define PERIOD_IR_SENSORS_Ap_1 (5.2)
#define PERIOD_SURVEY_Ap_1 (2.1)
#define PERIOD_GPS_SOL_Ap_1 (5.0)
#define TELEMETRY_MODE_Ap_extremal 2
#define PERIOD_ALIVE_Ap_2 (5)
#define PERIOD_GPS_Ap_2 (5.1)
#define PERIOD_ESTIMATOR_Ap_2 (5.3)
#define PERIOD_BAT_Ap_2 (10.1)
#define PERIOD_DESIRED_Ap_2 (10.2)
#define PERIOD_NAVIGATION_Ap_2 (5.4)
#define PERIOD_PPRZ_MODE_Ap_2 (7.5)
#define PERIOD_STATE_FILTER_STATUS_Ap_2 (8.)
#define PERIOD_DOWNLINK_Ap_2 (5.7)
#define TELEMETRY_MODE_Ap_raw_sensors 3
#define PERIOD_DL_VALUE_Ap_3 (0.5)
#define PERIOD_ALIVE_Ap_3 (2.1)
#define PERIOD_IMU_ACCEL_RAW_Ap_3 (.05)
#define PERIOD_IMU_GYRO_RAW_Ap_3 (.05)
#define PERIOD_IMU_MAG_RAW_Ap_3 (.05)
#define PERIOD_BARO_RAW_Ap_3 (0.5)
#define TELEMETRY_MODE_Ap_scaled_sensors 4
#define PERIOD_DL_VALUE_Ap_4 (0.5)
#define PERIOD_ALIVE_Ap_4 (2.1)
#define PERIOD_IMU_GYRO_Ap_4 (.075)
#define PERIOD_IMU_ACCEL_Ap_4 (.075)
#define PERIOD_IMU_MAG_Ap_4 (.1)
#define TELEMETRY_MODE_Ap_debug_imu 5
#define PERIOD_ATTITUDE_Ap_5 (0.1)
#define PERIOD_ALIVE_Ap_5 (5)
#define PERIOD_GPS_Ap_5 (5.1)
#define PERIOD_ESTIMATOR_Ap_5 (5.3)
#define PERIOD_BAT_Ap_5 (10.1)
#define PERIOD_DESIRED_Ap_5 (10.2)
#define PERIOD_NAVIGATION_Ap_5 (5.4)
#define PERIOD_PPRZ_MODE_Ap_5 (5.5)
#define PERIOD_STATE_FILTER_STATUS_Ap_5 (5.)
#define PERIOD_DOWNLINK_Ap_5 (5.7)
#define PERIOD_IMU_ACCEL_Ap_5 (.5)
#define PERIOD_IMU_GYRO_Ap_5 (.5)
#define PERIOD_IMU_MAG_Ap_5 (.5)
#define PERIOD_IMU_ACCEL_RAW_Ap_5 (.5)
#define PERIOD_IMU_GYRO_RAW_Ap_5 (.5)
#define PERIOD_IMU_MAG_RAW_Ap_5 (.5)
#define TELEMETRY_AP_MSG_IMU_ACCEL_RAW_ID 0
#define TELEMETRY_AP_MSG_DOWNLINK_ID 1
#define TELEMETRY_AP_MSG_WP_MOVED_ID 2
#define TELEMETRY_AP_MSG_IMU_GYRO_RAW_ID 3
#define TELEMETRY_AP_MSG_DESIRED_ID 4
#define TELEMETRY_AP_MSG_GPS_SOL_ID 5
#define TELEMETRY_AP_MSG_SURVEY_ID 6
#define TELEMETRY_AP_MSG_ENERGY_ID 7
#define TELEMETRY_AP_MSG_IMU_GYRO_ID 8
#define TELEMETRY_AP_MSG_PPRZ_MODE_ID 9
#define TELEMETRY_AP_MSG_AIRSPEED_ID 10
#define TELEMETRY_AP_MSG_IMU_MAG_RAW_ID 11
#define TELEMETRY_AP_MSG_STATE_FILTER_STATUS_ID 12
#define TELEMETRY_AP_MSG_ESTIMATOR_ID 13
#define TELEMETRY_AP_MSG_GPS_ID 14
#define TELEMETRY_AP_MSG_ALIVE_ID 15
#define TELEMETRY_AP_MSG_BARO_RAW_ID 16
#define TELEMETRY_AP_MSG_IMU_MAG_ID 17
#define TELEMETRY_AP_MSG_IR_SENSORS_ID 18
#define TELEMETRY_AP_MSG_CALIBRATION_ID 19
#define TELEMETRY_AP_MSG_SEGMENT_ID 20
#define TELEMETRY_AP_MSG_NAVIGATION_ID 21
#define TELEMETRY_AP_MSG_IMU_ACCEL_ID 22
#define TELEMETRY_AP_MSG_CAM_POINT_ID 23
#define TELEMETRY_AP_MSG_CAM_ID 24
#define TELEMETRY_AP_MSG_DL_VALUE_ID 25
#define TELEMETRY_AP_MSG_NAVIGATION_REF_ID 26
#define TELEMETRY_AP_MSG_BAT_ID 27
#define TELEMETRY_AP_MSG_CIRCLE_ID 28
#define TELEMETRY_AP_MSG_SETTINGS_ID 29
#define TELEMETRY_AP_MSG_ATTITUDE_ID 30
#define TELEMETRY_AP_NB_MSG 31
#define TELEMETRY_AP_STRUCT { \
  { "IMU_ACCEL_RAW", NULL }, \
  { "DOWNLINK", NULL }, \
  { "WP_MOVED", NULL }, \
  { "IMU_GYRO_RAW", NULL }, \
  { "DESIRED", NULL }, \
  { "GPS_SOL", NULL }, \
  { "SURVEY", NULL }, \
  { "ENERGY", NULL }, \
  { "IMU_GYRO", NULL }, \
  { "PPRZ_MODE", NULL }, \
  { "AIRSPEED", NULL }, \
  { "IMU_MAG_RAW", NULL }, \
  { "STATE_FILTER_STATUS", NULL }, \
  { "ESTIMATOR", NULL }, \
  { "GPS", NULL }, \
  { "ALIVE", NULL }, \
  { "BARO_RAW", NULL }, \
  { "IMU_MAG", NULL }, \
  { "IR_SENSORS", NULL }, \
  { "CALIBRATION", NULL }, \
  { "SEGMENT", NULL }, \
  { "NAVIGATION", NULL }, \
  { "IMU_ACCEL", NULL }, \
  { "CAM_POINT", NULL }, \
  { "CAM", NULL }, \
  { "DL_VALUE", NULL }, \
  { "NAVIGATION_REF", NULL }, \
  { "BAT", NULL }, \
  { "CIRCLE", NULL }, \
  { "SETTINGS", NULL }, \
  { "ATTITUDE", NULL }, \
};

/* Functions for Ap process */
#ifdef PERIODIC_C_AP
#ifndef TELEMETRY_MODE_AP
#define TELEMETRY_MODE_AP 0
#endif
uint8_t telemetry_mode_Ap = TELEMETRY_MODE_AP;
struct telemetry_msg telemetry_msg_Ap[TELEMETRY_AP_NB_MSG] = TELEMETRY_AP_STRUCT;
struct pprz_telemetry telemetry_Ap = { TELEMETRY_AP_NB_MSG, telemetry_msg_Ap };
#else /* PERIODIC_C_AP not defined (general header) */
extern uint8_t telemetry_mode_Ap;
extern struct telemetry_msg telemetry_msg_Ap[TELEMETRY_AP_NB_MSG];
extern struct pprz_telemetry telemetry_Ap;
#endif /* PERIODIC_C_AP */
static inline void periodic_telemetry_send_Ap(void) {  /* 60Hz */
  if (telemetry_mode_Ap == TELEMETRY_MODE_Ap_default) {
    static uint8_t i6 = 0; i6++; if (i6>=6) i6=0;
    static uint8_t i12 = 0; i12++; if (i12>=12) i12=0;
    static uint8_t i15 = 0; i15++; if (i15>=15) i15=0;
    static uint8_t i30 = 0; i30++; if (i30>=30) i30=0;
    static uint8_t i36 = 0; i36++; if (i36>=36) i36=0;
    static uint8_t i48 = 0; i48++; if (i48>=48) i48=0;
    static uint8_t i60 = 0; i60++; if (i60>=60) i60=0;
    static uint8_t i63 = 0; i63++; if (i63>=63) i63=0;
    static uint8_t i66 = 0; i66++; if (i66>=66) i66=0;
    static uint8_t i72 = 0; i72++; if (i72>=72) i72=0;
    static uint8_t i78 = 0; i78++; if (i78>=78) i78=0;
    static uint8_t i90 = 0; i90++; if (i90>=90) i90=0;
    static uint8_t i120 = 0; i120++; if (i120>=120) i120=0;
    static uint8_t i126 = 0; i126++; if (i126>=126) i126=0;
    static uint8_t i132 = 0; i132++; if (i132>=132) i132=0;
    static uint8_t i144 = 0; i144++; if (i144>=144) i144=0;
    static uint16_t i294 = 0; i294++; if (i294>=294) i294=0;
    static uint16_t i300 = 0; i300++; if (i300>=300) i300=0;
    static uint16_t i306 = 0; i306++; if (i306>=306) i306=0;
    static uint16_t i540 = 0; i540++; if (i540>=540) i540=0;
    if (i540 == 0) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_NAVIGATION_REF_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_NAVIGATION_REF_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_NAVIGATION_REF_ID);
#endif
    }
    if (i306 == 6) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_DOWNLINK_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_DOWNLINK_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_DOWNLINK_ID);
#endif
    }
    else if (i306 == 12) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_ALIVE_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_ALIVE_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_ALIVE_ID);
#endif
    }
    if (i300 == 18) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_SETTINGS_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_SETTINGS_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_SETTINGS_ID);
#endif
    }
    if (i294 == 24) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_PPRZ_MODE_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_PPRZ_MODE_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_PPRZ_MODE_ID);
#endif
    }
    if (i144 == 30) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_ENERGY_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_ENERGY_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_ENERGY_ID);
#endif
    }
    if (i132 == 36) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_STATE_FILTER_STATUS_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_STATE_FILTER_STATUS_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_STATE_FILTER_STATUS_ID);
#endif
    }
    if (i126 == 42) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_SURVEY_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_SURVEY_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_SURVEY_ID);
#endif
    }
    else if (i126 == 48) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_CALIBRATION_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_CALIBRATION_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_CALIBRATION_ID);
#endif
    }
    if (i120 == 54) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_GPS_SOL_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_GPS_SOL_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_GPS_SOL_ID);
#endif
    }
    if (i90 == 60) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_DL_VALUE_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_DL_VALUE_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_DL_VALUE_ID);
#endif
    }
    if (i78 == 66) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_MAG_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_MAG_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_IMU_MAG_ID);
#endif
    }
    if (i72 == 0) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_IR_SENSORS_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_IR_SENSORS_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_IR_SENSORS_ID);
#endif
    }
    else if (i72 == 6) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_SEGMENT_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_SEGMENT_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_SEGMENT_ID);
#endif
    }
    if (i66 == 12) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_BAT_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_BAT_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_BAT_ID);
#endif
    }
    if (i63 == 18) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_CIRCLE_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_CIRCLE_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_CIRCLE_ID);
#endif
    }
    if (i60 == 24) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_CAM_POINT_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_CAM_POINT_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_CAM_POINT_ID);
#endif
    }
    else if (i60 == 30) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_NAVIGATION_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_NAVIGATION_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_NAVIGATION_ID);
#endif
    }
    else if (i60 == 36) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_AIRSPEED_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_AIRSPEED_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_AIRSPEED_ID);
#endif
    }
    if (i48 == 42) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_ACCEL_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_ACCEL_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_IMU_ACCEL_ID);
#endif
    }
    if (i36 == 12) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_GYRO_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_GYRO_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_IMU_GYRO_ID);
#endif
    }
    if (i30 == 18) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_CAM_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_CAM_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_CAM_ID);
#endif
    }
    else if (i30 == 24) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_WP_MOVED_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_WP_MOVED_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_WP_MOVED_ID);
#endif
    }
    else if (i30 == 0) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_ESTIMATOR_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_ESTIMATOR_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_ESTIMATOR_ID);
#endif
    }
    if (i15 == 6) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_GPS_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_GPS_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_GPS_ID);
#endif
    }
    if (i12 == 0) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_DESIRED_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_DESIRED_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_DESIRED_ID);
#endif
    }
    if (i6 == 0) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_ATTITUDE_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_ATTITUDE_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_ATTITUDE_ID);
#endif
    }
  }
  if (telemetry_mode_Ap == TELEMETRY_MODE_Ap_minimal) {
    static uint8_t i63 = 0; i63++; if (i63>=63) i63=0;
    static uint8_t i66 = 0; i66++; if (i66>=66) i66=0;
    static uint8_t i78 = 0; i78++; if (i78>=78) i78=0;
    static uint8_t i84 = 0; i84++; if (i84>=84) i84=0;
    static uint8_t i90 = 0; i90++; if (i90>=90) i90=0;
    static uint8_t i126 = 0; i126++; if (i126>=126) i126=0;
    static uint8_t i180 = 0; i180++; if (i180>=180) i180=0;
    static uint8_t i183 = 0; i183++; if (i183>=183) i183=0;
    static uint8_t i192 = 0; i192++; if (i192>=192) i192=0;
    static uint8_t i240 = 0; i240++; if (i240>=240) i240=0;
    static uint8_t i243 = 0; i243++; if (i243>=243) i243=0;
    static uint16_t i300 = 0; i300++; if (i300>=300) i300=0;
    static uint16_t i306 = 0; i306++; if (i306>=306) i306=0;
    static uint16_t i312 = 0; i312++; if (i312>=312) i312=0;
    static uint16_t i540 = 0; i540++; if (i540>=540) i540=0;
    if (i540 == 0) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_NAVIGATION_REF_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_NAVIGATION_REF_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_NAVIGATION_REF_ID);
#endif
    }
    if (i312 == 6) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_IR_SENSORS_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_IR_SENSORS_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_IR_SENSORS_ID);
#endif
    }
    if (i306 == 12) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_DOWNLINK_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_DOWNLINK_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_DOWNLINK_ID);
#endif
    }
    else if (i306 == 18) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_CALIBRATION_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_CALIBRATION_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_CALIBRATION_ID);
#endif
    }
    if (i300 == 24) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_GPS_SOL_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_GPS_SOL_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_GPS_SOL_ID);
#endif
    }
    else if (i300 == 30) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_STATE_FILTER_STATUS_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_STATE_FILTER_STATUS_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_STATE_FILTER_STATUS_ID);
#endif
    }
    else if (i300 == 36) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_PPRZ_MODE_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_PPRZ_MODE_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_PPRZ_MODE_ID);
#endif
    }
    else if (i300 == 42) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_ALIVE_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_ALIVE_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_ALIVE_ID);
#endif
    }
    if (i243 == 48) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_DESIRED_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_DESIRED_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_DESIRED_ID);
#endif
    }
    if (i240 == 54) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_ATTITUDE_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_ATTITUDE_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_ATTITUDE_ID);
#endif
    }
    if (i192 == 60) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_SEGMENT_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_SEGMENT_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_SEGMENT_ID);
#endif
    }
    if (i183 == 66) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_CIRCLE_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_CIRCLE_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_CIRCLE_ID);
#endif
    }
    if (i180 == 72) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_NAVIGATION_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_NAVIGATION_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_NAVIGATION_ID);
#endif
    }
    if (i126 == 78) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_SURVEY_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_SURVEY_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_SURVEY_ID);
#endif
    }
    if (i90 == 84) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_DL_VALUE_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_DL_VALUE_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_DL_VALUE_ID);
#endif
    }
    if (i84 == 6) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_WP_MOVED_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_WP_MOVED_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_WP_MOVED_ID);
#endif
    }
    if (i78 == 12) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_ESTIMATOR_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_ESTIMATOR_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_ESTIMATOR_ID);
#endif
    }
    if (i66 == 18) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_BAT_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_BAT_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_BAT_ID);
#endif
    }
    if (i63 == 24) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_GPS_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_GPS_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_GPS_ID);
#endif
    }
  }
  if (telemetry_mode_Ap == TELEMETRY_MODE_Ap_extremal) {
    static uint16_t i300 = 0; i300++; if (i300>=300) i300=0;
    static uint16_t i306 = 0; i306++; if (i306>=306) i306=0;
    static uint16_t i318 = 0; i318++; if (i318>=318) i318=0;
    static uint16_t i324 = 0; i324++; if (i324>=324) i324=0;
    static uint16_t i342 = 0; i342++; if (i342>=342) i342=0;
    static uint16_t i450 = 0; i450++; if (i450>=450) i450=0;
    static uint16_t i480 = 0; i480++; if (i480>=480) i480=0;
    static uint16_t i606 = 0; i606++; if (i606>=606) i606=0;
    static uint16_t i612 = 0; i612++; if (i612>=612) i612=0;
    if (i612 == 0) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_DESIRED_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_DESIRED_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_DESIRED_ID);
#endif
    }
    if (i606 == 6) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_BAT_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_BAT_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_BAT_ID);
#endif
    }
    if (i480 == 12) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_STATE_FILTER_STATUS_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_STATE_FILTER_STATUS_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_STATE_FILTER_STATUS_ID);
#endif
    }
    if (i450 == 18) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_PPRZ_MODE_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_PPRZ_MODE_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_PPRZ_MODE_ID);
#endif
    }
    if (i342 == 24) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_DOWNLINK_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_DOWNLINK_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_DOWNLINK_ID);
#endif
    }
    if (i324 == 30) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_NAVIGATION_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_NAVIGATION_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_NAVIGATION_ID);
#endif
    }
    if (i318 == 36) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_ESTIMATOR_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_ESTIMATOR_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_ESTIMATOR_ID);
#endif
    }
    if (i306 == 42) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_GPS_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_GPS_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_GPS_ID);
#endif
    }
    if (i300 == 48) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_ALIVE_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_ALIVE_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_ALIVE_ID);
#endif
    }
  }
  if (telemetry_mode_Ap == TELEMETRY_MODE_Ap_raw_sensors) {
    static uint8_t i3 = 0; i3++; if (i3>=3) i3=0;
    static uint8_t i30 = 0; i30++; if (i30>=30) i30=0;
    static uint8_t i126 = 0; i126++; if (i126>=126) i126=0;
    if (i126 == 0) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_ALIVE_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_ALIVE_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_ALIVE_ID);
#endif
    }
    if (i30 == 6) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_BARO_RAW_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_BARO_RAW_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_BARO_RAW_ID);
#endif
    }
    else if (i30 == 12) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_DL_VALUE_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_DL_VALUE_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_DL_VALUE_ID);
#endif
    }
    if (i3 == 0) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_MAG_RAW_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_MAG_RAW_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_IMU_MAG_RAW_ID);
#endif
    }
    if (i3 == 0) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_GYRO_RAW_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_GYRO_RAW_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_IMU_GYRO_RAW_ID);
#endif
    }
    if (i3 == 0) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_ACCEL_RAW_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_ACCEL_RAW_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_IMU_ACCEL_RAW_ID);
#endif
    }
  }
  if (telemetry_mode_Ap == TELEMETRY_MODE_Ap_scaled_sensors) {
    static uint8_t i4 = 0; i4++; if (i4>=4) i4=0;
    static uint8_t i6 = 0; i6++; if (i6>=6) i6=0;
    static uint8_t i30 = 0; i30++; if (i30>=30) i30=0;
    static uint8_t i126 = 0; i126++; if (i126>=126) i126=0;
    if (i126 == 0) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_ALIVE_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_ALIVE_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_ALIVE_ID);
#endif
    }
    if (i30 == 6) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_DL_VALUE_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_DL_VALUE_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_DL_VALUE_ID);
#endif
    }
    if (i6 == 0) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_MAG_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_MAG_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_IMU_MAG_ID);
#endif
    }
    if (i4 == 2) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_ACCEL_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_ACCEL_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_IMU_ACCEL_ID);
#endif
    }
    else if (i4 == 0) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_GYRO_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_GYRO_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_IMU_GYRO_ID);
#endif
    }
  }
  if (telemetry_mode_Ap == TELEMETRY_MODE_Ap_debug_imu) {
    static uint8_t i6 = 0; i6++; if (i6>=6) i6=0;
    static uint8_t i30 = 0; i30++; if (i30>=30) i30=0;
    static uint16_t i300 = 0; i300++; if (i300>=300) i300=0;
    static uint16_t i306 = 0; i306++; if (i306>=306) i306=0;
    static uint16_t i318 = 0; i318++; if (i318>=318) i318=0;
    static uint16_t i324 = 0; i324++; if (i324>=324) i324=0;
    static uint16_t i330 = 0; i330++; if (i330>=330) i330=0;
    static uint16_t i342 = 0; i342++; if (i342>=342) i342=0;
    static uint16_t i606 = 0; i606++; if (i606>=606) i606=0;
    static uint16_t i612 = 0; i612++; if (i612>=612) i612=0;
    if (i612 == 0) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_DESIRED_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_DESIRED_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_DESIRED_ID);
#endif
    }
    if (i606 == 6) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_BAT_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_BAT_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_BAT_ID);
#endif
    }
    if (i342 == 12) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_DOWNLINK_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_DOWNLINK_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_DOWNLINK_ID);
#endif
    }
    if (i330 == 18) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_PPRZ_MODE_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_PPRZ_MODE_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_PPRZ_MODE_ID);
#endif
    }
    if (i324 == 24) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_NAVIGATION_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_NAVIGATION_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_NAVIGATION_ID);
#endif
    }
    if (i318 == 30) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_ESTIMATOR_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_ESTIMATOR_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_ESTIMATOR_ID);
#endif
    }
    if (i306 == 36) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_GPS_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_GPS_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_GPS_ID);
#endif
    }
    if (i300 == 42) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_STATE_FILTER_STATUS_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_STATE_FILTER_STATUS_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_STATE_FILTER_STATUS_ID);
#endif
    }
    else if (i300 == 48) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_ALIVE_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_ALIVE_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_ALIVE_ID);
#endif
    }
    if (i30 == 24) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_MAG_RAW_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_MAG_RAW_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_IMU_MAG_RAW_ID);
#endif
    }
    else if (i30 == 0) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_GYRO_RAW_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_GYRO_RAW_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_IMU_GYRO_RAW_ID);
#endif
    }
    else if (i30 == 6) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_ACCEL_RAW_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_ACCEL_RAW_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_IMU_ACCEL_RAW_ID);
#endif
    }
    else if (i30 == 12) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_MAG_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_MAG_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_IMU_MAG_ID);
#endif
    }
    else if (i30 == 18) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_GYRO_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_GYRO_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_IMU_GYRO_ID);
#endif
    }
    if (i30 == 24) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_ACCEL_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_IMU_ACCEL_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_IMU_ACCEL_ID);
#endif
    }
    if (i6 == 0) {
      if (telemetry_Ap.msgs[TELEMETRY_AP_MSG_ATTITUDE_ID].cb != NULL)
        telemetry_Ap.msgs[TELEMETRY_AP_MSG_ATTITUDE_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Ap, telemetry_mode_Ap, TELEMETRY_AP_MSG_ATTITUDE_ID);
#endif
    }
  }
}

/* Periodic telemetry: Fbw process */
#define TELEMETRY_PROCESS_Fbw 0
#define TELEMETRY_MODE_Fbw_default 0
#define PERIOD_COMMANDS_Fbw_0 (5)
#define PERIOD_FBW_STATUS_Fbw_0 (2)
#define PERIOD_ACTUATORS_Fbw_0 (5)
#define TELEMETRY_MODE_Fbw_debug 1
#define PERIOD_PPM_Fbw_1 (0.5)
#define PERIOD_RC_Fbw_1 (0.5)
#define PERIOD_COMMANDS_Fbw_1 (0.5)
#define PERIOD_FBW_STATUS_Fbw_1 (1)
#define PERIOD_ACTUATORS_Fbw_1 (5)
#define TELEMETRY_FBW_MSG_RC_ID 0
#define TELEMETRY_FBW_MSG_COMMANDS_ID 1
#define TELEMETRY_FBW_MSG_ACTUATORS_ID 2
#define TELEMETRY_FBW_MSG_PPM_ID 3
#define TELEMETRY_FBW_MSG_FBW_STATUS_ID 4
#define TELEMETRY_FBW_NB_MSG 5
#define TELEMETRY_FBW_STRUCT { \
  { "RC", NULL }, \
  { "COMMANDS", NULL }, \
  { "ACTUATORS", NULL }, \
  { "PPM", NULL }, \
  { "FBW_STATUS", NULL }, \
};

/* Functions for Fbw process */
#ifdef PERIODIC_C_FBW
#ifndef TELEMETRY_MODE_FBW
#define TELEMETRY_MODE_FBW 0
#endif
uint8_t telemetry_mode_Fbw = TELEMETRY_MODE_FBW;
struct telemetry_msg telemetry_msg_Fbw[TELEMETRY_FBW_NB_MSG] = TELEMETRY_FBW_STRUCT;
struct pprz_telemetry telemetry_Fbw = { TELEMETRY_FBW_NB_MSG, telemetry_msg_Fbw };
#else /* PERIODIC_C_FBW not defined (general header) */
extern uint8_t telemetry_mode_Fbw;
extern struct telemetry_msg telemetry_msg_Fbw[TELEMETRY_FBW_NB_MSG];
extern struct pprz_telemetry telemetry_Fbw;
#endif /* PERIODIC_C_FBW */
static inline void periodic_telemetry_send_Fbw(void) {  /* 60Hz */
  if (telemetry_mode_Fbw == TELEMETRY_MODE_Fbw_default) {
    static uint8_t i120 = 0; i120++; if (i120>=120) i120=0;
    static uint16_t i300 = 0; i300++; if (i300>=12) i300=0;
    if (i300 == 0) {
      if (telemetry_Fbw.msgs[TELEMETRY_FBW_MSG_ACTUATORS_ID].cb != NULL)
        telemetry_Fbw.msgs[TELEMETRY_FBW_MSG_ACTUATORS_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Fbw, telemetry_mode_Fbw, TELEMETRY_FBW_MSG_ACTUATORS_ID);
#endif
    }
    else if (i300 == 6) {
      if (telemetry_Fbw.msgs[TELEMETRY_FBW_MSG_COMMANDS_ID].cb != NULL)
        telemetry_Fbw.msgs[TELEMETRY_FBW_MSG_COMMANDS_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Fbw, telemetry_mode_Fbw, TELEMETRY_FBW_MSG_COMMANDS_ID);
#endif
    }
    if (i120 == 12) {
      if (telemetry_Fbw.msgs[TELEMETRY_FBW_MSG_FBW_STATUS_ID].cb != NULL)
        telemetry_Fbw.msgs[TELEMETRY_FBW_MSG_FBW_STATUS_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Fbw, telemetry_mode_Fbw, TELEMETRY_FBW_MSG_FBW_STATUS_ID);
#endif
    }
  }
  if (telemetry_mode_Fbw == TELEMETRY_MODE_Fbw_debug) {
    static uint8_t i30 = 0; i30++; if (i30>=30) i30=0;
    static uint8_t i60 = 0; i60++; if (i60>=60) i60=0;
    static uint16_t i300 = 0; i300++; if (i300>=300) i300=0;
    if (i300 == 0) {
      if (telemetry_Fbw.msgs[TELEMETRY_FBW_MSG_ACTUATORS_ID].cb != NULL)
        telemetry_Fbw.msgs[TELEMETRY_FBW_MSG_ACTUATORS_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Fbw, telemetry_mode_Fbw, TELEMETRY_FBW_MSG_ACTUATORS_ID);
#endif
    }
    if (i60 == 6) {
      if (telemetry_Fbw.msgs[TELEMETRY_FBW_MSG_FBW_STATUS_ID].cb != NULL)
        telemetry_Fbw.msgs[TELEMETRY_FBW_MSG_FBW_STATUS_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Fbw, telemetry_mode_Fbw, TELEMETRY_FBW_MSG_FBW_STATUS_ID);
#endif
    }
    if (i30 == 12) {
      if (telemetry_Fbw.msgs[TELEMETRY_FBW_MSG_COMMANDS_ID].cb != NULL)
        telemetry_Fbw.msgs[TELEMETRY_FBW_MSG_COMMANDS_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Fbw, telemetry_mode_Fbw, TELEMETRY_FBW_MSG_COMMANDS_ID);
#endif
    }
    else if (i30 == 18) {
      if (telemetry_Fbw.msgs[TELEMETRY_FBW_MSG_RC_ID].cb != NULL)
        telemetry_Fbw.msgs[TELEMETRY_FBW_MSG_RC_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Fbw, telemetry_mode_Fbw, TELEMETRY_FBW_MSG_RC_ID);
#endif
    }
    else if (i30 == 24) {
      if (telemetry_Fbw.msgs[TELEMETRY_FBW_MSG_PPM_ID].cb != NULL)
        telemetry_Fbw.msgs[TELEMETRY_FBW_MSG_PPM_ID].cb();
#if USE_PERIODIC_TELEMETRY_REPORT
      else periodic_telemetry_err_report(TELEMETRY_PROCESS_Fbw, telemetry_mode_Fbw, TELEMETRY_FBW_MSG_PPM_ID);
#endif
    }
  }
}
#endif // _VAR_PERIODIC_H_
