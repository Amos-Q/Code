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

class Game;

class Block
{
	friend class Game;                  //声明Game类为友元类
private:
	static string all_state[7][4];  //标记所有方块的状态
	int id, dir;                     //id表示种类,dir表示方向
public:
	Block();
	Point p;                        //标记4*4数组的左上角坐标
	bool state[4][4];               //用4*4的数组标记自己的状态
	static void State_Init();       //初始化所有方块的状态
	void StateCpy();                //将自己的状态与id和dir对应
	void Rotate();                  //旋转
	void Show(bool);                //将方块在屏幕上输出
};

string Block::all_state[7][4];          //初始化静态变量