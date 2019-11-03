#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void Print(int* arr)
{
	while (*arr != '\0')
	{
		printf("%d ", *arr);
		arr++;
	}
}
void Hebin(int* arr, int* j, int* o)
{
	while (*j != '\0')
	{
		*arr = *j;
		arr++; 
		j++;
	}
	while (*o != '\0')
	{
		*arr = *o;
		arr++;
		o++;
	}
}
void Swap(int* arr,int i)
{
	int j[1000] = { 0 };
	int o[1000] = { 0 };
	int x = 0;
	int y = 0;
	int a = 0;
	int h[1000] = { 0 };
	while(*arr != '\0')
	{
		if ((*arr & 1) == 1)
		{
			j[x] = *arr;
			x++;
		}
		if ((*arr & 1) == 0)
		{
			o[y]= *arr;
			y++;
		}
		arr++;
	}
	Hebin(arr - i, j, o);
}
int main()
{
	int arr[1000] = { 0 };
	int i = 0;
	int x = 0;
	printf("Input number:");
	scanf("%d", &i);
	for (x; x < i; x++)
	{
		scanf("%d", &arr[x]);
	}
	Swap(arr,i);
	Print(arr);
	system("pause");
	return 0;
}