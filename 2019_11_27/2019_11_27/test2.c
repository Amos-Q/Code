#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
main()
{
	char word[3][80];
	int i, j, a, b, c, d, e;
	a = b = c = d = e = 0;
	printf("����3�����֣�\n");
	for (i = 0; i < 3; i++)
	{
		gets(word[i]);
		for (j = 0; j < 80 && word[i][j] != '\0'; j++)
		{
			if (word[i][j] >= 'A'&&word[i][j] <= 'Z') a++;
			else if (word[i][j] >= 'a'&&word[i][j] <= 'z') b++;
			else if (word[i][j] >= '0'&&word[i][j] <= '9') c++;
			else if (word[i][j] == ' ') d++;
			else e++;
		}
	}
	printf("��д��ĸ%d��\nСд��ĸ%d��\n����%d��\n�ո�%d��\n�����ַ�%d��\n", a, b, c, d, e);
	return 0;
}

**  *  *  *  *
*  *  *  *  *
* *  *  *
*



#include<stdio.h>
void main()
{
	char str[] = { "*****" };
	int i, k;
	for (i = 1; i <= 5; i++)
	{
		printf("%s\n", str);
		for (k = 1; k <= i; k++)
		{
			char c = 32;
			printf("%c", c);
		}
	}
}
