/**
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
 */
#ifndef BSDK_UTIL_H
#define BSDK_UTIL_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * Copy n bytes from src to dest
 * @param dst Where to copy to
 * @param src Where to copy from
 * @param n How many bytes to copy
 */
extern void bsdk_memcopy(void *dst, void *src, size_t n);
/**
 * Copy n bytes from src to dest wrapping over mod in dst
 * @param dst Where to copy to
 * @param src Where to copy from
 * @param n How many bytes to copy
 * @param mod wrap over this mod
 */
extern void bsdk_memcopy_dst_mod(void *dst, void *src, size_t n, size_t mod);
/**
 * Copy n bytes from src to dest wrapping over mod in src
 * @param dst Where to copy to
 * @param src Where to copy from
 * @param n How many bytes to copy
 * @param mod wrap over this mod
 */
extern void bsdk_memcopy_src_mod(void *dst, void *src, size_t n, size_t mod);
/**
 * Compare a to b in constant time a and b must have the same length n
 * @param a
 * @param b
 * @param n
 * @return 0 if the a != b 1 otherwise
 */
extern bool bsdk_ct_strcmp(const char *a, const char *b, size_t n);
/**
 * Compare a to b without short circuiting
 * @param a
 * @param b
 * @param n
 * @return 0 if the a != b 1 otherwise
 */
extern bool bsdk_strcmp(const char *a, const char *b, size_t n);
extern bool bsdk_bytecmp(const uint8_t *a, const uint8_t *b, size_t n);
/**
 * Measure a C string length up to the first null character
 * @param str the string to measure
 * @param max the maximum length to measure to (to avoid dos)
 * @return the size of the string
 */
extern size_t strlen(const char *str, size_t max);
extern size_t min(size_t x, size_t y);
extern size_t max(size_t x, size_t y);


#endif
