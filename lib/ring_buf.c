/*
 * ring_buf.c
 *
 *  Created on: May 28, 2014
 *      Author: j3
 */
#include "ring_buf.h"

ringBufS ethBufRx;

unsigned int modulo_inc(const unsigned int value, const unsigned int modulus) {
	unsigned int my_value = value + 1;
	if (my_value >= modulus) {
		my_value = 0;
	}
	return (my_value);
}

unsigned int modulo_dec(const unsigned int value, const unsigned int modulus) {
	unsigned int my_value = (0 == value) ? (modulus - 1) : (value - 1);
	return (my_value);
}

void ringBusS_putBlock(ringBufS *_this, unsigned char* c,
		int quantity) {
	//Take all of the bytes and put in the circular buffer
	while (quantity--)
		ringBufS_put(_this, *c++);
}

void ringBufS_put(ringBufS *_this, unsigned char c) {
	if (_this->count < RBUF_SIZE) {
		_this->buf[_this->head] = c;
		_this->head = modulo_inc(_this->head, RBUF_SIZE);
		++_this->count;
	}
}

int ringBufS_empty(ringBufS *_this) {
	return (0 == _this->count);
}

void ringBufS_flush(ringBufS *_this, const int clearBuffer) {
	_this->count = 0;
	_this->head = 0;
	_this->tail = 0;
	if (clearBuffer) {
		memset(_this->buf, 0, sizeof(_this->buf));
	}
}

int ringBufS_full(ringBufS *_this) {
	return (_this->count >= RBUF_SIZE);
}

unsigned char ringBufS_get(ringBufS *_this) {
	unsigned char c;
	if (_this->count > 0) {
		c = _this->buf[_this->tail];
		_this->tail = modulo_inc(_this->tail, RBUF_SIZE);
		--_this->count;
	} else {
		c = -1;
	}
	return (c);
}

void ringBufS_init(ringBufS *_this) {
	/*****
	 The following clears:
	 -> buf
	 -> head
	 -> tail
	 -> count
	 and sets head = tail
	 ***/
	memset(_this, 0, sizeof(*_this));
}

