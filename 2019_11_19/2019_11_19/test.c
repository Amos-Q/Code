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

void test1(int* arr, int n) // ok  -> ����
{
	printf("%d\n", sizeof(arr));
}

void test2(int arr[10], int n) // ok  ָ��  C���Դ��Σ������ڴ����飬�����˻���ָ��
{
	printf("%d\n", sizeof(arr));
}

void test3(int arr[], int n) // ok  ָ��  C���Դ��Σ������ڴ����飬�����˻���ָ��
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


void test1(int** arr, int n) // ok  -> ����
{
	printf("%d\n", sizeof(arr));
}

void test2(int* arr[10], int n) // ok  ָ��  C���Դ��Σ������ڴ����飬�����˻���ָ��
{
	printf("%d\n", sizeof(arr));
}

void test3(int* arr[], int n) // ok  ָ��  C���Դ��Σ������ڴ����飬�����˻���ָ��
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

 �������β�λ���˻���ָ��