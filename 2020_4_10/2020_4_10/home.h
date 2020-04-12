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
class Game
{
private:
	static int level_up[6];             //各level对应的分数
	static int score_up[5];             //消除各行对应要加的分数
	static int tick_cnt[6];             //各level对应的cnt数
	int level, score;
public:
	Block runB, nextB;
	Game();
	int GetTickCnt();                   //得到当前level的cnt数
	void ShowFrame();                   //输出游戏框架
	void CheckBoard();                  //检查键盘响应
	bool AllSquare(int);                //检查xx行是否可消
	void DropDown(int);                 //将xx行以上的全部下移一格
	void CheckLine();                   //方块安放后检查是否有可消行
	void PlaceOn();                     //方块安放好
	void Update(int);                   //更新信息
	void GetNext();                     //得到下一个方块
	inline bool OutBoard(int, int);      //检查坐标是否出界
	bool CanChange(int, int);            //检查是否可以发生这样的改变
	bool ChangePos(int, int);            //检查并改变下落方块的位置
	void Rotate();                      //旋转
	void Begin();                       //游戏欢迎界面
	void Over();                        //游戏结束界面
};

int Game::level_up[6] = { 0,80,180,290,410,666 };
int Game::score_up[5] = { 0,10,30,60,100 };
int Game::tick_cnt[6] = { 0,50,40,30,20,10 };