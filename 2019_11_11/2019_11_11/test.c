#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Compare(char* arr1, char* arr2,int x, int y)
{
	int s = x;
	char tmp = 0;
	while (y--)
	{
		if (strcmp(arr1, arr2) == 0)
			return 1;
		int l = x;
		tmp = *arr1;
		while (--l)
		{
			*arr1 = *(arr1 + 1);
			arr1++;
		}
		*arr1 = tmp;
		arr1 = arr1 - s + 1;
	}
	return 0;
}

int main()
{
	int a = 0;
	int b = 0;
	printf("Input the size of char:");
	scanf("%d", &a);
	char *arr1 = (char*)malloc(sizeof(char) * a);
	printf("Input the size of target char:");
	scanf("%d", &b);
	char *arr2 = (char*)malloc(sizeof(char) * b);
	printf("Input the char:");
	scanf("%s", arr1);
	printf("Input the target char:");
	scanf("%s", arr2);
	int ret = Compare(arr1,arr2,a,b);
	printf("%d", ret);
	system("pause");
	return 0;
}