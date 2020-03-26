#define _CRT_SECURE_NO_WARNINGS 1
#include "Student.h"

struct Node * Insert(struct Node * Head, struct Node * pNode)
{
	struct Node * p = Head, *q = Head;

	if (p == NULL)
	{
		Head = pNode;

	}
	else
	{
		while (p)
		{
			if (pNode->data.Score < p->data.Score)
			{
				q = p;
				p = p->next;
			}
			else
			{
				if (p == Head)
				{
					Head = pNode;
					pNode->next = p;

				}
				else
				{
					q->next = pNode;
					pNode->next = p;

				}
				break;
			}
		}
		if (p == NULL)
		{
			q->next = pNode;
		}
	}
	return Head;
}

void Display(struct Node * Head)
{
	if (Head == NULL)
	{
		printf("当前没有学生成绩信息！\n");
		return;
	}

	struct Node * p = Head;
	for (int i = 0; i < Count; i++)
	{
		printf("学号：%lu\t姓名：%s\t成绩：%.1f\n", p->data.ID, p->data.Name, p->data.Score);
		p = p->next;
	}
}

void Add()
{
	unsigned long ID;
	char Name[21];
	float Score;
	struct Node * Head = NULL;

	printf("请输入学号：");
	scanf("%lu", &ID);

	while (ID)
	{
		printf("请输入姓名：");
		scanf("%s", Name);
		printf("请输入成绩：");
		scanf("%f", &Score);

		struct Node * pNew = (struct Node *) malloc(sizeof(struct Node));
		pNew->data.ID = ID;
		strcpy(pNew->data.Name, Name);
		pNew->data.Score = Score;
		pNew->next = NULL;

		Count++;

		Head = Insert(Head, pNew);

		printf("请输入学号：");
		scanf("%lu", &ID);
	}

	H = Head;
}


void Search(struct Node * Head)
{
	char Name[21];
	int i = 0;
	struct Node * p = Head;
	if (p == NULL)
	{
		printf("当前没有学生成绩信息！\n");
		return;
	}
	printf("请输入姓名：");
	scanf("%s", Name);
	while (p)
	{
		for (i = 0; Name[i] != 0; i++)
		{
			if (Name[i] != p->data.Name[i])
				break;
		}
		if (Name[i])
			p = p->next;
		else
		{
			printf("%.2f\n", p->data.Score);
			return;
		}

	}
	if (p == NULL)
	{
		printf("无当前学生信息\n");
		return;
	}

}

void Change(struct Node * Head)
{
	unsigned long ID;
	struct Node *m = Head, *n = Head, *d = Head;
	float Score;
	printf("请输入学号：");
	scanf("%lu", &ID);
	printf("请输入成绩：");
	scanf("%f", &Score);
	while (m)
	{
		if (ID == m->data.ID)
		{
			if (m == Head)
			{
				m->data.Score = Score;
				Head = m->next;

			}
			else if (m->next == NULL)
			{
				n->next = NULL;
				m->data.Score = Score;
			}
			else
			{
				d = m->next;
				m->data.Score = Score;
				n->next = d;
			}
			Head = Insert(Head, m);
			H = Head;
			return;
		}
		else
		{
			n = m;
			m = m->next;
		}
	}
	if (m == NULL)
		printf("无当前学生信息\n");
	return;
}