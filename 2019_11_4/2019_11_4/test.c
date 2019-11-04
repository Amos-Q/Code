#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

int Search(int arr[ROW][COL], int val)
{
	int i = 0;
	int j = COL - 1;
	int tmp = arr[i][j];
	while (1)
	{
		if (tmp == val)
		{
			return 1;
		}
		else if (tmp < val && j >= 0)
		{
			tmp = arr[++i][j];
		}
		else if (tmp > val &&j >= 0)
		{
			tmp = arr[i][--j];
		}
		else
		{
			return 0;
		}
	}

}

int main()
{
	int a[ROW][COL] = { 0 };
	int i = 0;
	int j = 0;
	int num = 0;
	printf("Input:\n");
	for (i = 0; i < 3; i++) 
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter find number:");
	scanf("%d", &num);
	if (Search(a, num))
	{
		printf("%d在该数组中\n", num);
	}
	else
	{
		printf("%d不在该数组中\n", num);
	}
	system("pause");
	return 0;
}
