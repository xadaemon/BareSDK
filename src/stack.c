/**
* BSD 3-Clause License
* Copyright (c) 2021, Matheus Xavier
* All rights reserved.
*/

#include <stack.h>
#include "util.h"

void stack_init(struct stack *ref, uint8_t *buff, size_t buff_len)
{
	ref->backing_buffer = buff;
	ref->stack_size = buff_len;
	ref->top = 0ul;
}

int stack_push(struct stack *ref, uint8_t *buff, size_t buff_len)
{
	/* First we check to see if we are not going over the top of the
	 * stack with this push
	 */
	if (ref->top + buff_len > ref->stack_size)
		return -1;

	kkc_mem_copy((ref->backing_buffer + ref->top), buff, buff_len);
	ref->top += buff_len;
	return 0;
}

int stack_pop(struct stack *ref, uint8_t *buff, size_t buff_len)
{
	/* First we check to see if we are not going under the start of the
	 * stack with this pop */
	if (ref->top - buff_len > ref->stack_size)
		return -1;

	ref->top -= buff_len;
	kkc_mem_copy(buff, (ref->backing_buffer + ref->top), buff_len);
	return 0;
}
