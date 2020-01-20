#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	char * base;
	char * top;
	int stacksize;
}stack;

void initstack(stack*s)//ջ�ĳ�ʼ������
{
	s->base = (char*)malloc(sizeof(char));
	if (!s->base)//����ڴ��Ƿ����ɹ�
	{
		exit(0);
	}
	s->base = s->top;
	s->stacksize = 10;
}

void push(stack*s, char x)//��ջ����
{
	if (s->top - s->base >= s->stacksize)//�ȼ���Ƿ�������
	{
		s->base = (char*)realloc(s->base, (s->stacksize + 10) * sizeof(char));//��������������10���ڴ�ռ䣨��̬���ݣ�
		if (!s->base)//����ڴ��Ƿ����ɹ�
		{
			exit(0);
		}
		s->stacksize = s->stacksize + 10;
		s->top = s->base + 10;
	}
	*s->top = x;
	s->top++;
}

int main()
{
	stack * s = (stack*)malloc(sizeof(stack));
	initstack(s);
	char c;
	printf("�����������������{[]()}#,#��־�����������");
	c = getchar();
	push(s, c);
	while (c != '#')
	{
		c = getchar();
		if (c == '{' || c == '(' || c == '[')
		{
			push(s, c);
		}
		if (c == '}' || c == ')' || c == ']')
		{
			if (s->base == s->top)
			{
				push(s, c);
			}
			if (c == '}')
			{
				if (*--(s->top) == '{')//��������£�*--(s->top)��������ջ��Ԫ�أ�������������Ѿ�ʵ����top--�������ʵ����pop���ܡ�����ʵ������û��ɾ��ջ�е�Ԫ�أ�ֻ���ƶ�topָ�룬���ϵĸ���Ԫ�ء�
				{
					//top--�Ѿ�ʵ�֣����ﲻ��Ҫ�κβ���
				}
				else
				{
					push(s, c);
				}
			}
			if (c == ')')
			{

				if (*--(s->top) == '(')
				{

				}
				else
				{
					push(s, c);
				}
			}
			if (c == ']')
			{
				if (*--(s->top) == '[')
				{

				}
				else
				{
					push(s, c);
				}
			}
		}
	}
	if (s->base == s->top)
	{
		printf("���Ǹ�������");
	}
	else
	{
		printf("������۾���̫��");
	}
	return 0;
}
