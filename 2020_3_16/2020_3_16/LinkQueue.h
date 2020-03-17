#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include "BinaryTree.h"

/** 链队列的节点定义，包含一个数据域和下一个节点的指针 */
typedef struct QueueNode {
	BiTreeNode* data;
	struct QueueNode* next;
}QueueNode;

/**  链队列的定义，包含队头和队尾指针*/
typedef struct {
	QueueNode* front;
	QueueNode* rear;
}LinkQueue;

LinkQueue* InitQueue();/** 链队列的初始化 */
void DestoryQueue(LinkQueue*);/** 销毁队列 */
void EnQueue(LinkQueue*, BiTreeNode*);/** 入队 */
BiTreeNode* DeQueue(LinkQueue*);/** 出队 */