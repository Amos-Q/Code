#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void Js(int n, int k)
{
	int i = 0;
	int sum = n;
	for (i = 1; i < k; i++)
		sum *= n;
	printf("%d\n", sum);
}
int main()
{
	int n = 0;
	int k = 0;
	printf("Input the number:");
	scanf("%d %d", &n, &k);
	Js(n, k);
	system("pause");
	return 0;
}


int Js(int n, int k)
{
	if (k > 1)
		return n * Js(n, k - 1);
	else
		return n;
}
int main()
{
	int n = 0;
	int k = 0;
	int sum = 0;
	printf("Input the number:");
	scanf("%d %d", &n, &k);
	sum = Js(n, k);
	printf("%d\n", sum);
	system("pause");
	return 0;
}