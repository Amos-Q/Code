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
	int front;//队头
	int rear;//队尾
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
/*尾插法入队*/
int EnQueue(SqQueue &Q, QElemType e)
{
	if ((Q.rear + 1) % MAX == Q.front) //队列满
	{
		return ERROR;
	}
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAX;
	return  OK;
}
/*出队*/
int DeQueue(SqQueue &Q, QElemType &e) {
	if (Q.front == Q.rear)
	{
		return ERROR;
	}
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAX;
	return OK;
}
/*纸牌*/
int Playing_Cards(SqQueue &Q, QElemType &e)
{
	int n, i = 1;
	int number = 1;//计数
	printf("请输入的数量:  ");
	scanf("%d", &n);
	printf("牌的编号为: ");
	for (i = 1; i <= n; i++)
	{
		EnQueue(Q, i);
		printf(" %d ", i);
	}
	printf("\n");
	while (1)
	{

		DeQueue(Q, e);
		printf("第 %d 次删除掉：%d ", number++, e);
		if (Q.front == Q.rear)
			break;
		DeQueue(Q, e);
		printf("%2d \n", e);
		if (Q.front == Q.rear)
			break;
		DeQueue(Q, e);     //新的第一张出队
		if (Q.front == Q.rear)
			break;
		if (Q.front + 1 == Q.rear&&n % 2 == 0)//保留偶数编号牌
			break;
		EnQueue(Q, e);//把牌放到整叠牌的最后
	}

	printf("从顶向底最后剩下:");
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

