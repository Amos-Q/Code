#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"

bintree creattree()
{
	int ch;
	bintree t;
	cin >> ch;
	if (0 == ch)
	{
		t = NULL;
	}
	else
	{
		t = (struct tree*)malloc(sizeof(struct tree));
		t->data = ch;
		t->lchild = creattree();
		t->rchild = creattree();
	}
	return t;
}

void pre_display(bintree head)
{
	if (head)
	{
		cout << head->data << ' ';
		pre_display(head->lchild);
		pre_display(head->rchild);

	}

}
void inorder_display(bintree head)
{
	if (head)
	{
		inorder_display(head->lchild);
		cout << head->data << ' ';
		inorder_display(head->rchild);
	}
}

int main()
{
	bintree head;
	bintree p;
	head = NULL;
	p = creattree();
	pre_display(p);
	system("PAUSE");
}