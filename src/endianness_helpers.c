#include <endianness_helpers.h>
#ifdef LE_ARCH
uint16_t uint16_from_be(const uint8_t *buff)
{
	union {
	    uint16_t val;
	    uint8_t bytes[2];
	} assist;
	assist.bytes[0] = buff[1];
	assist.bytes[1] = buff[0];
	return assist.val;
}

uint32_t uint32_from_be(const uint8_t *buff)
{
	union {
	    uint16_t val;
	    uint8_t bytes[4];
	} assist;
	assist.bytes[0] = buff[3];
	assist.bytes[1] = buff[2];
	assist.bytes[2] = buff[1];
	assist.bytes[3] = buff[0];
	return assist.val;
}

uint64_t uint64_from_be(const uint8_t *buff)
{
	union {
	    uint16_t val;
	    uint8_t bytes[8];
	} assist;
	assist.bytes[0] = buff[7];
	assist.bytes[1] = buff[6];
	assist.bytes[2] = buff[5];
	assist.bytes[3] = buff[4];
	assist.bytes[4] = buff[3];
	assist.bytes[5] = buff[2];
	assist.bytes[6] = buff[1];
	assist.bytes[7] = buff[0];
	return assist.val;
}

uint16_t uint16_from_le(const uint8_t *buff)
{
	union {
	    uint16_t val;
	    uint8_t bytes[2];
	} assist;
	assist.bytes[0] = buff[0];
	assist.bytes[1] = buff[1];
	return assist.val;
}

uint32_t uint32_from_le(const uint8_t *buff)
{
	union {
	    uint16_t val;
	    uint8_t bytes[4];
	} assist;
	assist.bytes[0] = buff[0];
	assist.bytes[1] = buff[1];
	assist.bytes[2] = buff[2];
	assist.bytes[3] = buff[3];
	return assist.val;
}

uint64_t uint64_from_le(const uint8_t *buff)
{
	union {
	    uint16_t val;
	    uint8_t bytes[8];
	} assist;
	assist.bytes[0] = buff[0];
	assist.bytes[1] = buff[1];
	assist.bytes[2] = buff[2];
	assist.bytes[3] = buff[3];
	assist.bytes[4] = buff[4];
	assist.bytes[5] = buff[5];
	assist.bytes[6] = buff[6];
	assist.bytes[7] = buff[7];
	return assist.val;
}
#elifdef BE_ARCH
uint16_t uint16_from_le(const uint8_t *buff)
{
	union {
	    uint16_t val;
	    uint8_t bytes[2];
	} assist;
	assist.bytes[0] = buff[1];
	assist.bytes[1] = buff[0];
	return assist.val;
}

uint32_t uint32_from_le(const uint8_t *buff)
{
	union {
	    uint16_t val;
	    uint8_t bytes[4];
	} assist;
	assist.bytes[0] = buff[3];
	assist.bytes[1] = buff[2];
	assist.bytes[2] = buff[1];
	assist.bytes[3] = buff[0];
	return assist.val;
}

uint64_t uint64_from_le(const uint8_t *buff)
{
	union {
	    uint16_t val;
	    uint8_t bytes[8];
	} assist;
	assist.bytes[0] = buff[7];
	assist.bytes[1] = buff[6];
	assist.bytes[2] = buff[5];
	assist.bytes[3] = buff[4];
	assist.bytes[4] = buff[3];
	assist.bytes[5] = buff[2];
	assist.bytes[6] = buff[1];
	assist.bytes[7] = buff[0];
	return assist.val;
}

uint16_t uint16_from_be(const uint8_t *buff)
{
	union {
	    uint16_t val;
	    uint8_t bytes[2];
	} assist;
	assist.bytes[0] = buff[0];
	assist.bytes[1] = buff[1];
	return assist.val;
}

uint32_t uint32_from_be(const uint8_t *buff)
{
	union {
	    uint16_t val;
	    uint8_t bytes[4];
	} assist;
	assist.bytes[0] = buff[0];
	assist.bytes[1] = buff[1];
	assist.bytes[2] = buff[2];
	assist.bytes[3] = buff[3];
	return assist.val;
}

uint64_t uint64_from_be(const uint8_t *buff)
{
	union {
	    uint16_t val;
	    uint8_t bytes[8];
	} assist;
	assist.bytes[0] = buff[0];
	assist.bytes[1] = buff[1];
	assist.bytes[2] = buff[2];
	assist.bytes[3] = buff[3];
	assist.bytes[4] = buff[4];
	assist.bytes[5] = buff[5];
	assist.bytes[6] = buff[6];
	assist.bytes[7] = buff[7];
	return assist.val;
}

#endif

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
