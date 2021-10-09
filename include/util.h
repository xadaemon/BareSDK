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

/**
 * Copy n bytes from src to dest
 * @param dst Where to copy to
 * @param src Where to copy from
 * @param n How many bytes to copy
 */
extern void kkc_memcopy(void *dst, void *src, size_t n);
/**
 * Copy n bytes from src to dest wrapping over mod in dst
 * @param dst Where to copy to
 * @param src Where to copy from
 * @param n How many bytes to copy
 * @param mod wrap over this mod
 */
extern void kkc_memcopy_dst_mod(void *dst, void *src, size_t n, size_t mod);
/**
 * Copy n bytes from src to dest wrapping over mod in src
 * @param dst Where to copy to
 * @param src Where to copy from
 * @param n How many bytes to copy
 * @param mod wrap over this mod
 */
extern void kkc_memcopy_src_mod(void *dst, void *src, size_t n, size_t mod);
extern bool kkc_ct_strcmp(const char *a, const char *b, size_t n);
extern size_t min(size_t x, size_t y);
extern size_t max(size_t x, size_t y);

#endif
