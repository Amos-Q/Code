#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef char USER_TYPE;
#include "stack.h"
PSeqStack *stack = NULL;
void dealalpha(char ch)//ǰ����Ԫ�س�ջ����,����������ջ
{
	char num1 = 0;
	char num2 = 0;
	char num3 = 0;
	switch (ch) {
	case '+':pop(stack, &num1);
		pop(stack, &num2);
		num3 = num2 + num1;//����ӡascii��Ĳ�ֵ,����
							   //+�Ļ�Ҫ��ȥ��96
		push(stack, num3);
		break;
	case '-':pop(stack, &num1);
		pop(stack, &num2);
		num3 = num2 - num1;
		push(stack, num3);
		break;
	case '*':pop(stack, &num1);
		pop(stack, &num2);
		num3 = num2 * num1;
		push(stack, num3);
		break;
	case '/':pop(stack, &num1);
		pop(stack, &num2);
		num3 = num2 / num1;
		push(stack, num3);
		break;
	}
}
void skipBlank(char *str)
{
	int i = 0, j = 0;
	for (i = 0; str[i];) {
		puts("sb");
		if (str[i] == ' ') {//�ǿո�������
			i++;
		}
		else {
			str[j] = str[i];//����ͼ�¼����
			j++;//ָ����һ��Ҫ����Ŀռ�
			i++;//ָ����һ��Ҫȡ�����ַ�
		}
	}
	str[j] = 0;//�ַ���������־
}
void getdeal(char *str)
{
	char ch;
	int i = 0;
	while (str[i]) {
		ch = str[i];
		if ('+' == str[i] || '-' == str[i]
			|| '/' == str[i] || '*' == str[i]) {
			dealalpha(ch);
			i++;
		}
		else {
			ch = str[i] - 48;//ת����ascii����
			push(stack, ch);
			i++;
		}
	}
}
void getout()
{
	char result = 0;
	pop(stack, &result);
	printf("���:%d\n", result);
}
int main()
{
	//	PSeqStack *stack = NULL;
	char str[20] = { 0 };
	printf("�������׺���ʽ:\n");
	gets(str);
	skipBlank(str);//�����ո�
	creatEmptyStack(&stack, strlen(str));
	getdeal(str);
	getout();
	return 0;
}