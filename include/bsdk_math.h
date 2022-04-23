/**
* This file is part of BareSDK and licensed under the:
* BSD 3-Clause License
* Copyright (c) 2021, Matheus Xavier
* All rights reserved.
*/

#ifndef BSDK_MATH_H_
#define BSDK_MATH_H_

#include <bsdk_common.h>

#define bsdk_min(A, B) ((A) < (B) ? (A):(B))
#define bsdk_max(A, B) ((A) > (B) ? (A):(B))

extern uint64_t bsdk_exp(uint32_t base, uint16_t exp);

#endif//BSDK_MATH_H_
