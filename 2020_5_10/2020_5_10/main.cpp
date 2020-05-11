#define _CRT_SECURE_NO_WARNINGS 1

#include "lib.h"

int main()
{
	Contact *p = new Contact[100];                                  //声明类p
	for (; ; )
	{
		int temp = 0;
		clear();
		interface();                                                //调用interface函数，输出主界面
		__fpurge(stdin);
		scanf("%d", &temp);

		switch (temp)                                                //switch语句选择功能
		{
		case 1: {
			add(p);
			printf("按enter返回主界面！\n");
			__fpurge(stdin);
			getchar();                                   //暂停界面，有输入才退出本次选择语句
			break;
		}

		case 2: {
			list(p);
			printf("按enter返回主界面！\n");
			__fpurge(stdin);
			getchar();
			break;
		}

		case 3: {
			mydelete(p);
			printf("按enter返回主界面！\n");
			__fpurge(stdin);
			getchar();
			break;
		}

		case 4: {
			seek(p);
			printf("按enter返回主界面！\n");
			__fpurge(stdin);
			getchar();
			break;
		}

		case 5: {
			revise(p);
			printf("按enter返回主界面！\n");
			__fpurge(stdin);
			getchar();
			break;
		}

		case 6:exit(0);

		default: {
			printf("输入错误!");
			printf("按enter返回主界面！\n");
			__fpurge(stdin);
			getchar();
			break;
		}
		}
	}
	return 0;
}