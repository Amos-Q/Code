#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

/** �����еĳ�ʼ�� */
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

/** �����е����٣�ע���Ƚ�ȥ���Ƕ���ͷ�����ȥ���Ƕ���β */
void DestoryQueue(LinkQueue* queue)
{
	while (queue->front)
	{
		queue->rear = queue->front->next;
		free(queue->front);
		queue->front = queue->rear;
	}
}

/** ��� */
void EnQueue(LinkQueue* queue, BiTreeNode* node)
{
	QueueNode* queueNode = (QueueNode*)malloc(sizeof(QueueNode));
	queueNode->data = node;
	queueNode->next = NULL;
	queue->rear->next = queueNode;
	queue->rear = queueNode;
}

/** ���� */
BiTreeNode* DeQueue(LinkQueue* queue)
{
	if (queue->front == queue->rear)//����Ϊ��
		return NULL;
	QueueNode* p = queue->front->next;
	BiTreeNode* node = p->data;
	queue->front = p;
	return node;
}
void LayerOrderBiTree(struct BiTreeNode* root)
{
	int curLayerCount = 0; //��ǰ���еĽڵ���
	int nextLayerCount = 0; //��һ���еĽڵ���
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
		if (curLayerCount == 0)//һ���Ѿ��������
		{
			curLayerCount = nextLayerCount;
			nextLayerCount = 0;
			printf("\n");
		}
	}
}