#define _CRT_SECURE_NO_WARNINGS 1
#include "home.h"

void print()  /*打印棋盘*/
{
	int i, j;
	cout << " -------" << endl;
	for (i = 0; i < 3; ++i)
	{
		cout << "| ";
		for (j = 0; j < 3; ++j)
			cout << arr[i][j] << ' ';
		cout << "| ";
		cout << endl;
	}
	cout << " ------" << endl;
}
void init()             //初始化
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void player()          //玩家行动
{
	int i = 0;
	int j = 0;
	cout << "请输入行和列：" << endl;
	cin >> i >> j;
	i--;
	j--;
	if (arr[i][j] != ' ')
	{
		cout << "输入无效,请重新输入" << endl;
		player();
	}
	else
	{
		arr[i][j] = '*';
	}
}
void computer()           //电脑行动
{
	for (int i = 0; i < 3; i++)    //如果在那一行上有两个元素，则在剩余的位置下子
	{
		int count = 0;
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] == '*')
				count++;  //在每一行上计数
			if (count == 2)
				break;
		}
		if (count == 2)
		{
			for (int k = 0; k < 3; k++)
			{
				if (arr[i][k] == ' ')     //在空位置上下子
				{
					arr[i][k] = '@';
					return;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++)    //在列上有两个元素，则在剩余位置下子
	{
		int count = 0;
		for (int j = 0; j < 3; j++)
		{
			if (arr[j][i] == '*')     //在每一列上计数
			{
				count++;
			}
		}
		if (count == 2)
		{
			for (int k = 0; k < 3; k++)
			{
				if (arr[k][i] == ' ')        //在空位置上下子
				{
					arr[k][i] = '@';
					return;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++)    //判断主对角线
	{
		int count = 0;          //在主对角线上计数
		if (arr[i][i] == '*')
			count++;
		if (count == 2)
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr[j][j] == ' ')
				{
					arr[j][j] = '@';
					return;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++)     //判断副对角线
	{
		int count = 0;           //在副对角线上计数
		if (arr[i][3 - i] == '*')
			count++;
		if (count == 2)
		{
			for (int j = 1; j <= 3; j++)
			{
				if (arr[j][3 - j] == ' ')
				{
					arr[j][3 - j] = '@';
					return;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++)      //如果没有两个子相连的情况，就随便下了
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] == ' ')
			{
				arr[i][j] = '@';
				return;
			}
		}
	}
}
char judge()         //判断哪方胜利
{
	int i = 0;
	for (int i = 0; i < 3; i++)          //判断是否在一行
	{
		if ((arr[i][0] == arr[i][1]) && (arr[i][1] == arr[i][2]))
		{
			return arr[i][0];
		}
	}
	for (i = 0; i < 3; i++)              //判断是否在一列
	{
		if ((arr[0][i] == arr[1][i]) && (arr[1][i] == arr[2][i]))
		{
			return arr[0][i];
		}
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])      //判断主对角线
		return arr[0][0];
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])      //判断副对角线
		return arr[0][2];
	return ' ';
}
int  panduan()     //判断胜负
{
	if (judge() == '*')
	{
		cout << "恭喜你赢了" << endl;
		print();
		return  1;
	}
	else if (judge() == '@')
	{
		cout << "很遗憾，你输了" << endl;
		print();
		return 1;
	}
	return 0;
}
int main()
{
	int n = 0;    //记录步数
	init();          //初始化
	cout << "棋盘游戏" << endl;
	while (n <= 9)
	{
		print();
		player();
		n++;
		if (panduan() == 1)     //胜负已定
		{
			return 0;
		}
		computer();
		n++;
		if (panduan() == 1)     //胜负已定
		{
			return 0;
		}
	}
	print();
	cout << "平局" << endl;
	return 0;
}