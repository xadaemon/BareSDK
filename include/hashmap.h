/**
* BSD 3-Clause License
* Copyright (c) 2021, Matheus Xavier
* All rights reserved.
*/
#ifndef KERNELKIT_HASHMAP_H
#define KERNELKIT_HASHMAP_H

#include <stddef.h>
#include <stdint.h>

/** Planned to include sip as an secure alternative
 */
enum hashmap_alg {
	fnv1,
	fnv1a,
};

struct hashmap {
	uint8_t *data;
	size_t len;
	size_t keys;
	uint64_t (*alg_impl)(const uint8_t *, size_t);
};

struct map_entry {
	uint64_t hash;
	void *data;
};

extern void init_map(struct hashmap *ref, uint8_t *buf, size_t len, enum hashmap_alg alg);

#endif
