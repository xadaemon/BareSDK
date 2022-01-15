/**
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
 */

#ifndef KKC_QEUE_H_
#define KKC_QEUE_H_

#include <stddef.h>
#include <stdint.h>

struct bsdk_queue {
    uint8_t *data;
    /**
     * The rw_off of the bsdk_queue as an offset that satisfies offset < stack_size
     */
    size_t rw_off;
    /**
     * The bsdk_stack size in bytes
     */
    size_t queue_size;
};

/**
 * Initializes a bsdk_stack using `buff` as a backing buffer
 * @warning Care must be taken to not use after freeing of the `buff`
 * buffer (not applicable to bsdk_stack memory)
 * @param ref Pointer to a uninitialized bsdk_stack struct that is to be initialized
 * @param buff Backing buffer to use with this bsdk_stack
 * @param buff_len How long is the backing buffer
 */
extern void bsdk_queue_init(struct bsdk_queue *ref, uint8_t *buff, size_t buff_len);

/**
 * Pushes a value on to the rw_off of the `ref` bsdk_stack.
 * @param ref The bsdk_stack to push the value into
 * @param buff A buffer holding the value to push onto the bsdk_stack
 * @param buff_len How many bytes to push from buff into the bsdk_stack
 * @return -1 if the push would go over the bsdk_stack's rw_off 0 otherwise
 */
extern int bsdk_queue_add(struct bsdk_queue *ref, uint8_t *buff, size_t buff_len);

/**
 * Removes a value off the rw_off of the bsdk_stack (it will remain in memory however).
 * @param ref The bsdk_stack to pop the value from
 * @param buff A buffer to put the popped value into
 * @param buff_len How many bytes to pop from the bsdk_stack into buff
 * @return -1 if the pop would go under the bsdk_stack start 0 otherwise
 */
extern int bsdk_queue_head(struct bsdk_queue *ref, uint8_t *buff, size_t buff_len);
#endif //KKC_QEUE_H_
