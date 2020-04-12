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

class Game;

class Block
{
	friend class Game;                  //����Game��Ϊ��Ԫ��
private:
	static string all_state[7][4];  //������з����״̬
	int id, dir;                     //id��ʾ����,dir��ʾ����
public:
	Block();
	Point p;                        //���4*4��������Ͻ�����
	bool state[4][4];               //��4*4���������Լ���״̬
	static void State_Init();       //��ʼ�����з����״̬
	void StateCpy();                //���Լ���״̬��id��dir��Ӧ
	void Rotate();                  //��ת
	void Show(bool);                //����������Ļ�����
};

string Block::all_state[7][4];          //��ʼ����̬����
class Game
{
private:
	static int level_up[6];             //��level��Ӧ�ķ���
	static int score_up[5];             //�������ж�ӦҪ�ӵķ���
	static int tick_cnt[6];             //��level��Ӧ��cnt��
	int level, score;
public:
	Block runB, nextB;
	Game();
	int GetTickCnt();                   //�õ���ǰlevel��cnt��
	void ShowFrame();                   //�����Ϸ���
	void CheckBoard();                  //��������Ӧ
	bool AllSquare(int);                //���xx���Ƿ����
	void DropDown(int);                 //��xx�����ϵ�ȫ������һ��
	void CheckLine();                   //���鰲�ź����Ƿ��п�����
	void PlaceOn();                     //���鰲�ź�
	void Update(int);                   //������Ϣ
	void GetNext();                     //�õ���һ������
	inline bool OutBoard(int, int);      //��������Ƿ����
	bool CanChange(int, int);            //����Ƿ���Է��������ĸı�
	bool ChangePos(int, int);            //��鲢�ı����䷽���λ��
	void Rotate();                      //��ת
	void Begin();                       //��Ϸ��ӭ����
	void Over();                        //��Ϸ��������
};

int Game::level_up[6] = { 0,80,180,290,410,666 };
int Game::score_up[5] = { 0,10,30,60,100 };
int Game::tick_cnt[6] = { 0,50,40,30,20,10 };