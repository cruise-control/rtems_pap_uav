/* This file has been generated from /home/j3/paparazzi/conf/flight_plans/nav_modules_j.xml */
/* Please DO NOT EDIT */

#ifndef FLIGHT_PLAN_H
#define FLIGHT_PLAN_H

#include "std.h"
#include "generated/modules.h"
#include "subsystems/datalink/datalink.h"
#include "modules/digital_cam/dc.h"
#define LINE_START_FUNCTION dc_Survey(40);
#define LINE_STOP_FUNCTION dc_autoshoot = DC_AUTOSHOOT_STOP;
#define FLIGHT_PLAN_NAME "Basic"
#define NAV_UTM_EAST0 360285
#define NAV_UTM_NORTH0 4813595
#define NAV_UTM_ZONE0 31
#define NAV_LAT0 434622300 /* 1e7deg */
#define NAV_LON0 12728900 /* 1e7deg */
#define NAV_ALT0 185000 /* mm above msl */
#define NAV_MSL0 51850 /* mm, EGM96 geoid-height (msl) over ellipsoid */
#define QFU 0.0
#define WP_dummy 0
#define WP_HOME 1
#define WP_STDBY 2
#define WP_1 3
#define WP_2 4
#define WP_MOB 5
#define WP_S1 6
#define WP_S2 7
#define WP_S3 8
#define WP_S4 9
#define WP_S5 10
#define WP_AF 11
#define WP_TD 12
#define WP__BASELEG 13
#define WP_CLIMB 14
#define WAYPOINTS { \
 {42.0, 42.0, 260},\
 {0.0, 0.0, 260},\
 {49.5, 100.1, 260},\
 {-337.0, 17.0, 260},\
 {230.0, -30.0, 260},\
 {137.0, -11.6, 260},\
 {-109.0, 245.9, 260},\
 {274.4, 209.5, 260},\
 {322.1, 29.9, 260},\
 {0.8, -68.1, 260},\
 {-239.9, 81.8, 260},\
 {177.4, 45.1, 215.0},\
 {28.8, 57.0, 185.0},\
 {168.8, -13.8, 260},\
 {-150.0, 50.0, 260},\
};
#define WAYPOINTS_LLA { \
 {434626158, 12733981, 26000}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434622299, 12728900, 26000}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434631401, 12734759, 26000}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434623200, 12687216, 26000}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434620028, 12757395, 26000}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434621511, 12745857, 26000}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434644228, 12714801, 26000}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434641667, 12762269, 26000}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434625591, 12768622, 26000}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434616172, 12729173, 26000}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434629213, 12699047, 26000}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434626690, 12750704, 21500}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434627483, 12732312, 18500}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434621372, 12749792, 26000}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
 {434626519, 12710237, 26000}, /* 1e7deg, 1e7deg, cm (hmsl=51.85m) */ \
};
#define NB_WAYPOINT 15
#define FP_BLOCKS { \
 { "Wait GPS" }, \
 { "Geo init" }, \
 { "Holding point" }, \
 { "Takeoff" }, \
 { "Standby" }, \
 { "Figure 8 around wp 1" }, \
 { "Oval 1-2" }, \
 { "MOB" }, \
 { "Line 1-2" }, \
 { "Survey S1-S3" }, \
 { "Bungee take-off" }, \
 { "Poly Survey" }, \
 { "Border line 1-2" }, \
 { "Smooth nav (wp 1-2)" }, \
 { "Flower (wp 1-2)" }, \
 { "Poly survey osam" }, \
 { "Flight Line block" }, \
 { "Vertical Raster" }, \
 { "Land Right AF-TD" }, \
 { "Land Left AF-TD" }, \
 { "land" }, \
 { "final" }, \
 { "flare" }, \
 { "HOME" }, \
};
#define NB_BLOCK 24
#define GROUND_ALT 185.
#define GROUND_ALT_CM 18500
#define SECURITY_HEIGHT 25.
#define SECURITY_ALT 210.
#define HOME_MODE_HEIGHT 25.
#define MAX_DIST_FROM_HOME 1500.
static inline bool_t InsidePOLY_SURVEY(float _x, float _y) { \
  if (_y <= 81.8) {
    if (_y <= 29.9) {
      if (_y <= -68.1) {
        return FALSE;
      } else {
        float dy = _y - 29.9;
        return (-156.6+dy*-1.605737<= _x && _x <= 322.1+dy*3.278571);
      }
    } else {
      float dy = _y - 81.8;
      return (-239.9+dy*-1.605737<= _x && _x <= 308.3+dy*-0.265590);
    }
  } else {
    if (_y <= 245.9) {
      if (_y <= 209.5) {
        float dy = _y - 209.5;
        return (-138.0+dy*0.797684<= _x && _x <= 274.4+dy*-0.265590);
      } else {
        float dy = _y - 245.9;
        return (-109.0+dy*0.797684<= _x && _x <= -109.0+dy*-10.532967);
      }
    } else {
      return FALSE;
    }
  }
}
#ifdef NAV_C

