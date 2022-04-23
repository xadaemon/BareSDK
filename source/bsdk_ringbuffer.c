/**
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
 */
#include "bsdk_ringbuffer.h"
#include "bsdk_memutils.h"

void ringbuffer_init(struct bsdk_ringbuffer *self, uint8_t *buff, size_t buff_len)
{
	self->data = buff;
	self->size = buff_len;
	self->r_off = 0;
	self->w_off = 0;
}

int bsdk_ringbuffer_write(struct bsdk_ringbuffer *self, uint8_t *src, size_t n)
{
	/* If you want to write more than can fit in this bsdk_ringbuffer it's
	 * likely an error...
	 */
	if (n > self->size)
		return -1;

	bsdk_memcopy_dst_mod(self->data + self->w_off, src, n, self->size);
	self->w_off = (self->w_off + n) % self->size;
	return 0;
}

size_t bsdk_ringbuffer_read(struct bsdk_ringbuffer *self, uint8_t *dst, size_t n)
{
	/* If you want to read more than can fit in this bsdk_ringbuffer it's
	 * likely an error...
	 */
	if (n > self->size)
		return -1;

	bsdk_memcopy_src_mod(dst, self->data + self->r_off, n, self->size);
	self->r_off = (self->r_off + n) % self->size;
	return 0;
}
