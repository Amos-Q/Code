#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("**************************\n");
	printf("*****   1.开始游戏   *****\n");
	printf("*****   0.退出游戏   *****\n");
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
		printf("请选择->");
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
				printf("电脑走:\n");
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
			printf("退出游戏!\n");
			break;
		default:
			printf("输入错误，重新输入\n");
			break;
		}
		if (ret == '*')
			printf("玩家胜\n");
		if (ret == '#')
			printf("电脑胜\n");
		if (ret == 'q')
			printf("平局\n");
	} while (true);
	system("pause");
	return 0;
}