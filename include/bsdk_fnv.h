/**
* BSD 3-Clause License
* Copyright (c) 2021, Matheus Xavier
* All rights reserved.
*/
#ifndef BSDK_FNV_H
#define BSDK_FNV_H

#include <stddef.h>
#include <stdint.h>

extern uint64_t fnv1(const uint8_t *data, size_t n);
extern uint64_t fnv1a(const uint8_t *data, size_t n);

#endif
