#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>

void Ts(char * str, int i)
{
	int j = 0;
	char arr = 0 ;
	do
	{
		i--;
		if (i < 0)
			break;
		arr = *(str+i);
		printf("%c\n", arr);
	} while (arr != '\0');
}

int main()
{
	char str[100] = { 0 };
	int i = 0;
	gets(str);
	while (str[i] != '\0')
	{
		i++;
	}
	printf("%d", i);
	Ts(str,i);
	system("pause");
	return 0;
}