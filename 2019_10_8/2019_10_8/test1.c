#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int strlen(char * str)
{
	int count = 0;
	if (*str != '\0')
	{
		str++;
		count = 1 + strlen(str);
	}
	return count;
}

int main()
{
	char str[] = { 0 };
	int sum = 0;
	printf("ÊäÈë×Ö·û:");
	scanf("%s", &str);
	sum = strlen(str);
	printf("%d\n", sum);
	system("pause");
	return 0;
}


int main()
{
	char str[] = { 0 };
	int count = 0;
	int i = 0;
	int sz = 0;
	printf("ÊäÈë×Ö·û:");
	gets(str);
	for(i = 0;str[i] != '\0';i++)
			count++;
	printf("%d\n", count);
	system("pause");
	return 0;
}