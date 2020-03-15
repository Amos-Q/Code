#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"

BinTree CreateBinTree()//����һ����ȫ����������ȫ���̵ľ���
{
	ElementType Data;
	BinTree BT, T;
	Queue Q = CreateQueue();//����һ���ն���
	scanf_s("%d", &Data);//��ʱ�������
	if (Data != NoInfo)//����0��ʾ�����ս�
	{
		BT = (BinTree)malloc(sizeof(struct TreeNode));//Ϊ�������ڵ�����һ���ڴ�,�Ȳ��������
		BT->Data = Data;
		BT->Left = BT->Right = NULL;
		AddQ(Q, BT);//���
	}
	else//����0��ʾ�����ս�
		return NULL;
	while (Q->Size != 0)//������в�Ϊ��
	{
		T = DeleteQ(Q);//����,�Ѿ�ɸѡ����ָ�룬����ֱ����
		scanf_s("%d", &Data);
		if (Data == NoInfo)
		{
			T->Left = NULL;
			T->Right = NULL;
			return BT;
		}
		else//Ϊ�����������ڴ�ڵ㣬�ѽڵ���������
		{
			T->Left = (BinTree)malloc(sizeof(struct TreeNode));
			T->Left->Data = Data;
			T->Left->Left = T->Left->Right = NULL;
			AddQ(Q, T->Left);
		}
		scanf_s("%d", &Data);
		if (Data == NoInfo)
		{
			T->Right = NULL;
			return BT;
		}
		else//Ϊ�����������ڴ�ڵ㣬�ѽڵ���������
		{
			T->Right = (BinTree)malloc(sizeof(struct TreeNode));
			T->Right->Data = Data;
			T->Right->Left = T->Right->Right = NULL;
			AddQ(Q, T->Right);
		}
	}
	return BT;
}