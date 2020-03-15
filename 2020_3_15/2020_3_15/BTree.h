#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;//��������ݵ�����
#define NoInfo 0//���������0�����������
////////////////////////////////////////////////////////////////////
typedef struct TreeNode* BinTree;
struct TreeNode//�������ڵ�
{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};
/////////////////////////////////////////////////////////////////////
typedef struct QueueNode*PtrToNode;//�����еĽڵ�
struct QueueNode
{
	BinTree Data;//ָ���ǿ��ڴ�
	PtrToNode Next;
};
typedef PtrToNode Position;
typedef struct QNode* PtrToQNode;//���е�ͷβ���ݺͶ��еĳ���
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