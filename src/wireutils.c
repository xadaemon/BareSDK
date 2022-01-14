#include <wireutils.h>

bool is_le_rt()
{
	union {
	    uint16_t val;
	    uint8_t bytes[2];
	} test;
	test.val = 138;
	/* Test the endianness of the platform by checking if a crafted value is at 0 or 1
	 */
	return (bool)(test.bytes[0] == 0x8A && test.bytes[1] == 0);
}
