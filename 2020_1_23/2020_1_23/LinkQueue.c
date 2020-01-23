#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkQueue.h"

Status InitQueue(LinkQueue & Q)
{
	//构造一个空队列Q
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

Status DetroyQueue(LinkQueue & Q)
{
	//销毁一个队列
	while (Q.front) {
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

Status ClearQueue(LinkQueue & Q)
{	//清除一个队列
	while (Q.front->next) {
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	Q.front->next = NULL;
	return OK;
}

Status QueueEmpty(LinkQueue Q)
{	//判断队列是否为空
	if (Q.front == Q.rear) return TRUE;
	return FALSE;
}

int QueueLenth(LinkQueue Q)
{	//返回队列长度	
	QueuePtr p;
	p = Q.front;
	int i = 0;
	while (!(p == Q.rear)) {
		i++;
		p = p->next;
	}
	return i;
}

Status GetHead(LinkQueue Q, QElemType & e)
{
	//
	if (Q.front == Q.rear)return ERROR;
	e = Q.front->next->data;
	return OK;
}

Status EnQueue(LinkQueue & Q, QElemType e)
{	//插入元素e为Q的新的队尾元素
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)return ERROR;
	p->next = NULL;
	p->data = e;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status DeQueue(LinkQueue & Q, QElemType & e)
{//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK
	if (Q.front == Q.rear)return ERROR;
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));   //此处为何要给p申请空间？
	p = Q.front->next;								//Q.front->next已经申请过内存空间
	e = p->data;									//p = Q.front->next之后
	Q.front->next = p->next;						//free（p）free的是哪一块？
	if (Q.rear == p)Q.rear = Q.front;
	free(p);
	return OK;
}

Status QueueTraverse(LinkQueue Q, Status(*visit)(QueuePtr))
{
	QueuePtr p;
	p = Q.front;
	while (p->next)
	{
		p = p->next;
		if (!(visit(p)))return ERROR;
	}
	return OK;
}
