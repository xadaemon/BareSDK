/**
* BSD 3-Clause License
* Copyright (c) 2021, Matheus Xavier
* All rights reserved.
*/

#ifndef BSDK_HASHMAP_H_
#define BSDK_HASHMAP_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

extern const size_t HASHMAP_ENTRY_SZ;

#define HASHMAP_SIZE_FOR(N) ((N) * HASHMAP_ENTRY_SZ)
#define HASHMAP_KEY_FRAG_LEN 255

struct bsdk_hashmap_entry;

struct bsdk_hashmap {
	uint64_t len;
	struct bsdk_hashmap_entry *entries;
};

extern int bsdk_hashmap_init(struct bsdk_hashmap *ref, struct bsdk_hashmap_entry *inner_buffer, uint64_t len);
extern int bsdk_hashmap_insert(struct bsdk_hashmap *ref, uint8_t *key, size_t key_len, void *value);
extern void *bsdk_hashmap_get(struct bsdk_hashmap *ref, void *key, size_t key_len);

#endif//BSDK_HASHMAP_H_
