#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"

int main()
{
	BinTree T = CreateBinTree();//输入一个元素就回一次车，他就会层序给你排好，建立一个完全二叉树
	SequenceTraversal(T);
	return 0;
}