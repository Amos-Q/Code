#define _CRT_SECURE_NO_WARNINGS 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


struct Student
{
	unsigned long	ID;
	char			Name[21];
	float			Score;
};

struct Node
{
	struct Student	data;
	struct Node *	next;
};

int Count = 0;
struct Node * H = NULL;


struct Node * Insert(struct Node * Head, struct Node * pNode);
void Display(struct Node * Head);
void Add();

void Search(struct Node * Head);
void Change(struct Node * Head);