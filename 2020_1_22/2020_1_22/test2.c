#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>

#define Max 100

typedef struct Node
{
	int data;
	struct Node * pNext;
}NODE, *PNODE;

typedef struct Stack
{
	PNODE Bottom;
	PNODE Top;
}STACK, *PSTACK;

void create(PSTACK pS)
{
	pS->Top = (PNODE)malloc(sizeof(NODE));
	pS->Bottom = pS->Top;
	pS->Top->pNext = NULL;
}

int isEmpty(PSTACK pS)
{
	int n = 0;
	if (pS->Bottom == pS->Top)
		n = 1;
	else
		n = 0;
	return n;
}

void push(PSTACK pS, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (pNew != NULL)
	{
		pNew->data = val;
		pNew->pNext = pS->Top;
		pS->Top = pNew;
	}
}

void pop(PSTACK pS)
{
	if (pS->Top != pS->Bottom)
	{
		PNODE p = pS->Top;
		pS->Top = p->pNext;
		free(p);
	}
}

void clean(PSTACK pS)
{
	if (pS->Top != pS->Bottom)
	{
		PNODE p = pS->Top;
		PNODE q = NULL;
		while (p != pS->Bottom)
		{
			q = p->pNext;
			free(p);
			p = q;
		}
		pS->Bottom = pS->Top;
	}
}

int main()
{
	PSTACK pS = (PSTACK)malloc(sizeof(STACK));
	create(pS);

	char val;
	int count, i = 0;
	int r[Max];

	scanf("%d", &count);
	if (count <= 0 || count > 100)
		return 0;
	fflush(stdin);

	for (i = 0; i < count; i++)
	{
		while (scanf("%c", &val))
		{
			if (val == '\n')
				break;
			if (val == ' ')
			{
				continue;
			}
			else
			{
				if (val == ']')
				{
					if (pS->Top->data == '[')
						pop(pS);
					else
						push(pS, val);
				}
				else if (val == ')')
				{
					if (pS->Top->data == '(')
						pop(pS);
					else
						push(pS, val);
				}
				else
					push(pS, val);
			}
		}
		r[i] = isEmpty(pS);
		clean(pS);
	}

	for (i = 0; i < count; i++)
	{
		if (r[i] == 0)
			printf("No\n");
		else
			printf("Yes\n");
	}

	return 0;
}