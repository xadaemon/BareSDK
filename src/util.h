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

extern void kkc_mem_copy(void *dst, void *src, size_t len);
extern void kkc_mem_copy_mod(void *dst, void *src, size_t len, size_t mod);
extern size_t min(size_t x, size_t y);
extern size_t max(size_t x, size_t y);

#endif
