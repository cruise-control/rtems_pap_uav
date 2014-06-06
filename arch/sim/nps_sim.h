/*
 * nps_sim.h
 *
 *  Created on: Jun 3, 2014
 *      Author: j3
 */

#ifndef NPS_SIM_H_
#define NPS_SIM_H_

void sim_overwrite_ahrs_ltp(double qi, double qx, double qy, double qz);
void sim_overwrite_ahrs_ecef(double p, double q, double r);
void sim_overwrite_ins_ltpprz_ecef_accel(double x, double y, double z);
void sim_overwrite_ins_ltpprz_ecef_vel(double x, double y, double z);
void sim_overwrite_ins_ltpprz_pos(double x, double y, double z);

#endif /* NPS_SIM_H_ */
