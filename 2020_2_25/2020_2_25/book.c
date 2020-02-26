#define _CRT_SECURE_NO_WARNINGS 1

struct library//图书馆结构体
{
	int xcl;//库存

	float price;//单价

	char name[20], author[20], chuban[20], kind[20], shuhao[20];

	struct library *next;

};

struct reader//读者结构体
{

	int zhenghao;

	char mingzi[20], riqi[20], zname[20];

	struct reader *next;

};

void mainmenu()//主菜单

{
	system("cls");

	printf("**************************************************");

	printf("\n\n 1.图书信息\n\n");

	printf("\n\n 2.借阅系统\n\n");

	printf("\n\n 3.退出系统\n\n");

	printf("\n\n 请按键选择，回车确定\n");

	printf("*************************************************\n");

	return;

}

void menu1() //显示图书馆信息菜单

{
	system("cls");

	printf("****************************************************");

	printf("\n 1.增加图书\n\n");

	printf("\n 2.删除图书\n\n");

	printf("\n 3.图书查询\n\n");

	printf("\n 4.库存浏览\n\n");

	printf("\n 5.返回上一层\n\n");

	printf("\n 请按键选择，回车确定\n");

	printf("***************************************************\n");

	return;

}

void menu2() //显示查询菜单

{
	system("cls");

	printf("请输入书号,书名,作者或类别查询：\n");

	printf("类别（科学技术 语言文学 政治经济 历史地理 意识形态 艺术）\n\n");

	return;

}

void main1()//main1函数

{
	void tsgxx();//声明

	void jieshuxitong();//声明

	char choose;

	mainmenu();

	scanf("%c", &choose);

	switch (choose)//功能函数选择

	{
	case '1':

		tsgxx();

		break;

	case '2':

		jieshuxitong();

		break;

	case '3':

		system("cls");

		getch();

		exit(0);

		system("cls");

		break;

	}
}

void tsgxx()//图书馆信息函数

{
	void tsjinku();

	void shanchu();

	void chaxunts();

	void xianshikucun();//函数声明

	char choose;

	menu1();

	scanf("%c", &choose);

	scanf("%c", &choose);

	for (;;)

		switch (choose)

		{
		case '1':

			tsjinku();

			break;

		case '2':

			shanchu();

			break;

		case '3':

			chaxunts();

			break;

		case '4':

			xianshikucun();

			break;

		case '5':

			main1();

			break;

		}
}

int tjzs()//统计文本个数函数

{
	FILE *fp;

	int txcl = 0, n;

	float tprice = 0;

	char tname[20] = { '\0' }, tauthor[20] = { '\0' }, tchuban[20] = { '\0' }, tkind[20] = { '\0' }, tshuhao[20] = { '\0' };

	fp = fopen("library.txt", "r");//打开文件

	for (n = 0; !feof(fp); n++)//逐个读文件

		fscanf(fp, "%s%s%s%s%s%d%f", tshuhao, tname, tauthor, tchuban, tkind, &txcl, &tprice);

	n--;

	fclose(fp);//关闭文件

	return (n);//返回个数

}
int tjdzzs()//统计文本个数函数

{
	FILE *fp;

	int zhenghao = 0, n;

	char mingzi[20] = { '\0' }, riqi[20] = { '\0' }, zname[20] = { '\0' };

	fp = fopen("reader.txt", "r");//打开文件

	for (n = 0; !feof(fp); n++)//逐个读文件

		fscanf(fp, "%d%s%s%s ", &zhenghao, &mingzi, &riqi, &zname);

	fclose(fp);//关闭文件

	return (n);//返回个数

}

void tsjinku()//图书进库函数

{
	FILE *fp;

	int xcl = 0, n = 0;

	float price = 0;

	char name[20] = { '\0' }, author[20] = { '\0' }, kind[20] = { '\0' }, chuban[20] = { '\0' }, shuhao[20] = { '\0' };

	char hitkey;

	system("cls");

	if ((fp = fopen("library.txt", "r")) == NULL)//打开图书馆文件，不存在此文件则新建

	{
		fp = fopen("library.txt", "w");

		fclose(fp);

	}

	fp = fopen("library.txt", "a");

	printf("\n请按以下格式输入图书信息:\n书号 书名 作者 出版社 类别 进库量 单价");

	printf("\n（类别（科学技术 语言文学 政治经济 历史地理 意识形态 艺术））\n");

	for (; hitkey != 27;)//循环输入

	{
		if (n != 0)

			printf("请输入:");

		scanf("%s%s%s%s%s%d%f", shuhao, name, author, chuban, kind, &xcl, &price);

		fprintf(fp, "%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n", shuhao, name, author, chuban, kind, xcl, price);

		printf("继续输入请按回车，结束输入请按Esc\n");

		n++;

		hitkey = getch();

		for (; hitkey != 13 && hitkey != 27;)

			hitkey = getch();

	}

	fclose(fp);

	printf("\n保存成功，按任意键返回上一层!");

	getch();

	tsgxx();//返回上一层

}

void shanchu()//删除图书信息

