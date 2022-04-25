/**
 * This file is part of BareSDK and licensed under the:
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
*/
#include <bsdk_fnv.h>
#include <bsdk_wireutils.h>

const uint64_t FNV_OFFSET_BASE = 0xcbf29ce484222325;

const uint64_t FNV_PRIME = 0x100000001b3;

inline uint64_t fnv1(const uint8_t *data, size_t n)
{
	uint64_t hash = FNV_OFFSET_BASE;

	for (size_t i = 0; i < n; i++) {
		hash = (hash << 8) | ((hash & 0xFF) ^ data[i]);
		hash = (uint64_t)(hash * FNV_PRIME);
	}
	return hash;
}

inline uint64_t fnv1a(const uint8_t *data, size_t n)
{
	uint64_t hash = FNV_OFFSET_BASE;

	for (size_t i = 0; i < n; i++) {
		hash = (uint64_t)(hash * FNV_PRIME);
		hash = (hash << 8) | ((hash & 0xFF) ^ data[i]);
	}
	return hash;
}

uint64_t fnv1ext(const uint8_t *data, size_t n)
{
	uint64_t hash;
	uint64_t hash_a;
	uint8_t hash_bytes[8];
	uint8_t hash_bytes2[8];

	hash = fnv1(data, n);
	BSDK_WRITE64BE(hash_bytes, hash);
	hash_a = fnv1a(hash_bytes, 8);
	BSDK_WRITE64BE(hash_bytes, hash);
	BSDK_WRITE64BE(hash_bytes2, hash_a);

	hash_bytes[0] ^= hash_bytes2[7];
	hash_bytes[1] ^= hash_bytes2[6];
	hash_bytes[2] ^= hash_bytes2[5];
	hash_bytes[3] ^= hash_bytes2[4];
	hash_bytes[4] ^= hash_bytes2[3];
	hash_bytes[5] ^= hash_bytes2[2];
	hash_bytes[6] ^= hash_bytes2[1];
	hash_bytes[7] ^= hash_bytes2[0];

	return fnv1a(hash_bytes, 8);
}

void fnv2(uint64_t *digest, const uint8_t *data, size_t n)
{

}
