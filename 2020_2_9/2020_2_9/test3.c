#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define nmax 50

int main()
{
	int i, k, m, n, num[nmax], *p;
	printf("please input the total of numbers:");
	scanf("%d", &n);
	p = num;
	for (i = 0; i < n; i++)
		*(p + i) = i + 1;
	i = 0;
	k = 0;
	m = 0;
	while (m < n - 1)
	{
		if (*(p + i) != 0) k++;
		if (k == 3)
		{
			*(p + i) = 0;
			k = 0;
			m++;
		}
		i++;
		if (i == n) i = 0;
	}
	while (*p == 0) p++;
	printf("%d is left/n", *p);
}


int main()
{
	int len;
	char *str[20];
	printf("please input a string:/n");
	scanf("%s", str);
	len = length(str);
	printf("the string has %d characters.", len);
}
length(p)
char *p;
{
	int n;
	n = 0;
	while (*p != '/0')
	{
		n++;
		p++;
	}
	return n;
}
