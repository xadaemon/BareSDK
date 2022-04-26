/**
* This file is part of BareSDK and licensed under the:
* BSD 3-Clause License
* Copyright (c) 2021, Matheus Xavier
* All rights reserved.
*/

#ifndef BSDK_HASHMAP_H_
#define BSDK_HASHMAP_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * Set the size of keys, impacts how much memory each entry uses
 */
#define HASHMAP_KEY_LEN 64

extern const size_t HASHMAP_ENTRY_SZ;
#define HASHMAP_SIZE_FOR(N) ((N)*HASHMAP_ENTRY_SZ)

struct bsdk_hashmap_entry;

struct bsdk_hashmap {
	uint64_t len;
	struct bsdk_hashmap_entry *entries;
};

extern int bsdk_hashmap_init(struct bsdk_hashmap *self, struct bsdk_hashmap_entry *inner_buffer, uint64_t len);
extern int bsdk_hashmap_insert(struct bsdk_hashmap *self, uint8_t *key, void *value);
extern void *bsdk_hashmap_get(struct bsdk_hashmap *self, uint8_t *key);
extern void bsdk_hashmap_set(struct bsdk_hashmap *self, void *key, void *value);

#endif//BSDK_HASHMAP_H_
