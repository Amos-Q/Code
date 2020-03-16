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
Queue CreateQueue()//创建一个空队列,里面没有除了头节点外的其他任何节点
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Front = Q->Rear = (Position)malloc(sizeof(struct QueueNode));//刚开始指针都指着头节点，为这个头节点申请了一块内存
	Q->Size = 0;
	Q->Front->Next = Q->Front->Data = NULL;
	return Q;
}
void AddQ(Queue Q, BinTree BT)
{
	Q->Size++;
	Position Temp = Q->Rear;//先保存好尾节点指针
	Q->Rear = (Position)malloc(sizeof(struct QueueNode));//尾节点指着这块内存
	Q->Rear->Data = BT;//这块内存里面的数据指针指着这个二叉树节点的内存
	Q->Rear->Next = NULL;
	Temp->Next = Q->Rear;//把上一个节点和这一个节点连接起来
}
BinTree DeleteQ(Queue Q)
{
	BinTree BT;
	if (Q->Front->Next == NULL)//如果是空的
		return NULL;//报错
	Q->Size--;//先把长度减一
	Position Temp = Q->Front->Next;//先保存好头节点的Next指针，Q->Front指着头节点
	if (Temp == Q->Rear)
		Q->Rear = Q->Front;//返回头节点
	Q->Front->Next = Temp->Next;//头节点的Next指针往下移，多出来一个节点就是要删除的节点
	BT = Temp->Data;
	free(Temp);//释放队列节点内存
	return BT;
}
void SequenceTraversal(BinTree BT)
{
	BinTree T = BT;
	Queue Q = CreateQueue();//先创建一个队列
	AddQ(Q, BT);//入队
	while (1)
	{
		T = DeleteQ(Q);//出队
		if (T == NULL)
			return;
		else
		{
			if (T->Left != NULL)
			{
				AddQ(Q, T->Left);
				if (T->Right != NULL)
					AddQ(Q, T->Right);
			}
			printf("%d ", T->Data);
		}
	}
}