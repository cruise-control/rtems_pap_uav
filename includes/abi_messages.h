///* Automatically generated from /home/j3/paparazzi/conf/abi.xml */
///* Please DO NOT EDIT */
//
///* Onboard middleware library ABI
// * send and receive messages of class airborne
// */
//
//#ifndef ABI_MESSAGES_H
//#define ABI_MESSAGES_H
//
//#include "subsystems/abi_common.h"
//
///* Messages IDs */
//#define ABI_BARO_ABS_ID 0
//#define ABI_BARO_DIFF_ID 1
//#define ABI_AGL_ID 2
//
///* Array and linked list structure */
//#define ABI_MESSAGE_NB 3
//
//ABI_EXTERN abi_event* abi_queues[ABI_MESSAGE_NB];
//
///* Callbacks */
//typedef void (*abi_callbackBARO_ABS)(uint8_t sender_id, const float * pressure);
//typedef void (*abi_callbackBARO_DIFF)(uint8_t sender_id, const float * pressure);
//typedef void (*abi_callbackAGL)(uint8_t sender_id, const float * distance);
//
///* Bind and Send functions */
//
//static inline void AbiBindMsgBARO_ABS(uint8_t sender_id, abi_event * ev, abi_callbackBARO_ABS cb) {
//  ev->id = sender_id;
//  ev->cb = (abi_callback)cb;
//  ABI_PREPEND(abi_queues[ABI_BARO_ABS_ID],ev);
//}
//
//static inline void AbiSendMsgBARO_ABS(uint8_t sender_id, const float * pressure) {
//  abi_event* e;
//  ABI_FOREACH(abi_queues[ABI_BARO_ABS_ID],e) {
//    if (e->id == ABI_BROADCAST || e->id == sender_id) {
//      abi_callbackBARO_ABS cb = (abi_callbackBARO_ABS)(e->cb);
//      cb(sender_id, pressure);
//    };
//  };
//};
//
//static inline void AbiBindMsgBARO_DIFF(uint8_t sender_id, abi_event * ev, abi_callbackBARO_DIFF cb) {
//  ev->id = sender_id;
//  ev->cb = (abi_callback)cb;
//  ABI_PREPEND(abi_queues[ABI_BARO_DIFF_ID],ev);
//}
//
//static inline void AbiSendMsgBARO_DIFF(uint8_t sender_id, const float * pressure) {
//  abi_event* e;
//  ABI_FOREACH(abi_queues[ABI_BARO_DIFF_ID],e) {
//    if (e->id == ABI_BROADCAST || e->id == sender_id) {
//      abi_callbackBARO_DIFF cb = (abi_callbackBARO_DIFF)(e->cb);
//      cb(sender_id, pressure);
//    };
//  };
//};
//
//static inline void AbiBindMsgAGL(uint8_t sender_id, abi_event * ev, abi_callbackAGL cb) {
//  ev->id = sender_id;
//  ev->cb = (abi_callback)cb;
//  ABI_PREPEND(abi_queues[ABI_AGL_ID],ev);
//}
//
//static inline void AbiSendMsgAGL(uint8_t sender_id, const float * distance) {
//  abi_event* e;
//  ABI_FOREACH(abi_queues[ABI_AGL_ID],e) {
//    if (e->id == ABI_BROADCAST || e->id == sender_id) {
//      abi_callbackAGL cb = (abi_callbackAGL)(e->cb);
//      cb(sender_id, distance);
//    };
//  };
//};
//
//#endif // ABI_MESSAGES_H
