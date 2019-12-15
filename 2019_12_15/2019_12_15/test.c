#define _CRT_SECURE_NO_WARNINGS 1
//DoubleCircleLinkList.c
#include "LinkList.h"

int LinkInit(Node **l)
{
	*l = (Node *)malloc(sizeof(Node) * 1);
	if (NULL == *l)
	{
		return FAILURE;
	}

	(*l)->next = (*l);
	(*l)->prior = (*l);

	return SUCCESS;
}

int LinkInsert(Node *l, int n, ElemType e)
{
	Node *p = l;
	int k = 1;

	if (NULL == l)
	{
		return FAILURE;
	}

	if (n > LinkLength(l) + 1)
	{
		return FAILURE;
	}

	while (k < n)
	{
		p = p->next;
		k++;
	}


	if (k > n)
	{
		return FAILURE;
	}

	Node *q = (Node *)malloc(sizeof(Node) * 1);
	if (NULL == q)
	{
		return FAILURE;
	}


	q->data = e;
	q->prior = p;
	q->next = p->next;
	p->next = q;
	if (l != q->next)
	{
		q->next->prior = q;
	}

	return SUCCESS;
}

int LinkTraverse(Node *l, void(*p)(ElemType))
{
	if (NULL == l)
	{
		return FAILURE;
	}
	Node *q = l;

	while (q->next != l)
	{
		q = q->next;
		p(q->data);
	}

	return SUCCESS;
}

int LinkLength(Node *l)
{
	if (NULL == l)
	{
		return FAILURE;
	}

	int len = 0;
	Node *p = l->next;

	while (p != l)
	{
		len++;
		p = p->next;
	}

	return len;
}

int LinkEmpty(Node *l)
{
	return (l->next == l && l->prior == l) ? TRUE : FALSE;
}

int GetElem(Node *l, int p, ElemType *e)
{
	if (NULL == l || p < 1)
	{
		return FAILURE;
	}

	Node *q = l->next;
	int i;

	for (i = 1; i < p && q != l; i++)
	{
		q = q->next;
	}

	if (q == l)
	{
		return FAILURE;
	}

	*e = q->data;

	return SUCCESS;
}

int LocateElem(Node *l, ElemType e, int(*p)(ElemType, ElemType))
{
	if (NULL == l)
	{
		return FAILURE;
	}

	Node *q = l->next;
	int len = 1;

	while (q != l)
	{
		if (p(e, q->data) == TRUE)
		{
			return len;
		}
		q = q->next;
		len++;
	}

	return FAILURE;
}

int LinkDelete(Node *l, int p, ElemType *e)
{
	int k = 1;
	Node *q = l;

	if (l == NULL)
	{
		return FAILURE;
	}

	if (p > LinkLength(l) + 1)
	{
		return FAILURE;
	}

	while (k < p)
	{
		q = q->next;
		k++;
	}

	if (k > p)
	{
		return FAILURE;
	}

	Node *n = q->next;
	*e = n->data;
	q->next = n->next;


	n->next->prior = q;
	free(n);

	return SUCCESS;
}

int LinkClear(Node *l)
{
	if (NULL == l)
	{
		return FAILURE;
	}

	Node *p = l->next;

	while (p != l)
	{
		l->next = p->next;
		//p->next->prior = l;
		free(p);
		p = l->next;
	}

	l->prior = l;   //**

	return SUCCESS;
}

int LinkDestroy(Node **l)
{
	if (l == NULL)
	{
		return FAILURE;
	}
	free(*l);
	(*l) = NULL;

	return SUCCESS;
}

#if 0
int LinkReverse(Node **l)
{
	if (NULL == l)
	{
		return FAILURE;
	}

	/*Node *p = l->next;
	l->next = NULL;
	while (p != NULL)
	{
		Node *q = p;
		p = p->next;
		q->next = l->next;
		q->prior = l;
		l->next = q;
	}*/

	Node *p = (*l)->next;
	Node *tmp;

	if (p == NULL)
	{
		return FAILURE;
	}

	if (p->next == NULL)
	{
		return FAILURE;
	}

	printf("xxxxx\n");
	while (p->next != NULL)
	{
		tmp = p->next;
		p->next = p->prior;
		p->prior = tmp;
		p = p->next;
	}

	printf("%d\n", p->data);
	tmp = p->next;
	p->next = p->prior;
	p->prior = (*l);

	(*l)->next = p;


	return SUCCESS;
}
#endif
