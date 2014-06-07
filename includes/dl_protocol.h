/* Automatically generated from /home/manish/paprazzi-git/paparazzi/conf/messages.xml */
/* Please DO NOT EDIT */
/* Macros to send and receive messages of class datalink */
#define DL_ACINFO 1
#define DL_MOVE_WP 2
#define DL_WIND_INFO 3
#define DL_SETTING 4
#define DL_BLOCK 5
#define DL_HITL_UBX 6
#define DL_HITL_INFRARED 7
#define DL_PING 8
#define DL_FORMATION_SLOT 9
#define DL_FORMATION_STATUS 10
#define DL_JOYSTICK_RAW 11
#define DL_COMMANDS_RAW 12
#define DL_DGPS_RAW 13
#define DL_GET_SETTING 16
#define DL_TCAS_RESOLVE 17
#define DL_MISSION_GOTO_WP 20
#define DL_MISSION_GOTO_WP_LLA 21
#define DL_MISSION_CIRCLE 22
#define DL_MISSION_CIRCLE_LLA 23
#define DL_MISSION_SEGMENT 24
#define DL_MISSION_SEGMENT_LLA 25
#define DL_MISSION_PATH 26
#define DL_MISSION_PATH_LLA 27
#define DL_MISSION_SURVEY 28
#define DL_MISSION_SURVEY_LLA 29
#define DL_GOTO_MISSION 30
#define DL_NEXT_MISSION 31
#define DL_END_MISSION 32
#define DL_WINDTURBINE_STATUS 50
#define DL_RC_3CH 51
#define DL_RC_4CH 52
#define DL_REMOTE_GPS 55
#define DL_KITE_COMMAND 96
#define DL_PAYLOAD_COMMAND 97
#define DL_SET_ACTUATOR 100
#define DL_CSC_SERVO_CMD 101
#define DL_BOOZ2_FMS_COMMAND 149
#define DL_BOOZ_NAV_STICK 150
#define DL_EXTERNAL_FILTER_SOLUTION 151
#define DL_ROTORCRAFT_CAM_STICK 152
#define DL_GPS_INT 155
#define DL_AHRS_LTP 156
#define DL_AHRS_ECEF 157
#define DL_INS_POS 158
#define DL_INS_ECEF_VEL 159
#define DL_INS_ECEF_ACCEL 160
#define DL_NPS_SENSORS_GYRO 161
#define DL_NPS_SENSORS_ACCEL 162
#define DL_HITL_GPS_COMMON 171
#define DL_HITL_IR_AHRS 172
#define DL_MSG_datalink_NB 40

#define MSG_datalink_LENGTHS {0,(2+0+2+4+4+4+4+2+2+1),(2+0+1+1+4+4+4),(2+0+1+1+4+4+4),(2+0+1+1+4),(2+0+1+1),(2+0+1+1+1+1+nb_ubx_payload*1),(2+0+2+2+2+1),(2+0),(2+0+1+1+4+4+4),(2+0+1+1+1),(2+0+1+1+1+1),(2+0+1+1+nb_commands*1),(2+0+1+1+1+nb_rtcm*1),0,0,(2+0+1+1),(2+0+1+1+1),0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(2+0+1+1+4+4),(2+0+1+1+1),(2+0+1+1+1+1+1+1),0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(2+0+2+2),(2+0+1+1+nb_command*1),0,0,(2+0+2+1+1),(2+0+2+2+2+2),0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(2+0+1+1+4+4+4+4+1),(2+0+1+1+1+1+1),(2+0+1+1+4+4+4+4),(2+0+1+1+1),0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(2+0+1+1+8+8+8+8+8+8+8),(2+0+1+1+8+8+8+8+8+8),}

/*
 Size for non variable messages
51 : MISSION_PATH
51 : MISSION_PATH_LLA
50 : REMOTE_GPS
26 : MISSION_SEGMENT
26 : MISSION_SEGMENT_LLA
26 : MISSION_SURVEY
26 : MISSION_SURVEY_LLA
23 : ACINFO
22 : MISSION_CIRCLE
22 : MISSION_CIRCLE_LLA
19 : BOOZ2_FMS_COMMAND
18 : MISSION_GOTO_WP
18 : MISSION_GOTO_WP_LLA
18 : EXTERNAL_FILTER_SOLUTION
14 : MOVE_WP
14 : WIND_INFO
14 : FORMATION_SLOT
10 : WINDTURBINE_STATUS
 8 : CSC_SERVO_CMD
 7 : HITL_INFRARED
 6 : SETTING
 6 : RC_4CH
 5 : BOOZ_NAV_STICK
 4 : JOYSTICK_RAW
 4 : KITE_COMMAND
 4 : SET_ACTUATOR
 3 : FORMATION_STATUS
 3 : TCAS_RESOLVE
 3 : RC_3CH
 3 : ROTORCRAFT_CAM_STICK
 2 : BLOCK
 2 : GET_SETTING
 2 : GOTO_MISSION
 1 : NEXT_MISSION
 1 : END_MISSION
 0 : HITL_UBX
 0 : PING
 0 : COMMANDS_RAW
 0 : DGPS_RAW
 0 : PAYLOAD_COMMAND
 */
