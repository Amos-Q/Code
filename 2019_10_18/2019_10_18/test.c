#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int Js(unsigned int a, unsigned int b)
{
	int count = 0;
	if (a >= b)
		while (a > 0)
		{
			if ((a & 1) != (b & 1))
			{
				count++;
			}
			a >>= 1;
			b >>= 1;
		}
	else if (b > a)
		while (b > 0)
		{
			if ((a & 1) != (b & 1))
			{
				count++;
			}
			a >>= 1;
			b >>= 1;
		}
	return count;
}

int main()
{
	int x = 0;
	int y = 0;
	int sum = 0;
	printf("Input two number:");
	scanf("%d%d", &x, &y);
	sum = Js(x, y);
	printf("不同位数:%d\n", sum);
	system("pause");
	return 0;
}