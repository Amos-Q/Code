#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//typedef struct tree
//{
//	char root;
//	btree lchild;
//	btree rchild;
//}tree,*btree;
//
//void Creattree(btree *t)
//{
//	char ch = 0;
//	ch = getchar();
//	if (ch == '#')
//		*t = NULL;
//	else
//	{
//		*t = (btree)malloc(sizeof(tree));
//		(*t)->root = ch;
//		Creattree(&((*t)->lchild));
//		Creattree(&((*t)->rchild));
//	}
//}
//
//void Inorder(btree root)
//{
//	if (root != NULL)
//	{
//		Inorder(root->lchild);
//		printf("%c", root);
//		Inorder(root->rchild);
//	}
//}
//
//int main()
//{
//	btree t;
//	Creattree(&t);
//	Inorder(t);
//	system("pause");
//	return 0;
//}

//#include <math.h>
//int main(void)
//{
//	int result1;
//	int x = 3;
//	result1 = log2(x);
//	printf("%d   ", result1);
//	x = 5;
//	result1 = log2(x);
//	printf("%d   ",result1);
//	x = 15;
//	result1 = log2(x);
//	printf("%d   ", result1);
//	system("pause");
//	return 0;
//}

#define bool int
#define true
#define false

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int treehight(struct TreeNode* root)
{
	if (root != NULL)
	{
		return treehight(root->left) + 1;
		return treehight(root->right) + 1;
	}
	else
		return 0;
}

bool isBalanced(struct TreeNode* root) {
	int lnum = log2(treehight(root->left));
	int rnum = log2(treehight(root->right));
	if (abs(lnum - rnum) <= 1)
		return true;
	else
		return false;
}

int main()
{
	struct TreeNode* root;

	isBalanced(root);
}