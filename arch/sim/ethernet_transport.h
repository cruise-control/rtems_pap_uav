/*
 * ethernet_transport.h
 *
 *  Created on: Apr 5, 2014
 *      Author: rtdroid
 */

#include <stdio.h>
#include "subsystems/datalink/transport.h"

extern char eth_buf[];
extern char* eth_p;
extern char *buffLen;
extern void ethernet_send_msg(int);
#define ETH_START 0x7E
#define ETH_END   0x7F

#define EthernetCheckFreeSpace(_dev,_) TRUE
#define EthernetSizeOf(_dev, _payload) (_payload)
#define EthernetPut1Byte(_dev,_x)  { \
    int bytes =sprintf(eth_p,"%c",_x);		 \
    (*buffLen)+=bytes;				 \
    eth_p+=bytes;				 \
  }

#define EthernetHeader(_dev,len) { \
	eth_p=eth_buf;		       \
    (*buffLen)=0;				\
    EthernetPut1Byte(_dev,ETH_START);	\
    EthernetPut1Byte(_dev,*buffLen);		\
  }

// need to replace the code for transport byte with socket code!!!
#define EthernetTrailer(_dev) {		\
  EthernetPut1Byte(_dev,'\0');		\
  EthernetPut1Byte(_dev,ETH_END);		\
  uint8_t _i= *buffLen;					\
  ethernet_send_msg(_i);					\
  }

#define EthernetPutUint8(_dev,x) {		\
    int bytes= sprintf(eth_p, "%u ", x);	\
    (*buffLen)+=bytes;				\
    eth_p+=bytes;				\
  }

#define EthernetPutNamedUint8(_dev,_name, _x) {	\
    int bytes = sprintf(eth_p, "%s ", _name);		\
    (*buffLen)+=bytes;					\
    eth_p+=bytes;					\
  }

#define EthSpace() {					\
    int bytes = sprintf(eth_p, " ");			\
    (*buffLen)+=bytes;					\
    eth_p+=bytes;					\
  }

#define EthComma() {					\
    int bytes  = sprintf(eth_p, ",");			\
    (*buffLen)+=bytes;					\
    eth_p+=bytes;					\
  }

#define EthernetPutUintByAddr(_dev,x) {		\
    int bytes = sprintf(eth_p, "%u", *x);				\
    (*buffLen)+=bytes;					\
    eth_p+=bytes;					\
  }
#define EthernetPutUint8ByAddr(_dev,x) EthernetPutUintByAddr(_dev,x) EthSpace()
#define EthernetPutUint16ByAddr(_dev,x) EthernetPutUintByAddr(_dev,x) EthSpace()
#define EthernetPutUint32ByAddr(_dev,x) EthernetPutUintByAddr(_dev,x) EthSpace()

#define EthernetPutIntByAddr(_dev,x){ \
  int bytes = sprintf(eth_p, "%d", *x);\
  (*buffLen)+=bytes;					\
  eth_p+=bytes;						\
}

#define EthernetPutInt8ByAddr(_dev,x) EthernetPutIntByAddr(_dev,x) EthSpace()
#define EthernetPutInt16ByAddr(_dev,x) EthernetPutIntByAddr(_dev,x) EthSpace()
#define EthernetPutInt32ByAddr(_dev,x) EthernetPutIntByAddr(_dev,x) EthSpace()

#define EthernetPutOneFloatByAddr(_dev,x) { \
    int bytes = sprintf(eth_p, "%f", *x);		\
    (*buffLen)+=bytes;					\
    eth_p+=bytes;					\
  }

#define EthernetPutFloatByAddr(_dev,x) EthernetPutOneFloatByAddr(_dev,x) EthSpace()
#define EthernetPutDoubleByAddr(_dev,x) EthernetPutOneFloatByAddr(_dev,x) EthSpace()

#define EthernetPutArray(_dev,_put, _n, _x) { \
  int __i; \
  for(__i = 0; __i < _n; __i++) { \
    _put(_dev,&_x[__i]); \
    EthComma(); \
  } \
}

#define EthernetPutUint8Array(_dev,_n, _x) EthernetPutArray(_dev,EthernetPutUintByAddr, _n, _x)
#define EthernetPutInt16Array(_dev,_n, _x) EthernetPutArray(_dev,EthernetPutIntByAddr, _n, _x)
#define EthernetPutUint16Array(_dev,_n, _x) EthernetPutArray(_dev,EthernetPutUintByAddr, _n, _x)
#define EthernetPutUint32Array(_dev,_n, _x) EthernetPutArray(_dev,EthernetPutUintByAddr, _n, _x)
#define EthernetPutFloatArray(_dev,_n, _x) EthernetPutArray(_dev,EthernetPutOneFloatByAddr, _n, _x)
#define EthernetPutDoubleArray(_dev,_n, _x) EthernetPutFloatArray(_dev,_n, _x)
