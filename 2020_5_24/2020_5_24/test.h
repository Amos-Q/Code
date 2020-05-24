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

