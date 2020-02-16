#define _CRT_SECURE_NO_WARNINGS 1
#include "home.h"
void main()
{
	int n;
	while (n != 6)
	{
		printf("\t大学计算机基础成绩管理系统\n");
		printf("1：输入一个班学生大学计算机基础成绩记录\n");
		printf("2：显示所有成绩记录\n");
		printf("3：计算并输出平均成绩，均方差\n");
		printf("4：输出成绩与排名\n");
		printf("5：结果存入文件chengji.txt\n");
		printf("6：退出系统\n");
		printf("输入选项代码:");
		scanf("%d", &n);
		switch (n)
		{
		case 1:a(); break;
		case 2:b(); break;
		case 3:c(); break;
		case 4:d(); break;
		case 5:e(); break;
		case 6:printf("\n*******************谢谢使用！*******************\n"); break;
			break;
		}
	}
	getchar();
}