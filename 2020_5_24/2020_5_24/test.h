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

