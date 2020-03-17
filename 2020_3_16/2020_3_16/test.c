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
	printf("ʹ�����򴴽���������#��ʾ�սڵ㣬����������������ݣ�\n");
	BiTreeNode* root = CreateBinaryTree();

	printResult("�������", LayerOrderBiTree, root);

	return 0;
}