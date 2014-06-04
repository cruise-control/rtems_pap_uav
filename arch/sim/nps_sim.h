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

#endif /* NPS_SIM_H_ */
