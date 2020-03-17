#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

/** 链队列的初始化 */
LinkQueue* InitQueue()
{
	LinkQueue* queue = (LinkQueue*)malloc(sizeof(LinkQueue));
	if (!queue)
	{
		printf("init queue error!\n");
		exit(0);
	}
	queue->front = (QueueNode*)malloc(sizeof(QueueNode));
	queue->front->next = NULL;
	queue->rear = queue->front;
	return queue;
}

/** 链队列的销毁，注意先进去的是队列头，后进去的是队列尾 */
void DestoryQueue(LinkQueue* queue)
{
	while (queue->front)
	{
		queue->rear = queue->front->next;
		free(queue->front);
		queue->front = queue->rear;
	}
}

/** 入队 */
void EnQueue(LinkQueue* queue, BiTreeNode* node)
{
	QueueNode* queueNode = (QueueNode*)malloc(sizeof(QueueNode));
	queueNode->data = node;
	queueNode->next = NULL;
	queue->rear->next = queueNode;
	queue->rear = queueNode;
}

/** 出队 */
BiTreeNode* DeQueue(LinkQueue* queue)
{
	if (queue->front == queue->rear)//队列为空
		return NULL;
	QueueNode* p = queue->front->next;
	BiTreeNode* node = p->data;
	queue->front = p;
	return node;
}
void LayerOrderBiTree(struct BiTreeNode* root)
{
	int curLayerCount = 0; //当前层中的节点数
	int nextLayerCount = 0; //下一层中的节点数
	struct Queue* queue = InitQueue();
	EnQueue(queue, root);
	curLayerCount++;
	struct BiTreeNode* p;
	while (p = DeQueue(queue))
	{
		curLayerCount--;
		printf("%c ", p->val);
		if (p->left)
		{
			EnQueue(queue, p->left);
			nextLayerCount++;
		}
		if (p->right)
		{
			EnQueue(queue, p->right);
			nextLayerCount++;
		}
		if (curLayerCount == 0)//一层已经遍历完毕
		{
			curLayerCount = nextLayerCount;
			nextLayerCount = 0;
			printf("\n");
		}
	}
}