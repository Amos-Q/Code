#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

void FindNum();
void Diamand(int);
int menu_select();

int main()
{
	for (;;)
	{
		switch (menu_select())
		{
		case 1:
			FindNum();
			break;
		case 2:
			Diamand(16);
			break;
		case 3:
			printf("Goodbye!\n");
			exit(0);
		}
	}
	return 0;
}

int menu_select()
{
	char s;
	int cn;
	printf("1. FindNum\n");
	printf("2. Diamand\n");
	printf("3.  Goodbye!\n");
	do {
		s = getchar();
		cn = (int)s - 48;

	} while (cn < 0 || cn>3);

	return cn;
}

//�����ȷ��������ɵ�ʽ
void FindNum()
{
	int i;
	printf("Ҫʹ����ĵ�ʽ������Ӧ�ڿ������ĸ���ͬ�����֣�\n");
	printf("      3�� X 6237=��3 x3564\n");
	printf("�����Ϊ��\n");
	for (i = 1; i < 10; i++)
	{
		if (((3 * 10 + i) * 6237) == (i * 10 + 3) * 3564)
		{
			printf("number=%d\n", i);
			break;
		}
	}
}


void Diamand(int number)
{
	int maxStar = 2 * number - 1;
	int i, j, k, space, star;

	for (i = 1; i < number + 1; i++)
	{
		if (i <= (number / 2) + 1)
		{
			space = maxStar - i;
			for (j = 0; j < space; j++)
			{
				printf(" ");
			}
			//��ӡ*
			star = 2 * i - 1;
			for (k = 1; k < star + 1; k++)
			{
				printf("*");
			}
			printf("\n");
		}
		else
		{
			int l = (number / 2 + 1) * 2 - i;
			space = maxStar - l;
			star = 2 * l - 1;
			for (j = 0; j < space; j++)
			{
				printf(" ");
			}

			for (k = 1; k < star + 1; k++)
			{
				printf("*");
			}
			printf("\n");
		}
	}
}
