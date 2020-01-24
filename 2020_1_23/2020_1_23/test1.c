#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1
#define MAX 100
typedef int QElemType;
typedef struct
{
	QElemType *data;
	int front;//��ͷ
	int rear;//��β
}SqQueue;

int InitiQueue(SqQueue &Q)
{
	Q.data = (QElemType*)malloc(MAX * sizeof(QElemType));
	if (!(Q.data))
	{
		exit(0);
	}
	Q.front = Q.rear = 0;
	return OK;
}
/*β�巨���*/
int EnQueue(SqQueue &Q, QElemType e)
{
	if ((Q.rear + 1) % MAX == Q.front) //������
	{
		return ERROR;
	}
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAX;
	return  OK;
}
/*����*/
int DeQueue(SqQueue &Q, QElemType &e) {
	if (Q.front == Q.rear)
	{
		return ERROR;
	}
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAX;
	return OK;
}
/*ֽ��*/
int Playing_Cards(SqQueue &Q, QElemType &e)
{
	int n, i = 1;
	int number = 1;//����
	printf("�����������:  ");
	scanf("%d", &n);
	printf("�Ƶı��Ϊ: ");
	for (i = 1; i <= n; i++)
	{
		EnQueue(Q, i);
		printf(" %d ", i);
	}
	printf("\n");
	while (1)
	{

		DeQueue(Q, e);
		printf("�� %d ��ɾ������%d ", number++, e);
		if (Q.front == Q.rear)
			break;
		DeQueue(Q, e);
		printf("%2d \n", e);
		if (Q.front == Q.rear)
			break;
		DeQueue(Q, e);     //�µĵ�һ�ų���
		if (Q.front == Q.rear)
			break;
		if (Q.front + 1 == Q.rear&&n % 2 == 0)//����ż�������
			break;
		EnQueue(Q, e);//���Ʒŵ������Ƶ����
	}

	printf("�Ӷ�������ʣ��:");
	if (Q.front + 1 == Q.rear)
	{
		printf("%2d ", Q.data[Q.rear - 1]);
		printf("%2d ", Q.data[Q.front - 1]);
	}
	else
		printf("%2d ", Q.data[Q.rear - 1]);
	printf("\n");
	return OK;
}

