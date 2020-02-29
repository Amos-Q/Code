#define _CRT_SECURE_NO_WARNINGS 1
#include "tree.h"

ChainBinTree *BinTreeInit(ChainBinTree *node) //初始化二叉树根结点 
{
	if (node != NULL) //若二叉树根结点不为空 
		return node;
	else
		return NULL;
}

int BinTreeAddNode(ChainBinTree *bt, ChainBinTree *node, int n) //添加数据到二叉树 
//bt为父结点，node为子结点,n=1表示添加左子树，n=2表示添加右子树 
{
	if (bt == NULL)
	{
		printf("父结点不存在，请先设置父结点!\n");
		return 0;
	}
	switch (n)
	{
	case 1: //添加到左结点 
		if (bt->left) //左子树不为空 
		{
			printf("左子树结点不为空!\n");
			return 0;
		}
		else
			bt->left = node;
		break;
	case 2://添加到右结点
		if (bt->right) //右子树不为空 
		{
			printf("右子树结点不为空!\n");
			return 0;
		}
		else
			bt->right = node;
		break;
	default:
		printf("参数错误!\n");
		return 0;
	}
	return 1;
}


ChainBinTree *BinTreeLeft(ChainBinTree *bt) //返回左子结点 
{
	if (bt)
		return bt->left;
	else
		return NULL;
}
ChainBinTree *BinTreeRight(ChainBinTree *bt) //返回右子结点 
{
	if (bt)
		return bt->right;
	else
		return NULL;
}


int BinTreeIsEmpty(ChainBinTree *bt) //检查二叉树是否为空，为空则返回1,否则返回0 
{
	if (bt)
		return 0;
	else
		return 1;
}
int BinTreeDepth(ChainBinTree *bt) //求二叉树深度
{
	int dep1, dep2;
	if (bt == NULL)
		return 0; //对于空树，深度为0
	else
	{
		dep1 = BinTreeDepth(bt->left); //左子树深度 (递归调用)
		dep2 = BinTreeDepth(bt->right); //右子树深度 (递归调用)
		if (dep1 > dep2)
			return dep1 + 1;
		else
			return dep2 + 1;
	}
}