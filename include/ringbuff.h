/**
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
 */
#ifndef KERNELKIT_RINGBUFF_H
#define KERNELKIT_RINGBUFF_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * Flags to control some of the ringbuffer behaviours
 */
enum ringbuff_flags {
    /**
     * If the write pointer is about to overwrite data, that is if
     * w_off + n > r_off return -1
     * @note this flag is meaningless if RINGBUFF_LITE is defined
     */
    no_overwrite = 1,
    /**
     * If requested to read n and there is less than n fail the read
     * @note this flag is meaningless if RINGBUFF_LITE is defined
     */
    no_read_past = 2,
};

/**
 * Ringbuffer struct, this implementation deals in bytes,
 * care is expected from the caller to only read/write
 * constant size or to keep track of element sizing
 * elsewhere.
 */
struct ringbuff {
    size_t size;
    size_t r_base;
    size_t data_size;
    uint8_t* data;
};

/**
 * Initialize a ringbuffer using `buff` as a backing buffer this function gives
 * the caller full control of the lifetime of the backing buffer
 * @attention Care must be taken to not use after freeing of the `buff` buffer
 * @param ref the ringbuff to initialize
 * @param buff
 * @param buff_len
 */
extern void ringbuff_init(struct ringbuff *ref, uint8_t *buff, size_t buff_len);

/**
 * Write n bytes from src to to the ringbuffer ref
 * @param ref the ringbuff to operate on
 * @param src from where to copy bytes from
 * @param n how many bytes to copy
 * @return some positive number &le; n on success, 0 on failure
 */
extern size_t ringbuff_write(struct ringbuff *ref, uint8_t *src, size_t n);

extern size_t ringbuff_read(uint8_t *dst, struct ringbuff *ref, size_t n);

extern size_t ringbuff_available(struct ringbuff *ref);

#endif //KERNELKIT_RINGBUFF_H
