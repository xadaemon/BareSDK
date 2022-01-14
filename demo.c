#include <bsdk_codes.h>
#include <crc32.h>
#include <hashmap.h>
#include <malloc.h>
#include <ringbuffer.h>
#include <stack.h>
#include <stdio.h>
#include <util.h>

union {
	uint16_t integer;
	uint8_t bytes[2];
} ibytes;

int main(void)
{
	struct stack demo_stack;
	struct ringbuffer demo_ring;
	struct hashmap_container hashmap;
	struct hashmap_entry *hm_buff = malloc(HASHMAP_SIZE_FOR(10));
	uint8_t demo_stack_buff[128];
	uint8_t demo_ring_buff[64];
	uint8_t ret[2];
	const char *str = "Hello World!";
	size_t len = strlen(str, 100);

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
			return last_error;
		}
		printf("pop %d\n", (uint16_t)ret[0]);

		ringbuffer_read(&demo_ring, ret, 2);
		printf("read %d\n", (uint16_t)ret[0]);
	}

	printf("%s, %X\n", str, crc32_calc((uint8_t *)str, len));
	printf("%s, %X\n", str, crc32c_calc((uint8_t *)str, len));

	hashmap_init(&hashmap, hm_buff, 10);
	hashmap_insert(&hashmap, (uint8_t *)str, len, (void *)str);
	char *str2 = (char *)hashmap_get(&hashmap, (uint8_t *)str, len);
	printf("%s \n", str2);

	return 0;
}
