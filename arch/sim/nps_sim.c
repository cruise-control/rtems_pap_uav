/*
 * nps_sim.c
 *
 *  Created on: Jun 3, 2014
 *      Author: j3
 */
#include "math/pprz_algebra_double.h"
#include "state.h"

void sim_overwrite_ahrs_ltp(double qi, double qx, double qy, double qz) {

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

	struct DoubleRates body_ecef_rotvel;

	body_ecef_rotvel.p = p;
	body_ecef_rotvel.q = q;
	body_ecef_rotvel.r = r;

	struct FloatRates rates_f;
	RATES_COPY(rates_f, body_ecef_rotvel);
	stateSetBodyRates_f(&rates_f);
}
