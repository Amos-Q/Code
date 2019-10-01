#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void fr_num(int i)
{
	int x = 1;
	int y = 1;
	int c = 0;
	if (i <= 2)
		printf("%d\n", 1);
	else if (i > 2)
	{
		for (i -= 2; i > 0; i--)
		{
			c = x + y;
			x = y;
			y = c;
		}
		printf("%d\n", c);
	}
}

int main()
{
	int i = 0;
	printf("Input:");
	scanf("%d", &i);
	fr_num(i);
	system("pause");
	return 0;
}