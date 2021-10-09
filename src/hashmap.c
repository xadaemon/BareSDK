/**
* BSD 3-Clause License
* Copyright (c) 2021, Matheus Xavier
* All rights reserved.
*/

#include <fnv.h>
#include <hashmap.h>

void init_map(struct hashmap *ref, uint8_t *buf, size_t len, enum hashmap_alg alg)
{
	ref->data = buf;
	ref->len = len;
	if (alg == fnv1)
		ref->alg_impl = &fnv1_impl;
	else if (alg == fnv1a)
		ref->alg_impl = &fnv1a_impl;
	ref->keys = 0;
}
