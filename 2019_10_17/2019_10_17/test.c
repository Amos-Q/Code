#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

void Print(unsigned int value)
{
	while (value > 0)
	{
		if ((value & 1) == 1)
			printf("%d ", 1);
		if ((value & 1) == 0)
			printf("%d ", 0);
		value >>= 2;
	}
	printf("\n");
}

int main()
{
	int i = 0;
	printf("Input number:");
	scanf("%d", &i);
	printf("奇数序列:");
	Print(i);
	i >>= 1;
	printf("偶数序列:");
	Print(i);
	system("pause");
	return 0;
}