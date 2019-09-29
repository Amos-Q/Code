#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void PD_year(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		printf("The year %d is R\n",year);
	else
		printf("Not R\n");
}

int main()
{
	int year = 0;
	printf("Input year:");
	scanf("%d", &year);
	PD_year(year);
	system("pause");
	return 0;
}