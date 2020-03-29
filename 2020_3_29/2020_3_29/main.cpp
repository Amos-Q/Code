#define _CRT_SECURE_NO_WARNINGS 1

#include "main.h"
int main()
{
	int sat;
	//初始化交互
	Queue Q = Initinteract();
	TravQueue(Q);
	//操作交互
	int loc, val;
	char m;
	while (1)
	{
		printf("\n插入请按A，弹出值请按B，遍历请C");
		//system("cls");
		cin >> m;
		switch (m)
		{
		case 'A':
			printf("开始插入，请输入插入值\n");
			scanf_s("%d", &val);
			sat = InsertQueue(Q, val);
			break;
		case 'B':
			printf("开始删除\n");
			printf("已弹出值%d\n", DeQueue(Q));
			break;
		case 'C':
			printf("当前数组值如下");
			TravQueue(Q);
			break;
		default:
			exit(0);
		}
	}
}