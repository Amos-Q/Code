#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


typedef struct tree
{
	char parent;
	struct tree* lchild;
	struct tree* rchild;
}tree,*btree;


void Creattree(btree *t)
{
	char ch = 0;
	ch = getchar();
	if (ch == '#')
		*t = NULL;
	else
	{
		*t = (btree)malloc(sizeof(tree));
		(*t)->parent = ch;
		Creattree(&((*t)->lchild));
		Creattree(&((*t)->rchild));
	}
}


void Inorder(btree root)
{
	if (root != NULL)
	{
		Inorder(root->lchild);
		printf("%c ", root->parent);
		Inorder(root->rchild);
	}
}


int main()
{
	btree t;
	Creattree(&t);
	Inorder(t);
	system("pause");
	return 0;
}




int maxDepth(struct TreeNode* root){
    if(root == NULL)
    return 0;
    int l= maxDepth(root->left);
    int r= maxDepth(root->right);
    return l>r?l+1:r+1;
}


bool isBalanced(struct TreeNode* root){
    if(root == NULL)
    return true;
    int lnum = maxDepth(root->left);
    int rnum = maxDepth(root->right);
    printf("<%d %d>",lnum,rnum);
    return abs(lnum-rnum) < 2 && isBalanced(root->left) && isBalanced(root->right);
}


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL)
    return true;
    if(p && q == NULL)
    return false;
    if(q && p == NULL)
    return false;
    if(p->val == q->val)
    {
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
    return false;
}


bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    if(!s && !t )
    return true;
    else if(!s || !t)
    return false;
    return isSameTree(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);
}



