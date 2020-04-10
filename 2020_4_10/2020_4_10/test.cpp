#include "home.h"

void SetCursor(int x, int y)             //���ù��λ��
{
	COORD cd = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}

void SetCursor(const Point& p)          //�������е�λ��ӳ�䵽��Ļ��
{
	SetCursor(2 * p.y, p.x);
}

void HideCursor()                       //���ع��
{
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	GetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
	ConsoleCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
}

template<typename T>
void PrintAt(const Point& p, T data, int wid = 0)                   //�ڵ�p�����data
{
	SetCursor(p);
	if (wid)
		cout.width(wid);
	cout << data;
}

void MagicShow(const Point& p, bool flag = false, bool info = false)  //�ڵ�p�����/��������
{
	if (info || g[p.x][p.y] == space)
		PrintAt(p, flag ? square : space);
}