#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void PD(int i)
{
	int j = 0;
	for (j = 2; j <= sqrt(i); j++)
	{
		if (i % j != 0)
		{
			continue;
			j++;
		}
		else
		{
			printf("��������\n");
			break;
		}
	}
	if (j > sqrt(i))
		printf("%d������\n", i);
}

int main()
{
	int i = 0;
	int a = 0;
	int tr = 1;
	printf("******* 1.����  2.�ж�  3.�˳� *******\n");
	while (tr)
	{
		printf("��ѡ��:");
		scanf("%d", &a);
		switch (a)
		{
		case 1:	printf("Input the number:");
			scanf("%d", &i);
			break;
		case 2:PD(i);
			break;
		case 3:tr = 0;
			break;
		default:
			printf("����������������룺\n");
		}
	}
	system("pause");
	return 0;
}