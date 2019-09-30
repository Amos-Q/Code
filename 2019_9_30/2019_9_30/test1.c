#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void init(int *arr, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("初始化数组\n");
	for (i = 0; i < len; i++)
	{
		printf("%d\t", arr[i]);
	}
}
void empty(int *arr, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		arr[i] = 0;
	}
	printf("清空数组\n");
	for (i = 0; i < len; i++)
	{
		printf("%d", arr[i]);
	}
}
void reverse(int *arr, int len)
{
	int temp = 0, i = 0;
	for (i = 0; i < len / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[len - 1 - i];
		arr[len - 1 - i] = temp;
	}
	printf("逆置数组\n");
	for (i = 0; i < len; i++)
	{
		printf("%d\t", arr[i]);
	}
}

int main()
{
	int arr[] = { 0 };
	int n = 0;
	int m = 0;
	int a = 0;
	int count = 1;
	/*int len = 0;*/
	printf("数组的大小：");
	scanf("%d", &n);
	printf("*******  1、初始化     *******\n");
	printf("*******  2、清空数组   *******\n");
	printf("*******  3、数组逆置   *******\n");
	printf("*******  4、退出程序   *******\n");
	while (count)
	{
		printf("\n请选择:\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:init(arr, n);
			count = 1;
			break;
		case 2:empty(arr, n);
			break;
		case 3:reverse(arr, n);
			break;
		case 4:count = 0;
			break;
		default:
			printf("输入错误，请重新输入：\n");
		}
	}
	system("pause");
	return 0;
}