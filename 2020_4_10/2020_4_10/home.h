#include <vector>
#include <time.h>
#include <string>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

const int N = 22;                       //游戏栏&&信息栏的行数
const int M = 12;                       //游戏栏的列数
const int MM = 6;                       //信息栏的列数

const string square = "■";
const string space = "  ";
const string line[] = { "┄","┆" };
const string corner[] = { "┌","┐","└" ,"┘" };

string g[N][M], gg[N][MM];               //g为游戏栏,gg为信息栏

struct Point
{
	int x, y;
	Point() {}
	Point(int _x, int _y) :x(_x), y(_y) {}
	Point operator++(int)
	{
		y++;
		return (*this);
	}
	Point operator--(int)
	{
		y--;
		return (*this);
	}
	Point operator++()
	{
		x++;
		return (*this);
	}
	bool operator==(const Point& B)
	{
		return x == B.x && y == B.y;
	}
};