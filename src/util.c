/**
* BSD 3-Clause License
* Copyright (c) 2021, Matheus Xavier
* All rights reserved.
*/
#include "util.h"

void kkc_mem_copy(void *dst, void *src, size_t len)
{
	for (size_t i = 0; i < len; ++i) {
		((uint8_t *)dst)[i] = ((uint8_t *)src)[i];
	}
}
void kkc_mem_copy_mod(void *dst, void *src, size_t len, size_t mod)
{
	size_t i_mod;
	for (size_t i = 0; i < len; ++i) {
		i_mod = i % mod;
		((uint8_t *)dst)[i] = ((uint8_t *)src)[i_mod];
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
