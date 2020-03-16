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
Queue CreateQueue()//����һ���ն���,����û�г���ͷ�ڵ���������κνڵ�
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Front = Q->Rear = (Position)malloc(sizeof(struct QueueNode));//�տ�ʼָ�붼ָ��ͷ�ڵ㣬Ϊ���ͷ�ڵ�������һ���ڴ�
	Q->Size = 0;
	Q->Front->Next = Q->Front->Data = NULL;
	return Q;
}
void AddQ(Queue Q, BinTree BT)
{
	Q->Size++;
	Position Temp = Q->Rear;//�ȱ����β�ڵ�ָ��
	Q->Rear = (Position)malloc(sizeof(struct QueueNode));//β�ڵ�ָ������ڴ�
	Q->Rear->Data = BT;//����ڴ����������ָ��ָ������������ڵ���ڴ�
	Q->Rear->Next = NULL;
	Temp->Next = Q->Rear;//����һ���ڵ����һ���ڵ���������
}
BinTree DeleteQ(Queue Q)
{
	BinTree BT;
	if (Q->Front->Next == NULL)//����ǿյ�
		return NULL;//����
	Q->Size--;//�Ȱѳ��ȼ�һ
	Position Temp = Q->Front->Next;//�ȱ����ͷ�ڵ��Nextָ�룬Q->Frontָ��ͷ�ڵ�
	if (Temp == Q->Rear)
		Q->Rear = Q->Front;//����ͷ�ڵ�
	Q->Front->Next = Temp->Next;//ͷ�ڵ��Nextָ�������ƣ������һ���ڵ����Ҫɾ���Ľڵ�
	BT = Temp->Data;
	free(Temp);//�ͷŶ��нڵ��ڴ�
	return BT;
}
void SequenceTraversal(BinTree BT)
{
	BinTree T = BT;
	Queue Q = CreateQueue();//�ȴ���һ������
	AddQ(Q, BT);//���
	while (1)
	{
		T = DeleteQ(Q);//����
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