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

//求出正确的数字完成等式
void FindNum()
{
	int i;
	printf("要使下面的等式成立，应在口中填哪个相同的数字？\n");
	printf("      3口 X 6237=口3 x3564\n");
	printf("求解结果为：\n");
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
			//打印*
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
