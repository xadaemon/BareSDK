/**
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
 */
#ifndef KERNELKIT_UTIL
#define KERNELKIT_UTIL
#include <stddef.h>
#include <stdint.h>

typedef signed long ssize_t;

size_t min(size_t x, size_t y)
{
	return x < y ? x : y;
}

#endif
