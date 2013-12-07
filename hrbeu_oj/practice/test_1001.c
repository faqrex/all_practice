//#include "debug.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
/* Hrbeu ACM OJ Practice */
#define DIGITMAX 8
#define MAX 99999999UL
#define BASE(n) (n)
#define RADIX(n) (n)
#define REFNUM(n) (n)
#define TRUE (1)
#define FALSE (0)
#define YES TRUE
#define NO  FALSE
typedef char digit_t;

static inline void _fixref(char* digflag,int* refcnt, int now)
{ 
	int fix;
	if (*digflag && (now != 1) ) fix = -1;
	else if (!*digflag && (now == 1)) fix = 1;
	else fix = 0;

	*refcnt += fix;
	*digflag = (now == 1)? 1 :0;
}

static int digit_fastaddone(digit_t src[],int max, char refflag[], int refcnt)
{
	int i;
	int carry;
	
	
	i = 0;
	carry = 0;
	src[0] += 1;
	do {
		src[i] += carry;
		if (src[i] >= RADIX(10)) {
			carry = 1;
			src[i] -= RADIX(10);
			_fixref(&refflag[i],&refcnt, src[i]);
		} else {
			carry = 0;
			_fixref(&refflag[i],&refcnt, src[i]);
		}
		if (carry == 0) break;
		i++;
	}while(i < max);
	
	return refcnt;
}

static int conv_to_digit(char refflag[],digit_t dignum[], const char* arr, int len)
{
	int i,j;	
	for (i = len - 1,j = 0 ; i >= 0 && j< len ; i--,j++) {
		dignum[i] = arr[j] - '0';
		if (dignum[i] == 1) refflag[i] = YES;
		else refflag[i] = NO;
	}
	for (j = len ; j < DIGITMAX+1 ; j++ ){
		 dignum[j] = 0;
		 refflag[j] = NO;
	}
	return 0;	
}

int main()
{
	char arg_1[DIGITMAX+1];
	char arg_2[DIGITMAX+1];

	digit_t dignum[DIGITMAX+1];
	digit_t refflag[DIGITMAX+1];

	int sum, cnt;
	int a,b,tmp;
	int i;
	char *pa,*pb;

	while (scanf("%s %s",arg_1,arg_2) != EOF) {
		pa = arg_1;
		pb = arg_2;
		sscanf(arg_1,"%d",&a);
		sscanf(arg_2,"%d",&b);
		if (*arg_1 == '0' && *arg_2 == '0') return 0;
		
		if (a > b) {
			tmp = a;
			a = b;
			b = tmp;
			pa = arg_2;
			pb = arg_1;	
		}
		int a_len = strlen(pa);
		//int b_len = strlen(pb);
			conv_to_digit(refflag,dignum,pa,a_len);
			sum = 0;
			cnt = 0;
			for (i = 0 ; i < DIGITMAX ; i++) cnt += refflag[i];
			sum = cnt;
			for (i = a; i < b ; i++) {
				cnt = digit_fastaddone(dignum, DIGITMAX, refflag, cnt);
				sum += cnt;
			}
		printf("%d\n",sum);
	}
	return 0;
} 
