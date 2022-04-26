/**
 * This file is part of BareSDK and licensed under the:
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
*/

#include "bsdk_hashmap.h"
#include "bsdk_hashes.h"
#include "bsdk_memutils.h"

struct bsdk_hashmap_entry {
	uint8_t key[HASHMAP_KEY_LEN];
	void *val;
};

const size_t HASHMAP_ENTRY_SZ = sizeof(struct bsdk_hashmap_entry);

int bsdk_hashmap_init(struct bsdk_hashmap *self, struct bsdk_hashmap_entry *inner_buffer, uint64_t len)
{
	if (inner_buffer == NULL)
		return -1;

	self->len = len;
	self->entries = inner_buffer;
	return 0;
}

int bsdk_hashmap_insert(struct bsdk_hashmap *self, uint8_t *key, void *value)
{
	struct bsdk_hashmap_entry entry;
	uint64_t hash;
	uint64_t index;

	hash = bsdk_fnv1ext(key, HASHMAP_KEY_LEN);

	index = hash % self->len;

	bsdk_memcopy(entry.key, key, HASHMAP_KEY_LEN);
	entry.val = value;

	bsdk_memcopy(self->entries + index, &entry, HASHMAP_ENTRY_SZ);
	return 0;
}

extern void *bsdk_hashmap_get(struct bsdk_hashmap *self, uint8_t *key)
{
	uint64_t hash;
	uint64_t index;

	hash = bsdk_fnv1ext(key, HASHMAP_KEY_LEN);

	index = hash % self->len;

	return self->entries[index].val;
}

void bsdk_hashmap_set(struct bsdk_hashmap *self, void *key, void *value)
{
	struct bsdk_hashmap_entry *entry;
	uint64_t hash;
	uint64_t index;

	hash = bsdk_fnv1ext(key, HASHMAP_KEY_LEN);

	index = hash % self->len;

	entry = self->entries + index;
	entry->val = value;
}
