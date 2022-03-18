/**
 * This file is part of BareSDK and licensed under the:
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
*/

#include "bsdk_crc32.h"

bool tables_init = 0;

uint32_t crc32_table[256];

inline uint32_t reverse(uint32_t x)
{
	x = ((x & 0xAAAAAAAA) >> 1) | ((x & 0x55555555) << 1);
	x = ((x & 0xCCCCCCCC) >> 2) | ((x & 0x33333333) << 2);
	x = ((x & 0xF0F0F0F0) >> 4) | ((x & 0x0F0F0F0F) << 4);
	x = ((x & 0xFF00FF00) >> 8) | ((x & 0x00FF00FF) << 8);
	x = (x >> 16) | (x << 16);

	return x;
}

void gen_table(uint32_t* table, uint32_t polynomial, bool selflect_in, bool selflect_out)
{
	for (uint32_t byte = 0; byte < 256; ++byte) {
		uint32_t crc = (selflect_in ? (reverse(byte) >> 24) : byte);
		for (uint8_t bit = 32; bit > 0; --bit) {
			if (crc & 0x80000000) {
				crc = (crc << 1) ^ polynomial;
			} else {
				crc <<= 1;
			}
		}
		table[byte] = (selflect_out ? reverse(crc) : crc);
	}
}

inline uint32_t crc32_impl_lookup(const uint8_t* data, size_t data_len, const uint32_t* table, int mode, uint32_t orig)
{
	uint32_t crc32 = 0xFFFFFFFF;
	uint32_t lookup_idx = 0;

	for (size_t i = 0; i < data_len; i++) {
		lookup_idx = (crc32 ^ data[i]) & 0xFF;
		crc32 = (crc32 >> 8) ^ table[lookup_idx];
	}

	crc32 ^= 0xFFFFFFFF;
	if (mode == 0)
		return crc32;
	else
		return crc32 ^ orig;
}

uint32_t crc32_calc(const uint8_t* data, size_t data_len)
{
	gen_table(crc32_table, CRC32POLY, true, true);
	uint32_t calc = crc32_impl_lookup(data, data_len, crc32_table, 0, 0);
	return calc;
}

bool crc32_check(const uint8_t* data, size_t data_len, uint32_t orig)
{
	gen_table(crc32_table, CRC32POLY, true, true);
	uint32_t calc = crc32_impl_lookup(data, data_len, crc32_table, 1, orig);
	return calc;
}

uint32_t crc32c_calc(const uint8_t* data, size_t data_len)
{
	gen_table(crc32_table, CRC32CPOLY, true, true);
	uint32_t calc = crc32_impl_lookup(data, data_len, crc32_table, 0, 0);
	return calc;
}

bool crc32c_check(const uint8_t* data, size_t data_len, uint32_t orig)
{
	gen_table(crc32_table, CRC32CPOLY, true, true);
	uint32_t calc = crc32_impl_lookup(data, data_len, crc32_table, 1, orig);
	return calc;
}
