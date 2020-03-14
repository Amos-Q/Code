#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
#include "BTree.h"

typedef BTNode* ElemType;//定义数据类型
typedef struct sqQueue
{
	ElemType _data;
	struct sqQueue* _next;
}sqQueue;
typedef struct Queue
{
	sqQueue* _front;
	sqQueue* _tail;
}Queue;

void QueueInit(Queue *q);
void QueueDestory(Queue *q);
int QueueEmpty(Queue *q);
void QueuePush(Queue *q, ElemType x);
void QueuePop(Queue *q);
ElemType QueueFront(Queue *q);
