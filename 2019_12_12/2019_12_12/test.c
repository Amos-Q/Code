#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;
//初始化单链表
Status InitLinkList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(LNode));
	if (*L == NULL) {
		printf("内存分配失败");
		return 0;
	}
	(*L)->next = NULL;
	return OK;
}
//前插法创建单链表
Status CreateList_H(LinkList L, int n) {
	LNode *p;
	ElemType elem, i;
	printf("请按递增顺序输入元素：\n");
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &elem);
		p->data = elem;
		p->next = L->next;
		L->next = p;
	}
	p->next == NULL;
	return OK;
}
//后插法创建单链表
Status CreateList_T(LinkList L, int n) {
	LNode *p, *r;
	r = L;
	ElemType elem, i;
	printf("请按递增顺序输入元素：\n");
	for (i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &elem);
		p->data = elem;
		p->next = NULL;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return OK;
}
//插入元素
Status InsertLinkList(LinkList L, int i, ElemType e) {
	LNode *p, *s;
	p = L;
	ElemType j = 0;
	while (p&&j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return ERROR;
	s = (LinkList)malloc(sizeof(LinkList));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
//删除元素
Status DeleteLinkList(LinkList L, int i) {
	LNode *p, *q;
	p = L;
	ElemType j = 0;
	while (p->next && (j < i - 1)) {
		p = p->next;
		j++;
	}
	if (!(p->next) || (j > i - 1)) return ERROR;
	q = p->next;
	p->next = q->next;
	free(q);
	return OK;
}

//遍历单链表
void TranverseLinkList(LinkList L)
{
	LNode *p;
	p = (L)->next;
	if (p == NULL)
	{
		printf("nil\n");
		return;
	}
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
//插入排序
void InsertSort(LinkList L)
{
	if ((L->next == NULL) || (L->next->next == NULL))
	{
		return;
	}

	LNode*head, *p1, *prep1, *p2, *prep2, *temp;
	head = L;
	prep1 = head->next;
	p1 = prep1->next;
	bool flag;
	while (p1 != NULL)
	{
		flag = true;
		temp = p1;
		for (prep2 = head, p2 = prep2->next; p2 != p1; prep2 = prep2->next, p2 = p2->next)
		{

			if (p2->data > p1->data)
			{
				p1 = p1->next;
				prep1->next = p1;
				prep2->next = temp;
				temp->next = p2;
				flag = false;
				break;
			}
		}
		if (flag)
		{
			prep1 = prep1->next;
			p1 = p1->next;
		}
	}
}
int main() {
	LinkList L;
	InitLinkList(&L);
	int Number;
	printf("请输入元素的个数:\n");
	scanf("%d", &Number);
	CreateList_T(L, Number);
	InsertLinkList(L, 4, 24);
	printf("添加元素后的序列:");
	InsertSort(L);
	TranverseLinkList(L);
	DeleteLinkList(L, 3);
	printf("删除元素后的序列:");
	TranverseLinkList(L);
	return 0;
}