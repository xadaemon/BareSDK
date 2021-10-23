#include <hashtable.h>
#include <kkc_codes.h>
#include <ringbuffer.h>
#include <stack.h>
#include <stdio.h>

union {
	uint16_t integer;
	uint8_t bytes[2];
} ibytes;

int main(void)
{
	struct stack demo_stack;
	struct ringbuffer demo_ring;
	struct hashtable demo_htbl;
	uint8_t demo_stack_buff[128];
	uint8_t demo_ring_buff[64];
	uint8_t demo_htbl_buff[HTBL_ENTRY_SIZE * 4];
	uint8_t ret[2];
	uint8_t *retd = NULL;

	char *keys[4] = {"test1", "test2", "test3", "test4"};
	char *vals[4] = {"val1", "val2", "val3", "val4"};

	printf("Starting demo\n\n");
	stack_init(&demo_stack, demo_stack_buff, 128);
	ringbuffer_init(&demo_ring, demo_ring_buff, 32);
	htbl_init(&demo_htbl, demo_htbl_buff, HTBL_ENTRY_SIZE * 8);

	for (size_t i = 0; i < 4; ++i) {
		htbl_set(&demo_htbl, keys[i], 6, &vals[i]);
	}

	for (uint32_t i = 0; i < 64; ++i) {
		ibytes.integer = i;
		stack_push(&demo_stack, ibytes.bytes, 2);
		ringbuffer_write(&demo_ring, ibytes.bytes, 2);
		printf("writing %d\n", i);
	}

	for (uint32_t i = 0; i < 64; ++i) {
		if (stack_pop(&demo_stack, ret, 2) == -1) {
			return last_error;
		}
		printf("pop %d\n", (uint16_t)ret[0]);

		ringbuffer_read(&demo_ring, ret, 2);
		printf("read %d\n", (uint16_t)ret[0]);
	}

	for (size_t i = 0; i < 4; ++i) {
		retd = htbl_get(&demo_htbl, keys[i], 5);
		printf("%s\n", &retd);
	}

	return 0;
}
