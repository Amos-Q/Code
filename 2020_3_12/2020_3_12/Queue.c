#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
//初始化
void QueueInit(Queue *q)
{
	assert(q);
	q->_front = q->_tail = NULL;
}
//销毁
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
//判断队列是否为空,0为空，1不为空
int QueueEmpty(Queue *q)
{
	return q->_front == NULL ? 0 : 1;
}
//入队
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
//出队
void QueuePop(Queue *q)
{
	assert(q);
	sqQueue* front = q->_front->_next;
	free(q->_front);
	q->_front = front;

	if (front == NULL)
		q->_tail = NULL;
}

//出队头元素
ElemType QueueFront(Queue *q)
{
	assert(q);
	ElemType tmp = q->_front->_data;
	return tmp;
}
////打印
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
