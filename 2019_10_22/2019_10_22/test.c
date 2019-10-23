#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0;
	int j = 0;
	int arr[4][4] = { 1 };
	for (i = 1; i < 4; i++)
	{
		for (j = 1; j <= i; j++)
		{
			arr[i][0] = 1;
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
