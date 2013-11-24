#include <stdint.h>
#define BASE 10
typedef uint8_t digit_t;

static int digit_add(uint8_t* dest,const uint8_t* src, int sz)
{
	int i;
	int carry;	
	
	carry = 0;
	for (i = 0 ; i < sz ; i++) {
		dest[i] += src[i] + carry;
		if (dest[i] >= BASE) {
			carry = 1;
			dest[i] -= BASE;
		} else {
			carry = 0;
		}
	}

	dest[i] += carry;
	return carry;
}
