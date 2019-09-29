#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void swap(int x, int y)
{
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
	printf("The swap number:%d %d\n", x, y);
}

int main()
{
	int a = 0;
	int b = 0;
	printf("Input two number:");
	scanf("%d %d",&a,&b);
	swap(a, b);
	system("pause");
	return 0;
}