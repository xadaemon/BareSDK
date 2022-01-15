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

#define HASHMAP_SIZE_FOR(N) (N) * sizeof(struct bsdk_hashmap_entry)
#define HMP_P_IN_N_BYTES(N) (N) / sizeof(struct bsdk_hashmap_entry)
#define HASHMAP_ENTRY_SZ sizeof(struct bsdk_hashmap_entry)
#define HASHMAP_KEY_FRAG_LEN 255

struct bsdk_hashmap_entry {
	/* First 20 bytes of the key for a fast comparison on recovery
	 */
	char key_frag[HASHMAP_KEY_FRAG_LEN];
	bool used;
	/* The hash stored in this slot
	 */
	uint64_t hash;
	void *val;
};

struct bsdk_hashmap_container {
	uint64_t len;
	uint64_t stored;
	struct bsdk_hashmap_entry *entries;
};

extern int bsdk_hashmap_init(struct bsdk_hashmap_container *ref, struct bsdk_hashmap_entry *inner_buffer, uint64_t len);
extern int bsdk_hashmap_insert(struct bsdk_hashmap_container *ref, uint8_t *key, size_t key_len, void *value);
extern void *bsdk_hashmap_get(struct bsdk_hashmap_container *ref, void *key, size_t key_len);

#endif//_HASHMAP_H_
