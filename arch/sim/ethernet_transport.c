/*
 * ethernet_transport.c
 *
 *  Created on: Apr 5, 2014
 *      Author: rtdroid
 */

/* Sai */

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/sockio.h>
#include "../../mcu_periph/uart.h"
//#include "ethernet_transport.h"

#define sendPort 9999

char eth_buf[256];
char *eth_p = eth_buf;
char *buffLen = &eth_buf[1];
////TODO At some point will need to close the port...
int obtainedSocket = 0;
int send_fd;

struct sockaddr_in send_addr;
#ifndef DEBUG_ETH

#else
#undef DEBUG_ETH
#endif
void ethernet_send_msg(int length) {
#ifdef NO_ETHERNET
	return;
#endif

	/*
	 * TODO Fix the problem in Serial_pap later. This for now
	 * Padding the temp buffer with 0x01 values. Then transmitting a
	 * packet that is 256 in length always. This is because of the
	 * message parsing thread in Serial_pap which does not recombine packets
	 * and cannot handle corner cases with partial messages.
	 * This will add more latency to communications but keeps the serial_pap
	 * program simple and generic
	 */

#define MAX_BUF_SIZE 256

	int txLength = length;

	uint8_t temp_buffer[txLength + 1];
//	memset(temp_buffer, '0', sizeof(temp_buffer));
	memcpy(temp_buffer, eth_buf, txLength);

	/*
	 * Only obtain the socket once. Hold open and write to other times
	 */
	if (!obtainedSocket) {
		send_fd = socket(AF_INET, SOCK_STREAM, 0);
		if (send_fd < 0) {
			return;
		}
		memset(&send_addr, '0', sizeof(send_addr));
		send_addr.sin_family = AF_INET;
		send_addr.sin_addr.s_addr = inet_addr("10.42.0.3");
		send_addr.sin_port = htons(sendPort);

		int status = connect(send_fd, &send_addr, sizeof(send_addr));
		if (status < 0) {
			return;
		}

		obtainedSocket = 1;
	}

//#define DEBUG_NO_ETHERNET_TX
#ifdef DEBUG_NO_ETHERNET_TX
	return;
#endif

#ifdef DEBUG_ETH
	struct timespec er;
	UART1Puts(">> ethernet_send_msg");
	rtems_clock_get_uptime(&er);
#endif

	int num_bytes = send(send_fd, temp_buffer, txLength, 0);

#ifdef DEBUG_ETH
	struct timespec ex;
	rtems_clock_get_uptime(&ex);
#endif

	if (num_bytes != txLength) {
		//TODO If this happens, check the connection and determine if we should reconnect
		//UART1Puts("Could not send all the bytes in one single packet");
	}
	//Dumb but it'll work
	if (!obtainedSocket)
		close(send_fd);
#ifdef DEBUG_ETH
	long begin = er.tv_sec * 1000 * 1000 + er.tv_nsec / 1000;
	long finish = ex.tv_sec * 1000 * 1000 + ex.tv_nsec / 1000;
	char buf[256];
	buf[0] = '\0';
	sprintf(buf, " start [%ld %ld] end [%ld %ld] diff %ld ", er.tv_sec,
			er.tv_nsec, ex.tv_sec, ex.tv_nsec, finish - begin);
	UART1PutBuf(buf);
	UART1Puts(" >>\r\n");
#endif

}
