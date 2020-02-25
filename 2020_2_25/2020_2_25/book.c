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