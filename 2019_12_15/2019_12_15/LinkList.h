#pragma once
//DoubleCircleLinkLst.h
#ifndef _LINKLIST_H
#define _LINKLIST_H

#include <stdio.h>
#include <stdlib.h>

#define FAILURE    10000
#define SUCCESS    10001
#define TRUE       10002
#define FALSE      10003

typedef int ElemType;

struct node
{
	ElemType data;
	struct node *next;
	struct node *prior;
};

typedef struct node Node;

int LinkInit(Node **l);
int LinkInsert(Node *l, int n, ElemType e);
int LinkTraverse(Node *l, void(*p)(ElemType));
int LinkLength(Node *l);
int LinkEmpty(Node *l);
int GetElem(Node *l, int p, ElemType *e);
int LocateElem(Node *l, ElemType e, int(*p)(ElemType, ElemType));
int LinkDelete(Node *l, int p, ElemType *e);
int LinkClear(Node *l);
int LinkDestroy(Node **l);

#endif
