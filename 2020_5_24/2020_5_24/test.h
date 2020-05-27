#define _CRT_SECURE_NO_WARNINGS 1
#include "main.h"
#include <iostream>
#include <ctime>
#define max_length 10 //玩家姓名长度不能大于10个字节 
using namespace std;
//声明21点的游戏类
class Point21
{
	//公共变量 
public:
	//函数声明
	Point21();	//无参构造函数
	virtual ~Point21() {};//析构函数 
	void Game();

	//私有变量		
private:
	Card PK[52];//54张牌减去大小王
	int startPosition;//发牌初始位
	Card gamers[8][21];
	//gamers[0]存放庄家的牌，gamers[1]到[7]存放玩家的牌 
	//设置庄家即是机器人，一个人也能玩

	int numcards[8];	//庄家(numcards[0])及玩家的牌数
	char name[8][max_length];	//庄家及玩家姓名
	int numgamer;//玩家数

	void Shuffle();	//洗牌函数 

	int GetTotalScore(Card gamer[21], int n);	//返回第一手牌（第一次发牌）的总分值

	void ShowStatus(int num, bool hideFirstCard = false);
	//显示庄家(对应num=0)或玩家(对应num>0)的当前状态，要隐藏庄家机器人的第一次发的牌和分数 

	Card FirstCard()
	{
		return PK[startPosition++];
	}//发一张扑克牌


};
//初始化扑克牌，发牌位置，庄家与各玩家手中的扑克牌数
Point21::Point21()
{
	int nowPos = 0;	//当前扑克牌位置

	char* str;

	for (int shapePos = 0; shapePos < 4; shapePos++)	//花色
	{
		for (int numPos = 1; numPos <= 13; numPos++)	//面值
		{
			PK[nowPos].shape = (shapetype)shapePos;	//花色
			PK[nowPos].num = (numtype)numPos;	//面值
			nowPos++;
		}
	}
	cout << endl << "请问有几个人参加游戏？(最多7个人):";
	str = new char[1];
	cin >> str;
	numgamer = atoi(str);
	//atoi函数与itoa()函数区别 

	while (numgamer < 1 || numgamer>7) //限制人数在1~7之间
	{
		cout << endl << "玩家人数限定在1~7个,请重新输入人数：";
		cin >> str;
		numgamer = atoi(str);
	}

	startPosition = 0;	//发牌位置
	int i = 0;	//临时变量
	//庄家numcards[0]及玩家numcards[1~7]手中的扑克牌张数
	for (i = 0; i <= numgamer; i++) numcards[i] = 0;

	strcpy(name[0], "庄家");

	for (i = 1; i <= numgamer; i++)   //玩家姓名
	{
		cout << "输入第" << i << "个玩家的姓名:";
		cin >> name[i];
	}
	cout << "游戏开始" << endl << endl;
}
