#define _CRT_SECURE_NO_WARNINGS 1
#include "main.h"

//初始化函数
Status InitQueue(Queue &Q, int capacity)
{
	Q.base = (Elemtype*)malloc(sizeof(Elemtype)*capacity);
	if (Q.base == NULL)
		return ERROR;
	Q.front = Q.rear = 0;
	Q.maxsize = capacity;
	return OK;
}

//判满函数
Status isEmptyQueue(Queue &Q)
{
	if (Q.front == Q.rear)
		return True;
	else return False;
}
//判空函数
Status isFullQueue(Queue  &Q)
{//此队列满状态为最后空一个格放rear
	if ((Q.rear + 1) % Q.maxsize == Q.front)
		return True;
	return False;
}

//进入队列
Status InsertQueue(Queue &Q, Elemtype e)
{
	if (isFullQueue(Q))
	{
		printf("队列已满,无法插入");
		return ERROR;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % Q.maxsize;
	return OK;
}

//出队列
Elemtype DeQueue(Queue& Q)
{
	Elemtype e;
	if (isEmptyQueue(Q))
	{
		printf("空队列");
		return ERROR;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % Q.maxsize;
	return e;
}

//遍历队列
void TravQueue(Queue &Q)
{
	if (Q.front == Q.rear)
	{
		printf("此队列为空\n");
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


//初始化赋值交互
Queue Initinteract()
{
	printf("welcome to the Sequence Queue\n");
	printf("你好 主人 是否开始创建队列，是回答 1 ，否回答2\n ");
	int on;
	cin >> on;
	if (on != 1 && on != 2)
	{
		printf("输入值不合法\n");
		exit(0);
	}
	if (on == 2)
		exit(0);
	else
	{
		system("cls");
		printf("请输入您想创建的容量\n");
		int cap;
		cin >> cap;
		Queue Q;
		int tag2 = 0;
		tag2 = InitQueue(Q, cap + 1);
		if (tag2 != 1)
			exit(0);
		printf("顺序循环队列创建完毕\n");
		printf("开始输入%d个数", cap);
		int i = 1;
		while (i <= cap)
		{
			printf("第%d个:", i);
			cin >> Q.base[i - 1];
			Q.rear = Q.rear + 1;
			system("cls");
			i++;
		}
		return Q;
	}
}
