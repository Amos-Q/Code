#define _CRT_SECURE_NO_WARNINGS 1
bool isValid(char* s)
{
	struct Stack st;
	StackInit(&st, 10);
	//括号数组
	char symbols[][2] = {
	{ '(', ')' },
	{ '[', ']' },
	{ '{', '}' },
	};
	while (*s)
	{
		int i = 0;
		for (; i < 3; ++i)
		{
			//如果为左括号，则入栈
			if (*s == symbols[i][0])
			{
				StackPush(&st, *s);
				++s;
				break;
			}
		}

		if (i == 3)
		{
			// 走到这里说明*s不是左括号，取出栈顶元素
			// 判断是否和当前的右括号匹配
			char top = StackTop(&st);
			for (int j = 0; j < 3; ++j)
			{
				if (*s == symbols[j][1])
				{
					if (top == symbols[j][0])
					{
						++s;
						StackPop(&st);
						break;
					}
					else
					{
						//如果没有一个可以匹配，说明不匹配
						return false;
					}
				}
			}
		}


		比特科技
	}
	//如果栈为空，说明完全匹配
	if (StackEmpty(&st) == 0)
		return true;
	else
		return false;
}