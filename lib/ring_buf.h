/*
 * ring_buf.h
 *
 *  Created on: May 28, 2014
 *      Author: j3
 */

#ifndef RING_BUF_H_
#define RING_BUF_H_

#define RBUF_SIZE    768

typedef struct ringBufS {
	unsigned char buf[RBUF_SIZE];
	int head;
	int tail;
	int count;
} ringBufS;


extern ringBufS ethBufRx;


void ringBufS_init(ringBufS *_this);
int ringBufS_empty(ringBufS *_this);
int ringBufS_full(ringBufS *_this);
unsigned char ringBufS_get(ringBufS *_this);
void ringBufS_put(ringBufS *_this, unsigned char c);
void ringBusS_putBlock(ringBufS *_this, unsigned char* c,
		int quantity);
void ringBufS_flush(ringBufS *_this, const int clearBuffer);

#endif /* RING_BUF_H_ */
