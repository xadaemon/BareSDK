/**
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
 */
#ifndef BSDK_RINGBUFF_H
#define BSDK_RINGBUFF_H

#include <stddef.h>
#include <stdint.h>

/**
 * Ringbuffer struct, this implementation deals in bytes,
 * care is expected from the caller to only read/write
 * constant size or to keep track of element sizing
 * elsewhere.
 */
struct ringbuffer {
	size_t size;
	size_t r_off;
	size_t w_off;
	uint8_t *data;
};

/**
 * Initialize a ringbuffer using buff as a backing buffer
 * @attention Care must be taken to not use after freeing of the `buff` buffer (not applicable to stack memory)
 * @param ref the ringbuffer to initialize
 * @param buff the buffer to initialize
 * @param buff_len how long is the buffer
 */
extern void ringbuffer_init(struct ringbuffer *ref, uint8_t *buff,
			    size_t buff_len);

/**
 * Write n bytes from src to to the ringbuffer ref
 * @param ref the ringbuffer to operate on
 * @param src where to copy the bytes from
 * @param n how many bytes to copy
 * @return -1 on failure 0 on success
 */
extern int ringbuffer_write(struct ringbuffer *ref, uint8_t *src, size_t n);

/**
 *
 * @param ref the ringbuffer to operate on
 * @param dst where to copy bytes to
 * @param n how many bytes to retrieve
 * @return -1 on failure 0 on success
 */
extern size_t ringbuffer_read(struct ringbuffer *ref, uint8_t *dst, size_t n);

#endif//BSDK_RINGBUFF_H
