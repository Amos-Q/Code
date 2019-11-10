#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Print(char* arr)
{
	while (*arr != '\0')
	{
		printf("%c", *arr);
		arr++;
	}
}
void Swap(char* arr,int i,int len)
{
	int s = len;
	char tmp = 0;
	while (i--)
	{
		int l = len;
		tmp = *arr;
		while (--l)
		{
			*arr = *(arr+1);
			arr++;
		}
		*arr = tmp;
		arr = arr - s + 1;
	}
}

int main()
{
	int n = 0;
	printf("Input the size");
	scanf("%d",&n);
	char *arr = (char *)malloc(sizeof(char)*n);
	int i = 0;
	printf("Input the char:");
	scanf("%s", arr);
	printf("Input the swap number:");
	scanf("%d", &i);
	Swap(arr,i,n);
	Print(arr);
	system("pause");
	return 0;
}