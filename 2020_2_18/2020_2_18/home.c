#define _CRT_SECURE_NO_WARNINGS 1
#include"home.h"

void login()//登录 
{
	//用户名和密码都是：123456 
	char userName[15];
	char password[15];
	int i;

	for (i = 1; i <= 3; i++)
	{
		printf("请输入用户名和密码\n");
		printf("用户名：");
		gets(userName);
		printf("密码：");
		gets(password);
		if ((strcmp(userName, "123456") == 0) && (strcmp(password, "123456") == 0))
		{
			printf("--显示主菜单--");
			return;
		}
		else
		{
			if (i < 3)
			{
				printf("用户名或密码错误，请重新输入，您还有%d次机会", 3 - i);
			}
			else
			{
				printf("错误超过三次，自动退出");
				exit(0);
			}
		}
	}
}

void menu()    //菜单
{
	do
	{
		system("cls");  //清屏
		char t;
		printf("         图书管理员查询系统\n\n");  //6个空格前面 ，这样好看一点 *_* 
		printf("       | |    1.增添图书     | |\n");
		printf("       | |    2.修改信息     | |\n");
		printf("       | |    3.删除信息     | |\n");
		printf("       | |    4.图书查询     | |\n");
		printf("       | |    5.图书总览     | |\n");
		printf("       | |    6.退出软件     | |\n");
		printf("       请输入要进行的操作：");
		t = getchar();
		switch (t)
		{
		case '1':inputBook();
			break;
		case '2':amendBook();
			break;
		case '3':deleteBook();
			break;
		case '4':findBook();
			break;
		case '5':printBook();
			break;
		case '6':over();
			break;
		default:break;
		}
	} while (1);
}

struct BOOK *readIn()//将文件中的内容读出到链表中，返回值为表头地址 
{
	FILE *fp;       //文件指针
	int n = 0;
	struct BOOK *head = NULL;
	struct BOOK *p, *p2, *pr = NULL;
	fp = fopen("books", "ab+");     //以只读的方式打开文件
	if (fp == NULL)
	{
		printf("cannot open the file\n");
	}

	while (!feof(fp))        //判断文件位置标志是否移动到文件末尾（是否结束）,是的话为1，否的话为0   书上341页有具体解释 
	{
		n++;
		p = (struct BOOK *)malloc(N); //向内存申请一段空间   
		fread(p, N, 1, fp);     //将fp所指向的文件中的内容赋给p   
		if (n == 1)
		{
			head = p;
			p2 = p;
		}
		else             //创建链表  课本316 
		{
			pr = p2;
			p2->next = p;
			p2 = p;
		}
	}

	if (pr != NULL)
	{
		pr->next = NULL;  //内容读到链表中
	}
	else
	{
		head = NULL;  //没有读进去 
	}

	fclose(fp);    //关闭文件   
	return head;   //返回头指针
}

void inputBook()    //增添图书  
{
	do
	{
		system("cls");
		char t;
		struct BOOK *p;
		p = (struct BOOK *)malloc(N);     //申请空间   
		//输入图书信息  
		printf("请输入书名：");
		scanf("%s", p->name);
		getchar();//用于接收回车键  
		printf("请输入作者名：");
		scanf("%s", p->author);
		getchar();
		printf("请输入图书类型：");
		scanf("%s", p->type);
		getchar();
		printf("请输入图书价格：");
		scanf("%f", &p->price);
		getchar();
		printf("请输入图书数量：");
		scanf("%d", &p->num);
		getchar();

		saveBook(p);	//通过saveBook（）函数来保存图书 
		system("cls");
		printf("      ---------------------------\n");
		printf("      ||(　 ′-ω- )▄︻┻┳═-||\n");
		printf("      ||                       ||\n");
		printf("      || 保存成功！是否继续？  ||\n");
		printf("      ||                       ||\n");
		printf("      || 1.是             2.否 ||\n");
		printf("      ||         ￣ω￣        ||\n");
		printf("      ---------------------------\n");
		printf("	    指令：");
		while (1)    //利用死循环防止其他按键干扰   
		{
			t = getchar();
			if (t == '1')
			{
				break;
			}
			else if (t == '2')
			{
				menu();
			}
		}
	} while (1);
}

void saveBook(struct BOOK *p)//将图书信息存入文件
{
	//过程：打开文件-> 写入->关闭 
	FILE *fp;    //文件指针   
	fp = fopen("books", "ab");   //以追加的方式打开名字为books的二进制文件   
	if (fp == NULL)
	{
		printf("cannot open the file (╬◣д◢)");
	}
	if (fwrite(p, N, 1, fp) != 1)   //将p所指向的一段大小为N的内容  写入  p所指向的文件中  345页区分buffer 
	{
		printf("write error");
	}
	fclose(fp);    //关闭文件
}

