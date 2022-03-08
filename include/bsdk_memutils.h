/**
 * @file bsdk_memutils.h
 * @brief Utilities for moving memory around and comparing it, comes in safe(bounded) and unsafe (unbounded) flavours
 * @authors Matheus Xavier
 * This file is part of BareSDK and licensed under the:
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
 */


#ifndef BSDK_MEMUTILS_H
#define BSDK_MEMUTILS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * Copy n bytes from source to dest
 * @param dst Where to copy to
 * @param src Where to copy from
 * @param n How many bytes to copy
 */
extern void bsdk_memcopy(void* dst, void* src, size_t n);

/**
 * Copy n bytes from source to dest wrapping over mod in dst
 * @param dst Where to copy to
 * @param src Where to copy from
 * @param n How many bytes to copy
 * @param mod wrap over this mod
 */
extern void bsdk_memcopy_dst_mod(void* dst, void* src, size_t n, size_t mod);

/**
 * Copy n bytes from source to dest wrapping over mod in source
 * @param dst Where to copy to
 * @param src Where to copy from
 * @param n How many bytes to copy
 * @param mod wrap over this mod
 */
extern void bsdk_memcopy_src_mod(void* dst, void* src, size_t n, size_t mod);

/**
 * Compare a to b in constant time a and b must have the same length n
 * @param a
 * @param b
 * @param n
 * @return 0 if the a != b 1 otherwise
 */
extern bool bsdk_ct_strcmp(const char* a, const char* b, size_t n);

/**
 * Compare a to b until null is found or n is reached
 * @param a
 * @param b
 * @param n
 * @return 0 if a != b 1 otherwise
 */
extern bool bsdk_strcmpn(const char* a, const char* b, size_t n);

/**
 * Compare n bytes from a and b
 * @param a
 * @param b
 * @param n
 * @return 0 if a != b 1 otherwise
 */
extern bool bsdk_bytecmp(const uint8_t* a, const uint8_t* b, size_t n);

/**
 * Measure a C string length up to the first null character
 * @param str the string to measure
 * @param max the maximum length to measure to (to avoid dos)
 * @return the size of the string
 */
extern size_t bsdk_strlen(const char* str, size_t max);

/**
 * Copies at most n characters from source to dst, stops at null or n
 * @param dst
 * @param src
 * @param n
 * @return the number of characters copied
 */
extern size_t bsdk_strcpn(char* dst, const char* src, size_t n);

/**
 * Copy characters from dst to source until null is found, this function should not
 * be used on untrusted values.
 * @unsafe If a non null terminated string is given to this function it has undefined behaviour
 * @warning Use bsdk_strcpn where possible
 * @param dst
 * @param src
 */
extern void bsdk_strcp(char* dst, const char* src);

#endif
