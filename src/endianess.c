#include <endianess.h>

uint16_t uint16_from_be(const uint8_t *buff)
{
	return (((uint16_t)buff[1] << 8) | (uint16_t)buff[0]) | 0x0000;
}
