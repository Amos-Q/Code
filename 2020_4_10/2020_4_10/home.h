#include <vector>
#include <time.h>
#include <string>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

const int N = 22;                       //��Ϸ��&&��Ϣ��������
const int M = 12;                       //��Ϸ��������
const int MM = 6;                       //��Ϣ��������

const string square = "��";
const string space = "  ";
const string line[] = { "��","��" };
const string corner[] = { "��","��","��" ,"��" };

string g[N][M], gg[N][MM];               //gΪ��Ϸ��,ggΪ��Ϣ��

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