#define _CRT_SECURE_NO_WARNINGS 1
#include "home.h"

void display()//显示所有信息
{
	int a = 0;
	struct person *p;
	printf("ID   name   sex     position     place    score         email     telephone\n");
	for (p = player; p < player + 24; p++)
	{
		a = 1;
		printf("%d   %s  %s     %s    %s    %.1f        %s      %ld  \n", p->ID, p->name, p->sex, p->position, p->place, p->score, p->email, p->telephone);
	}
	if (a == 1)
	{
		printf("返回主菜单\n");
		system("pause");//页面停留
		system("cls");
		menu();

	}
}
void find()
{
	struct person *p;
	int num, loop;
	printf("\n请输入编号：\n");
	scanf("%d", &num);
	for (p = player; p < player + 24; p++)
	{
		if (p->ID == num)
		{
			loop = 1;
			printf("ID   name   sex     position     place    score    email    telephone");
			printf("\n%d   %s   %s   %s   %s   %f   %s   %ld  \n\n", p->ID, p->name, p->sex, p->position, p->place, p->score, p->email, p->telephone);
			printf("返回主菜单\n");
			system("pause\n");
			menu(); break;

		}

	}
	if (loop == 0)
	{
		system("cls");
		printf("无此球员信息\n");
	}
	printf("无此球员信息,请重新选择编号");
	find();

}
void change()
{
	system("cls");

	int b, c, num;
	struct person *p;
	int loop = 0;
	printf("\n请输入需要修改的球员编号：\n");
	scanf("%d", &num);
	for (p = player; p < player + 24; p++)
	{
		if (p->ID == num)
		{
			do
			{
				puts("\n\n1.ID   2.name   3.sex    4.position    5.place    6.score    7.email    8.telephone   9.所有信息   10.取消并返回\n");
				printf("请选择要修改的信息种类: [  ]\b\b\b");
				scanf("%d", &c);
				if (c > 10 || c < 1)
				{
					system("cls");
					puts("\n选择错误!请重新选择!\n");
					getchar();
				}
			} while (c > 10 || c < 1); break;
		}
		else
		{
			if (p == p + 24)
				printf("无此球员，请重新选择\n");
		}
	}

	do
	{
		switch (c)
		{
		case 1: printf("ID:"); scanf("%d", &p->ID); break;
		case 2: printf("name:"); scanf("%s", p->name); break;
		case 3: printf("sex:"); scanf("%s", p->sex); break;
		case 4: printf("position:"); scanf("%s", p->position); break;
		case 5: printf("place:"); scanf("%s", p->place); break;
		case 6: printf("score:"); scanf("%f", &p->score); break;
		case 7: printf("email:"); scanf("%s", p->email); break;
		case 8: printf("telephone:"); scanf("%ld", &p->telephone); break;
		case 9: change1(); break;
		case 10: menu();
		}
		save();//修改完保存
		puts("\n修改后的信息：\n");
		printf("ID   name   sex     position     place    score    email    telephone\n");
		printf("%d   %s   %s   %s   %s   %f   %s   %ld  \n", p->ID, p->name, p->sex, p->position, p->place, p->score, p->email, p->telephone);
		puts("是否完成修改 请选择\n1/完成并退出  2/继续修改 3/修改其他球员信息");
		printf("    [  ]\b\b");
		scanf("%d", &b);
	} while (b == 2);
	if (b == 1)
		menu();
	if (b == 3)
		change();


}
void change1()
{
	struct person *p;
	int num, loop = 0;
	printf("\n请再次输入编号：\n");
	scanf("%d", &num);
	for (p = player; p < player + 24; p++)
	{
		if (p->ID == num)
		{
			loop = 1;
			printf("请输入该球员的新信息：依次输入 ID   name   sex     position     place    score    email    telephone\n");
			scanf("%d%s%s%s%s%f%s%ld\n", &p->ID, p->name, p->sex, p->position, p->place, &p->score, p->email, &p->telephone);
			break;//有bug
		}
	}
	if (loop)
	{
		printf("\n修改成功！！\n");
		printf("返回主菜单");
		system("pause");
		menu();

	}
	else
	{
		system("cls");
		printf("\n不存在该球员！！\n");
		printf("\n");
		change();
	}

}
void sort()//排序
{
	struct person p;//定义结构体变量，做中间变量
	int j, k;
	int i;
	for (i = 0; i < 24; i++)
	{
		k = i;
		for (j = i + 1; j < 24; j++)
			if (player[j].score > player[k].score)
			{
				k = j;
				p = player[k]; player[k] = player[i]; player[i] = p;
			}
	}
	display();
	printf("返回主菜单\n");


}
void max()//找出得分最高
{
	int i, m = 0;
	for (i = 0; i < 24; i++)
	{
		if (player[i].score > player[m].score)
			m = i;
	}
	printf("本赛季最佳球员是：%s\n\n", player[m].name);
	printf("返回主菜单\n");
	system("pause");//页面停留
	menu();
}
int load() /*打开文件,读取里面的数据，即写出*/
{
	struct person *p;
	p = player;
	FILE *fp;
	int i;
	if ((fp = fopen("file.txt", "rb")) == NULL) /*读入空文件，rb表示打开一个二进制文件，只允许读数据*/
	{
		printf("\n文件不存在!\n");
		return 0;
	}
	for (i = 0; !feof(fp); i++)  /*处理到文件结尾*/
		for (p = player; p < player + 24; p++)
			fscanf(fp, "%d\t%s\t%s\t%s\t%s\t%f\t%s\t%ld\n", &p->ID, p->name, p->sex, p->position, p->place, &p->score, p->email, &p->telephone);
	fclose(fp);
	return 0;
}
void save() /*保存学生信息*/
{
	struct person *p;
	p = player;
	//void exit();
	FILE *fp;
	int i;
	if ((fp = fopen("file.txt", "wb")) == NULL)/*只打开或建立一个二进制文件，只允许写数据*/
	{
		printf("\n文件不存在!\n");
	}
	for (i = 0; i < 24; i++)
		if (player[i].name[0] != '\0')
			if (fprintf(fp, "%d\t%s\t%s\t%s\t%s\t%f\t%s\t%ld\n", p[i].ID, p[i].name, p[i].sex, p[i].position, p[i].place, p[i].score, p[i].email, p[i].telephone) == 1)/*将一批数据作为一个整体一次性写入磁盘文件*/
				printf("文件写入错误!\n");
	fclose(fp);
}
void face()/*访问起始页面*/
{
	system("color 4e");
	printf("\n\t                         ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★\n\n");
	puts("\n");
	puts("\t                              ┃                                       ┃");
	puts("\t                              ┃                                       ┃");
	puts("\t                              ┃       欢迎访问球队管理系统!           ┃");
	puts("\t                              ┃                                       ┃");
	puts("\t                              ┃                                       ┃");
	puts("\t                              ┃                制作人：燕京理工学院高鸿浩         ┃");
	puts("\t                              ┃                        2019.6.20      ┃ ");
	puts("\n ");
	printf("\n\t                              请按回车键继续……\n");

	getchar();
	system("cls");
}
void tail()
{
	printf("\n\t                         ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★\n\n");
	puts("\n");
	puts("\t                             ┃                                               ┃");
	puts("\t                             ┃                                               ┃");
	puts("\t                             ┃       感谢访问球队管理系统!欢迎下次再来!      ┃");
	puts("\t                             ┃                                               ┃");
	puts("\t                             ┃                                               ┃");
	puts("\t                             ┃                  制作人：燕京理工学院高鸿浩            ┃");
	puts("\t                             ┃                          2019.6.20            ┃ ");
	puts("\n ");

}
void menu()/*主菜单*/
{
	int choice;
	int n;
	do
	{
		system("cls");
		printf("\n");
		printf("                                          ---巴塞罗那球员信息管理系统---\n");
		puts("\n");
		printf("                                             1/按编号查询球员信息\n");
		puts("\n");
		printf("                                             2/  修改球员信息\n");
		puts("\n");
		printf("                                             3/按照本赛季成绩排序\n");
		puts("\n");
		printf("                                             4/ 本赛季最佳球员\n");
		puts("\n");
		printf("                                             5/  显示所有信息\n");
		puts("\n");
		printf("                                             6/     退出\n");
		puts("\n");
		printf("                                          请选择服务种类(1-6) : [ ]\b\b");
		scanf("%d", &n);
		if (n < 1 || n>6)
		{
			system("cls");
			printf("选择错误!  请重新选择!\n");
			system("pause");
			choice = 1;
		}
		else
		{
			break;
		}
	} while (choice == 1);
	switch (n)
	{
	case 1:system("cls"); system("cls"); find(); break;//调用find函数以对球员进行查找
	case 2:system("cls"); change(); break;//调用change函数以对球员信息进行修改
	case 3:system("cls"); sort(); break;//调用sort函数以对球员进行按成绩排序并输出
	case 4:system("cls"); max(); break;//调用max函数以输出全场最佳球员
	case 5:system("cls"); display(); break;//调用display函数以输出全部信息
	case 6:system("cls"); tail(); break;//调用tail函数以展现末尾页面
	}
}