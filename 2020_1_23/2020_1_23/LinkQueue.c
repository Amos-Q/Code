#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkQueue.h"

Status InitQueue(LinkQueue & Q)
{
	//����һ���ն���Q
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

Status DetroyQueue(LinkQueue & Q)
{
	//����һ������
	while (Q.front) {
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

Status ClearQueue(LinkQueue & Q)
{	//���һ������
	while (Q.front->next) {
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	Q.front->next = NULL;
	return OK;
}

Status QueueEmpty(LinkQueue Q)
{	//�ж϶����Ƿ�Ϊ��
	if (Q.front == Q.rear) return TRUE;
	return FALSE;
}

int QueueLenth(LinkQueue Q)
{	//���ض��г���	
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
{	//����Ԫ��eΪQ���µĶ�βԪ��
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)return ERROR;
	p->next = NULL;
	p->data = e;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status DeQueue(LinkQueue & Q, QElemType & e)
{//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK
	if (Q.front == Q.rear)return ERROR;
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));   //�˴�Ϊ��Ҫ��p����ռ䣿
	p = Q.front->next;								//Q.front->next�Ѿ�������ڴ�ռ�
	e = p->data;									//p = Q.front->next֮��
	Q.front->next = p->next;						//free��p��free������һ�飿
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
