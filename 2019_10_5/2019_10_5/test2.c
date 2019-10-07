#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void Js(int n)
{
	int i = 0;
	int sum = 1;
	for (i = 1; i <= n; i++)
		sum *= i;
	printf("%d\n", sum);
}
int main()
{
	int n = 0;
	int k = 0;
	printf("Input the number:");
	scanf("%d", &n);
	Js(n);
	system("pause");
	return 0;
}