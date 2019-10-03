#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int Js(int n,int m,int k)
{
	if (k == 1)
		return m;
	else if (k > 1)
		m *= n;
		return Js(n,m,k - 1);
}

int main()
{
	int n = 0;
	int k = 0;
	int a = 0;
	printf("Input n and k:");
	scanf("%d %d", &n, &k);
	int m = n;
	a = Js(n,m,k);
	printf("Answer:%d\n", a);
	system("pause");
	return 0;
}