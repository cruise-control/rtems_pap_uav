/*
 * nps_sim.c
 *
 *  Created on: Jun 3, 2014
 *      Author: j3
 */
#include "math/pprz_algebra_double.h"
#include "state.h"
#include "math/pprz_geodetic_double.h"

bool_t nps_bypass_ahrs = false;
bool_t nps_bypass_ins = false;

void sim_overwrite_ahrs_ltp(double qi, double qx, double qy, double qz) {
	if (!nps_bypass_ahrs)
		return;
	struct DoubleQuat ltp_to_body_quat;

	ltp_to_body_quat.qi = qi;
	ltp_to_body_quat.qx = qx;
	ltp_to_body_quat.qy = qy;
	ltp_to_body_quat.qz = qz;

	struct FloatQuat quat_f;
	QUAT_COPY(quat_f, ltp_to_body_quat);
	stateSetNedToBodyQuat_f(&quat_f);
}

void sim_overwrite_ahrs_ecef(double p, double q, double r) {
	if (!nps_bypass_ahrs)
		return;
	struct DoubleRates body_ecef_rotvel;

	body_ecef_rotvel.p = p;
	body_ecef_rotvel.q = q;
	body_ecef_rotvel.r = r;

	struct FloatRates rates_f;
	RATES_COPY(rates_f, body_ecef_rotvel);
	stateSetBodyRates_f(&rates_f);
}

void sim_overwrite_ins_ltpprz_pos(double x, double y, double z) {
	if (!nps_bypass_ins)
		return;
	struct NedCoor_d lltpprz_pos;
	lltpprz_pos.x = x;
	lltpprz_pos.y = y;
	lltpprz_pos.z = z;
	struct NedCoor_f ltp_pos;
	VECT3_COPY(ltp_pos, lltpprz_pos);
	stateSetPositionNed_f(&ltp_pos);
}

void sim_overwrite_ins_ltpprz_ecef_vel(double x, double y, double z) {
	if (!nps_bypass_ins)
		return;
	struct NedCoor_d lltpprz_ecef_vel;
	lltpprz_ecef_vel.x = x;
	lltpprz_ecef_vel.y = y;
	lltpprz_ecef_vel.z = z;
	struct NedCoor_f ltp_speed;
	VECT3_COPY(ltp_speed, lltpprz_ecef_vel);
	stateSetSpeedNed_f(&ltp_speed);
}

void sim_overwrite_ins_ltpprz_ecef_accel(double x, double y, double z) {
	if (!nps_bypass_ins)
		return;
	struct NedCoor_d lltpprz_ecef_accel;
	lltpprz_ecef_accel.x = x;
	lltpprz_ecef_accel.y = y;
	lltpprz_ecef_accel.z = z;
	struct NedCoor_f ltp_accel;
	VECT3_COPY(ltp_accel, lltpprz_ecef_accel);
	stateSetAccelNed_f(&ltp_accel);
}
