#define _CRT_SECURE_NO_WARNINGS 1
#include "Student.h"

int main()
{

	printf(" =========================================================\n");
	printf("<                   学生管理系统                          >\n");
	printf(" =========================================================\n");
	printf("                       （请选择功能）\n（1）成绩录入 （2）显示全部（3）成绩查询 （4）成绩修改 (0)退出\n");
	int a = 0;
	scanf("%d", &a);
	while (a)
	{

		switch (a)
		{
		case 1:
			Add();
			break;
		case 2:
			Display(H);
			break;
		case 3:
			Search(H);
			break;
		case 4:
			Change(H);
			break;

		}
		printf("                       （请选择功能）\n（1）成绩录入 （2）显示全部（3）成绩查询 （4）成绩修改 (0)退出\n");
		scanf("%d", &a);

	}
	printf(" =========================================================\n");
	return 0;
}
