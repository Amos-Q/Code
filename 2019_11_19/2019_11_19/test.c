#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a[10];
	int* p1 = a;
	char* p2 = (char*)a;

	p1 = p2;

	return 0;
}

void test1(int* arr, int n) // ok  -> 常用
{
	printf("%d\n", sizeof(arr));
}

void test2(int arr[10], int n) // ok  指针  C语言传参，不存在传数组，都会退化成指针
{
	printf("%d\n", sizeof(arr));
}

void test3(int arr[], int n) // ok  指针  C语言传参，不存在传数组，都会退化成指针
{
	printf("%d\n", sizeof(arr));
}

int main()
{
	int arr[10] = { 0 };
	test1(arr, 10); // int*
	test2(arr, 10);

	//printf("%d\n", sizeof(arr));

	return 0;
}


void test1(int** arr, int n) // ok  -> 常用
{
	printf("%d\n", sizeof(arr));
}

void test2(int* arr[10], int n) // ok  指针  C语言传参，不存在传数组，都会退化成指针
{
	printf("%d\n", sizeof(arr));
}

void test3(int* arr[], int n) // ok  指针  C语言传参，不存在传数组，都会退化成指针
{
	printf("%d\n", sizeof(arr));
}

int main()
{
	int* arr[10] = { NULL};
	test1(arr, 10); // int*
	test2(arr, 10);
	test3(arr, 10);


	//printf("%d\n", sizeof(arr));

	return 0;
}

 数组在形参位置退化成指针