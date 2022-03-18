/**
 * This file is part of BareSDK and licensed under the:
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
*/

#include "bsdk_fnv.h"
#include "bsdk_hashmap.h"
#include "bsdk_memutils.h"

struct bsdk_hashmap_entry
{
    /* First 20 bytes of the key for a fast comparison on recovery
     */
    char key_frag[HASHMAP_KEY_FRAG_LEN];
    bool used;
    /* The hash stored in this slot
     */
    uint64_t hash;
    void* val;
};

const size_t HASHMAP_ENTRY_SZ = sizeof(struct bsdk_hashmap_entry);

int bsdk_hashmap_init(struct bsdk_hashmap* self, struct bsdk_hashmap_entry* inner_buffer, uint64_t len)
{
	if (inner_buffer == NULL)
		return -1;

	self->len = len;
	self->entries = inner_buffer;
	return 0;
}

int bsdk_hashmap_insert(struct bsdk_hashmap* self, uint8_t* key, size_t key_len, void* value)
{
	struct bsdk_hashmap_entry entry;
	uint64_t hash;
	uint64_t index;

	hash = fnv1a(key, key_len);

	index = hash % self->len;
	if (self->entries[index].used
		&& !bsdk_bytecmp((uint8_t*)self->entries[index].key_frag, key, HASHMAP_KEY_FRAG_LEN)) {
		hash = fnv1(key, key_len);
		index = hash % self->len;
	}

	bsdk_memcopy(&entry.key_frag, key, HASHMAP_KEY_FRAG_LEN);
	entry.hash = hash;
	entry.used = true;
	entry.val = value;

	bsdk_memcopy(self->entries + index, &entry, HASHMAP_ENTRY_SZ);
	return 0;
}

extern void* bsdk_hashmap_get(struct bsdk_hashmap* self, void* key, size_t key_len)
{
	uint64_t hash;
	uint64_t index;

	hash = fnv1a(key, key_len);

	index = hash % self->len;
	if (self->entries[index].used && !bsdk_strcmpn(self->entries[index].key_frag, key, HASHMAP_KEY_FRAG_LEN)) {
		hash = fnv1(key, key_len);
		index = hash % self->len;
	}

	return self->entries[index].val;
}
