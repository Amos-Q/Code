#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m = 0;
	int p = m / 1;
	int e = m;
	printf("Input the money:");
	scanf("%d", &m);
	while (e > 1)
	{
		p += e / 2;
		e = e / 2 + e % 2;
	}
	printf("%d\n", p);
	system("pause");
	return 0;
}