void amendBook()//修改图书信息 
{
	//步骤：读入数据-> 输入修改书名 ->找到数据中这个书 ->修改 
	do {
		system("cls");
		struct BOOK *head, *p;
		int j = 0, x, t;
		char ch;
		FILE *fp;  //文件指针
		char _name[20];  //要改的书名 
		char name[20];   //书名
		char author[20]; //作者名   
		char type[10];   //类型   
		float price;     //价格   
		int num;         //数量 

		head = readIn();  //读入数据 
		p = head;
		printf("请输入你要修改的图书的书名：");
		scanf("%s", _name);
		while (p != NULL)//让链表中的x都为0， 
		{
			p->x = 0;
			p = p->next;
		}
		p = head;//重新使p指向head
		printf("***********************************图书信息***************************************\n");
		printf("----------------------------------------------------------------------------------\n");
		while (p != NULL)//逐个比较链表中的名字，并标记位置 
		{
			if (p != NULL && strcmp(p->name, _name) == 0)
			{
				j++;
				printf("图书编号:%d\n", j);
				printf("  	书名:%s", p->name);
				printf("  	作者名:%s", p->author);
				printf("  	图书类别:%s", p->type);
				printf("  	价格:%f", p->price);
				printf("  	数量:%d", p->num);
				printf("\n");
				p->x = j;//找到目标并标记
			}
			p = p->next;
		}

		//接下来是没有找到时的函数 
		if (j == 0)
		{
			printf("没有找到信息(╥.╥), 按0返回，按1重新搜索");
			while (true)
			{
				ch = getchar();
				if (ch == '0')
				{
					menu();
					break;
				}
				if (ch == '1')
				{
					break;
				}
			}
			if (ch == '1')
			{
				continue;
			}
		}

		//找到后的修改操作
		while (1)
		{
			printf("请输入要修改的图书编号：");//此处用x表示
			scanf("%d", &x);
			if (x > j || x == 0)
			{
				printf("输入错误，请重输罒ω罒\n");
			}
			else
			{
				break;
			}
		}

		p = head;     //让p重新指向表头   
		while (p != NULL && p->x != x)   //遍历链表查询符合条件的结点   
		{
			p = p->next;
		}
		if (p)    //如果p不为空   
		{
			system("cls");
			//输入要修改的信息   
			printf("请输入修改后的书名：");
			scanf("%s", name);
			strcpy(p->name, name);
			printf("\n请输入修改后的作者名：");
			scanf("%s", author);
			strcpy(p->author, author);
			printf("\n请输入修改后的图书类别：");
			scanf("%s", type);
			strcpy(p->type, type);
			printf("\n请输入修改后的图书价格：");
			scanf("%f", &price);
			p->price = price;
			printf("\n请输入修改后的图书数量：");
			scanf("%d", &num);
			p->num = num;
		}
		printf("-------------------------");
		printf("\n|         罒ω罒        |");
		printf("\n|     是否确认修改？    |");
		printf("\n| 1.是             2.否 |");
		printf("\n|                       |");
		printf("\n------------------------- ");
		printf("\n  指令：");
		while (1)   //利用死循环防止其他按键干扰   
		{
			scanf("%d", &t);
			if (t == 1)
			{
				break;
			}
			if (t == 2)
			{
				menu();
			}
		}

		system("cls");
		printf("正在修改，请稍后....");

		//以只写的方式打开名为books的二进制文件，打开的同时清空文件中的内容
		fp = fopen("books", "wb");
		if (fp == NULL)
		{
			printf("cannot open file");
		}
		if (fwrite(head, N, 1, fp) != 1)   //将head写入fp所指向的文件中   
		{
			printf("write error!");
		}
		fclose(fp);   //关闭文件  

		//将头后面的数据写入 
		if (head != NULL)   //如果head不为空   
		{
			p = head->next;   //让p指向第二个结点 
			fp = fopen("books", "ab");   //以追加的方式打开文件
			if (fp == NULL)
			{
				printf("cannot open file");
			}
			while (p != NULL)
			{
				if (fwrite(p, N, 1, fp) != 1)//将p写入fp所指向的文件中  
				{
					printf("write error!");
				}
				p = p->next;
			}
			fclose(fp);  //关闭文件   
		}

		printf(" \n(*_*)☆");
		printf("\n修改成功！按任意键返回主菜单...");
		getchar();
		getchar(); //此处要用两个getchar，虽然不知道为什么 
		break;
	} while (true);
}

