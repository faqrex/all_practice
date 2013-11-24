#include <stdio.h>
#include <stdint.h>
#define DIGITMAX 8
#define MAX 99999999UL

inline void swap32(uint32_t* a, uint32_t* b)
{
	uint32_t tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	uint32_t min;
	uint32_t max;
	while (scanf("%lu %lu",&min,&max) != EOF) {
		if(min == 0 && max == 0) return 0;
		if (min > max) swap32(&min, &max);
		
	}
	return 0;	
}
