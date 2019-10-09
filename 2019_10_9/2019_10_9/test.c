#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<process.h>

int main()
{
	printf("%d\n", f(1));
	system("pause");
	return 0;
}

int f(int day)
{
	int n;
	if (day == 10)
		n = 1;
	else
	{
		n = (f(day + 1) + 1) * 2;
		printf("第%d天所剩桃子%d个\n", day, n);
	}
	return n;
}