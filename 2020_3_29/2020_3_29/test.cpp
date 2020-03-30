#define _CRT_SECURE_NO_WARNINGS 1
#include "main.h"

//��ʼ������
Status InitQueue(Queue &Q, int capacity)
{
	Q.base = (Elemtype*)malloc(sizeof(Elemtype)*capacity);
	if (Q.base == NULL)
		return ERROR;
	Q.front = Q.rear = 0;
	Q.maxsize = capacity;
	return OK;
}

//��������
Status isEmptyQueue(Queue &Q)
{
	if (Q.front == Q.rear)
		return True;
	else return False;
}
//�пպ���
Status isFullQueue(Queue  &Q)
{//�˶�����״̬Ϊ����һ�����rear
	if ((Q.rear + 1) % Q.maxsize == Q.front)
		return True;
	return False;
}

//�������
Status InsertQueue(Queue &Q, Elemtype e)
{
	if (isFullQueue(Q))
	{
		printf("��������,�޷�����");
		return ERROR;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % Q.maxsize;
	return OK;
}

//������
Elemtype DeQueue(Queue& Q)
{
	Elemtype e;
	if (isEmptyQueue(Q))
	{
		printf("�ն���");
		return ERROR;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % Q.maxsize;
	return e;
}

//��������
void TravQueue(Queue &Q)
{
	if (Q.front == Q.rear)
	{
		printf("�˶���Ϊ��\n");
	}
	else
	{
		Elemtype p = Q.front;
		do
		{
			printf("%d\t", Q.base[p]);
			p = (p + 1) % Q.maxsize;
		} while (p != Q.rear);
	}
}


//��ʼ����ֵ����
Queue Initinteract()
{
	printf("welcome to the Sequence Queue\n");
	printf("��� ���� �Ƿ�ʼ�������У��ǻش� 1 ����ش�2\n ");
	int on;
	cin >> on;
	if (on != 1 && on != 2)
	{
		printf("����ֵ���Ϸ�\n");
		exit(0);
	}
	if (on == 2)
		exit(0);
	else
	{
		system("cls");
		printf("���������봴��������\n");
		int cap;
		cin >> cap;
		Queue Q;
		int tag2 = 0;
		tag2 = InitQueue(Q, cap + 1);
		if (tag2 != 1)
			exit(0);
		printf("˳��ѭ�����д������\n");
		printf("��ʼ����%d����", cap);
		int i = 1;
		while (i <= cap)
		{
			printf("��%d��:", i);
			cin >> Q.base[i - 1];
			Q.rear = Q.rear + 1;
			system("cls");
			i++;
		}
		return Q;
	}
}
