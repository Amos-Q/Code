#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main() 
{
	int arr[1000] = { 0 };
	int sz = 0;
	int i = 0;
	printf("Input number:");
	scanf("%d", &sz);
	for (i = 0; i < sz; i++)
	{
		scanf("%d", &arr[i]);
	}
	int t = arr[0];
	for (i = 1; i < sz; i++) {
		t = t ^ arr[i];
	}
	printf("%d\n", t);
	system("pause");
	return 0;
}