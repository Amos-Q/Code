#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void Print(int a , int b)
{
	int avg = a - (a - b) / 2;
	printf("%d\n", avg);
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	Print(a, b);
	system("pause");
	return 0;
}