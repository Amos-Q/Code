#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	char * base;
	char * top;
	int stacksize;
}stack;

void initstack(stack*s)//栈的初始化函数
{
	s->base = (char*)malloc(sizeof(char));
	if (!s->base)//检测内存是否分配成功
	{
		exit(0);
	}
	s->base = s->top;
	s->stacksize = 10;
}

void push(stack*s, char x)//入栈函数
{
	if (s->top - s->base >= s->stacksize)//先检测是否发生上溢
	{
		s->base = (char*)realloc(s->base, (s->stacksize + 10) * sizeof(char));//若发生，则增加10个内存空间（动态扩容）
		if (!s->base)//检测内存是否分配成功
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
	printf("请输入测试用例（如{[]()}#,#标志输入结束）：");
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
				if (*--(s->top) == '{')//这里解释下，*--(s->top)很明显是栈顶元素，但是这个操作已经实现了top--。变相的实现了pop功能。所以实际上是没有删除栈中的元素，只是移动top指针，不断的覆盖元素。
				{
					//top--已经实现，这里不需要任何操作
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
		printf("你是个正常人");
	}
	else
	{
		printf("你可能眼睛不太好");
	}
	return 0;
}
