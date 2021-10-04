#include <stdio.h>
#include <ringbuffer.h>
#include <stack.h>

union {
	uint16_t integer;
	uint8_t bytes[2];
} ibytes;

int main(void)
{
	struct stack demo_stack;
	struct ringbuffer demo_ring;
	uint8_t demo_stack_buff[128];
	uint8_t demo_ring_buff[64];
	uint8_t ret[2];
	printf("Starting demo\n\n");
	stack_init(&demo_stack, demo_stack_buff, 128);
	ringbuffer_init(&demo_ring, demo_ring_buff, 32);
	for (uint32_t i = 0; i < 64; ++i) {
		ibytes.integer = i;
		stack_push(&demo_stack, ibytes.bytes, 2);
		ringbuffer_write(&demo_ring, ibytes.bytes, 2);
		printf("writing %d\n", i);
	}
	for (uint32_t i = 0; i < 64; ++i) {
		if (stack_pop(&demo_stack, ret, 2) == -1) {
			return -1;
		}
		printf("pop %d\n", (uint16_t)ret[0]);

		ringbuffer_read(&demo_ring, ret, 2);
		printf("read %d\n", (uint16_t)ret[0]);
	}
	return 0;
}
