//
// Created by mxavier on 1/14/22.
//

#ifndef BSDK_MATH_H_
#define BSDK_MATH_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define bsdk_min(A, B) ((A) < (B) ? (A):(B))
#define bsdk_max(A, B) ((A) > (B) ? (A):(B))

extern uint64_t bsdk_exp(uint32_t base, uint16_t exp);

#endif//BSDK_MATH_H_
