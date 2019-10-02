#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int fr_num(int i)
{
	if (i <= 2)
		return 1;
	else if (i > 2)
		return fr_num(i - 1) + fr_num(i - 2);
}

int main()
{
	int i = 0;
	int p = 0;
	printf("Input number:");
	scanf("%d", &i);
	p = fr_num(i);
	printf("The number is:%d\n", p);
	system("pause");
	return 0;
}