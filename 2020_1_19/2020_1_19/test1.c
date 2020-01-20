#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef char USER_TYPE;
#include "stack.h"
PSeqStack *stack = NULL;
void dealalpha(char ch)//前两个元素出栈运算,将运算结果入栈
{
	char num1 = 0;
	char num2 = 0;
	char num3 = 0;
	switch (ch) {
	case '+':pop(stack, &num1);
		pop(stack, &num2);
		num3 = num2 + num1;//最后打印ascii码的差值,所以
							   //+的话要减去和96
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
		if (str[i] == ' ') {//是空格则跳过
			i++;
		}
		else {
			str[j] = str[i];//否则就记录下来
			j++;//指向下一个要放入的空间
			i++;//指向下一个要取出的字符
		}
	}
	str[j] = 0;//字符串结束标志
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
			ch = str[i] - 48;//转换成ascii数字
			push(stack, ch);
			i++;
		}
	}
}
void getout()
{
	char result = 0;
	pop(stack, &result);
	printf("结果:%d\n", result);
}
int main()
{
	//	PSeqStack *stack = NULL;
	char str[20] = { 0 };
	printf("请输入后缀表达式:\n");
	gets(str);
	skipBlank(str);//跳过空格
	creatEmptyStack(&stack, strlen(str));
	getdeal(str);
	getout();
	return 0;
}