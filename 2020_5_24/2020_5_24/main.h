#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

typedef enum
{
	//����A,J=10,Q=10,K=10
	A = 1, two, three, four, five, six, seven, eight, nine, ten, J, Q, K
}numtype;
//����numtype������Ϊö����enum 

typedef enum
{
	//�˿��ƵĻ�ɫ��clubs(÷��)��diamonds(����)��hearts(����)��spades(����)
	clubs, diamonds, hearts, spades
}shapetype;
//����shapetype������Ϊö����enum 

struct Card
{
	numtype num;//��ֵ����
	shapetype shape;//��ɫ��״
};
//����һ���ƵĽṹ��


//���������<<
//������const
ostream &operator<<(ostream &output, const Card &card)
{
	//�����ɫ
	if (card.shape == clubs)  output << "÷��";
	if (card.shape == diamonds) output << "����";
	if (card.shape == hearts) output << "����";
	if (card.shape == spades) output << "����";

	//�����ֵ
	if (card.num == A)
	{
		output << "A";
	}
	else if (card.num == J)
	{
		output << "J";
	}
	else if (card.num == Q)
	{
		output << "Q";
	}
	else if (card.num == K)
	{
		output << "K";
	}
	else cout << (int)card.num;//ǿ��ת����ֵΪint��

	return output;

}