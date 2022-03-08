/**
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
 */

#include "bsdk_queue.h"
#include "bsdk_memutils.h"

void bsdk_queue_init(struct bsdk_queue* ref, uint8_t* buff, size_t buff_len)
{
	ref->data = buff;
	ref->queue_size = buff_len;
	ref->rw_off = 0;
}

int bsdk_queue_add(struct bsdk_queue* ref, uint8_t* buff, size_t buff_len)
{
	/* First we check to see if we are not going over the rw_off of the
	 * bsdk_stack with this push
	 */
	if (ref->rw_off + buff_len > ref->queue_size)
		return -1;

	bsdk_memcopy((ref->data + ref->rw_off), buff, buff_len);
	return 0;
}

int bsdk_queue_head(struct bsdk_queue* ref, uint8_t* buff, size_t buff_len)
{
	/* first we check if we are not going over the last element in the
	 * bsdk_queue with the head operation
	 */
	if (ref->rw_off + buff_len > ref->queue_size)
		return -1;

	bsdk_memcopy(buff, (ref->data + ref->rw_off), buff_len);
	ref->rw_off += buff_len;
	return 0;
}
