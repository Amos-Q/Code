#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n, i, m = 0, k = 0;
	int a[500];

	printf("Please input n:");
	scanf("%d", &n);

	for (i = 0; i < n; i++) //给n个数赋值
	{
		a[i] = i + 1;
	}

	while (m < n - 1) //m代表总共被标记为0的个数
	{
		for (i = 0; i < n; i++)
		{
			if (a[i] != 0)
			{
				k++;
				if (k % 3 == 0) //k是每数到3个非零数标记为0
				{
					a[i] = 0;
					m++;
				}
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		if (a[i] != 0) //最后输出唯一一个非零数
			printf("The last one is:%d\n", a[i]);
	}
	system("pause");
	return 0;
}