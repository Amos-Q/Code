#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void Compare(int* arr, int n)
{
	int i = 0;
	int f = *arr;
	int j[100] = { 0 };
	int o[100] = { 0 };
	int a = 0;
	int b = 0;
	for (i = 1; i < n; i++)
	{
		f ^= *(arr + i);
	}
	while ((f & 1) != 1)
	{
		f >>= 1;
	}
	for (i = 0; i < n; i++)
	{
		if ((*(arr + i) & f) == 1)
		{
			j[a] = *(arr + i);
			a++;
		}
		else
		{
			o[b] = *(arr + i);
			b++;
		}
	}
	int c = 1;
	a -= 1;
	b -= 1;
	while ((a - c) >= 0)
	{
		j[a] ^= j[a - c];
		c++;
	}
	printf("%d ", j[a]);
	c = 1;
	while ((b - c) >= 0)
	{
		o[b] ^= o[b - c];
		c++;
	}
	printf("%d ", o[b]);
}

int main()
{
	int n = 0;
	int q = 0;
	printf("Input the size of int:");
	scanf("%d", &n);
	printf("Input the number:");
	int *arr = (int *)malloc(sizeof(int) * n);
	for (q = 0; q < n; q++)
	{
		scanf("%d", arr + q);
	}
	Compare(arr,n);
	system("pause");
	return 0;
}