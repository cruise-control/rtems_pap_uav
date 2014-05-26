/*
 * ethernet_transport.h
 *
 *  Created on: Apr 5, 2014
 *      Author: rtdroid
 */

#include <stdio.h>
#include "subsystems/datalink/transport.h"

//#include "system.h"
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/sockio.h>
#include "../../mcu_periph/uart.h"

#define recvPort 10000

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

/* Sai: */
#ifdef USE_ETH
static inline void eth_parse_payload(struct pprz_transport * t) {
	uint8_t i;
	for (i = 0; i < t->trans.payload_len; i++)
		dl_buffer[i] = t->trans.payload[i];
	dl_msg_available = TRUE;
}

static inline void readEthBuffer(struct pprz_transport* t) {
#ifdef DEBUG_ETH
	UART1Puts(">> readEthBuffer");
#endif
	int recv_fd;
	//fd_set read_set;
	uint8_t buffer[256];
	//char reply[256];
	buffer[0] = '\0';
	//reply[0] = '\0';
	//struct sockaddr_in serv_addr;
	struct sockaddr_in recv_addr;
	//int n;
	struct timespec er;
	rtems_clock_get_uptime(&er);

	//listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	recv_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (recv_fd < 0) {
#ifdef DEBUG_ETH
		struct timespec ex;
		rtems_clock_get_uptime(&ex);

		long begin = er.tv_sec * 1000 * 1000 + er.tv_nsec / 1000;
		long finish = ex.tv_sec * 1000 * 1000 + ex.tv_nsec / 1000;
		char buf[256];
		buf[0] = '\0';
		sprintf(buf, " start [%ld %ld] end [%ld %ld] diff %ld XX\n", er.tv_sec,
				er.tv_nsec, ex.tv_sec, ex.tv_nsec, finish - begin);
		UART1PutBuf(buf);
#endif
		return;
	}

	memset(&recv_addr, '0', sizeof(recv_addr));
	// Sai:
	recv_addr.sin_family = AF_INET;
	recv_addr.sin_addr.s_addr = inet_addr("10.42.0.3");
	recv_addr.sin_port = htons(recvPort);
	int status = connect(recv_fd, &recv_addr, sizeof(recv_addr));

	if (status < 0) {
#ifdef DEBUG_ETH
		struct timespec ex;
		rtems_clock_get_uptime(&ex);

		long begin = er.tv_sec * 1000 * 1000 + er.tv_nsec / 1000;
		long finish = ex.tv_sec * 1000 * 1000 + ex.tv_nsec / 1000;
		char buf[256];
		buf[0] = '\0';
		sprintf(buf, " start [%ld %ld] end [%ld %ld] diff %ld ||\n", er.tv_sec,
				er.tv_nsec, ex.tv_sec, ex.tv_nsec, finish - begin);
		UART1PutBuf(buf);
#endif
		return;
	}
	//send(qt_fd, reply, strlen(reply), 0);
	memset(&buffer, 0, sizeof(buffer));
	int numBytes = recv(recv_fd, buffer, sizeof(buffer) - 1, 0);
	buffer[numBytes] = '\0';
	//printf(buffer);
	//printf("\n");
	close(recv_fd);

	int var;
	for (var = 0; var < sizeof(buffer); ++var) {
		if (buffer[var] == '\0') {
			break;
		}
		uint8_t ch = buffer[var];
		parse_pprz(t, ch);
	}
#ifdef DEBUG_ETH
	struct timespec ex;
	rtems_clock_get_uptime(&ex);

	long begin = er.tv_sec * 1000 * 1000 + er.tv_nsec / 1000;
	long finish = ex.tv_sec * 1000 * 1000 + ex.tv_nsec / 1000;
	char buf[256];
	buf[0] = '\0';
	sprintf(buf, " start [%ld %ld] end [%ld %ld] diff %ld ", er.tv_sec,
			er.tv_nsec, ex.tv_sec, ex.tv_nsec, finish - begin);
	UART1PutBuf(buf);
	UART1Puts(" >>\n");
#endif
}

/* Sai */
extern struct pprz_transport eth_tp;

#endif

/* Sai: */
#define EthCheckAndParse(_trans) {  \
	readEthBuffer(&(_trans));          \
    if (_trans.trans.msg_received) {      \
    	eth_parse_payload(&(_trans));      \
      _trans.trans.msg_received = FALSE;  \
    }									\
}
