/**
 * This file is part of BareSDK and licensed under the:
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
*/
#ifndef BSDK_CRC32_H
#define BSDK_CRC32_H

#include <bsdk_common.h>

#define CRC32POLY 0x04C11DB7u
#define CRC32CPOLY 0x1EDC6F41u

uint32_t crc32_calc(const uint8_t* data, size_t data_len);
uint32_t crc32c_calc(const uint8_t* data, size_t data_len);
bool crc32_check(const uint8_t* data, size_t data_len, uint32_t orig);
bool crc32c_check(const uint8_t* data, size_t data_len, uint32_t orig);

#endif
