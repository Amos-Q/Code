#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"

BinTree CreateBinTree()//创建一个完全二叉树，是全过程的精髓
{
	ElementType Data;
	BinTree BT, T;
	Queue Q = CreateQueue();//创建一个空队列
	scanf_s("%d", &Data);//临时存放数据
	if (Data != NoInfo)//等于0表示输入终结
	{
		BT = (BinTree)malloc(sizeof(struct TreeNode));//为二叉树节点申请一个内存,先插入二叉树
		BT->Data = Data;
		BT->Left = BT->Right = NULL;
		AddQ(Q, BT);//入队
	}
	else//等于0表示输入终结
		return NULL;
	while (Q->Size != 0)//如果队列不为空
	{
		T = DeleteQ(Q);//出队,已经筛选好了指针，可以直接用
		scanf_s("%d", &Data);
		if (Data == NoInfo)
		{
			T->Left = NULL;
			T->Right = NULL;
			return BT;
		}
		else//为新数据申请内存节点，把节点插入二叉树
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
		else//为新数据申请内存节点，把节点插入二叉树
		{
			T->Right = (BinTree)malloc(sizeof(struct TreeNode));
			T->Right->Data = Data;
			T->Right->Left = T->Right->Right = NULL;
			AddQ(Q, T->Right);
		}
	}
	return BT;
}