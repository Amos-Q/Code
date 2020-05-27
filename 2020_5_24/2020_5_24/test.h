#define _CRT_SECURE_NO_WARNINGS 1
#include "main.h"
#include <iostream>
#include <ctime>
#define max_length 10 //����������Ȳ��ܴ���10���ֽ� 
using namespace std;
//����21�����Ϸ��
class Point21
{
	//�������� 
public:
	//��������
	Point21();	//�޲ι��캯��
	virtual ~Point21() {};//�������� 
	void Game();

	//˽�б���		
private:
	Card PK[52];//54���Ƽ�ȥ��С��
	int startPosition;//���Ƴ�ʼλ
	Card gamers[8][21];
	//gamers[0]���ׯ�ҵ��ƣ�gamers[1]��[7]�����ҵ��� 
	//����ׯ�Ҽ��ǻ����ˣ�һ����Ҳ����

	int numcards[8];	//ׯ��(numcards[0])����ҵ�����
	char name[8][max_length];	//ׯ�Ҽ��������
	int numgamer;//�����

	void Shuffle();	//ϴ�ƺ��� 

	int GetTotalScore(Card gamer[21], int n);	//���ص�һ���ƣ���һ�η��ƣ����ܷ�ֵ

	void ShowStatus(int num, bool hideFirstCard = false);
	//��ʾׯ��(��Ӧnum=0)�����(��Ӧnum>0)�ĵ�ǰ״̬��Ҫ����ׯ�һ����˵ĵ�һ�η����ƺͷ��� 

	Card FirstCard()
	{
		return PK[startPosition++];
	}//��һ���˿���


};
//��ʼ���˿��ƣ�����λ�ã�ׯ�����������е��˿�����
Point21::Point21()
{
	int nowPos = 0;	//��ǰ�˿���λ��

	char* str;

	for (int shapePos = 0; shapePos < 4; shapePos++)	//��ɫ
	{
		for (int numPos = 1; numPos <= 13; numPos++)	//��ֵ
		{
			PK[nowPos].shape = (shapetype)shapePos;	//��ɫ
			PK[nowPos].num = (numtype)numPos;	//��ֵ
			nowPos++;
		}
	}
	cout << endl << "�����м����˲μ���Ϸ��(���7����):";
	str = new char[1];
	cin >> str;
	numgamer = atoi(str);
	//atoi������itoa()�������� 

	while (numgamer < 1 || numgamer>7) //����������1~7֮��
	{
		cout << endl << "��������޶���1~7��,����������������";
		cin >> str;
		numgamer = atoi(str);
	}

	startPosition = 0;	//����λ��
	int i = 0;	//��ʱ����
	//ׯ��numcards[0]�����numcards[1~7]���е��˿�������
	for (i = 0; i <= numgamer; i++) numcards[i] = 0;

	strcpy(name[0], "ׯ��");

	for (i = 1; i <= numgamer; i++)   //�������
	{
		cout << "�����" << i << "����ҵ�����:";
		cin >> name[i];
	}
	cout << "��Ϸ��ʼ" << endl << endl;
}
