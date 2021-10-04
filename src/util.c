/**
* BSD 3-Clause License
* Copyright (c) 2021, Matheus Xavier
* All rights reserved.
*/
#include "util.h"

void kkc_memcopy(void *dst, void *src, size_t n)
{
	for (size_t i = 0; i < n; ++i) {
		((uint8_t *)dst)[i] = ((uint8_t *)src)[i];
	}
}

void kkc_memcopy_dst_mod(void *dst, void *src, size_t len, size_t n)
{
	size_t i_mod;
	for (size_t i = 0; i < len; ++i) {
		i_mod = i % n;
		((uint8_t *)dst)[i] = ((uint8_t *)src)[i_mod];
	}
}

void kkc_memcopy_src_mod(void *dst, void *src, size_t len, size_t n)
{
	size_t i_mod;
	for (size_t i = 0; i < len; ++i) {
		i_mod = i % n;
		((uint8_t *)dst)[i_mod] = ((uint8_t *)src)[i];
	}
}

size_t min(size_t x, size_t y)
{
	return x < y ? x : y;
}

size_t max(size_t x, size_t y)
{
	return x > y ? x : y;
}
