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

// ����MyChar
MyChar* CreateMyChar(char* p)
{
	MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
	mychar->p = p;
	return mychar;
}

void LeftOperate(LinkStack* stack, char *p)        // �����Ų���
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
	// ���ж�ջ����û��Ԫ��
	while (Size_LinkStack(stack) > 0)
	{
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		// ���ƥ�䵽������
		if (IsLeft(*(mychar->p)))
		{
			Pop_LinkStack(stack);
			break;
		}
		printf("%c", *(mychar->p));         // ���
		Pop_LinkStack(stack);               // ����

	}
}

void OperatorOperate(LinkStack* stack, char* p)
{
	// ��ȡ��ջ���ķ���

	MyChar* mychar = (MyChar*)Top_LinkStack(stack);
	if (mychar == NULL)
	{
		Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
		return;
	}
	// ���ջ�����ȼ����ڵ�ǰ�ַ������ȼ���ֱ����ջ
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
			printf("%c", *(mychar2->p));          // ���
			Pop_LinkStack(stack);                 // ����
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

		if (IsNumber(*p))              // ���������
		{
			NumberOperator(*p);        // ������֣����������)
		}

		if (IsLeft(*p))
		{
			LeftOperate(stack, p);     // ������������ţ�ֱ�ӽ�ջ
		}

		if (IsRight(*p))               // �������������              
		{
			RightOperator(stack);      // �����Ų���
		}

		if (IsOperator(*p))            // ������������
		{
			OperatorOperate(stack, p);
		}

		// ��������������
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