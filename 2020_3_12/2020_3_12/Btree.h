#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
//����
void BinaryTreeDestory(BTNode* root);
//�ڵ���
int BinaryTreeSize(BTNode* root);
//Ҷ�ӽڵ���
int BinaryTreeLeafSize(BTNode* root);
//��K����
int BinaryTreeLevelKSize(BTNode* root, int k);
//��ѯ
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// ����
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);

// �������
void BinaryTreeLevelOrder(BTNode* root);
void testTree();