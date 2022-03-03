//
// Created by mxavier on 1/14/22.
//

#include <bsdk_math.h>

uint64_t bsdk_exp(uint32_t base, uint16_t exp)
{
	uint64_t r = (uint64_t)base;

	if (exp % 2 == 0 && exp >= 1)
		/** Powers of two make the job easy
		 */
		return r << (exp - 1);

	/** If we can't take the shifting shortcut we do multiplications
	 */
	for (uint64_t i = 1; i < exp; ++i) {
		r *= base;
	}

	return r;
}
