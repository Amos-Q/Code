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

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
//销毁
void BinaryTreeDestory(BTNode* root);
//节点数
int BinaryTreeSize(BTNode* root);
//叶子节点数
int BinaryTreeLeafSize(BTNode* root);
//第K层数
int BinaryTreeLevelKSize(BTNode* root, int k);
//查询
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// 遍历
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
void testTree();