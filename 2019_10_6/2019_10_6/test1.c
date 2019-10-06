#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void Print(int i)
{
	if (i >= 10)
	{
		printf("%d\n", (i % 10));
		return Print(i / 10);
	}
	else
		printf("%d\n", i);
}

int main()
{
	int i = 0;
	printf("Input the number:");
	scanf("%d", &i);
	Print(i);
	system("pause");
	return 0;
}