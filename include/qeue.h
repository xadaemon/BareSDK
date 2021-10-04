/**
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
 */

#ifndef KKC_QEUE_H_
#define KKC_QEUE_H_

#include <stddef.h>
#include <stdint.h>

struct queue {
    uint8_t *data;
    /**
     * The rw_off of the queue as an offset that satisfies offset < stack_size
     */
    size_t rw_off;
    /**
     * The stack size in bytes
     */
    size_t queue_size;
};

/**
 * Initializes a stack using `buff` as a backing buffer
 * @warning Care must be taken to not use after freeing of the `buff`
 * buffer (not applicable to stack memory)
 * @param ref Pointer to a uninitialized stack struct that is to be initialized
 * @param buff Backing buffer to use with this stack
 * @param buff_len How long is the backing buffer
 */
extern void queue_init(struct queue *ref, uint8_t *buff, size_t buff_len);

/**
 * Pushes a value on to the rw_off of the `ref` stack.
 * @param ref The stack to push the value into
 * @param buff A buffer holding the value to push onto the stack
 * @param buff_len How many bytes to push from buff into the stack
 * @return -1 if the push would go over the stack's rw_off 0 otherwise
 */
extern int queue_add(struct queue *ref, uint8_t *buff, size_t buff_len);

/**
 * Removes a value off the rw_off of the stack (it will remain in memory however).
 * @param ref The stack to pop the value from
 * @param buff A buffer to put the popped value into
 * @param buff_len How many bytes to pop from the stack into buff
 * @return -1 if the pop would go under the stack start 0 otherwise
 */
extern int queue_head(struct queue *ref, uint8_t *buff, size_t buff_len);
#endif //KKC_QEUE_H_
