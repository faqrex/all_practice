
int digit_add(digit_t src[],const digit_t num[], int max)
{
	int i;
	int carry;//carry
	
	carry = 0;
	for (i = 0 ; i < max ; i++) {
		src[i] += num[i] + carry;
		if (src[i] >= BASE(10)) {
			carry = 1;
			src[i] -= BASE(10);
		} else {
			carry = 0;
		}
	}
}
