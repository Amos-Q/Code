#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int Js(int n)
{
	if (n > 1)
		return n * Js(n-1);
	else
		return n;
}
int main()
{
	int n = 0;
	int k = 0;
	int sum = 0;
	printf("Input the number:");
	scanf("%d", &n);
	sum = Js(n);
	printf("%d\n", sum);
	system("pause");
	return 0;
}