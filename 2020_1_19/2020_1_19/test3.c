#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkStack.h"

int IsNumber(char c)
{
	return c >= '0' && c <= '9';
}

void NumberOperator(char c)
{
	printf("%c", c);
}

int IsLeft(char c)
{
	return c == '(';
}

int IsRight(char c)
{
	return c == ')';
}

int IsOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

typedef struct MYCHAR
{
	LinkNode node;
	char* p;
}MyChar;

// 创建MyChar
MyChar* CreateMyChar(char* p)
{
	MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
	mychar->p = p;
	return mychar;
}

void LeftOperate(LinkStack* stack, char *p)        // 左括号操作
{
	Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
}

int GetPrirority(char c)
{
	if (c == '*' || c == '/')
		return 2;
	if (c == '+' || c == '-')
		return 1;

	return 0;
}

void RightOperator(LinkStack* stack)
{
	// 先判断栈中有没有元素
	while (Size_LinkStack(stack) > 0)
	{
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		// 如果匹配到左括号
		if (IsLeft(*(mychar->p)))
		{
			Pop_LinkStack(stack);
			break;
		}
		printf("%c", *(mychar->p));         // 输出
		Pop_LinkStack(stack);               // 弹出

	}
}

void OperatorOperate(LinkStack* stack, char* p)
{
	// 先取出栈顶的符号

	MyChar* mychar = (MyChar*)Top_LinkStack(stack);
	if (mychar == NULL)
	{
		Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
		return;
	}
	// 如果栈顶优先级低于当前字符的优先级，直接入栈
	if (GetPrirority(*(mychar->p)) < GetPrirority(*p))
	{
		Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
	}
	else
	{
		while (Size_LinkStack(stack) > 0)
		{
			MyChar* mychar2 = (MyChar*)Top_LinkStack(stack);
			if (GetPrirority(*(mychar2->p) < GetPrirority(*p)))
			{
				Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
				break;
			}
			printf("%c", *(mychar2->p));          // 输出
			Pop_LinkStack(stack);                 // 弹出
			free(mychar2);
		}

	}

}

int main()
{
	char str[50] = "8+(3-1)*5";
	char *p = str;

	LinkStack* stack = Init_LinkStack();

	while (*p != '\0')
	{

		if (IsNumber(*p))              // 如果是数字
		{
			NumberOperator(*p);        // 输出数字（数字入队列)
		}

		if (IsLeft(*p))
		{
			LeftOperate(stack, p);     // 如果遇到左括号，直接进栈
		}

		if (IsRight(*p))               // 如果遇到右括号              
		{
			RightOperator(stack);      // 右括号操作
		}

		if (IsOperator(*p))            // 如果遇到运算符
		{
			OperatorOperate(stack, p);
		}

		// 如果遇到运算符号
		p++;
	}

	while (Size_LinkStack(stack) > 0)
	{
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		printf("%c", *(mychar->p));
		Pop_LinkStack(stack);
		free(mychar);
	}

	printf("\n");
	system("pause");
	FreeSpace_LinkStack(stack);
}