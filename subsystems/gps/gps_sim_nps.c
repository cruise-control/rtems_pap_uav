/*
 * Copyright (C) 2008-2011 The Paparazzi Team
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

#include "subsystems/gps/gps_sim_nps.h"
#include "subsystems/gps.h"

#if GPS_USE_LATLONG
/* currently needed to get nav_utm_zone0 */
#include "subsystems/navigation/common_nav.h"
#include "math/pprz_geodetic_float.h"
#endif

#include "math/pprz_geodetic_double.h"

bool_t gps_available;
bool_t gps_has_fix;

//void  gps_feed_value() {
//  gps.ecef_pos.x = sensors.gps.ecef_pos.x * 100.;
//  gps.ecef_pos.y = sensors.gps.ecef_pos.y * 100.;
//  gps.ecef_pos.z = sensors.gps.ecef_pos.z * 100.;
//  gps.ecef_vel.x = sensors.gps.ecef_vel.x * 100.;
//  gps.ecef_vel.y = sensors.gps.ecef_vel.y * 100.;
//  gps.ecef_vel.z = sensors.gps.ecef_vel.z * 100.;
//  //ecef pos seems to be based on geocentric model, hence we get a very high alt when converted to lla
//  gps.lla_pos.lat = sensors.gps.lla_pos.lat * 1e7;
//  gps.lla_pos.lon = sensors.gps.lla_pos.lon * 1e7;
//  gps.lla_pos.alt = sensors.gps.lla_pos.alt * 1000.;
//  gps.hmsl        = sensors.gps.hmsl * 1000.;
//
//  /* calc NED speed from ECEF */
//  struct LtpDef_d ref_ltp;
//  ltp_def_from_ecef_d(&ref_ltp, &sensors.gps.ecef_pos);
//  struct NedCoor_d ned_vel_d;
//  ned_of_ecef_vect_d(&ned_vel_d, &ref_ltp, &sensors.gps.ecef_vel);
//  gps.ned_vel.x = ned_vel_d.x * 100;
//  gps.ned_vel.y = ned_vel_d.y * 100;
//  gps.ned_vel.z = ned_vel_d.z * 100;
//
//  /* horizontal and 3d ground speed in cm/s */
//  gps.gspeed = sqrt(ned_vel_d.x * ned_vel_d.x + ned_vel_d.y * ned_vel_d.y) * 100;
//  gps.speed_3d = sqrt(ned_vel_d.x * ned_vel_d.x + ned_vel_d.y * ned_vel_d.y + ned_vel_d.z * ned_vel_d.z) * 100;
//
//  /* ground course in radians * 1e7 */
//  gps.course = atan2(ned_vel_d.y, ned_vel_d.x) * 1e7;
//
//#if GPS_USE_LATLONG
//  /* Computes from (lat, long) in the referenced UTM zone */
//  struct LlaCoor_f lla_f;
//  lla_f.lat = ((float) gps.lla_pos.lat) / 1e7;
//  lla_f.lon = ((float) gps.lla_pos.lon) / 1e7;
//  struct UtmCoor_f utm_f;
//  utm_f.zone = nav_utm_zone0;
//  /* convert to utm */
//  utm_of_lla_f(&utm_f, &lla_f);
//  /* copy results of utm conversion */
//  gps.utm_pos.east = utm_f.east*100;
//  gps.utm_pos.north = utm_f.north*100;
//  gps.utm_pos.alt = gps.lla_pos.alt;
//  gps.utm_pos.zone = nav_utm_zone0;
//#endif
//
//  if (gps_has_fix)
//    gps.fix = GPS_FIX_3D;
//  else
//    gps.fix = GPS_FIX_NONE;
//  gps_available = TRUE;
//}

