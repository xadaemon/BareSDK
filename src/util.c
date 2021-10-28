/**
* BSD 3-Clause License
* Copyright (c) 2021, Matheus Xavier
* All rights reserved.
*/
#include <util.h>

inline void kkc_memcopy(void *dst, void *src, size_t n)
{
	for (size_t i = 0; i < n; ++i) {
		((uint8_t *)dst)[i] = ((uint8_t *)src)[i];
	}
}

inline void kkc_memcopy_dst_mod(void *dst, void *src, size_t n, size_t mod)
{
	size_t i_mod;
	for (size_t i = 0; i < n; ++i) {
		i_mod = i % mod;
		((uint8_t *)dst)[i] = ((uint8_t *)src)[i_mod];
	}
}

inline void kkc_memcopy_src_mod(void *dst, void *src, size_t n, size_t mod)
{
	size_t i_mod;
	for (size_t i = 0; i < n; ++i) {
		i_mod = i % mod;
		((uint8_t *)dst)[i_mod] = ((uint8_t *)src)[i];
	}
}

bool kkc_ct_strcmp(const char *a, const char *b, size_t n)
{
	volatile uint8_t res = 0;
	for (size_t i = 0; i < n; i++) {
		res = a[i] ^ b[i];
	}
	return !res;
}

bool kkc_strcmp(const char *a, const char *b, size_t n)
{
	for (size_t i = 0; i < n; i++) {
		if ((a[i] ^ b[i]) != 0)
			return 0;
	}
	return 1;
}

size_t strlen(const char *str, size_t max)
{
	size_t i;
	for (i = 0; i < max; i++) {
		if (str[i] == 0)
			break;
		else
			continue;
	}
	return i;
}

size_t min(size_t x, size_t y)
{
	return x < y ? x : y;
}

size_t max(size_t x, size_t y)
{
	return x > y ? x : y;
}
