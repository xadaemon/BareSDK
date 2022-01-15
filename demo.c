#include <bsdk_codes.h>
#include <bsdk_crc32.h>
#include <bsdk_ringbuffer.h>
#include <bsdk_stack.h>
#include <bsdk_util.h>
#include <bsdk_math.h>
#include <hashmap.h>
#include <malloc.h>
#include <stdio.h>

union {
	uint16_t integer;
	uint8_t bytes[2];
} ibytes;

int main(void)
{
	struct bsdk_stack demo_stack;
	struct bsdk_ringbuffer demo_ring;
	struct bsdk_hashmap_container hashmap;
	struct bsdk_hashmap_entry *hm_buff = malloc(HASHMAP_SIZE_FOR(10));
	uint8_t demo_stack_buff[128];
	uint8_t demo_ring_buff[64];
	uint8_t ret[2];
	const char *str = "Hello World!";
	size_t len = bsdk_strlen(str, 100);

	printf("Starting demo\n\n");
	stack_init(&demo_stack, demo_stack_buff, 128);
	ringbuffer_init(&demo_ring, demo_ring_buff, 32);

	for (uint32_t i = 0; i < 64; ++i) {
		ibytes.integer = i;
		stack_push(&demo_stack, ibytes.bytes, 2);
		bsdk_ringbuffer_write(&demo_ring, ibytes.bytes, 2);
		printf("writing %d\n", i);
	}

	for (uint32_t i = 0; i < 64; ++i) {
		if (stack_pop(&demo_stack, ret, 2) == -1) {
			return bsdk_last_error;
		}
		printf("pop %d\n", (uint16_t)ret[0]);

		bsdk_ringbuffer_read(&demo_ring, ret, 2);
		printf("read %d\n", (uint16_t)ret[0]);
	}

	printf("%s, %X\n", str, crc32_calc((uint8_t *)str, len));
	printf("%s, %X\n", str, crc32c_calc((uint8_t *)str, len));

	bsdk_hashmap_init(&hashmap, hm_buff, 10);
	bsdk_hashmap_insert(&hashmap, (uint8_t *)str, len, (void *)"test");
	char *str2 = (char *)bsdk_hashmap_get(&hashmap, (uint8_t *)str, len);
	printf("%s \n", str2);

	printf("%lu \n", bsdk_exp(2, 32));
	printf("%lu \n", bsdk_exp(2, 33));

	return 0;
}
