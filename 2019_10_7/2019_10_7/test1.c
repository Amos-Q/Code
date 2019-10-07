#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void reverse_string(char * str)
{
	if (*str == '\0')
		;
	else
	{
		reverse_string(++str);
		printf("%c ", *(--str));
	}
}

int main()
{
	char str[] = { 0 };
	printf("ÊäÈë×Ö·û´®:");
	scanf("%s", &str);
	reverse_string(str);
	system("pause");
	return 0;
}