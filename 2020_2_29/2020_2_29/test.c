#define _CRT_SECURE_NO_WARNINGS 1
#include "tree.h"

ChainBinTree *BinTreeInit(ChainBinTree *node) //��ʼ������������� 
{
	if (node != NULL) //������������㲻Ϊ�� 
		return node;
	else
		return NULL;
}

int BinTreeAddNode(ChainBinTree *bt, ChainBinTree *node, int n) //������ݵ������� 
//btΪ����㣬nodeΪ�ӽ��,n=1��ʾ�����������n=2��ʾ��������� 
{
	if (bt == NULL)
	{
		printf("����㲻���ڣ��������ø����!\n");
		return 0;
	}
	switch (n)
	{
	case 1: //��ӵ����� 
		if (bt->left) //��������Ϊ�� 
		{
			printf("��������㲻Ϊ��!\n");
			return 0;
		}
		else
			bt->left = node;
		break;
	case 2://��ӵ��ҽ��
		if (bt->right) //��������Ϊ�� 
		{
			printf("��������㲻Ϊ��!\n");
			return 0;
		}
		else
			bt->right = node;
		break;
	default:
		printf("��������!\n");
		return 0;
	}
	return 1;
}


ChainBinTree *BinTreeLeft(ChainBinTree *bt) //�������ӽ�� 
{
	if (bt)
		return bt->left;
	else
		return NULL;
}
ChainBinTree *BinTreeRight(ChainBinTree *bt) //�������ӽ�� 
{
	if (bt)
		return bt->right;
	else
		return NULL;
}


int BinTreeIsEmpty(ChainBinTree *bt) //���������Ƿ�Ϊ�գ�Ϊ���򷵻�1,���򷵻�0 
{
	if (bt)
		return 0;
	else
		return 1;
}
int BinTreeDepth(ChainBinTree *bt) //����������
{
	int dep1, dep2;
	if (bt == NULL)
		return 0; //���ڿ��������Ϊ0
	else
	{
		dep1 = BinTreeDepth(bt->left); //��������� (�ݹ����)
		dep2 = BinTreeDepth(bt->right); //��������� (�ݹ����)
		if (dep1 > dep2)
			return dep1 + 1;
		else
			return dep2 + 1;
	}
}