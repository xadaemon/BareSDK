/**
* BSD 3-Clause License
* Copyright (c) 2021, Matheus Xavier
* All rights reserved.
*/

#include <bsdk_fnv.h>
#include <bsdk_util.h>
#include <hashmap.h>

int bsdk_hashmap_init(struct bsdk_hashmap_container *ref, struct bsdk_hashmap_entry *inner_buffer, uint64_t len)
{
	if (inner_buffer == NULL)
		return -1;

	ref->stored = 0;
	ref->len = len;
	ref->entries = inner_buffer;
	return 0;
}

int bsdk_hashmap_insert(struct bsdk_hashmap_container *ref, uint8_t *key, size_t key_len, void *value)
{
	struct bsdk_hashmap_entry entry;
	uint64_t hash;
	uint64_t index;

	hash = fnv1a(key, key_len);

	index = hash % ref->len;
	if (ref->entries[index].used && !bsdk_bytecmp((uint8_t *)ref->entries[index].key_frag, key, HASHMAP_KEY_FRAG_LEN)) {
		hash = fnv1(key, key_len);
		index = hash % HMP_P_IN_N_BYTES(ref->len);
	}

	bsdk_memcopy(&entry.key_frag, key, HASHMAP_KEY_FRAG_LEN);
	entry.hash = hash;
	entry.used = true;
	entry.val = value;

	bsdk_memcopy(ref->entries + index, &entry, HASHMAP_ENTRY_SZ);
	return 0;
}

extern void *bsdk_hashmap_get(struct bsdk_hashmap_container *ref, void *key, size_t key_len)
{
	uint64_t hash;
	uint64_t index;

	hash = fnv1a(key, key_len);

	index = hash % ref->len;
	if (ref->entries[index].used && !bsdk_strcmp(ref->entries[index].key_frag, key, HASHMAP_KEY_FRAG_LEN)) {
		hash = fnv1(key, key_len);
		index = hash % HMP_P_IN_N_BYTES(ref->len);
	}

	return ref->entries[index].val;
}
