#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void Playgame(char box[3][3], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", box[i][j]);
			if (j < row - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}


void myplay(char box[3][3], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("输入你要下的坐标->");
	scanf("%d%d", &x,&y);
	if (x > 0 && x < 4 && y > 0 && y < 4)
	{
		if (box[x - 1][y - 1] ==  ' ')
		{
			box[x - 1][y - 1] = '*';
		}
		else
			printf("坐标有误，请重新输入\n");
	}
	else
		printf("坐标有误，请重新输入\n");
}

void complay(char box[3][3], int row, int col)
{
	int a = 0;
	int b = 0;
	while (1)
	{
		srand((unsigned)time(NULL));
		a = rand() % row + 1;
		b = rand() % col + 1;
		if (box[a - 1][b - 1] == ' ')
		{
			box[a - 1][b - 1] = '#';
			break;
		}
	}
}

int win(char box[3][3], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (box[i][0] == '*'&& box[i][1] == '*'&& box[i][2] == '*')
			return '*';
		if (box[i][0] == '#'&& box[i][1] == '#' && box[i][2] == '#')
			return '#';
	}
	for(j = 0;j < col;j++)
	{
		if (box[0][j] == '*'&& box[1][j] == '*'&& box[2][j] == '*')
			return '*';
		if (box[0][j] == '#' && box[1][j] == '#'&& box[2][j] == '#')
			return '#';
	}
	if (box[0][0] == '*'&& box[1][1] == '*'&& box[2][2] == '*')
		return '*';
	if (box[0][0] == '#'&& box[1][1] == '#'&& box[2][2] == '#')
		return '#';
	if (box[0][2] == '*'&& box[1][1] == '*'&& box[2][0] == '*')
		return '*';
	if (box[0][2] == '#'&& box[1][1] == '#'&& box[2][0] == '#')
		return '#';
	return ' ';
}

int full(char box[3][3], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (box[i][j] == ' ')
				return ' ';
		}
	}
	return 'q';
}