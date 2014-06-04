#ifndef GPS_SIM_NPS_H
#define GPS_SIM_NPS_H
#include "stdint.h"

#define GPS_NB_CHANNELS 16


void gps_feed_value(int32_t ecef_pox_x, int32_t ecef_pox_y,
		int32_t ecef_pox_z, int32_t ecef_vel_x, int32_t ecef_vel_y,
		int32_t ecef_vel_z, int32_t lla_pos_lat, int32_t lla_pos_lon,
		int32_t lla_pos_alt, int32_t hmsl, int32_t pacc, int32_t sacc,
		int32_t tow);

extern void gps_impl_init();


#endif /* GPS_SIM_NPS_H */
