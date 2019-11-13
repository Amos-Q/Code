#define _CRT_SECURE_NO_WARNINGS 1
//3.模拟实现strcpy 
//4.模拟实现strcat
#include <stdio.h>
#include <stdlib.h>

void My_strcpy(char* arr1, char* arr2,int n)
{
	while (*arr2 != '\0')
	{
		*arr1 = *arr2;
		arr1++;
		arr2++;
	}
	arr1 -= n;
	printf("arr1:");
	while (*arr1 != '\0')
	{
		printf("%c", *arr1);
		arr1++;
	}
	printf("\n");
}

void My_strcat(char* arr1, char* arr2,int n)
{
	int i = 0;
	arr1 += n;
	while (*arr2 != '\0')
	{
		*arr1 = *arr2;
		arr1++;
		arr2++;
	}
	*arr1 = '\0';
	arr1 -= 2 * n;
	printf("arr1:");
	while (*arr1 != '\0')
	{
		printf("%c", *arr1);
		arr1++;
	}
}

int main()
{
	int n = 0;
	char *arr1 = (char*)malloc(sizeof(char)*n);
	char *arr2 = (char*)malloc(sizeof(char)*n);
	printf("Input the size of char:");
	scanf("%d", &n);
	printf("Input the arr1:");
	scanf("%s", arr1);
	printf("Input the arr2:");
	scanf("%s", arr2);
	//My_strcpy(arr1, arr2,n);
	My_strcat(arr1, arr2,n);
	system("pause");
	return 0;
}