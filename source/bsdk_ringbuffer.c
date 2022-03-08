/**
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
 */
#include "bsdk_memutils.h"
#include "bsdk_ringbuffer.h"

void ringbuffer_init(struct bsdk_ringbuffer* ref, uint8_t* buff, size_t buff_len)
{
	ref->data = buff;
	ref->size = buff_len;
	ref->r_off = 0;
	ref->w_off = 0;
}

int bsdk_ringbuffer_write(struct bsdk_ringbuffer* ref, uint8_t* src, size_t n)
{
	/* If you want to write more than can fit in this bsdk_ringbuffer it's
	 * likely an error...
	 */
	if (n > ref->size)
		return -1;

	bsdk_memcopy_dst_mod(ref->data + ref->w_off, src, n, ref->size);
	ref->w_off = (ref->w_off + n) % ref->size;
	return 0;
}

size_t bsdk_ringbuffer_read(struct bsdk_ringbuffer* ref, uint8_t* dst, size_t n)
{
	/* If you want to read more than can fit in this bsdk_ringbuffer it's
	 * likely an error...
	 */
	if (n > ref->size)
		return -1;

	bsdk_memcopy_src_mod(dst, ref->data + ref->r_off, n, ref->size);
	ref->r_off = (ref->r_off + n) % ref->size;
	return 0;
}
