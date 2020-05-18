#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	char a[] = "SSSWLIA";
	char c;
	for (int k = 2; (c = a[k]) != '\0'; k++)
	{
		switch(c)
		{
			case 'I':++k; break;
			case 'L':continue;
			default:putchar(c); continue;
		}
		putchar('*');
	}
	return 0;
}