#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("**************************\n");
	printf("*****   1.��ʼ��Ϸ   *****\n");
	printf("*****   0.�˳���Ϸ   *****\n");
	printf("**************************\n");
}

void box_jl(char box[3][3])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			box[i][j] = ' ';
		}
	}
}

int main()
{
	int true = 0;
	char ret = 0;
	do
	{
		char box[3][3] = { 0 };
		box_jl(box);
		menu();
		printf("��ѡ��->");
		scanf("%d", &true);
		switch (true)
		{
		case 1:
			Playgame(box, 3, 3);
			while (1)
			{
				myplay(box, 3, 3);
				Playgame(box, 3, 3);
				ret = win(box, 3, 3);
				if (ret != ' ')
					break;
				ret = full(box, 3, 3);
				if (ret != ' ')
					break;
				printf("������:\n");
				complay(box, 3, 3);
				Playgame(box, 3, 3);
				ret = win(box, 3, 3);
				if (ret != ' ')
					break;
				ret = full(box, 3, 3);
				if(ret != ' ')
					break;
			}
			break;
		case 0:
			printf("�˳���Ϸ!\n");
			break;
		default:
			printf("���������������\n");
			break;
		}
		if (ret == '*')
			printf("���ʤ\n");
		if (ret == '#')
			printf("����ʤ\n");
		if (ret == 'q')
			printf("ƽ��\n");
	} while (true);
	system("pause");
	return 0;
}