void deleteBook()//删除图书信息 步骤：读入文件-> 找到要删除的书名-> 删除->保存 
{
	do
	{
		system("cls");
		FILE *fp;
		struct BOOK *head, *p, *pre = NULL;
		int j = 0, x;
		char name[20];
		char t, c, ch;

		head = readIn();    //读入

		printf("请输入你要删除的图书的书名：\n");
		scanf("%s", name);
		p = head;

		while (p != NULL)
		{
			p->x = 0;  //令x全部为0，和 修改信息   差不多的步骤
			p = p->next;
		}

		p = head;
		printf("*************************图书信息*****************************\n");
		printf("--------------------------------------------------------------\n");

		while (p != NULL)
		{
			if (p != NULL && strcmp(p->name, name) == 0)
			{
				j++;
				printf("图书编号:%d\n", j);
				printf("  	书名:%s", p->name);
				printf("  	作者名:%s", p->author);
				printf("  	图书类别:%s", p->type);
				printf("  	价格:%f", p->price);
				printf("  	数量:%d", p->num);
				printf("\n");
				p->x = j;
			}
			p = p->next;
		}

		if (j == 0)   //如果j=0，即没有找到相应的图书
		{
			printf("没有找到相应的信息！(按0返回，按1重新搜索)\n");
			while (1)   //死循环是为了防止除0和1的其他按键干扰
			{
				ch = getchar();
				if (ch == '0')
				{
					menu();
					break;
				}
				else if (ch == '1')
				{
					break;
				}
			}
			if (ch == '1')     //如果输入的ch等于1，则结束本次循环 
			{
				continue;
			}
		}

		while (1)
		{
			printf("请输入您要删除的图书的编号：\n");
			scanf("%d", &x);
			if (x > j || x == 0)
			{
				printf("输入错误，请重新输入!");
			}
			else
			{
				break;
			}
		}

		printf("-------------------------\n");
		printf("|       (〃'▽'〃)      |\n");
		printf("|     是否确认删除？    |\n");
		printf("| 1.是             2.否 |\n");
		printf("|                       |\n");
		printf("-------------------------\n");
		while (1)
		{
			t = getchar();
			if (t == '1')
			{
				break;
			}
			else if (t == '2')
			{
				menu();
			}
		}

		//下面是在链表中删除一条信息￣ω￣= 
		p = head;
		while (p != NULL && p->x != x)
		{
			pre = p;
			p = p->next;
		}

		if (p != NULL)
		{
			if (pre == NULL)
			{
				head = head->next;  //删除头部 时 
			}
			else
			{
				pre->next = p->next;  //删除其他 
			}
		}
		free(p);  //将指针p释放掉 ,否则会造成内存泄漏 

		fp = fopen("books", "wb");//以只写的方式打开名为books的二进制文件
		if (fp == NULL)
		{
			printf("cannot open file");
		}
		if (fwrite(head, N, 1, fp) != 1)
		{
			printf("write error!");
		}
		fclose(fp);

		if (head != NULL)
		{
			p = head->next;
			fp = fopen("books", "ab");  //以追加的方式打开文件
			if (fp == NULL)
			{
				printf("cannot open file");
			}
			while (p != NULL)
			{
				if (fwrite(p, N, 1, fp) != 1)
				{
					printf("write error!");
				}
				p = p->next;
			}
			fclose(fp);
		}

		system("cls");
		printf("正在删除，请稍后....\n");
		printf("-------------------------\n");
		printf("|        .(*_*).        |\n");
		printf("|  删除成功，是否继续？ |\n");
		printf("| 1.是             2.否 |\n");
		printf("|                       |\n");
		printf("-------------------------\n");
		printf("  指令：");

		while (1)
		{
			c = getchar();
			if (c == '1')
			{
				break;
			}
			else if (c == '2')
			{
				menu();
			}
		}
	} while (1);
}

void findBook()//读书查询 
{
	do
	{
		system("cls");
		char t;
		printf(" --------图书查询--------\n");
		printf("*     1.按照书名查询      *\n");
		printf("*     2.按照作者查询      *\n");
		printf("*     3.按照类型查询      *\n");
		printf("*     4.按照价格查询      *\n");
		printf("按0返回主菜单\n指令：");
		t = getchar();
		switch (t)
		{
		case '0':menu();
			break;
		case '1':find_name_book();//这四个查找其实是一样的， (〃'▽'〃)，这样可以让代码看起来比较长@_@ 
			break;
		case '2':find_author_book();
			break;
		case '3':find_type_book();
			break;
		case '4':find_price_book();
			break;
		default:break;
		}
	} while (1);
}

