/*
 * ethernet_transport.h
 *
 *  Created on: Apr 5, 2014
 *      Author: rtdroid
 */

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include "subsystems/datalink/transport.h"

//#include "system.h"
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/sockio.h>
#include "../../mcu_periph/uart.h"
#include "../../lib/ring_buf.h"

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

#ifdef USE_ETH
static inline void eth_parse_payload(struct pprz_transport * t) {
	uint8_t i;
	for (i = 0; i < t->trans.payload_len; i++)
		dl_buffer[i] = t->trans.payload[i];
	dl_msg_available = TRUE;
}

//#define DEBUG_ETH

//TODO Must implement our own message parsing here
//Need to Scan over the bytes for the start and end chars of the packet
//Then extract this as a message while saving the rest of the buffer for later processing
//If there is more data in the buffer, parse it for complete messages
//If the message is incomplete, store it
//A circular buffer would be idea.
//Can parse the tail and read from the head

/*
 * Circular buffer for incoming ethernet traffic.
 * This will be used to enable parsing an incoming message queue
 * without loosing any messages. The fragmentation will appear seam-less
 * to the parsing operation
 */

static inline void parseCircBuf(struct pprz_transport* t) {
	int iteration;
	//Only parse when there is plenty of data
	if (ethBufRx.count < 10)
		return;

	for (iteration = 0; iteration < 1; iteration++) {
		//We can only parse a single message at a time
		int var;
		for (var = 0; var < ethBufRx.count; ++var) {
			//If we have found a message, bail and process it
			if (t->trans.msg_received)
				break;

			uint8_t ch = ringBufS_get(&ethBufRx);

			parse_pprz(t, ch);
		}

		if (t->trans.msg_received) {
			eth_parse_payload(t);
			t->trans.msg_received = FALSE;
			DlCheckAndParse();
		}
	}
}

//void ethReadCallback(struct socket *so, caddr_t arg) {
//	rtems_event_send(1, RTEMS_EVENT_17);
//}

static inline void readEthBuffer(struct pprz_transport* t) {

#ifdef NO_ETHERNET
	return;
#endif

	static int sockfd, clientfd, portno;
	static struct sockaddr_in serv_addr;
	static int ethServerSetup = 0;
	struct fd_set working;
	struct timeval timeout;
//	struct sockwakeup wakeup;

	/*
	 #ifdef DEBUG_ETH
	 UART1Puts(">> readEthBuffer");
	 struct timespec er;
	 rtems_clock_get_uptime(&er);
	 #endif
	 */

	if (!ethServerSetup) {
		//Initialise the ethernet buffer
		ringBufS_init(&ethBufRx);
		sockfd = socket(AF_INET, SOCK_STREAM, 0);
		if (sockfd < 0) {
			UART1Puts("ERROR opening socket");
			return;
		}

		memset(&serv_addr, '0', sizeof(serv_addr));
		portno = 10000;
		serv_addr.sin_family = AF_INET;
		serv_addr.sin_addr.s_addr = INADDR_ANY;
		serv_addr.sin_port = htons(portno);

		if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))
				< 0) {
			/*
			 #ifdef DEBUG_ETH
			 struct timespec ex;
			 rtems_clock_get_uptime(&ex);

			 long begin = er.tv_sec * 1000 * 1000 + er.tv_nsec / 1000;
			 long finish = ex.tv_sec * 1000 * 1000 + ex.tv_nsec / 1000;
			 char buf[256];
			 buf[0] = '\0';
			 sprintf(buf, " start [%ld %ld] end [%ld %ld] diff %ld XX\r\n",
			 er.tv_sec, er.tv_nsec, ex.tv_sec, ex.tv_nsec,
			 finish - begin);
			 UART1PutBuf(buf);
			 #endif
			 */
			return;
		}

		listen(sockfd, 5);

		printf("Server waiting for accept\r\n");
		//waiting for connection
		clientfd = accept(sockfd, NULL, NULL);
		if (clientfd < 0) {
			/*
			 #ifdef DEBUG_ETH
			 struct timespec ex;
			 rtems_clock_get_uptime(&ex);

			 long begin = er.tv_sec * 1000 * 1000 + er.tv_nsec / 1000;
			 long finish = ex.tv_sec * 1000 * 1000 + ex.tv_nsec / 1000;
			 char buf[256];
			 buf[0] = '\0';
			 sprintf(buf, " start [%ld %ld] end [%ld %ld] diff %ld ||\r\n",
			 er.tv_sec, er.tv_nsec, ex.tv_sec, ex.tv_nsec,
			 finish - begin);
			 UART1PutBuf(buf);
			 #endif
			 */
		}
		/* This must be less than the size of the smallest message, otherwise in the processing
		 * of any given message, we could end up processing two in one cycle effectively loosing the first
		 * */
