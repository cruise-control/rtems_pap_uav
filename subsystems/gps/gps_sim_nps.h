#ifndef GPS_SIM_NPS_H
#define GPS_SIM_NPS_H
#include "includes/std.h"
//#include "nps_sensors.h"

#define GPS_NB_CHANNELS 16

extern bool_t gps_available;
extern bool_t gps_has_fix;

extern void gps_feed_value(int32_t ecef_pox_x, int32_t ecef_pox_y, int32_t ecef_pox_z,
		int32_t ecef_vel_x, int32_t ecef_vel_y, int32_t ecef_vel_z,
		int32_t lla_pos_lat, int32_t lla_pos_lon, int32_t lla_pos_alt,
		int32_t hmsl, int32_t pacc, int32_t sacc, int32_t tow);

extern void gps_impl_init();

#define GpsEvent(_sol_available_callback) {         \
    if (gps_available) {                            \
      gps.last_msg_ticks = sys_time.nb_sec_rem;     \
      gps.last_msg_time = sys_time.nb_sec;          \
      if (gps.fix == GPS_FIX_3D) {                  \
        gps.last_3dfix_ticks = sys_time.nb_sec_rem; \
        gps.last_3dfix_time = sys_time.nb_sec;      \
      }                                             \
      _sol_available_callback();                    \
      gps_available = FALSE;                        \
    }                                               \
  }

#endif /* GPS_SIM_NPS_H */