static inline void auto_nav(void) {
  switch (nav_block) {
    Block(0) // Wait GPS
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        kill_throttle = 1;
        NextStageAndBreak();
        break;
      Label(while_1)
      Stage(1)
        if (! (!(GpsFixValid()))) Goto(endwhile_2) else NextStageAndBreak();
        Stage(2)
          Goto(while_1)
        Label(endwhile_2)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(1) // Geo init
    ; // pre_call
    switch(nav_stage) {
      Label(while_3)
      Stage(0)
        if (! (LessThan(NavBlockTime(),10))) Goto(endwhile_4) else NextStageAndBreak();
        Stage(1)
          Goto(while_3)
        Label(endwhile_4)
      Stage(2)
        if (! (NavSetGroundReferenceHere()))
          NextStageAndBreak();
        break;
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(2) // Holding point
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        kill_throttle = 1;
        NextStageAndBreak();
        break;
      Stage(1)
        {
          NavAttitude(RadOfDeg(0));
          NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
          NavVerticalThrottleMode(9600*(0));
        }
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(3) // Takeoff
    ; // pre_call
    if ((nav_block != 4) && (GetPosAlt()>(ground_alt+25))) { GotoBlock(4); return; }
    switch(nav_stage) {
      Stage(0)
        kill_throttle = 0;
        NextStageAndBreak();
        break;
      Stage(1)
        autopilot_flight_time = 0;
        NextStageAndBreak();
        break;
      Stage(2)
        if (NavApproachingFrom(14,1,CARROT)) NextStageAndBreakFrom(14) else {
          NavGotoWaypoint(14);
          NavVerticalAutoThrottleMode(RadOfDeg(15));
          NavVerticalThrottleMode(9600*(1.000000));
        }
        break;
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(8) // Standby
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
        NavVerticalAltitudeMode(WaypointAlt(2), 0.);
        NavCircleWaypoint(2, nav_radius);
        break;
      default:
      Stage(1)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(5) // Figure 8 around wp 1
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        nav_eight_init();
        NextStageAndBreak();
      Stage(1)
        NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
        NavVerticalAltitudeMode(WaypointAlt(3), 0.);
        Eight(3, 4, nav_radius);
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(6) // Oval 1-2
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        nav_oval_init();
        NextStageAndBreak();
      Stage(1)
        NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
        NavVerticalAltitudeMode(WaypointAlt(3), 0.);
        Oval(3, 4, nav_radius);
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(7) // MOB
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (! (NavSetWaypointHere(WP_MOB)))
          NextStageAndBreak();
        break;
      Stage(1)
        nav_radius = DEFAULT_CIRCLE_RADIUS;
        NextStageAndBreak();
        break;
      Stage(2)
        NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
        NavVerticalAltitudeMode(WaypointAlt(5), 0.);
        NavCircleWaypoint(5, nav_radius);
        break;
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(4) // Line 1-2
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (! (nav_line_setup()))
          NextStageAndBreak();
        break;
      Stage(1)
        if (! (nav_line_run(WP_1, WP_2, nav_radius)))
          NextStageAndBreak();
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(9) // Survey S1-S3
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        NavSurveyRectangleInit(6, 8, 150, NS);
        NextStageAndBreak();
      Stage(1)
        NavSurveyRectangle(6, 8);
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(10) // Bungee take-off
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (! (nav_bungee_takeoff_setup(WP_HOME)))
          NextStageAndBreak();
        break;
      Stage(1)
        if (! (nav_bungee_takeoff_run()))
          NextStageAndBreak();
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(11) // Poly Survey
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (! (nav_survey_polygon_setup(WP_S1,5,80,30,10,50,ground_alt+60)))
          NextStageAndBreak();
        break;
      Stage(1)
        if (! (nav_survey_polygon_run()))
          NextStageAndBreak();
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(12) // Border line 1-2
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (! (nav_line_border_setup()))
          NextStageAndBreak();
        break;
      Stage(1)
        if (! (nav_line_border_run(WP_1, WP_2, nav_radius)))
          NextStageAndBreak();
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(13) // Smooth nav (wp 1-2)
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        snav_desired_tow = ((gps.tow/1000.000000)+60.000000);
        NextStageAndBreak();
        break;
      Stage(1)
        if (! (snav_init(WP_1, M_PI_2-atan2(WaypointY(WP_2)-WaypointY(WP_1),WaypointX(WP_2)-WaypointX(WP_1)), DEFAULT_CIRCLE_RADIUS/2.)))
          NextStageAndBreak();
        break;
      Stage(2)
        if (! (snav_circle1()))
          NextStageAndBreak();
        break;
      Stage(3)
        if (! (snav_route()))
          NextStageAndBreak();
        break;
      Stage(4)
        if (! (snav_circle2()))
          NextStageAndBreak();
        break;
      Stage(5)
        if (! (snav_on_time(DEFAULT_CIRCLE_RADIUS)))
          NextStageAndBreak();
        break;
      Stage(6)
        if (NavApproachingFrom(4,3,CARROT)) NextStageAndBreakFrom(4) else {
          NavSegment(3, 4);
          NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
          NavVerticalAltitudeMode(WaypointAlt(4), 0.);
        }
        break;
      Stage(7)
        GotoBlock(4);
        break;
      default:
      Stage(8)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(14) // Flower (wp 1-2)
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (! (nav_flower_setup(WP_1, WP_2)))
          NextStageAndBreak();
        break;
      Stage(1)
        if (! (nav_flower_run()))
          NextStageAndBreak();
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(15) // Poly survey osam
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (! (nav_survey_poly_osam_setup(WP_S1, 5, 100, 45)))
          NextStageAndBreak();
        break;
      Stage(1)
        if (! (nav_survey_poly_osam_run()))
          NextStageAndBreak();
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(16) // Flight Line block
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (! (nav_line_osam_block_run(WP_S1, WP_S5, nav_radius, 30, 10)))
          NextStageAndBreak();
        break;
      default:
      Stage(1)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(17) // Vertical Raster
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (! (nav_vertical_raster_setup()))
          NextStageAndBreak();
        break;
      Stage(1)
        if (! (nav_vertical_raster_run(WP_S1, WP_S2, nav_radius, 50)))
          NextStageAndBreak();
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(18) // Land Right AF-TD
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        nav_radius = DEFAULT_CIRCLE_RADIUS;
        NextStageAndBreak();
        break;
      Stage(1)
        GotoBlock(20);
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(19) // Land Left AF-TD
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        nav_radius = -(DEFAULT_CIRCLE_RADIUS);
        NextStageAndBreak();
        break;
      Stage(1)
        GotoBlock(20);
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(20) // land
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (! (nav_compute_baseleg(WP_AF, WP_TD, WP__BASELEG, nav_radius)))
          NextStageAndBreak();
        break;
      Stage(1)
        NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
        NavVerticalAltitudeMode(WaypointAlt(13), 0.);
        NavCircleWaypoint(13, nav_radius);
        if ((NavCircleCount()>0.500000)) NextStageAndBreak();
        break;
      Stage(2)
        NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
        NavVerticalAltitudeMode(WaypointAlt(13), 0.);
        NavCircleWaypoint(13, nav_radius);
        if (And(NavQdrCloseTo((DegOfRad(baseleg_out_qdr)-((nav_radius/fabs(nav_radius))*10))),(10>fabs((GetPosAlt()-WaypointAlt(WP__BASELEG)))))) NextStageAndBreak();
        break;
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(21) // final
    ; // pre_call
    if ((nav_block != 22) && ((ground_alt+10)>GetPosAlt())) { GotoBlock(22); return; }
    switch(nav_stage) {
      Stage(0)
        if (NavApproachingFrom(12,11,CARROT)) NextStageAndBreakFrom(12) else {
          NavSegment(11, 12);
          NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
          NavGlide(11, 12);
        }
        break;
      default:
      Stage(1)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(22) // flare
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (NavApproachingFrom(12,11,0)) NextStageAndBreakFrom(12) else {
          NavSegment(11, 12);
          NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
          NavVerticalThrottleMode(9600*(0.000000));
        }
        break;
      Stage(1)
        if (FALSE) NextStageAndBreak() else {
          NavAttitude(RadOfDeg(0.000000));
          NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
          NavVerticalThrottleMode(9600*(0.000000));
        }
        break;
      default:
      Stage(2)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(23) // HOME
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        nav_home();
        break;
      default:
      Stage(1)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    default: break;
  }
}
#endif // NAV_C

#endif // FLIGHT_PLAN_H
