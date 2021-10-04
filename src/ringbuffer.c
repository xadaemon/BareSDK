/**
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
 */
#include <ringbuffer.h>
#include "util.h"

void ringbuffer_init(struct ringbuffer *ref, uint8_t *buff, size_t buff_len)
{
	ref->data = buff;
	ref->size = buff_len;
	ref->r_off = 0;
	ref->w_off = 0;
}

int ringbuffer_write(struct ringbuffer *ref, uint8_t *src, size_t n)
{
	/* If you want to write more than can fit in this ringbuffer it's
	 * likely an error...
	 */
	if (n > ref->size)
		return -1;

	kkc_mem_copy(ref->data + ref->w_off, src, n);
	ref->w_off = (ref->w_off + n) % ref->size;
	return 0;
}

size_t ringbuffer_read(struct ringbuffer *ref, uint8_t *dst, size_t n)
{
	/* If you want to read more than can fit in this ringbuffer it's
	 * likely an error...
	 */
	if (n > ref->size)
		return -1;

	kkc_mem_copy_mod(dst, ref->data + ref->r_off, n, ref->size);
	ref->r_off = (ref->r_off + n) % ref->size;
	return 0;
}
