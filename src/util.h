/**
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
 */
#ifndef KERNELKIT_UTIL_H
#define KERNELKIT_UTIL_H

#include <stddef.h>
#include <stdint.h>

typedef signed long ssize_t;

extern void kkc_memcopy(void *dst, void *src, size_t n);
/**
 * Copy n bytes from src to dst
 * @warning No content size checks are made
 * @param dst Copy operation destination buffer
 * @param src Copy operation source buffer
 * @param len
 * @param n
 */
extern void kkc_memcopy_dst_mod(void *dst, void *src, size_t len, size_t n);
extern void kkc_memcopy_src_mod(void *dst, void *src, size_t len, size_t n);
extern size_t min(size_t x, size_t y);
extern size_t max(size_t x, size_t y);

#endif
