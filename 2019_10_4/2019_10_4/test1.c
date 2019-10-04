#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void DigitSum(int n,int sum)
{
	if (n >= 10)
	{
		sum += (n % 10);
		return DigitSum(n / 10, sum);
	}
	else
	{
		sum = sum + (n % 10);
		printf("%d\n", sum);
	}
}
int main()
{
	int n = 0;
	int sum = 0;
	printf("Input the number:");
	scanf("%d", &n);
	DigitSum(n,sum);
	system("pause");
	return 0;
}



int DigitSum(int i)
{
	if (i == 0)
	{
		return 0;
	}
	else
	{
		return i % 10 + DigitSum(i / 10);
	}
}
int main()
{
	int i = 0;
	printf("ÇëÊäÈëÊı×Ö£º ");
	scanf("%d", &i);
	DigitSum(i);
	printf("%d\n", DigitSum(i));
	return 0;
}