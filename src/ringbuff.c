/**
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
 */
#include <ringbuff.h>
#include "util.h"

void ringbuff_init(struct ringbuff *ref, uint8_t *buff, size_t buff_len)
{
	ref->data = buff;
	ref->size = buff_len;
	ref->r_base = 0;
	ref->data_size = 0;

}

size_t ringbuff_write(struct ringbuff *ref, uint8_t *src, size_t n)
{
	ssize_t w_base = ref->r_base + ref->data_size;

	for (size_t i = 0; i < n; i++) {
		ref->data[(w_base + i) % ref->size] = src[i];
	}

	/* Have we erased old data? */
	if (n > ref->size - ringbuff_available(ref)) {
		ref->r_base = (w_base + n) % ref->size;
	}

	ref->data_size = min(ref->data_size + n, ref->size);

	return min(n, ref->size);
}

size_t ringbuff_read(uint8_t *dst, struct ringbuff *ref, size_t n)
{
	size_t to_read = min(n, ringbuff_available(ref));

	for (size_t i = 0; i < to_read; i++) {
		dst[i] = ref->data[(ref->r_base + i) % ref->size];
	}

	ref->r_base = (ref->r_base + to_read) % ref->size;
	ref->data_size -= to_read;

	return to_read;
}

size_t ringbuff_available(struct ringbuff *ref)
{
	return ref->data_size;
}
