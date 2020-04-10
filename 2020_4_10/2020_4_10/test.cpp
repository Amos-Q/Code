#include "home.h"

void SetCursor(int x, int y)             //设置光标位置
{
	COORD cd = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}

void SetCursor(const Point& p)          //将数组中的位置映射到屏幕上
{
	SetCursor(2 * p.y, p.x);
}

void HideCursor()                       //隐藏光标
{
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	GetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
	ConsoleCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
}

template<typename T>
void PrintAt(const Point& p, T data, int wid = 0)                   //在点p处输出data
{
	SetCursor(p);
	if (wid)
		cout.width(wid);
	cout << data;
}

void MagicShow(const Point& p, bool flag = false, bool info = false)  //在点p处输出/擦除方块
{
	if (info || g[p.x][p.y] == space)
		PrintAt(p, flag ? square : space);
}