/**
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
 */

#ifndef KKC_ENDIANESS_H
#define KKC_ENDIANESS_H

#if defined(__BYTE_ORDER) && __BYTE_ORDER == __BIG_ENDIAN || \
    defined(__BIG_ENDIAN__) || \
    defined(__ARMEB__) || \
    defined(__THUMBEB__) || \
    defined(__AARCH64EB__) || \
    defined(_MIBSEB) || defined(__MIBSEB) || defined(__MIBSEB__)
#define BE_ARCH
#elif defined(__BYTE_ORDER) && __BYTE_ORDER == __LITTLE_ENDIAN || \
    defined(__LITTLE_ENDIAN__) || \
    defined(__ARMEL__) || \
    defined(__THUMBEL__) || \
    defined(__AARCH64EL__) || \
    defined(_MIPSEL) || defined(__MIPSEL) || defined(__MIPSEL__)
#define LE_ARCH
#else
#error Unable to determine arch
#endif


#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * Takes buffer buff and reads 2 bytes into an uint16
 * @param buff buffer to read from if needed offset first
 * @return machine endian value in big endian ISAs is a no-op
 */
extern uint16_t uint16_from_be(const uint8_t *buff);
/**
 * Takes buffer buff and reads 4 bytes into an uint32
 * @param buff buffer to read from if needed offset first
 * @return machine endian value in big endian ISAs is a no-op
 */
extern uint32_t uint32_from_be(const uint8_t *buff);
/**
 * Takes buffer buff and reads 8 bytes into an uint64
 * @param buff buffer to read from if needed offset first
 * @return machine endian value in big endian ISAs is a no-op
 */
extern uint64_t uint64_from_be(const uint8_t *buff);

/**
 * Takes buffer buff and reads 2 bytes into an uint16
 * @param buff buffer to read from if needed offset first
 * @return machine endian value in little endian ISAs is a no-op
 */
extern uint16_t uint16_from_le(const uint8_t *buff);
/**
 * Takes buffer buff and reads 4 bytes into an uint32
 * @param buff buffer to read from if needed offset first
 * @return machine endian value in little endian ISAs is a no-op
 */
extern uint32_t uint32_from_le(const uint8_t *buff);
/**
 * Takes buffer buff and reads 8 bytes into an uint64
 * @param buff buffer to read from if needed offset first
 * @return machine endian value in little endian ISAs is a no-op
 */
extern uint64_t uint64_from_le(const uint8_t *buff);

extern bool is_le_rt();

#endif // KKC_ENDIANESS_H
