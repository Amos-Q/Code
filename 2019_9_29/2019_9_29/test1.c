#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void Print(int n)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d * %d = %d   ", i, j, i*j);
		}
		printf("\n");
	}
}

int main()
{
	int n = 0;
	printf("输入打印口诀表大小：");
	scanf("%d", &n);
	if (n > 0)
		Print(n);
	else
		printf("Input error!\n");
	system("pause");
	return 0;
}