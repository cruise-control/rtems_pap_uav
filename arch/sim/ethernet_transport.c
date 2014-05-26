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

#define sendPort 9999

char eth_buf[256];
char *eth_p = eth_buf;
char *buffLen = &eth_buf[1];
////TODO At some point will need to close the port...
//int obtainedSocket = 0;
//
//int send_fd;
//struct sockaddr_in send_addr;
//
//void ethernet_send_msg(int length) {
//
//	/*
//	 * TODO Fix the problem in Serial_pap later. This for now
//	 * Padding the temp buffer with 0x01 values. Then transmitting a
//	 * packet that is 256 in length always. This is because of the
//	 * message parsing thread in Serial_pap which does not recombine packets
//	 * and cannot handle corner cases with partial messages.
//	 * This will add more latency to communications but keeps the serial_pap
//	 * program simple and generic
//	 */
//
//#define MAX_BUF_SIZE 256
//
//	int txLength = length;
//
//	//Fill the buffer with padded data
//	int i = 0;
//	for (i = length; i < txLength; i++) {
//		eth_buf[i] = 0x01;
//	}
//
//	uint8_t temp_buffer[txLength];
//	memset(temp_buffer, '0', sizeof(temp_buffer));
//	memcpy(temp_buffer, eth_buf, txLength);
//
//	//Open the Socket only once
//	if (!obtainedSocket) {
//
//		send_fd = socket(AF_INET, SOCK_STREAM, 0);
//		if (send_fd < 0) {
//			//We don't have a socket fd, this message is lost, return
//			//printf("ERROR opening send socket");
//			UART1Puts("ethSend bad fd\n");
//			return;
//
//		}
//
//		memset(&send_addr, '0', sizeof(send_addr));
//
//		send_addr.sin_family = AF_INET;
//		send_addr.sin_addr.s_addr = inet_addr("10.42.0.3");
//		send_addr.sin_port = htons(sendPort);
//		int status = connect(send_fd, &send_addr, sizeof(send_addr));
//
//		if (status != -1) {
//			//printf("connected\n");
//		} else {
//			//We don't have a socket connection, this message is lost, return
//			UART1Puts("ethSend no connect\n");
//			return;
//		}
//
//		obtainedSocket = 1;
//	}
//
//	int num_bytes = send(send_fd, temp_buffer, txLength, 0);
//	if (num_bytes != txLength) {
//		//printf("Could not send all the bytes in one single packet");
//	}
//	close(send_fd);
//
//	UART1Puts("ethSend complete\n");
//}

void ethernet_send_msg(int length) {

	/*
	 * TODO Fix the problem in Serial_pap later. This for now
	 * Padding the temp buffer with 0x01 values. Then transmitting a
	 * packet that is 256 in length always. This is because of the
	 * message parsing thread in Serial_pap which does not recombine packets
	 * and cannot handle corner cases with partial messages.
	 * This will add more latency to communications but keeps the serial_pap
	 * program simple and generic
	 */

	UART1Puts(">> ethernet_send_msg");
#define MAX_BUF_SIZE 256

	int txLength = length;

	//Fill the buffer with padded data
	int i = 0;
	for (i = length; i < txLength; i++) {
		eth_buf[i] = 0x01;
	}

	uint8_t temp_buffer[txLength];
	memset(temp_buffer, '0', sizeof(temp_buffer));
	memcpy(temp_buffer, eth_buf, txLength);
	int send_fd;
	struct sockaddr_in send_addr;
	send_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (send_fd < 0) {
		//We don't have a socket fd, this message is lost, return
		//printf("ERROR opening send socket");
//		UART1Puts("ethSend bad fd\n");
//		return;

	}

	memset(&send_addr, '0', sizeof(send_addr));

	send_addr.sin_family = AF_INET;
	send_addr.sin_addr.s_addr = inet_addr("10.42.0.3");
	send_addr.sin_port = htons(sendPort);
	int status = connect(send_fd, &send_addr, sizeof(send_addr));

	if (status != -1) {
		//printf("connected\n");
	} else {
		//We don't have a socket connection, this message is lost, return
//		UART1Puts("ethSend no connect\n");
//		return;
	}
	int num_bytes = send(send_fd, temp_buffer, txLength, 0);
	if (num_bytes != txLength) {
		//printf("Could not send all the bytes in one single packet");
	}
	close(send_fd);

	UART1Puts(" >>\n");

}