{
	struct library *head = NULL;

	struct library *p, *p1, *p2;

	int txcl = 0, n = 0, j, i;

	float tprice = 0;

	char tname[20] = { '\0' }, tauthor[20] = { '\0' }, tchuban[20] = { '\0' }, tkind[20] = { '\0' }, ttname[20] = { '\0' }, tshuhao[20] = { '\0' };

	char hitkey;

	FILE *fp;

	if ((fp = fopen("library.txt", "r")) == NULL)//打开文件

	{
		system("cls");

		printf("\n记录文件不存在!按任意键返回");

		getch();

		tsgxx();

	}

	else

	{
		system("cls");

		printf("\n请输入你要删除的书名:");//输入删除图书书名

		scanf("%s", &ttname);

		printf("\n确认删除请回车，取消请按Esc\n");

		hitkey = getch();

		for (; hitkey != 13 && hitkey != 27;)

			hitkey = getch();

		if (hitkey == 27)

			tsgxx();

		fp = fopen("library.txt", "r");

		for (j = 0; !feof(fp);)//读文件夹信息，统计个数

		{
			j++;

			fscanf(fp, "%s%s%s%s%s%d%f", tshuhao, tname, tauthor, tchuban, tkind, &txcl, &tprice);
		}

		fclose(fp);

		fp = fopen("library.txt", "r");

		for (i = 1; i < j; i++)

		{
			fscanf(fp, "%s%s%s%s%s%d%f", tshuhao, tname, tauthor, tchuban, tkind, &txcl, &tprice);

			if (strcmp(ttname, tname))//比较名字，将不同名字的信息复制到链表

			{
				n++;

				if (n == 1)//建立链表

				{
					p1 = p2 = (struct library*)malloc(LEN);

					head = p1;
				}

				else

				{
					p2->next = p1;

					p2 = p1;

					p1 = (struct library*)malloc(LEN);//新建链表

				}

				strcpy(p1->shuhao, tshuhao);//复制书号

				strcpy(p1->name, tname);//复制书名

				strcpy(p1->author, tauthor);//复制作者名字

				strcpy(p1->chuban, tchuban);//复制出版社

				strcpy(p1->kind, tkind);//复制类别

				p1->xcl = txcl;//复制个数

				p1->price = tprice;//复制单价

			}
		}

		if (n == 0)

		{
			head = NULL;
		}

		else

		{

			p2->next = p1;

			p1->next = NULL;

			fclose(fp);

		}
	}

	fp = fopen("library.txt", "w");//清空文件

	fclose(fp);

	fp = fopen("library.txt", "a");//追加文件

	p = head;

	for (; p != NULL;)//把链表内容覆盖到文件

	{

		fprintf(fp, "%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n", p->shuhao, p->name, p->author, p->chuban, p->kind, p->xcl, p->price);

		p = p->next;

	}

	fclose(fp);//关闭文件

	system("cls");

	printf("\n删除成功 \n按任意键返回上一层\n");

	getch();//返回上一层

	tsgxx();

}
void chaxunts()//查询函数

{

	FILE *fp;

	char choose;

	int txcl = 0, n = 0, k = 0, i, l;

	float tprice = 0;

	char tname[20] = { '\0' }, tauthor[20] = { '\0' }, chazhao[20] = { '\0' }, tchuban[20] = { '\0' },

		tshuhao[20] = { '\0' }, tkind[20] = { '\0' };

	if ((fp = fopen("library.txt", "r")) == NULL)//打开文件

	{
		system("cls");

		printf("\n记录文件不存在!按任意键返回");

		getch();

		tsgxx();

	}

	l = tjzs();//获得文件个数

	menu2();//调用菜单函数

	scanf("%s", chazhao);

	system("cls");

	for (i = 0; i < l; i++)

	{
		fscanf(fp, "%s%s%s%s%s%d%f", tshuhao, tname, tauthor, tchuban, tkind, &txcl, &tprice);//读文件信息

		if (!strcmp(chazhao, tshuhao) || !strcmp(chazhao, tname) || !strcmp(chazhao, tauthor) || !strcmp(chazhao, tkind))//输出查询信息

		{
			if (k == 0)

			{

				printf("查询结果:\n\n");

				printf("书号\t书名\t作者\t\t出版社\t\t类别\t\t现存量\t单价\n");

			}

			printf("%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n", tshuhao, tname, tauthor, tchuban, tkind, txcl, tprice);

			k++;

		}
	}

	if (k == 0)//文件夹为空则输出无记录

	{
		system("cls");

		printf("\n无符合记录!\n");

		getch();

		tsgxx();

	}

	fclose(fp);

	getch();//返回

	tsgxx();

}

void xianshikucun()//现实库存信息

{

	FILE *fp;

	int xcl = 0, n = 0, i = 0, j = 0;

	float price = 0;

	char name[20] = { '\0' }, author[20] = { '\0' }, kind[20] = { '\0' }, chuban[20] = { '\0' }, shuhao[20] = { '\0' };

	if ((fp = fopen("library.txt", "r")) == NULL)//打开文件夹

	{

		system("cls");

		printf("\n记录文件不存在!");

	}

	n = tjzs();

	if (n == 0)

	{
		system("cls");

		printf("\n无任何记录!");

	}

	fp = fopen("library.txt", "r");//打开只读文件

	system("cls");

	printf("书号\t书名\t作者\t\t出版社\t\t类别\t\t库存量\t单价\n");

	for (i = 0; i < n; i++)//输出信息

	{

		fscanf(fp, "%s%s%s%s%s%d%f", shuhao, name, author, chuban, kind, &xcl, &price);

		printf("%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n", shuhao, name, author, chuban, kind, xcl, price);

	}

	fclose(fp);

	printf("\n按任意键返回\n");

	getch();//返回

	tsgxx();

}