#define DOWNLINK_SEND_ACINFO(_trans, _dev, course, utm_east, utm_north, alt, itow, speed, climb, ac_id){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+4+4+4+2+2+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+4+4+4+2+2+1)); \
	  DownlinkStartMessage(_trans, _dev, "ACINFO", DL_ACINFO, 0+2+4+4+4+4+2+2+1) \
	  DownlinkPutInt16ByAddr(_trans, _dev, (course)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (utm_east)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (utm_north)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (alt)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (itow)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (speed)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (climb)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_MOVE_WP(_trans, _dev, wp_id, ac_id, lat, lon, alt){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "MOVE_WP", DL_MOVE_WP, 0+1+1+4+4+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (wp_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (lat)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (lon)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (alt)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_WIND_INFO(_trans, _dev, ac_id, pad0, east, north, airspeed){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "WIND_INFO", DL_WIND_INFO, 0+1+1+4+4+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (pad0)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (east)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (north)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (airspeed)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_SETTING(_trans, _dev, index, ac_id, value){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4)); \
	  DownlinkStartMessage(_trans, _dev, "SETTING", DL_SETTING, 0+1+1+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (index)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (value)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BLOCK(_trans, _dev, block_id, ac_id){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "BLOCK", DL_BLOCK, 0+1+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (block_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_HITL_UBX(_trans, _dev, class, id, ac_id, nb_ubx_payload, ubx_payload){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1+1+nb_ubx_payload*1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1+1+nb_ubx_payload*1)); \
	  DownlinkStartMessage(_trans, _dev, "HITL_UBX", DL_HITL_UBX, 0+1+1+1+1+nb_ubx_payload*1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (class)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8Array(_trans, _dev, nb_ubx_payload, ubx_payload); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_HITL_INFRARED(_trans, _dev, roll, pitch, top, ac_id){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+1)); \
	  DownlinkStartMessage(_trans, _dev, "HITL_INFRARED", DL_HITL_INFRARED, 0+2+2+2+1) \
	  DownlinkPutInt16ByAddr(_trans, _dev, (roll)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (pitch)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (top)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_PING(_trans, _dev ){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0)); \
	  DownlinkStartMessage(_trans, _dev, "PING", DL_PING, 0) \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_FORMATION_SLOT(_trans, _dev, ac_id, mode, slot_east, slot_north, slot_alt){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "FORMATION_SLOT", DL_FORMATION_SLOT, 0+1+1+4+4+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (mode)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (slot_east)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (slot_north)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (slot_alt)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_FORMATION_STATUS(_trans, _dev, ac_id, leader_id, status){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "FORMATION_STATUS", DL_FORMATION_STATUS, 0+1+1+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (leader_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (status)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_JOYSTICK_RAW(_trans, _dev, ac_id, roll, pitch, throttle){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "JOYSTICK_RAW", DL_JOYSTICK_RAW, 0+1+1+1+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutInt8ByAddr(_trans, _dev, (roll)); \
	  DownlinkPutInt8ByAddr(_trans, _dev, (pitch)); \
	  DownlinkPutInt8ByAddr(_trans, _dev, (throttle)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_COMMANDS_RAW(_trans, _dev, ac_id, nb_commands, commands){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+nb_commands*1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+nb_commands*1)); \
	  DownlinkStartMessage(_trans, _dev, "COMMANDS_RAW", DL_COMMANDS_RAW, 0+1+1+nb_commands*1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutInt8Array(_trans, _dev, nb_commands, commands); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_DGPS_RAW(_trans, _dev, ac_id, length, nb_rtcm, rtcm){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1+nb_rtcm*1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1+nb_rtcm*1)); \
	  DownlinkStartMessage(_trans, _dev, "DGPS_RAW", DL_DGPS_RAW, 0+1+1+1+nb_rtcm*1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (length)); \
	  DownlinkPutUint8Array(_trans, _dev, nb_rtcm, rtcm); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_GET_SETTING(_trans, _dev, index, ac_id){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "GET_SETTING", DL_GET_SETTING, 0+1+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (index)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_TCAS_RESOLVE(_trans, _dev, ac_id, ac_id_conflict, resolve){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "TCAS_RESOLVE", DL_TCAS_RESOLVE, 0+1+1+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id_conflict)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (resolve)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_MISSION_GOTO_WP(_trans, _dev, ac_id, insert, wp_east, wp_north, wp_alt, duration){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "MISSION_GOTO_WP", DL_MISSION_GOTO_WP, 0+1+1+4+4+4+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (insert)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (wp_east)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (wp_north)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (wp_alt)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (duration)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_MISSION_GOTO_WP_LLA(_trans, _dev, ac_id, insert, wp_lat, wp_lon, wp_alt, duration){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "MISSION_GOTO_WP_LLA", DL_MISSION_GOTO_WP_LLA, 0+1+1+4+4+4+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (insert)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (wp_lat)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (wp_lon)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (wp_alt)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (duration)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_MISSION_CIRCLE(_trans, _dev, ac_id, insert, center_east, center_north, center_alt, radius, duration){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "MISSION_CIRCLE", DL_MISSION_CIRCLE, 0+1+1+4+4+4+4+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (insert)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (center_east)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (center_north)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (center_alt)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (radius)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (duration)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_MISSION_CIRCLE_LLA(_trans, _dev, ac_id, insert, center_lat, center_lon, center_alt, radius, duration){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "MISSION_CIRCLE_LLA", DL_MISSION_CIRCLE_LLA, 0+1+1+4+4+4+4+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (insert)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (center_lat)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (center_lon)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (center_alt)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (radius)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (duration)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_MISSION_SEGMENT(_trans, _dev, ac_id, insert, segment_east_1, segment_north_1, segment_east_2, segment_north_2, segment_alt, duration){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "MISSION_SEGMENT", DL_MISSION_SEGMENT, 0+1+1+4+4+4+4+4+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (insert)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (segment_east_1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (segment_north_1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (segment_east_2)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (segment_north_2)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (segment_alt)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (duration)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_MISSION_SEGMENT_LLA(_trans, _dev, ac_id, insert, segment_lat_1, segment_lon_1, segment_lat_2, segment_lon_2, segment_alt, duration){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "MISSION_SEGMENT_LLA", DL_MISSION_SEGMENT_LLA, 0+1+1+4+4+4+4+4+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (insert)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (segment_lat_1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (segment_lon_1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (segment_lat_2)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (segment_lon_2)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (segment_alt)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (duration)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_MISSION_PATH(_trans, _dev, ac_id, insert, point_east_1, point_north_1, point_east_2, point_north_2, point_east_3, point_north_3, point_east_4, point_north_4, point_east_5, point_north_5, path_alt, duration, nb){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+4+4+4+4+4+4+4+4+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+4+4+4+4+4+4+4+4+1)); \
	  DownlinkStartMessage(_trans, _dev, "MISSION_PATH", DL_MISSION_PATH, 0+1+1+4+4+4+4+4+4+4+4+4+4+4+4+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (insert)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (point_east_1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (point_north_1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (point_east_2)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (point_north_2)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (point_east_3)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (point_north_3)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (point_east_4)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (point_north_4)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (point_east_5)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (point_north_5)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (path_alt)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (duration)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (nb)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_MISSION_PATH_LLA(_trans, _dev, ac_id, insert, point_lat_1, point_lon_1, point_lat_2, point_lon_2, point_lat_3, point_lon_3, point_lat_4, point_lon_4, point_lat_5, point_lon_5, path_alt, duration, nb){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+4+4+4+4+4+4+4+4+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+4+4+4+4+4+4+4+4+1)); \
	  DownlinkStartMessage(_trans, _dev, "MISSION_PATH_LLA", DL_MISSION_PATH_LLA, 0+1+1+4+4+4+4+4+4+4+4+4+4+4+4+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (insert)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (point_lat_1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (point_lon_1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (point_lat_2)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (point_lon_2)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (point_lat_3)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (point_lon_3)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (point_lat_4)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (point_lon_4)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (point_lat_5)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (point_lon_5)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (path_alt)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (duration)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (nb)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_MISSION_SURVEY(_trans, _dev, ac_id, insert, survey_east_1, survey_north_1, survey_east_2, survey_north_2, survey_alt, duration){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "MISSION_SURVEY", DL_MISSION_SURVEY, 0+1+1+4+4+4+4+4+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (insert)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (survey_east_1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (survey_north_1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (survey_east_2)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (survey_north_2)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (survey_alt)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (duration)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_MISSION_SURVEY_LLA(_trans, _dev, ac_id, insert, survey_lat_1, survey_lon_1, survey_lat_2, survey_lon_2, survey_alt, duration){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "MISSION_SURVEY_LLA", DL_MISSION_SURVEY_LLA, 0+1+1+4+4+4+4+4+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (insert)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (survey_lat_1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (survey_lon_1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (survey_lat_2)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (survey_lon_2)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (survey_alt)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (duration)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_GOTO_MISSION(_trans, _dev, ac_id, mission_id){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "GOTO_MISSION", DL_GOTO_MISSION, 0+1+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (mission_id)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_NEXT_MISSION(_trans, _dev, ac_id){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1)); \
	  DownlinkStartMessage(_trans, _dev, "NEXT_MISSION", DL_NEXT_MISSION, 0+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_END_MISSION(_trans, _dev, ac_id){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1)); \
	  DownlinkStartMessage(_trans, _dev, "END_MISSION", DL_END_MISSION, 0+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_WINDTURBINE_STATUS(_trans, _dev, ac_id, tb_id, sync_itow, cycle_time){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "WINDTURBINE_STATUS", DL_WINDTURBINE_STATUS, 0+1+1+4+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (tb_id)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (sync_itow)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (cycle_time)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_RC_3CH(_trans, _dev, throttle_mode, roll, pitch){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "RC_3CH", DL_RC_3CH, 0+1+1+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (throttle_mode)); \
	  DownlinkPutInt8ByAddr(_trans, _dev, (roll)); \
	  DownlinkPutInt8ByAddr(_trans, _dev, (pitch)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_RC_4CH(_trans, _dev, ac_id, mode, throttle, roll, pitch, yaw){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1+1+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1+1+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "RC_4CH", DL_RC_4CH, 0+1+1+1+1+1+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (mode)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (throttle)); \
	  DownlinkPutInt8ByAddr(_trans, _dev, (roll)); \
	  DownlinkPutInt8ByAddr(_trans, _dev, (pitch)); \
	  DownlinkPutInt8ByAddr(_trans, _dev, (yaw)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_REMOTE_GPS(_trans, _dev, ac_id, numsv, ecef_x, ecef_y, ecef_z, lat, lon, alt, hmsl, ecef_xd, ecef_yd, ecef_zd, tow, course){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "REMOTE_GPS", DL_REMOTE_GPS, 0+1+1+4+4+4+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (numsv)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ecef_x)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ecef_y)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ecef_z)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (lat)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (lon)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (alt)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (hmsl)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ecef_xd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ecef_yd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ecef_zd)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (tow)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (course)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_KITE_COMMAND(_trans, _dev, POWER, TURN){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2)); \
	  DownlinkStartMessage(_trans, _dev, "KITE_COMMAND", DL_KITE_COMMAND, 0+2+2) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (POWER)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (TURN)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_PAYLOAD_COMMAND(_trans, _dev, ac_id, nb_command, command){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+nb_command*1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+nb_command*1)); \
	  DownlinkStartMessage(_trans, _dev, "PAYLOAD_COMMAND", DL_PAYLOAD_COMMAND, 0+1+1+nb_command*1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8Array(_trans, _dev, nb_command, command); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_SET_ACTUATOR(_trans, _dev, value, no, ac_id){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "SET_ACTUATOR", DL_SET_ACTUATOR, 0+2+1+1) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (value)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (no)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_CSC_SERVO_CMD(_trans, _dev, servo_1, servo_2, servo_3, servo_4){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2)); \
	  DownlinkStartMessage(_trans, _dev, "CSC_SERVO_CMD", DL_CSC_SERVO_CMD, 0+2+2+2+2) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (servo_1)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (servo_2)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (servo_3)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (servo_4)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BOOZ2_FMS_COMMAND(_trans, _dev, h_mode, v_mode, v_sp, h_sp_1, h_sp_2, h_sp_3, ac_id){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+1)); \
	  DownlinkStartMessage(_trans, _dev, "BOOZ2_FMS_COMMAND", DL_BOOZ2_FMS_COMMAND, 0+1+1+4+4+4+4+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (h_mode)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (v_mode)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (v_sp)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (h_sp_1)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (h_sp_2)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (h_sp_3)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BOOZ_NAV_STICK(_trans, _dev, ac_id, vx_sp, vy_sp, vz_sp, r_sp){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "BOOZ_NAV_STICK", DL_BOOZ_NAV_STICK, 0+1+1+1+1+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutInt8ByAddr(_trans, _dev, (vx_sp)); \
	  DownlinkPutInt8ByAddr(_trans, _dev, (vy_sp)); \
	  DownlinkPutInt8ByAddr(_trans, _dev, (vz_sp)); \
	  DownlinkPutInt8ByAddr(_trans, _dev, (r_sp)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_EXTERNAL_FILTER_SOLUTION(_trans, _dev, ac_id, status, x, xd, y, yd){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "EXTERNAL_FILTER_SOLUTION", DL_EXTERNAL_FILTER_SOLUTION, 0+1+1+4+4+4+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (status)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (x)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (xd)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (y)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (yd)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_ROTORCRAFT_CAM_STICK(_trans, _dev, ac_id, tilt, pan){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "ROTORCRAFT_CAM_STICK", DL_ROTORCRAFT_CAM_STICK, 0+1+1+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutInt8ByAddr(_trans, _dev, (tilt)); \
	  DownlinkPutInt8ByAddr(_trans, _dev, (pan)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_HITL_GPS_COMMON(_trans, _dev, gps_id, ac_id, lat, lon, alt, course, gspeed, climb, time){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+8+8+8+8+8+8+8))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+8+8+8+8+8+8+8)); \
	  DownlinkStartMessage(_trans, _dev, "HITL_GPS_COMMON", DL_HITL_GPS_COMMON, 0+1+1+8+8+8+8+8+8+8) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (gps_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (lat)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (lon)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (alt)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (course)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (gspeed)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (climb)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (time)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_HITL_IR_AHRS(_trans, _dev, ir_id, ac_id, roll, pitch, yaw, p, q, r){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+8+8+8+8+8+8))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+8+8+8+8+8+8)); \
	  DownlinkStartMessage(_trans, _dev, "HITL_IR_AHRS", DL_HITL_IR_AHRS, 0+1+1+8+8+8+8+8+8) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ir_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (roll)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (pitch)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (yaw)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (p)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (q)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (r)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DL_ACINFO_course(_payload) ((int16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_ACINFO_utm_east(_payload) ((int32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24))
#define DL_ACINFO_utm_north(_payload) ((int32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24))
#define DL_ACINFO_alt(_payload) ((int32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24))
#define DL_ACINFO_itow(_payload) ((uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24))
#define DL_ACINFO_speed(_payload) ((uint16_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8))
#define DL_ACINFO_climb(_payload) ((int16_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8))
#define DL_ACINFO_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+24)))

#define DL_MOVE_WP_wp_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_MOVE_WP_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_MOVE_WP_lat(_payload) ((int32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24))
#define DL_MOVE_WP_lon(_payload) ((int32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24))
#define DL_MOVE_WP_alt(_payload) ((int32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24))

#define DL_WIND_INFO_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_WIND_INFO_pad0(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_WIND_INFO_east(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_WIND_INFO_north(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_WIND_INFO_airspeed(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))

#define DL_SETTING_index(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_SETTING_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_SETTING_value(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))

#define DL_BLOCK_block_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_BLOCK_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))

#define DL_HITL_UBX_class(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_HITL_UBX_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_HITL_UBX_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+4)))
#define DL_HITL_UBX_ubx_payload_length(_payload) ((uint8_t)(*((uint8_t*)_payload+5)))
#define DL_HITL_UBX_ubx_payload(_payload) ((uint8_t*)(_payload+6))

#define DL_HITL_INFRARED_roll(_payload) ((int16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_HITL_INFRARED_pitch(_payload) ((int16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_HITL_INFRARED_top(_payload) ((int16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))
#define DL_HITL_INFRARED_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+8)))


#define DL_FORMATION_SLOT_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_FORMATION_SLOT_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_FORMATION_SLOT_slot_east(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_FORMATION_SLOT_slot_north(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_FORMATION_SLOT_slot_alt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))

#define DL_FORMATION_STATUS_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_FORMATION_STATUS_leader_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_FORMATION_STATUS_status(_payload) ((uint8_t)(*((uint8_t*)_payload+4)))

#define DL_JOYSTICK_RAW_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_JOYSTICK_RAW_roll(_payload) ((int8_t)(*((uint8_t*)_payload+3)))
#define DL_JOYSTICK_RAW_pitch(_payload) ((int8_t)(*((uint8_t*)_payload+4)))
#define DL_JOYSTICK_RAW_throttle(_payload) ((int8_t)(*((uint8_t*)_payload+5)))

#define DL_COMMANDS_RAW_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_COMMANDS_RAW_commands_length(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_COMMANDS_RAW_commands(_payload) ((int8_t*)(_payload+4))

#define DL_DGPS_RAW_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_DGPS_RAW_length(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_DGPS_RAW_rtcm_length(_payload) ((uint8_t)(*((uint8_t*)_payload+4)))
#define DL_DGPS_RAW_rtcm(_payload) ((uint8_t*)(_payload+5))

#define DL_GET_SETTING_index(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_GET_SETTING_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))

#define DL_TCAS_RESOLVE_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_TCAS_RESOLVE_ac_id_conflict(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_TCAS_RESOLVE_resolve(_payload) ((uint8_t)(*((uint8_t*)_payload+4)))

#define DL_MISSION_GOTO_WP_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_MISSION_GOTO_WP_insert(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_MISSION_GOTO_WP_wp_east(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_MISSION_GOTO_WP_wp_north(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_MISSION_GOTO_WP_wp_alt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))
#define DL_MISSION_GOTO_WP_duration(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24); _f.f; }))

#define DL_MISSION_GOTO_WP_LLA_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_MISSION_GOTO_WP_LLA_insert(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_MISSION_GOTO_WP_LLA_wp_lat(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_MISSION_GOTO_WP_LLA_wp_lon(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_MISSION_GOTO_WP_LLA_wp_alt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))
#define DL_MISSION_GOTO_WP_LLA_duration(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24); _f.f; }))

#define DL_MISSION_CIRCLE_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_MISSION_CIRCLE_insert(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_MISSION_CIRCLE_center_east(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_MISSION_CIRCLE_center_north(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_MISSION_CIRCLE_center_alt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))
#define DL_MISSION_CIRCLE_radius(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24); _f.f; }))
#define DL_MISSION_CIRCLE_duration(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8|((uint32_t)*((uint8_t*)_payload+20+2))<<16|((uint32_t)*((uint8_t*)_payload+20+3))<<24); _f.f; }))

#define DL_MISSION_CIRCLE_LLA_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_MISSION_CIRCLE_LLA_insert(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_MISSION_CIRCLE_LLA_center_lat(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_MISSION_CIRCLE_LLA_center_lon(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_MISSION_CIRCLE_LLA_center_alt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))
#define DL_MISSION_CIRCLE_LLA_radius(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24); _f.f; }))
#define DL_MISSION_CIRCLE_LLA_duration(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8|((uint32_t)*((uint8_t*)_payload+20+2))<<16|((uint32_t)*((uint8_t*)_payload+20+3))<<24); _f.f; }))

#define DL_MISSION_SEGMENT_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_MISSION_SEGMENT_insert(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_MISSION_SEGMENT_segment_east_1(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_MISSION_SEGMENT_segment_north_1(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_MISSION_SEGMENT_segment_east_2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))
#define DL_MISSION_SEGMENT_segment_north_2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24); _f.f; }))
#define DL_MISSION_SEGMENT_segment_alt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8|((uint32_t)*((uint8_t*)_payload+20+2))<<16|((uint32_t)*((uint8_t*)_payload+20+3))<<24); _f.f; }))
#define DL_MISSION_SEGMENT_duration(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+24)|*((uint8_t*)_payload+24+1)<<8|((uint32_t)*((uint8_t*)_payload+24+2))<<16|((uint32_t)*((uint8_t*)_payload+24+3))<<24); _f.f; }))

#define DL_MISSION_SEGMENT_LLA_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_MISSION_SEGMENT_LLA_insert(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_MISSION_SEGMENT_LLA_segment_lat_1(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_MISSION_SEGMENT_LLA_segment_lon_1(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_MISSION_SEGMENT_LLA_segment_lat_2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))
#define DL_MISSION_SEGMENT_LLA_segment_lon_2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24); _f.f; }))
#define DL_MISSION_SEGMENT_LLA_segment_alt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8|((uint32_t)*((uint8_t*)_payload+20+2))<<16|((uint32_t)*((uint8_t*)_payload+20+3))<<24); _f.f; }))
#define DL_MISSION_SEGMENT_LLA_duration(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+24)|*((uint8_t*)_payload+24+1)<<8|((uint32_t)*((uint8_t*)_payload+24+2))<<16|((uint32_t)*((uint8_t*)_payload+24+3))<<24); _f.f; }))

#define DL_MISSION_PATH_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_MISSION_PATH_insert(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_MISSION_PATH_point_east_1(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_MISSION_PATH_point_north_1(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_MISSION_PATH_point_east_2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))
#define DL_MISSION_PATH_point_north_2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24); _f.f; }))
#define DL_MISSION_PATH_point_east_3(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8|((uint32_t)*((uint8_t*)_payload+20+2))<<16|((uint32_t)*((uint8_t*)_payload+20+3))<<24); _f.f; }))
#define DL_MISSION_PATH_point_north_3(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+24)|*((uint8_t*)_payload+24+1)<<8|((uint32_t)*((uint8_t*)_payload+24+2))<<16|((uint32_t)*((uint8_t*)_payload+24+3))<<24); _f.f; }))
#define DL_MISSION_PATH_point_east_4(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+28)|*((uint8_t*)_payload+28+1)<<8|((uint32_t)*((uint8_t*)_payload+28+2))<<16|((uint32_t)*((uint8_t*)_payload+28+3))<<24); _f.f; }))
#define DL_MISSION_PATH_point_north_4(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+32)|*((uint8_t*)_payload+32+1)<<8|((uint32_t)*((uint8_t*)_payload+32+2))<<16|((uint32_t)*((uint8_t*)_payload+32+3))<<24); _f.f; }))
#define DL_MISSION_PATH_point_east_5(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+36)|*((uint8_t*)_payload+36+1)<<8|((uint32_t)*((uint8_t*)_payload+36+2))<<16|((uint32_t)*((uint8_t*)_payload+36+3))<<24); _f.f; }))
#define DL_MISSION_PATH_point_north_5(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+40)|*((uint8_t*)_payload+40+1)<<8|((uint32_t)*((uint8_t*)_payload+40+2))<<16|((uint32_t)*((uint8_t*)_payload+40+3))<<24); _f.f; }))
#define DL_MISSION_PATH_path_alt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+44)|*((uint8_t*)_payload+44+1)<<8|((uint32_t)*((uint8_t*)_payload+44+2))<<16|((uint32_t)*((uint8_t*)_payload+44+3))<<24); _f.f; }))
#define DL_MISSION_PATH_duration(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+48)|*((uint8_t*)_payload+48+1)<<8|((uint32_t)*((uint8_t*)_payload+48+2))<<16|((uint32_t)*((uint8_t*)_payload+48+3))<<24); _f.f; }))
#define DL_MISSION_PATH_nb(_payload) ((uint8_t)(*((uint8_t*)_payload+52)))

#define DL_MISSION_PATH_LLA_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_MISSION_PATH_LLA_insert(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_MISSION_PATH_LLA_point_lat_1(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_MISSION_PATH_LLA_point_lon_1(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_MISSION_PATH_LLA_point_lat_2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))
#define DL_MISSION_PATH_LLA_point_lon_2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24); _f.f; }))
#define DL_MISSION_PATH_LLA_point_lat_3(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8|((uint32_t)*((uint8_t*)_payload+20+2))<<16|((uint32_t)*((uint8_t*)_payload+20+3))<<24); _f.f; }))
#define DL_MISSION_PATH_LLA_point_lon_3(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+24)|*((uint8_t*)_payload+24+1)<<8|((uint32_t)*((uint8_t*)_payload+24+2))<<16|((uint32_t)*((uint8_t*)_payload+24+3))<<24); _f.f; }))
#define DL_MISSION_PATH_LLA_point_lat_4(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+28)|*((uint8_t*)_payload+28+1)<<8|((uint32_t)*((uint8_t*)_payload+28+2))<<16|((uint32_t)*((uint8_t*)_payload+28+3))<<24); _f.f; }))
#define DL_MISSION_PATH_LLA_point_lon_4(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+32)|*((uint8_t*)_payload+32+1)<<8|((uint32_t)*((uint8_t*)_payload+32+2))<<16|((uint32_t)*((uint8_t*)_payload+32+3))<<24); _f.f; }))
#define DL_MISSION_PATH_LLA_point_lat_5(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+36)|*((uint8_t*)_payload+36+1)<<8|((uint32_t)*((uint8_t*)_payload+36+2))<<16|((uint32_t)*((uint8_t*)_payload+36+3))<<24); _f.f; }))
#define DL_MISSION_PATH_LLA_point_lon_5(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+40)|*((uint8_t*)_payload+40+1)<<8|((uint32_t)*((uint8_t*)_payload+40+2))<<16|((uint32_t)*((uint8_t*)_payload+40+3))<<24); _f.f; }))
#define DL_MISSION_PATH_LLA_path_alt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+44)|*((uint8_t*)_payload+44+1)<<8|((uint32_t)*((uint8_t*)_payload+44+2))<<16|((uint32_t)*((uint8_t*)_payload+44+3))<<24); _f.f; }))
#define DL_MISSION_PATH_LLA_duration(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+48)|*((uint8_t*)_payload+48+1)<<8|((uint32_t)*((uint8_t*)_payload+48+2))<<16|((uint32_t)*((uint8_t*)_payload+48+3))<<24); _f.f; }))
#define DL_MISSION_PATH_LLA_nb(_payload) ((uint8_t)(*((uint8_t*)_payload+52)))

#define DL_MISSION_SURVEY_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_MISSION_SURVEY_insert(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_MISSION_SURVEY_survey_east_1(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_MISSION_SURVEY_survey_north_1(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_MISSION_SURVEY_survey_east_2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))
#define DL_MISSION_SURVEY_survey_north_2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24); _f.f; }))
#define DL_MISSION_SURVEY_survey_alt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8|((uint32_t)*((uint8_t*)_payload+20+2))<<16|((uint32_t)*((uint8_t*)_payload+20+3))<<24); _f.f; }))
#define DL_MISSION_SURVEY_duration(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+24)|*((uint8_t*)_payload+24+1)<<8|((uint32_t)*((uint8_t*)_payload+24+2))<<16|((uint32_t)*((uint8_t*)_payload+24+3))<<24); _f.f; }))

#define DL_MISSION_SURVEY_LLA_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_MISSION_SURVEY_LLA_insert(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_MISSION_SURVEY_LLA_survey_lat_1(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_MISSION_SURVEY_LLA_survey_lon_1(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_MISSION_SURVEY_LLA_survey_lat_2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))
#define DL_MISSION_SURVEY_LLA_survey_lon_2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24); _f.f; }))
#define DL_MISSION_SURVEY_LLA_survey_alt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8|((uint32_t)*((uint8_t*)_payload+20+2))<<16|((uint32_t)*((uint8_t*)_payload+20+3))<<24); _f.f; }))
#define DL_MISSION_SURVEY_LLA_duration(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+24)|*((uint8_t*)_payload+24+1)<<8|((uint32_t)*((uint8_t*)_payload+24+2))<<16|((uint32_t)*((uint8_t*)_payload+24+3))<<24); _f.f; }))

#define DL_GOTO_MISSION_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_GOTO_MISSION_mission_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))

#define DL_NEXT_MISSION_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))

#define DL_END_MISSION_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))

#define DL_WINDTURBINE_STATUS_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_WINDTURBINE_STATUS_tb_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_WINDTURBINE_STATUS_sync_itow(_payload) ((uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24))
#define DL_WINDTURBINE_STATUS_cycle_time(_payload) ((uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24))

#define DL_RC_3CH_throttle_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_RC_3CH_roll(_payload) ((int8_t)(*((uint8_t*)_payload+3)))
#define DL_RC_3CH_pitch(_payload) ((int8_t)(*((uint8_t*)_payload+4)))

#define DL_RC_4CH_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_RC_4CH_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_RC_4CH_throttle(_payload) ((uint8_t)(*((uint8_t*)_payload+4)))
#define DL_RC_4CH_roll(_payload) ((int8_t)(*((uint8_t*)_payload+5)))
#define DL_RC_4CH_pitch(_payload) ((int8_t)(*((uint8_t*)_payload+6)))
#define DL_RC_4CH_yaw(_payload) ((int8_t)(*((uint8_t*)_payload+7)))

#define DL_REMOTE_GPS_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_REMOTE_GPS_numsv(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_REMOTE_GPS_ecef_x(_payload) ((int32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24))
#define DL_REMOTE_GPS_ecef_y(_payload) ((int32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24))
#define DL_REMOTE_GPS_ecef_z(_payload) ((int32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24))
#define DL_REMOTE_GPS_lat(_payload) ((int32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24))
#define DL_REMOTE_GPS_lon(_payload) ((int32_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8|((uint32_t)*((uint8_t*)_payload+20+2))<<16|((uint32_t)*((uint8_t*)_payload+20+3))<<24))
#define DL_REMOTE_GPS_alt(_payload) ((int32_t)(*((uint8_t*)_payload+24)|*((uint8_t*)_payload+24+1)<<8|((uint32_t)*((uint8_t*)_payload+24+2))<<16|((uint32_t)*((uint8_t*)_payload+24+3))<<24))
#define DL_REMOTE_GPS_hmsl(_payload) ((int32_t)(*((uint8_t*)_payload+28)|*((uint8_t*)_payload+28+1)<<8|((uint32_t)*((uint8_t*)_payload+28+2))<<16|((uint32_t)*((uint8_t*)_payload+28+3))<<24))
#define DL_REMOTE_GPS_ecef_xd(_payload) ((int32_t)(*((uint8_t*)_payload+32)|*((uint8_t*)_payload+32+1)<<8|((uint32_t)*((uint8_t*)_payload+32+2))<<16|((uint32_t)*((uint8_t*)_payload+32+3))<<24))
#define DL_REMOTE_GPS_ecef_yd(_payload) ((int32_t)(*((uint8_t*)_payload+36)|*((uint8_t*)_payload+36+1)<<8|((uint32_t)*((uint8_t*)_payload+36+2))<<16|((uint32_t)*((uint8_t*)_payload+36+3))<<24))
#define DL_REMOTE_GPS_ecef_zd(_payload) ((int32_t)(*((uint8_t*)_payload+40)|*((uint8_t*)_payload+40+1)<<8|((uint32_t)*((uint8_t*)_payload+40+2))<<16|((uint32_t)*((uint8_t*)_payload+40+3))<<24))
#define DL_REMOTE_GPS_tow(_payload) ((uint32_t)(*((uint8_t*)_payload+44)|*((uint8_t*)_payload+44+1)<<8|((uint32_t)*((uint8_t*)_payload+44+2))<<16|((uint32_t)*((uint8_t*)_payload+44+3))<<24))
#define DL_REMOTE_GPS_course(_payload) ((int32_t)(*((uint8_t*)_payload+48)|*((uint8_t*)_payload+48+1)<<8|((uint32_t)*((uint8_t*)_payload+48+2))<<16|((uint32_t)*((uint8_t*)_payload+48+3))<<24))

#define DL_KITE_COMMAND_POWER(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_KITE_COMMAND_TURN(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))

#define DL_PAYLOAD_COMMAND_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_PAYLOAD_COMMAND_command_length(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_PAYLOAD_COMMAND_command(_payload) ((uint8_t*)(_payload+4))

#define DL_SET_ACTUATOR_value(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_SET_ACTUATOR_no(_payload) ((uint8_t)(*((uint8_t*)_payload+4)))
#define DL_SET_ACTUATOR_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+5)))

#define DL_CSC_SERVO_CMD_servo_1(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_CSC_SERVO_CMD_servo_2(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_CSC_SERVO_CMD_servo_3(_payload) ((uint16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))
#define DL_CSC_SERVO_CMD_servo_4(_payload) ((uint16_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8))

#define DL_BOOZ2_FMS_COMMAND_h_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_BOOZ2_FMS_COMMAND_v_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_BOOZ2_FMS_COMMAND_v_sp(_payload) ((int32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24))
#define DL_BOOZ2_FMS_COMMAND_h_sp_1(_payload) ((int32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24))
#define DL_BOOZ2_FMS_COMMAND_h_sp_2(_payload) ((int32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24))
#define DL_BOOZ2_FMS_COMMAND_h_sp_3(_payload) ((int32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24))
#define DL_BOOZ2_FMS_COMMAND_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+20)))

#define DL_BOOZ_NAV_STICK_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_BOOZ_NAV_STICK_vx_sp(_payload) ((int8_t)(*((uint8_t*)_payload+3)))
#define DL_BOOZ_NAV_STICK_vy_sp(_payload) ((int8_t)(*((uint8_t*)_payload+4)))
#define DL_BOOZ_NAV_STICK_vz_sp(_payload) ((int8_t)(*((uint8_t*)_payload+5)))
#define DL_BOOZ_NAV_STICK_r_sp(_payload) ((int8_t)(*((uint8_t*)_payload+6)))

#define DL_EXTERNAL_FILTER_SOLUTION_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_EXTERNAL_FILTER_SOLUTION_status(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_EXTERNAL_FILTER_SOLUTION_x(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_EXTERNAL_FILTER_SOLUTION_xd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_EXTERNAL_FILTER_SOLUTION_y(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))
#define DL_EXTERNAL_FILTER_SOLUTION_yd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24); _f.f; }))

#define DL_ROTORCRAFT_CAM_STICK_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_ROTORCRAFT_CAM_STICK_tilt(_payload) ((int8_t)(*((uint8_t*)_payload+3)))
#define DL_ROTORCRAFT_CAM_STICK_pan(_payload) ((int8_t)(*((uint8_t*)_payload+4)))

#define DL_HITL_GPS_COMMON_gps_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_HITL_GPS_COMMON_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_HITL_GPS_COMMON_lat(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+4)|((uint64_t)*((uint8_t*)_payload+4+1))<<8|((uint64_t)*((uint8_t*)_payload+4+2))<<16|((uint64_t)*((uint8_t*)_payload+4+3))<<24|((uint64_t)*((uint8_t*)_payload+4+4))<<32|((uint64_t)*((uint8_t*)_payload+4+5))<<40|((uint64_t)*((uint8_t*)_payload+4+6))<<48|((uint64_t)*((uint8_t*)_payload+4+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_HITL_GPS_COMMON_lon(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+12)|((uint64_t)*((uint8_t*)_payload+12+1))<<8|((uint64_t)*((uint8_t*)_payload+12+2))<<16|((uint64_t)*((uint8_t*)_payload+12+3))<<24|((uint64_t)*((uint8_t*)_payload+12+4))<<32|((uint64_t)*((uint8_t*)_payload+12+5))<<40|((uint64_t)*((uint8_t*)_payload+12+6))<<48|((uint64_t)*((uint8_t*)_payload+12+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_HITL_GPS_COMMON_alt(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+20)|((uint64_t)*((uint8_t*)_payload+20+1))<<8|((uint64_t)*((uint8_t*)_payload+20+2))<<16|((uint64_t)*((uint8_t*)_payload+20+3))<<24|((uint64_t)*((uint8_t*)_payload+20+4))<<32|((uint64_t)*((uint8_t*)_payload+20+5))<<40|((uint64_t)*((uint8_t*)_payload+20+6))<<48|((uint64_t)*((uint8_t*)_payload+20+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_HITL_GPS_COMMON_course(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+28)|((uint64_t)*((uint8_t*)_payload+28+1))<<8|((uint64_t)*((uint8_t*)_payload+28+2))<<16|((uint64_t)*((uint8_t*)_payload+28+3))<<24|((uint64_t)*((uint8_t*)_payload+28+4))<<32|((uint64_t)*((uint8_t*)_payload+28+5))<<40|((uint64_t)*((uint8_t*)_payload+28+6))<<48|((uint64_t)*((uint8_t*)_payload+28+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_HITL_GPS_COMMON_gspeed(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+36)|((uint64_t)*((uint8_t*)_payload+36+1))<<8|((uint64_t)*((uint8_t*)_payload+36+2))<<16|((uint64_t)*((uint8_t*)_payload+36+3))<<24|((uint64_t)*((uint8_t*)_payload+36+4))<<32|((uint64_t)*((uint8_t*)_payload+36+5))<<40|((uint64_t)*((uint8_t*)_payload+36+6))<<48|((uint64_t)*((uint8_t*)_payload+36+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_HITL_GPS_COMMON_climb(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+44)|((uint64_t)*((uint8_t*)_payload+44+1))<<8|((uint64_t)*((uint8_t*)_payload+44+2))<<16|((uint64_t)*((uint8_t*)_payload+44+3))<<24|((uint64_t)*((uint8_t*)_payload+44+4))<<32|((uint64_t)*((uint8_t*)_payload+44+5))<<40|((uint64_t)*((uint8_t*)_payload+44+6))<<48|((uint64_t)*((uint8_t*)_payload+44+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_HITL_GPS_COMMON_time(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+52)|((uint64_t)*((uint8_t*)_payload+52+1))<<8|((uint64_t)*((uint8_t*)_payload+52+2))<<16|((uint64_t)*((uint8_t*)_payload+52+3))<<24|((uint64_t)*((uint8_t*)_payload+52+4))<<32|((uint64_t)*((uint8_t*)_payload+52+5))<<40|((uint64_t)*((uint8_t*)_payload+52+6))<<48|((uint64_t)*((uint8_t*)_payload+52+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))

#define DL_GPS_INT_gps_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_GPS_INT_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_GPS_INT_ecef_x(_payload) ((int32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24))
#define DL_GPS_INT_ecef_y(_payload) ((int32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24))
#define DL_GPS_INT_ecef_z(_payload) ((int32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24))
#define DL_GPS_INT_lat(_payload) ((int32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24))
#define DL_GPS_INT_lon(_payload) ((int32_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8|((uint32_t)*((uint8_t*)_payload+20+2))<<16|((uint32_t)*((uint8_t*)_payload+20+3))<<24))
#define DL_GPS_INT_alt(_payload) ((int32_t)(*((uint8_t*)_payload+24)|*((uint8_t*)_payload+24+1)<<8|((uint32_t)*((uint8_t*)_payload+24+2))<<16|((uint32_t)*((uint8_t*)_payload+24+3))<<24))
#define DL_GPS_INT_hmsl(_payload) ((int32_t)(*((uint8_t*)_payload+28)|*((uint8_t*)_payload+28+1)<<8|((uint32_t)*((uint8_t*)_payload+28+2))<<16|((uint32_t)*((uint8_t*)_payload+28+3))<<24))
#define DL_GPS_INT_ecef_xd(_payload) ((int32_t)(*((uint8_t*)_payload+32)|*((uint8_t*)_payload+32+1)<<8|((uint32_t)*((uint8_t*)_payload+32+2))<<16|((uint32_t)*((uint8_t*)_payload+32+3))<<24))
#define DL_GPS_INT_ecef_yd(_payload) ((int32_t)(*((uint8_t*)_payload+36)|*((uint8_t*)_payload+36+1)<<8|((uint32_t)*((uint8_t*)_payload+36+2))<<16|((uint32_t)*((uint8_t*)_payload+36+3))<<24))
#define DL_GPS_INT_ecef_zd(_payload) ((int32_t)(*((uint8_t*)_payload+40)|*((uint8_t*)_payload+40+1)<<8|((uint32_t)*((uint8_t*)_payload+40+2))<<16|((uint32_t)*((uint8_t*)_payload+40+3))<<24))
#define DL_GPS_INT_pacc(_payload) ((int32_t)(*((uint8_t*)_payload+44)|*((uint8_t*)_payload+44+1)<<8|((uint32_t)*((uint8_t*)_payload+44+2))<<16|((uint32_t)*((uint8_t*)_payload+44+3))<<24))
#define DL_GPS_INT_sacc(_payload) ((int32_t)(*((uint8_t*)_payload+48)|*((uint8_t*)_payload+48+1)<<8|((uint32_t)*((uint8_t*)_payload+48+2))<<16|((uint32_t)*((uint8_t*)_payload+48+3))<<24))
#define DL_GPS_INT_tow(_payload) ((uint32_t)(*((uint8_t*)_payload+52)|*((uint8_t*)_payload+52+1)<<8|((uint32_t)*((uint8_t*)_payload+52+2))<<16|((uint32_t)*((uint8_t*)_payload+52+3))<<24))
#define DL_GPS_INT_pdop(_payload) ((uint16_t)(*((uint8_t*)_payload+56)|*((uint8_t*)_payload+56+1)<<8))
#define DL_GPS_INT_numsv(_payload) ((uint8_t)(*((uint8_t*)_payload+58)))
#define DL_GPS_INT_fix(_payload) ((uint8_t)(*((uint8_t*)_payload+59)))

#define DL_AHRS_ECEF_ir_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_AHRS_ECEF_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_AHRS_ECEF_p(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+4)|((uint64_t)*((uint8_t*)_payload+4+1))<<8|((uint64_t)*((uint8_t*)_payload+4+2))<<16|((uint64_t)*((uint8_t*)_payload+4+3))<<24|((uint64_t)*((uint8_t*)_payload+4+4))<<32|((uint64_t)*((uint8_t*)_payload+4+5))<<40|((uint64_t)*((uint8_t*)_payload+4+6))<<48|((uint64_t)*((uint8_t*)_payload+4+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_AHRS_ECEF_q(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+12)|((uint64_t)*((uint8_t*)_payload+12+1))<<8|((uint64_t)*((uint8_t*)_payload+12+2))<<16|((uint64_t)*((uint8_t*)_payload+12+3))<<24|((uint64_t)*((uint8_t*)_payload+12+4))<<32|((uint64_t)*((uint8_t*)_payload+12+5))<<40|((uint64_t)*((uint8_t*)_payload+12+6))<<48|((uint64_t)*((uint8_t*)_payload+12+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_AHRS_ECEF_r(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+20)|((uint64_t)*((uint8_t*)_payload+20+1))<<8|((uint64_t)*((uint8_t*)_payload+20+2))<<16|((uint64_t)*((uint8_t*)_payload+20+3))<<24|((uint64_t)*((uint8_t*)_payload+20+4))<<32|((uint64_t)*((uint8_t*)_payload+20+5))<<40|((uint64_t)*((uint8_t*)_payload+20+6))<<48|((uint64_t)*((uint8_t*)_payload+20+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))

#define DL_AHRS_LTP_ir_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_AHRS_LTP_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_AHRS_LTP_qi(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+4)|((uint64_t)*((uint8_t*)_payload+4+1))<<8|((uint64_t)*((uint8_t*)_payload+4+2))<<16|((uint64_t)*((uint8_t*)_payload+4+3))<<24|((uint64_t)*((uint8_t*)_payload+4+4))<<32|((uint64_t)*((uint8_t*)_payload+4+5))<<40|((uint64_t)*((uint8_t*)_payload+4+6))<<48|((uint64_t)*((uint8_t*)_payload+4+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_AHRS_LTP_qx(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+12)|((uint64_t)*((uint8_t*)_payload+12+1))<<8|((uint64_t)*((uint8_t*)_payload+12+2))<<16|((uint64_t)*((uint8_t*)_payload+12+3))<<24|((uint64_t)*((uint8_t*)_payload+12+4))<<32|((uint64_t)*((uint8_t*)_payload+12+5))<<40|((uint64_t)*((uint8_t*)_payload+12+6))<<48|((uint64_t)*((uint8_t*)_payload+12+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_AHRS_LTP_qy(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+20)|((uint64_t)*((uint8_t*)_payload+20+1))<<8|((uint64_t)*((uint8_t*)_payload+20+2))<<16|((uint64_t)*((uint8_t*)_payload+20+3))<<24|((uint64_t)*((uint8_t*)_payload+20+4))<<32|((uint64_t)*((uint8_t*)_payload+20+5))<<40|((uint64_t)*((uint8_t*)_payload+20+6))<<48|((uint64_t)*((uint8_t*)_payload+20+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_AHRS_LTP_qz(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+28)|((uint64_t)*((uint8_t*)_payload+28+1))<<8|((uint64_t)*((uint8_t*)_payload+28+2))<<16|((uint64_t)*((uint8_t*)_payload+28+3))<<24|((uint64_t)*((uint8_t*)_payload+28+4))<<32|((uint64_t)*((uint8_t*)_payload+28+5))<<40|((uint64_t)*((uint8_t*)_payload+28+6))<<48|((uint64_t)*((uint8_t*)_payload+28+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))

#define DL_NPS_SENSOR_XXX_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_NPS_SENSOR_XXX_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_NPS_SENSOR_XXX_X(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+4)|((uint64_t)*((uint8_t*)_payload+4+1))<<8|((uint64_t)*((uint8_t*)_payload+4+2))<<16|((uint64_t)*((uint8_t*)_payload+4+3))<<24|((uint64_t)*((uint8_t*)_payload+4+4))<<32|((uint64_t)*((uint8_t*)_payload+4+5))<<40|((uint64_t)*((uint8_t*)_payload+4+6))<<48|((uint64_t)*((uint8_t*)_payload+4+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_NPS_SENSOR_XXX_Y(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+12)|((uint64_t)*((uint8_t*)_payload+12+1))<<8|((uint64_t)*((uint8_t*)_payload+12+2))<<16|((uint64_t)*((uint8_t*)_payload+12+3))<<24|((uint64_t)*((uint8_t*)_payload+12+4))<<32|((uint64_t)*((uint8_t*)_payload+12+5))<<40|((uint64_t)*((uint8_t*)_payload+12+6))<<48|((uint64_t)*((uint8_t*)_payload+12+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_NPS_SENSOR_XXX_Z(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+20)|((uint64_t)*((uint8_t*)_payload+20+1))<<8|((uint64_t)*((uint8_t*)_payload+20+2))<<16|((uint64_t)*((uint8_t*)_payload+20+3))<<24|((uint64_t)*((uint8_t*)_payload+20+4))<<32|((uint64_t)*((uint8_t*)_payload+20+5))<<40|((uint64_t)*((uint8_t*)_payload+20+6))<<48|((uint64_t)*((uint8_t*)_payload+20+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))

#define DL_HITL_IR_AHRS_ir_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_HITL_IR_AHRS_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_HITL_IR_AHRS_roll(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+4)|((uint64_t)*((uint8_t*)_payload+4+1))<<8|((uint64_t)*((uint8_t*)_payload+4+2))<<16|((uint64_t)*((uint8_t*)_payload+4+3))<<24|((uint64_t)*((uint8_t*)_payload+4+4))<<32|((uint64_t)*((uint8_t*)_payload+4+5))<<40|((uint64_t)*((uint8_t*)_payload+4+6))<<48|((uint64_t)*((uint8_t*)_payload+4+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_HITL_IR_AHRS_pitch(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+12)|((uint64_t)*((uint8_t*)_payload+12+1))<<8|((uint64_t)*((uint8_t*)_payload+12+2))<<16|((uint64_t)*((uint8_t*)_payload+12+3))<<24|((uint64_t)*((uint8_t*)_payload+12+4))<<32|((uint64_t)*((uint8_t*)_payload+12+5))<<40|((uint64_t)*((uint8_t*)_payload+12+6))<<48|((uint64_t)*((uint8_t*)_payload+12+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_HITL_IR_AHRS_yaw(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+20)|((uint64_t)*((uint8_t*)_payload+20+1))<<8|((uint64_t)*((uint8_t*)_payload+20+2))<<16|((uint64_t)*((uint8_t*)_payload+20+3))<<24|((uint64_t)*((uint8_t*)_payload+20+4))<<32|((uint64_t)*((uint8_t*)_payload+20+5))<<40|((uint64_t)*((uint8_t*)_payload+20+6))<<48|((uint64_t)*((uint8_t*)_payload+20+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_HITL_IR_AHRS_p(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+28)|((uint64_t)*((uint8_t*)_payload+28+1))<<8|((uint64_t)*((uint8_t*)_payload+28+2))<<16|((uint64_t)*((uint8_t*)_payload+28+3))<<24|((uint64_t)*((uint8_t*)_payload+28+4))<<32|((uint64_t)*((uint8_t*)_payload+28+5))<<40|((uint64_t)*((uint8_t*)_payload+28+6))<<48|((uint64_t)*((uint8_t*)_payload+28+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_HITL_IR_AHRS_q(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+36)|((uint64_t)*((uint8_t*)_payload+36+1))<<8|((uint64_t)*((uint8_t*)_payload+36+2))<<16|((uint64_t)*((uint8_t*)_payload+36+3))<<24|((uint64_t)*((uint8_t*)_payload+36+4))<<32|((uint64_t)*((uint8_t*)_payload+36+5))<<40|((uint64_t)*((uint8_t*)_payload+36+6))<<48|((uint64_t)*((uint8_t*)_payload+36+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_HITL_IR_AHRS_r(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+44)|((uint64_t)*((uint8_t*)_payload+44+1))<<8|((uint64_t)*((uint8_t*)_payload+44+2))<<16|((uint64_t)*((uint8_t*)_payload+44+3))<<24|((uint64_t)*((uint8_t*)_payload+44+4))<<32|((uint64_t)*((uint8_t*)_payload+44+5))<<40|((uint64_t)*((uint8_t*)_payload+44+6))<<48|((uint64_t)*((uint8_t*)_payload+44+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
