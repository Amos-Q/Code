#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int count_one_bits(unsigned int value)
{
	int count = 0;
	while (value > 0)
	{
		if ((value & 1) == 1)
		{
			count++;
			value >>= 1;
		}
	}
	return count;
	// 返回 1的位数 
}

int main()
{
	int i = 0;
	int sum = 0;
	printf("Input number:\n");
	scanf("%d", &i);
	sum = count_one_bits(i);
	printf("1的个数:%d\n", sum);
	system("pause");
	return 0;
}