#define MSG_READ_SIZE 40

		//Set the reception socket to non-blocking
		if (fcntl(sockfd, F_SETFL, O_NONBLOCK) < 0) {
			UART1Puts("ERROR Setting sockfd to non-blocking");
			return;
		}

		//Set the reception socket to non-blocking
		if (fcntl(clientfd, F_SETFL, O_NONBLOCK) < 0) {
			UART1Puts("ERROR Setting clientfd to non-blocking");
			return;
		}

//		wakeup.sw_pfn = ethReadCallback;
//		wakeup.sw_arg = (caddr_t) sockfd;
//		setsockopt(sockfd, SOL_SOCKET, SO_RCVWAKEUP, &wakeup, sizeof(wakeup));

		/*
		 //Set the min count for revieve ops to be our min_read size, don't want to wait for large
		 //data volumes before we read data
		 int min = MSG_READ_SIZE;
		 setsockopt(clientfd, SOL_SOCKET, SO_RCVLOWAT, &min, sizeof(min));
		 */
		UART1Puts("Server received accept\r\n");
		ethServerSetup = 1;
	}

	//Allow the connection to happen but return
//#define DEBUG_NO_ETHERNET_RX
#ifdef DEBUG_NO_ETHERNET_RX
	return;
#endif

	struct timespec er;
	rtems_clock_get_uptime(&er);

	char buffer[MSG_READ_SIZE];
	memset(buffer, 0, sizeof(buffer));

	int numBytes = read(clientfd, buffer, MSG_READ_SIZE);

	if (numBytes <= 0) {

		//This is for non-blocking Rx which was not working
		if (errno == EWOULDBLOCK) {
#if 0
			struct timespec ex;
			rtems_clock_get_uptime(&ex);

			long begin = er.tv_sec * 1000 * 1000 + er.tv_nsec / 1000;
			long finish = ex.tv_sec * 1000 * 1000 + ex.tv_nsec / 1000;
			char buf[256];
			buf[0] = '\0';
			sprintf(buf, " diff %ld XX\r\n", finish - begin);
			//sprintf(buf, " start [%ld %ld] end [%ld %ld] diff %ld ||\r\n", er.tv_sec,
			//		er.tv_nsec, ex.tv_sec, ex.tv_nsec, finish - begin);
			UART1PutBuf(buf);
#endif
			return;
		}
		return;
	}

#define USE_CIRC_BUF
#ifndef USE_CIRC_BUF
	int var;
	for (var = 0; var < numBytes; ++var) {
		uint8_t ch = buffer[var];
		parse_pprz(t, ch);
	}

#else
	ringBusS_putBlock(&ethBufRx, (uint8_t*) buffer, numBytes);
#endif

#if 0
	struct timespec ex;
	rtems_clock_get_uptime(&ex);

	long begin = er.tv_sec * 1000 * 1000 + er.tv_nsec / 1000;
	long finish = ex.tv_sec * 1000 * 1000 + ex.tv_nsec / 1000;
	char buf[256];
	buf[0] = '\0';
	sprintf(buf, " diff %ld ||\r\n", finish - begin);
	//sprintf(buf, " start [%ld %ld] end [%ld %ld] diff %ld ||\r\n", er.tv_sec,
	//		er.tv_nsec, ex.tv_sec, ex.tv_nsec, finish - begin);
	UART1PutBuf(buf);
#endif
	if (!ethServerSetup)
		close();
}

extern struct pprz_transport eth_tp;

#endif

/* Sai: */

#define EthCheckAndParse(_trans) { \
	readEthBuffer(&(_trans)); \
	parseCircBuf(&(_trans)); \
	if (_trans.trans.msg_received) { \
		eth_parse_payload(&(_trans)); \
		_trans.trans.msg_received = FALSE; \
	} \
}