void find_name_book()//按照书名查询
{
	system("cls");
	struct BOOK *head, *p;
	head = readIn();
	char name[20];
	printf("请输入您要查询图书的书名：");
	scanf("%s", name);
	getchar();//接收回车字符用的 
	printf("\n正在查询....");
	p = head;
	printf("*************************图书信息*****************************\n");
	printf("--------------------------------------------------------------\n");

	while (p != NULL)
	{
		if (p != NULL && strcmp(p->name, name) == 0)
		{
			printf("书名:%s", p->name);
			printf("  	作者名:%s", p->author);
			printf("  	图书类别:%s", p->type);
			printf("  	价格:%f", p->price);
			printf("  	数量:%d", p->num);
			printf("\n");
		}
		p = p->next;
	}

	printf("按任意键返回！");
	getchar();
	findBook();
}

void find_author_book()//按照作者查询
{
	system("cls");
	struct BOOK *head, *p;
	head = readIn();
	char author[20];
	printf("请输入您要查询图书的作者：");
	scanf("%s", author);
	getchar();//接收回车字符用的 
	printf("\n正在查询....");
	p = head;
	printf("*************************图书信息*****************************\n");
	printf("--------------------------------------------------------------\n");

	while (p != NULL)
	{
		if (p != NULL && strcmp(p->author, author) == 0)
		{
			printf("书名:%s", p->name);
			printf("  	作者名:%s", p->author);
			printf("  	图书类别:%s", p->type);
			printf("  	价格:%f", p->price);
			printf("  	数量:%d", p->num);
			printf("\n");
		}
		p = p->next;
	}

	printf("按任意键返回！");
	getchar();
	findBook();
}

void find_type_book()//按照类型查询
{
	system("cls");
	struct BOOK *head, *p;
	head = readIn();
	char type[10];
	printf("请输入您要查询图书的类型：");
	scanf("%s", type);
	getchar();//接收回车字符用的 
	printf("\n正在查询....");
	p = head;
	printf("*************************图书信息*****************************\n");
	printf("--------------------------------------------------------------\n");

	while (p != NULL)
	{
		if (p != NULL && strcmp(p->type, type) == 0)
		{
			printf("书名:%s", p->name);
			printf("  	作者名:%s", p->author);
			printf("  	图书类别:%s", p->type);
			printf("  	价格:%f", p->price);
			printf("  	数量:%d", p->num);
			printf("\n");
		}
		p = p->next;
	}

	printf("按任意键返回！");
	getchar();
	findBook();
}

void find_price_book()//按照price查询
{
	system("cls");
	struct BOOK *head, *p;
	head = readIn();
	float price;
	printf("请输入您要查询图书的price：");
	scanf("%f", &price);
	getchar();//接收回车字符用的 
	printf("\n正在查询....");
	p = head;
	printf("*************************图书信息*****************************\n");
	printf("--------------------------------------------------------------\n");

	while (p != NULL)
	{
		if (p != NULL && (p->price == price))
		{
			printf("书名:%s", p->name);
			printf("  	作者名:%s", p->author);
			printf("  	图书类别:%s", p->type);
			printf("  	价格:%f", p->price);
			printf("  	数量:%d", p->num);
			printf("\n");
		}
		p = p->next;
	}

	printf("按任意键返回！");
	getchar();
	findBook();
}

void printBook()//图书总览 
{
	system("cls");
	struct BOOK *head, *p;
	int sum = 0;
	head = readIn();
	printf("*********************************************图书信息**********************************************\n");
	printf("---------------------------------------------------------------------------------------------------\n");
	if (head == NULL)
	{
		printf("书库暂时没有书哦~赶快去添加几本吧(￣.￣)(按任意键返回)");
		getchar();
		menu();
	}
	p = head;
	while (p != NULL)
	{
		printf("书名:%s", p->name);
		printf("  	作者名:%s", p->author);
		printf("  	图书类别:%s", p->type);
		printf("  	价格:%f", p->price);
		printf("  	数量:%d", p->num);
		printf("\n");
		sum += p->num;// 图书总数量
		p = p->next;
	}
	printf("图书总数量为：%d\n", sum);
	printf("按任意键返回");
	getchar();
	getchar();
}

void over()//结束程序 
{
	char t;
	printf("      -----------------------\n");
	printf("      |   您确定要退出吗？  |\n");
	printf("      | 1.确定     2.取消   |\n");
	printf("      -----------------------\n");
	printf("      指令：");
	while (1)
	{
		t = getchar();         //输入t
		switch (t)
		{
		case '1':
			printf("正在安全退出....\n");
			printf("已安全退出软件\n");
			printf("感谢使用！\n");
			printf("^_^  ^_^  ^_^");
			exit(0);
			break; //终止程序
		case '2':
			menu();
			break;   //调用函数，进入菜单 
		default:
			break;
		}
	}
}