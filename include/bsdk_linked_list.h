/**
 * @file bsdk_linked_list.h
 * @brief Utilities for encoding/decoding integers to and from bytes in a stream little or big endian
 * @authors Matheus Xavier
 * This file is part of BareSDK and licensed under the:
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
 */

#ifndef BSDK_LINKED_LIST_H
#define BSDK_LINKED_LIST_H

#include <bsdk_common.h>

struct bsdk_sll_node {
	void *value;
	void *next;
};

struct bsdk_dll_node {
	void *previous;
	void *value;
	void *next;
};

extern void bsdk_sll_init(struct bsdk_sll_node *self)

#endif//BSDK_LINKED_LIST_H
