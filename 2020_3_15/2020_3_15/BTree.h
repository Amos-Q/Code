#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;//输入的数据的类型
#define NoInfo 0//如果输入是0，则输入结束
////////////////////////////////////////////////////////////////////
typedef struct TreeNode* BinTree;
struct TreeNode//二叉树节点
{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};
/////////////////////////////////////////////////////////////////////
typedef struct QueueNode*PtrToNode;//队列中的节点
struct QueueNode
{
	BinTree Data;//指着那块内存
	PtrToNode Next;
};
typedef PtrToNode Position;
typedef struct QNode* PtrToQNode;//队列的头尾数据和队列的长度
struct QNode
{
	Position Front, Rear;
	int Size;
};
typedef PtrToQNode Queue;
///////////////////////////////////////////////////////////////////
BinTree CreateBinTree();
Queue CreateQueue();
void AddQ(Queue Q, BinTree BT);
BinTree DeleteQ(Queue Q);
void SequenceTraversal(BinTree BT);