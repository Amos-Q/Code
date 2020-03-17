#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>
#include "Stack.h"

void printResult(char *msg, void(*p)(BiTreeNode*), BiTreeNode* node)
{
	printf("\n---------%s---------\n", msg);
	p(node);
	printf("\n---------%s---------\n", msg);
}

int main()
{
	printf("使用先序创建二叉树，#表示空节点，请输入二叉树的数据：\n");
	BiTreeNode* root = CreateBinaryTree();

	printResult("层序遍历", LayerOrderBiTree, root);

	return 0;
}