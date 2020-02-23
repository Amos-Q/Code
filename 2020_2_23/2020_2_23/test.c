#define _CRT_SECURE_NO_WARNINGS 1
#include "home.h"


//菜单模块
void menu()//菜单
{
	printf("\t\t************职工信息管理系统菜单**********\n");
	printf("\t\t*                                        *\n");
	printf("\t\t*              1.录入职工信息            *\n");
	printf("\t\t*                                        *\n");
	printf("\t\t*              2.显示职工信息            *\n");
	printf("\t\t*                                        *\n");
	printf("\t\t*              3.查询职工信息            *\n");
	printf("\t\t*                                        *\n");
	printf("\t\t*              4.修改职工信息            *\n");
	printf("\t\t*                                        *\n");
	printf("\t\t*              5.删除职工信息            *\n");
	printf("\t\t*                                        *\n");
	printf("\t\t*              0.退出                    *\n");
	printf("\t\t*                                        *\n");
	printf("\t\t******************************************\n");
	printf("\t\t请输入指令(0-5): ");
}

int main()
{
	int num;
	n = 0;
	system("color 0B");
	while (1)
	{
		menu();
		scanf("%d", &num);
		system("cls");
		switch (num)
		{
		case 1: input(); break;
		case 2: show();  break;
		case 3: que();   break;
		case 4: mod();   break;
		case 5: del();   break;
		case 0: printf("谢谢使用！\n\n"); return 0;
		default:printf("\n--->无效的指令!\n\n\n");
		}
		system("pause");
		system("cls");
	}
}