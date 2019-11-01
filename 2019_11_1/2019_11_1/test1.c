#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int reverse_bit(unsigned int value,int sum)
{
	int a = 0;
	int ret = 0;
	for (a = 0; a < 32; a++) 
	{
		ret = ((value & 1) * pow(2,31 - a));
		value >>= 1;
		sum += ret;
	}
	return sum;
}
int main()
{
	int i = 0;
	int sum = 0;
	scanf("%d", &i);
	sum = reverse_bit(i , sum);
	printf("%u\n", sum);
	system("pause");
	return 0;
}