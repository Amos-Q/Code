#define _CRT_SECURE_NO_WARNINGS 1
#define bool int
#define false 0
#define true 1
#include <stdio.h>

//int evalRPN(char ** tokens, int tokensSize) {
//
//	int i;
//	int res;
//	int top = -1;
//	int *stack = (int *)malloc(sizeof(int) * tokensSize);
//	if (!stack)
//		exit(EXIT_FAILURE);
//
//	for (i = 0; i < tokensSize; i++)
//	{
//		if (tokens[i][0] == '0') // 0字符串要特殊考虑。
//			stack[++top] = 0;
//		if (res = atoi(tokens[i])) //如果当前字符串是数字
//			stack[++top] = res;
//		else                      // 如果当前字符串是操作符
//			switch (tokens[i][0])
//			{
//			case '+': res = stack[top--]; res = stack[top] + res; stack[top] = res; break;
//			case '-': res = stack[top--]; res = stack[top] - res; stack[top] = res; break;
//			case '*': res = stack[top--]; res = stack[top] * res; stack[top] = res; break;
//			case '/': res = stack[top--]; res = stack[top] / res; stack[top] = res; break;
//			}
//	}
//
//	return stack[top];
//}
////
//
//int evalRPN(char ** tokens, int tokensSize) {
//	int i = 0;
//	int res = 0;
//	int top = -1;
//	int *stack = (int *)malloc(sizeof(int) * tokensSize);
//	for (i = 0; i < tokensSize; i++)
//	{
//		// if(tokens[i][0] == '0') 
//		//     stack[++top] = 0;
//		if (tokens[i][0] >= '0' && tokens[i][0] <= '9')
//		{
//			res = tokens[i][0] - '0';
//			stack[++top] = res;
//		}
//		else
//			switch (tokens[i][0])
//			{
//			case '+': res = stack[top--]; res = stack[top] + res; stack[top] = res; break;
//			case '-': res = stack[top--]; res = stack[top] - res; stack[top] = res; break;
//			case '*': res = stack[top--]; res = stack[top] * res; stack[top] = res; break;
//			case '/': res = stack[top--]; res = stack[top] / res; stack[top] = res; break;
//			}
//	}
//	return stack[top];
//}
//
//int main()
//{
//	char tokens[5] = { '4','13','5','/','+' };
//	evalRPN(tokens,5);
//	system("pause");
//	return 0;
//}
//
//bool isMatch(char * s, char * p) {
//	int sz1 = strlen(s);
//	int sz2 = strlen(p);
//	int left1 = 0;
//	int left2 = 0;
//	char tmp = 0;
//	while (s[left1] != '/0')
//	{
//		if (s[left1] == p[left2])
//		{
//			left1++;
//			left2++;
//		}
//		else if (p[left2] == '*')
//		{
//			if (p[left2+1] != '/0') {
//				tmp = p[left2 + 1];
//				if (s[left1] == tmp) {
//					left1++;
//					left2 += 2;
//				}
//			}
//			left1++;
//		}
//		else if (p[left2] == '?')
//		{
//			left1++;
//			left2++;
//		}
//		else {
//			return false;
//		}
//	}
//	if (s[left1] == '/0')
//	{
//		if (p[left2] != '/0')
//		{
//			return false;
//		}
//	}
//	return true;
//}

int main()
{
	char s[2] = "av";
	char p[1] = "*";
	int left = 0;
	printf("%c  %d", s[left+1], left);

	system("pause");
	return 0;
}
