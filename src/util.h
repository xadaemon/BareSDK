/**
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
 */
#ifndef KERNELKIT_UTIL_H
#define KERNELKIT_UTIL_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef signed long ssize_t;

extern void kkc_memcopy(void *dst, void *src, size_t n);
extern void kkc_memcopy_dst_mod(void *dst, void *src, size_t n, size_t mod);
extern void kkc_memcopy_src_mod(void *dst, void *src, size_t n, size_t mod);
extern bool kkc_strcmp(const char *a, const char *b, size_t n);
extern size_t min(size_t x, size_t y);
extern size_t max(size_t x, size_t y);

#endif