//TODO Must pass through the double sensor values for the proper calcs
void gps_feed_value(int32_t ecef_pox_x, int32_t ecef_pox_y, int32_t ecef_pox_z,
		int32_t ecef_vel_x, int32_t ecef_vel_y, int32_t ecef_vel_z,
		int32_t lla_pos_lat, int32_t lla_pos_lon, int32_t lla_pos_alt,
		int32_t hmsl, int32_t pacc, int32_t sacc, int32_t tow) {
	gps.ecef_pos.x = ecef_pox_x;
	gps.ecef_pos.y = ecef_pox_y;
	gps.ecef_pos.z = ecef_pox_z;
	gps.ecef_vel.x = ecef_vel_x;
	gps.ecef_vel.y = ecef_vel_y;
	gps.ecef_vel.z = ecef_vel_z;
//ecef pos seems to be based on geocentric model, hence we get a very high alt when converted to lla
	gps.lla_pos.lat = lla_pos_lat;
	gps.lla_pos.lon = lla_pos_lon;
	gps.lla_pos.alt = lla_pos_alt;
	gps.hmsl = hmsl;

//	/* calc NED speed from ECEF */
//	struct LtpDef_i ref_ltp_i;
//	ltp_def_from_ecef_i(&ref_ltp_i, &gps.ecef_pos);
//	struct NedCoor_i ned_vel_i;
//	ned_of_ecef_vect_i(&ned_vel_i, &ref_ltp_i, &gps.ecef_vel);
//	gps.ned_vel.x = ned_vel_i.x * 100;
//	gps.ned_vel.y = ned_vel_i.y * 100;
//	gps.ned_vel.z = ned_vel_i.z * 100;
//
//	/* horizontal and 3d ground speed in cm/s */
//	gps.gspeed = sqrt(ned_vel_i.x * ned_vel_i.x + ned_vel_i.y * ned_vel_i.y)
//			* 100;
//	gps.speed_3d = sqrt(
//			ned_vel_i.x * ned_vel_i.x + ned_vel_i.y * ned_vel_i.y
//					+ ned_vel_i.z * ned_vel_i.z) * 100;
//
//	/* ground course in radians * 1e7 */
//	gps.course = atan2(ned_vel_i.y, ned_vel_i.x) * 1e7;

	struct LtpDef_d ref_ltp;
	//Reference nps_autopilot_remote.c in paparazzi project for the reason why this is
	//being done. Loosing accuracy but for now it may be ok... 05-06-14
	struct EcefCoor_d ecef_pos;
	ecef_pos.x = gps.ecef_pos.x / 100.;
	ecef_pos.y = gps.ecef_pos.y / 100.;
	ecef_pos.z = gps.ecef_pos.z / 100.;
	ltp_def_from_ecef_d(&ref_ltp, &ecef_pos);
	struct NedCoor_d ned_vel_d;
	struct EcefCoor_d ecef_vel;
	ecef_vel.x = gps.ecef_vel.x / 100.;
	ecef_vel.y = gps.ecef_vel.y / 100.;
	ecef_vel.z = gps.ecef_vel.z / 100.;
	ned_of_ecef_vect_d(&ned_vel_d, &ref_ltp, &ecef_vel);
	gps.ned_vel.x = ned_vel_d.x * 100;
	gps.ned_vel.y = ned_vel_d.y * 100;
	gps.ned_vel.z = ned_vel_d.z * 100;

	// horizontal and 3d ground speed in cm/s
	gps.gspeed = sqrt(ned_vel_d.x * ned_vel_d.x + ned_vel_d.y * ned_vel_d.y)
			* 100;
	gps.speed_3d = sqrt(
			ned_vel_d.x * ned_vel_d.x + ned_vel_d.y * ned_vel_d.y
					+ ned_vel_d.z * ned_vel_d.z) * 100;

	// ground course in radians * 1e7
	gps.course = atan2(ned_vel_d.y, ned_vel_d.x) * 1e7;

#if GPS_USE_LATLONG
	/* Computes from (lat, long) in the referenced UTM zone */
	struct LlaCoor_f lla_f;
	lla_f.lat = ((float) gps.lla_pos.lat) / 1e7;
	lla_f.lon = ((float) gps.lla_pos.lon) / 1e7;
	struct UtmCoor_f utm_f;
	utm_f.zone = nav_utm_zone0;
	/* convert to utm */
	utm_of_lla_f(&utm_f, &lla_f);
	/* copy results of utm conversion */
	gps.utm_pos.east = utm_f.east*100;
	gps.utm_pos.north = utm_f.north*100;
	gps.utm_pos.alt = gps.lla_pos.alt;
	gps.utm_pos.zone = nav_utm_zone0;
#endif

	if (gps_has_fix)
		gps.fix = GPS_FIX_3D;
	else
		gps.fix = GPS_FIX_NONE;

	gps_available = TRUE;
}

void gps_impl_init() {
	gps_available = FALSE;
	gps_has_fix = TRUE;
}
