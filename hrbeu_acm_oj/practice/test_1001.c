#define DEBUG 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
/* Hrbeu ACM OJ Practice */
#define DIGITMAX 8
#define MAX 99999999UL
#define BASE 10
#define YES 1
#define NO  0
typedef char digit_t;

static int digit_add(digit_t* src,const digit_t* num, int sz)
{
	int i;
	int carry;	
	
	carry = 0;
	for (i = 0 ; i < sz ; i++) {
		src[i] += num[i] + carry;
		if (src[i] >= BASE) {
			carry = 1;
			src[i] -= BASE;
		} else {
			carry = 0;
		}
	}

	src[i] += carry;	
	return carry;
}


static int conv_str_digits(digit_t* state,digit_t* digits, const char* arr, int sz)
{
	int i,j;	
	for (i = sz - 1,j = 0 ; i >= 0 && j< sz ; i--,j++) {
		digits[i] = arr[j] - '0';
		if (digits[i] == 1) state[i] = YES;
		else state[i] = NO;
	}
	for (j = sz ; j < DIGITMAX+1 ; j++ ){
		 digits[j] = 0;
		 state[j] = NO;
	}
	return 0;	
}

static int count_digit(digit_t* digits, int sz, int nu)
{
return 0;
}
int main()
{
	char str_1[DIGITMAX+1];
	char str_2[DIGITMAX+1];

	digit_t digits[DIGITMAX+1];
	digit_t state[DIGITMAX+1];
	const digit_t one[DIGITMAX] = {1,0};
	int sum;
	int a;
	int b;
	int tmp;
	int i;
	char* pa;
	char* pb;
	char* ptmp;
	while (scanf("%s %s",str_1,str_2) != EOF) {
		a = atoi(str_1);
		pa = str_1;
		b = atoi(str_2);
		pb = str_2;
		if (a==0 && b == 0) return 0;
		if (a > b) {
			tmp = a;
			a = b;
			b = tmp;
			pa = str_2;
			pb = str_1;
		}
		int a_len = strlen(pa);
		int b_len = strlen(pb);
			conv_str_digits(state,digits,pa,b_len);
			for (i = a,sum = 0; i <= b ; i++,digit_add(digits,one,b_len )) {
				sum += count_digit(digits, DIGITMAX, 1);
		printf("%d\n",sum);
	}
	return 0;
} 
