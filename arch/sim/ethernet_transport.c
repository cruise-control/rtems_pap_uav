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

#define sendPort 9999


char eth_buf[256];
char *eth_p = eth_buf;
char *buffLen =&eth_buf[1];

void ethernet_send_msg(int length) {

	uint8_t temp_buffer[256];
	memset(temp_buffer, '0', sizeof(temp_buffer));
	memcpy(temp_buffer, eth_buf, length);
	int send_fd;
	struct sockaddr_in send_addr;
	send_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (send_fd < 0)
		//printf("ERROR opening send socket");

	memset(&send_addr, '0', sizeof(send_addr));

	send_addr.sin_family = AF_INET;
	send_addr.sin_addr.s_addr = inet_addr("10.42.0.3");
	send_addr.sin_port = htons(sendPort);
	int status = connect(send_fd, &send_addr, sizeof(send_addr));

	if (status != -1) {
		//printf("connected\n");
	} else {
		//printf("error connecting\n");
	}
	int num_bytes = send(send_fd, temp_buffer, length, 0);
	if (num_bytes != length) {
		//printf("Could not send all the bytes in one single packet");
	}
	close(send_fd);
}
