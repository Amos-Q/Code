#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include "BinaryTree.h"

/** �����еĽڵ㶨�壬����һ�����������һ���ڵ��ָ�� */
typedef struct QueueNode {
	BiTreeNode* data;
	struct QueueNode* next;
}QueueNode;

/**  �����еĶ��壬������ͷ�Ͷ�βָ��*/
typedef struct {
	QueueNode* front;
	QueueNode* rear;
}LinkQueue;

LinkQueue* InitQueue();/** �����еĳ�ʼ�� */
void DestoryQueue(LinkQueue*);/** ���ٶ��� */
void EnQueue(LinkQueue*, BiTreeNode*);/** ��� */
BiTreeNode* DeQueue(LinkQueue*);/** ���� */