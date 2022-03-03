/**
 * This file is part of BareSDK and licensed under the:
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
*/
#include <bsdk_fnv.h>

const uint64_t FNV_OFFSET_BASE = 0xcbf29ce484222325;

const uint64_t FNV_PRIME = 0x100000001b3;

inline uint64_t fnv1(const uint8_t* data, size_t n)
{
	uint64_t hash = FNV_OFFSET_BASE;

	for (size_t i = 0; i < n; i++) {
		hash = (hash << 8) | ((hash & 0xFF) ^ data[i]);
		hash = (uint64_t)(hash * FNV_PRIME);
	}
	return hash;
}

inline uint64_t fnv1a(const uint8_t* data, size_t n)
{
	uint64_t hash = FNV_OFFSET_BASE;

	for (size_t i = 0; i < n; i++) {
		hash = (uint64_t)(hash * FNV_PRIME);
		hash = (hash << 8) | ((hash & 0xFF) ^ data[i]);
	}
	return hash;
}
