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
void Block::State_Init()
{
	//I
	all_state[0][0] = all_state[0][2] = "0100 0100 0100 0100";
	all_state[0][1] = all_state[0][3] = "0000 1111 0000 0000";
	//O
	all_state[1][0] = all_state[1][1] = "0000 0110 0110 0000";
	all_state[1][2] = all_state[1][3] = "0000 0110 0110 0000";
	//S
	all_state[2][0] = all_state[2][2] = "0000 0110 1100 0000";
	all_state[2][1] = all_state[2][3] = "0100 0110 0010 0000";
	//Z
	all_state[3][0] = all_state[3][2] = "0000 1100 0110 0000";
	all_state[3][1] = all_state[3][3] = "0100 1100 1000 0000";
	//T
	all_state[4][0] = "0000 1110 0100 0000";
	all_state[4][1] = "0100 1100 0100 0000";
	all_state[4][2] = "0100 1110 0000 0000";
	all_state[4][3] = "0100 0110 0100 0000";
	//J
	all_state[5][0] = "0100 0100 1100 0000";
	all_state[5][1] = "1000 1110 0000 0000";
	all_state[5][2] = "1100 1000 1000 0000";
	all_state[5][3] = "0000 1110 0010 0000";
	//L
	all_state[6][0] = "0100 0100 0110 0000";
	all_state[6][1] = "0000 1110 1000 0000";
	all_state[6][2] = "1100 0100 0100 0000";
	all_state[6][3] = "0010 1110 0000 0000";
}
Block::Block()
{
	id = rand() % 7;                      //随机生成块的种类
	dir = rand() % 4;                     //随机生成块的方向
	p = Point(4, 13);                    //初始化点p的位置
	StateCpy();
}