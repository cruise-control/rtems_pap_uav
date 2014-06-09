/*
 * nps_sim.c
 *
 *  Created on: Jun 3, 2014
 *      Author: j3
 */
#include "math/pprz_algebra_double.h"
#include "state.h"
#include "math/pprz_geodetic_double.h"

//false with IMU appears to work poorly :)
//True without IMU causes the plane to launch and then glide down to ground
//false without IMU causes no useful movement

/* 	by_AHRS 	by_INS 	USE_AHRS 	USE_IMU		Result
 * 	false		false	true		true		1:Poorly working simulation that blows up
 * 												2:No throttle,launch and then glide to gnd
 * 												3:Sys reboot, recompile, launches, poor simulation, throttle etc
 * 	false		false	true		false		No calculation of COMMANDS, plane launches and glides to ground FDM crashes
 * 	true		true	true		false
 * 	true		true	true		true
 * 	true		false	true		false
 * 	true		true	true		true		Launches, strange trajectory, no throttle, fall to gnd
 * 	true		false	true		true		1:Launches, strange trajectory, no throttle, fall to gnd
 * 												2: Launches, poor simulation
 * 												3: Launch, let run, then restart pc side, not autopilot, works poorly but works
 *	true		false	false		true		1:WORKING!!!
 *												2: -- Now its not!!
 *												3: After a system reboot, it is working again...
 *
 *	true		true	false		true		Launches, no throttle
 * 	true		false	false		false		Launches, no throttle.
 */


bool_t nps_bypass_ahrs = true;
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
