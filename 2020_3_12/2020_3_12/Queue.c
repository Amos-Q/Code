#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
//��ʼ��
void QueueInit(Queue *q)
{
	assert(q);
	q->_front = q->_tail = NULL;
}
//����
void QueueDestory(Queue *q)
{
	assert(q);
	sqQueue* cur = q->_front;
	while (cur)
	{
		sqQueue* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_tail = NULL;
}
//�ж϶����Ƿ�Ϊ��,0Ϊ�գ�1��Ϊ��
int QueueEmpty(Queue *q)
{
	return q->_front == NULL ? 0 : 1;
}
//���
void QueuePush(Queue *q, ElemType x)
{
	assert(q);
	sqQueue* node = (sqQueue *)malloc(sizeof(sqQueue));
	node->_data = x;
	node->_next = NULL;
	if (q->_tail == NULL)
	{
		q->_tail = q->_front = node;
	}
	else
	{
		q->_tail->_next = node;
		q->_tail = node;
	}
}
//����
void QueuePop(Queue *q)
{
	assert(q);
	sqQueue* front = q->_front->_next;
	free(q->_front);
	q->_front = front;

	if (front == NULL)
		q->_tail = NULL;
}

//����ͷԪ��
ElemType QueueFront(Queue *q)
{
	assert(q);
	ElemType tmp = q->_front->_data;
	return tmp;
}
////��ӡ
//void Queueprint(Queue *q)
//{
//	sqQueue *tmp = q->_front;
//	while (tmp)
//	{
//		printf("%d ", tmp->_data);
//		tmp = tmp->_next;
//	}
//	printf("\n");
//}
