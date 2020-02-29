#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include <stdlib.h> 
#define QUEUE_MAXSIZE 50
typedef char DATA;       //定义元素类型 
typedef struct ChainTree  //定义二叉树结点类型 
{
	DATA data;  //元素数据
	struct ChainTree *left; //左子树结点指针
	struct ChainTree *right;    //右子树结点指针
}ChainBinTree;