#define _CRT_SECURE_NO_WARNINGS 1
#include "home.h"

void mainmenuface() {

	char menu[] = {
		"欢迎来到我们的通讯录系统！！！\n制作人：201816404何鹏飞\t\t\t201816406张锦渊\n"
	};

	int i;
	for (i = 0; menu[i] != '\0'; i++) {
		Sleep(30);
		printf("%c", menu[i]);
	}
	printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");
	printf("☆********************************************************************★\n");
	printf("★                          通讯录管理系统                            ☆\n");
	printf("☆                                                                    ★\n");
	printf("★          1.新建联系人信息               5.保存联系人信息           ☆\n");
	printf("☆                                                                    ★\n");
	printf("★          2.浏览所有联系人               6.添加联系人信息           ☆\n");
	printf("☆                                                                    ★\n");
	printf("★          3.修改联系人信息               7.删除联系人信息           ☆\n");
	printf("☆                                                                    ★\n");
	printf("★          4.查找联系人信息               8.返回主菜单               ☆\n");
	printf("☆********************************************************************★\n");
	printf("★                          输入9退出系统                             ☆\n");
	printf("☆          -------------------------------------------               ★\n");
}
void show_one(phone *p) {
	printf("姓名:%s\t\t", p->name);
	printf("序号:%d\n", p->sign);
	printf("籍贯:%s\t", p->home);
	printf("电话号码1:%s\t", p->phone1);
	printf("电话号码2:%s\t", p->phone2);
	printf("电子邮箱:%s\n", p->email);
}

phone * Lookdata(phone *p1) {
	phone *p2;
	p2 = head;
	printf("\n\t\t\t☆☆☆显示数据☆☆☆\n");
	printf("----------------------------------------------------------------------\n");
	while (p2 != NULL) {
		printf("姓名:%s\t\t", p2->name);
		printf("序号:%d\n", p2->sign);
		printf("籍贯:%s\t", p2->home);
		printf("电话号码1:%s\t", p2->phone1);
		printf("电话号码2:%s\t", p2->phone2);
		printf("电子邮箱:%s\t", p2->email);
		printf("\n\n");
		printf("----------------------------------------------------------------------\n");
		p2 = p2->next;
	}
	return p2;
}

phone * Inputdata() {
	phone*p1, *p2, *p3;
	int flag = 1;
	int k = 1, i = 1, max;

	p1 = p2 = (phone*)malloc(len);
	head = NULL;

	printf("\n\t\t\t☆☆☆新建联系人信息☆☆☆\n");
	if (p1 != NULL) {
		head = p1;
		while (flag) {
			printf("----------------------------------------------------------------------\n");
			printf("请输入要录入联系人的姓名（姓名一栏中输入over结束）\n");
			p3 = head;
			scanf("%s", p1->name);
			if (strcmp(p1->name, "over") != 0) {



				p3 = head;
				while (i < k) {
					i++;
					if (strcmp(p1->name, p3->name) == 0) {
						if (p3->sign > max)max = p3->sign;
					}
					p3 = p3->next;
				}
				p1->sign = ++max;
				max = 0;

				p1->sign = 1;

				printf("请输入要录入联系人的籍贯\n");
				scanf("%s", p1->home);
				printf("请输入要录入联系人的电话1\n");
				scanf("%s", p1->phone1);
				printf("请输入要录入联系人的电话2\n");
				scanf("%s", p1->phone2);
				printf("请输入要录入联系人的电子邮箱\n");
				scanf("%s", p1->email);
				p2->next = p1;
				p2 = p1;
				p1 = (phone*)malloc(len);
				p1->next = NULL;
				k++;
				printf("----------------------------------------------------------------------\n");


			}

			else {
				flag = 0;
				p1->next = NULL;
				free(p1);
				printf("-----------------输入成功！退出时勿忘输入5保存信息！------------------\n");
				printf("----------------------------------------------------------------------\n");
			}
		}
	}
	return (head);
}

void readfile() {
	FILE *fp;
	phone *p1, *p2, *p4, *p5;
	p1 = p2 = (phone *)malloc(len);
	int flag = 1;
	head = NULL;
	if ((fp = fopen("通讯录", "r")) == NULL) {
		printf("未建立通讯录，请输入1新建联系人！\n");
	}
	else {
		if (p1 != NULL)head = p1;
		while (1) {
			if (!feof(fp)) {
				fscanf(fp, "%s%d%s%s%s%s", p1->name, &p1->sign, p1->home, p1->phone1, p1->phone2, p1->email);
				p2->next = p1;
				p5 = p2;
				p2 = p1;
				p1 = (phone *)malloc(len);
			}
			else {
				p5->next = NULL;

				break;
			}

		}

	}
	fclose(fp);
}

Seek(phone *p2) {
	char name[20];
	char ch1[5], ch2[5];
	memset(ch1, '\0', sizeof(ch1));
	memset(ch2, '\0', sizeof(ch2));
	int b;
	int n;
	printf("\n\t\t\t☆☆☆查找数据☆☆☆\n");
	printf("----------------------------------------------------------------------\n");
	printf("---------------------------按姓名请输入1:-----------------------------\n");
	printf("---------------------------按姓氏请输入2:-----------------------------\n");
	printf("请输入您的选择："); scanf("%d", &n);
	getchar();
	printf("请输入需要查找的姓名：");
	switch (n) {
	case 1:
		b = 0;
		scanf("%s", name);
		while (p2 != NULL) {
			if (strcmp(name, p2->name) == 0) {
				printf("你要找到的数据\n");
				printf("姓名:%s\t\t", p2->name);
				printf("序号:%d\n", p2->sign);
				printf("籍贯:%s\t", p2->home);
				printf("电话号码1:%s\t", p2->phone1);
				printf("电话号码2:%s\t", p2->phone2);
				printf("电子邮箱:%s\n", p2->email);
				printf("----------------------------------------------------------------------\n");
				b = 1;
			}
			p2 = p2->next;
		}
		if (b == 0) {
			printf("\n--------------------您要查找的人不存在!--------------------------------\n");
		}
		break;
	case 2:
		b = 0;
		printf("请输入姓：");
		scanf("%s", ch1);
		while (p2 != NULL) {
			strncpy(ch2, p2->name, 2);
			if (strcmp(ch1, ch2) == 0) {
				printf("你要找到的数据\n");
				printf("姓名:%s\t\t", p2->name);
				printf("序号:%d\n", p2->sign);
				printf("籍贯:%s\t", p2->home);
				printf("电话号码1:%s\t", p2->phone1);
				printf("电话号码2:%s\t", p2->phone2);
				printf("电子邮箱:%s\n", p2->email);
				printf("----------------------------------------------------------------------\n");
				b = 1;
			}
			p2 = p2->next;
		}
		if (b == 0) {
			printf("\n--------------------您要查找的姓不存在!--------------------------------\n");
		}

	}

}
Keepdata(phone *p2) {
	FILE *fp;

	printf("\n\t\t\t☆☆☆保存数据☆☆☆\n");
	printf("----------------------------------------------------------------------\n");
	if ((fp = fopen("通讯录", "w")) == NULL) {
		printf("cannot open this file\n");
		exit(0);
	}
	while (p2 != NULL) {
		fprintf(fp, "%s\t", p2->name);
		fprintf(fp, "%d\t", p2->sign);
		fprintf(fp, "%s\t", p2->home);
		fprintf(fp, "%s\t", p2->phone1);
		fprintf(fp, "%s\t", p2->phone2);
		fprintf(fp, "%s\t", p2->email);
		p2 = p2->next;
		fputc('\n', fp);
	}
	printf("\n------------------------------保存成功!-----------------------------\n");
	printf("---------------------------------------------------------------------\n");
	fclose(fp);
}

Changedata(phone *p) {
	char name[20];
	int k, flag = 1;
	printf("\n\t\t\t☆☆☆修改数据☆☆☆\n");
	printf("----------------------------------------------------------------------\n");
	printf("---------------------请输入需要修改的联系人姓名：---------------------\n");
	scanf("%s", name);
	while (p != NULL) {
		if (strcmp(p->name, name) == 0) {
			show_one(p);
			flag = 0;
			printf("\n------------------请选择要修改的信息:---------------------------\n");
			printf("+------------------------------------------------+\n");
			printf("|                                                |\n");
			printf("|          1.姓名              4.手机2           |\n");
			printf("|                                                |\n");
			printf("|          2.户籍              5.电子邮箱        |\n");
			printf("|                                                |\n");
			printf("|          3.手机1                               |\n");
			printf("|                                                |\n");
			printf("+------------------------------------------------+\n");
			scanf("%d", &k);
			switch (k) {
			case 1: printf("-------------------输入修改后的姓名：------------------\n");
				scanf("%s", p->name);
				break;

			case 2: printf("-------------------输入修改后的户籍：------------------\n");
				scanf("%s", p->home);
				break;

			case 3: printf("-------------------输入修改后的手机1：-----------------\n");
				scanf("%s", p->phone1);
				break;

			case 4: printf("-------------------输入修改后的手机2：-----------------\n");
				scanf("%s", p->phone2);
				break;

			case 5: printf("--------------------输入修改后的邮箱：------------------\n");
				scanf("%s", p->email);
				break;

			}
			printf("-----------------------修改成功！-------------------------------------\n");
			printf("----------------------------------------------------------------------\n");
			break;
		}
		else p = p->next;

	}
	if (flag)printf("------------------------查无此人！------------------------------------\n");
	printf("----------------------------------------------------------------------\n");

}

void deletedata() {
	phone *p1, *p2;
	phone *p3;
	char name[20];
	int n, k = 1;
	printf("\n\t\t\t☆☆☆删除数据☆☆☆\n");
	printf("----------------------------------------------------------------------\n");
	printf("输入您想删除的联系人姓名：\n");
	scanf("%s", name);
	p1 = head;
	if (head == NULL) {
		printf("未建立联系人信息，通讯录为空\n");
		return;
	}
	/*if(strcmp(p1->name,name)==0 ){
	head=p1->next ;
		printf("------------------------------删除成功！------------------------------\n");
}
   else{ */
	printf("请选择你要删除的人：\n");
	printf("----------------------------------------------------------------------\n");
	p3 = head;
	while (p3 != NULL) {
		if (strcmp(name, p3->name) == 0) {

			printf("姓名:%s\t\t", p3->name);
			printf("序号:%d\n", p3->sign);
			printf("籍贯:%s\t", p3->home);
			printf("电话号码1:%s\t", p3->phone1);
			printf("电话号码2:%s\t", p3->phone2);
			printf("电子邮箱:%s\n", p3->email);
			printf("\n\n");
			k = 0;
			printf("----------------------------------------------------------------------\n");
		}
		p3 = p3->next;
	}
	if (k) {
		printf("查无此人！\n");
		return;
	}
	printf("请输入您要删除的人序号：\n");
	scanf("%d", &n);
	while (p1 != NULL && (p1->sign != n || strcmp(p1->name, name) != 0)) {
		p2 = p1;
		p1 = p1->next;
	}
	if (p1 == NULL) {
		printf("查无此人！\n");
		return;
	}

	if (p1 != NULL) {
		p1 = p1->next;
		p2->next = p1;
		printf("------------------------------删除成功！------------------------------\n");
		return;
	}


	printf("----------------------------------------------------------------------\n");
}
void input(phone *p1) {
	printf("姓名:");
	scanf("%s", &p1->name);
	printf("户籍:");
	scanf("%s", &p1->home);
	printf("手机号1:");
	scanf("%s", &p1->phone1);
	printf("手机号2:");
	scanf("%s", &p1->phone2);
	printf("邮箱:");
	scanf("%s", &p1->email);
	p1->sign = 1;
}

void Insertdata() {
	char name2[20];
	int flag, max;
	phone *p1, *p2, *p3;
	phone *p4;
	p1 = head;
	p3 = (phone *)malloc(len);
	printf("\n\t\t\t☆☆☆添加联系人☆☆☆\n");
	printf("----------------------------------------------------------------------\n");
	printf("-------------------------请输入相关的数据：---------------------------\n");
	input(p3);
	p4 = head;


	max = 0;
	while (p4 != NULL) {
		if (strcmp(p3->name, p4->name) == 0) {
			if (p4->sign > max)max = p4->sign;
		}
		p4 = p4->next;
	}
	p3->sign = ++max;


	printf("-------------------------请输入插入的位置：---------------------------\n");
	printf("+---------------------------------------------------------+\n");
	printf("|                                                         |\n");
	printf("|                    1.首位置插入                         |\n");
	printf("|                                                         |\n");
	printf("|                    2.尾位置插入                         |\n");
	printf("|                                                         |\n");
	printf("|                    3.指定姓名前插入                     |\n");
	printf("+---------------------------------------------------------+\n");

	scanf("%d", &flag);
	switch (flag) {
	loop: case 1:
		p3->next = p1;
		head = p3;
		break;
	case 2:
		p2 = head;
		while (p2->next != NULL) {
			p2 = p2->next;
		}
		p2->next = p3;
		p3->next = NULL;
		break;
	case 3:
		printf("请输入您想插入的姓名前面：\n");
		scanf("%s", name2);
		while (p1->next != NULL && strcmp(p1->name, name2) != 0) {
			p2 = p1;
			p1 = p1->next;
		}
		if (p1 == head) {
			goto loop;
		}
		if (p1->next == NULL) {
			printf("------------------------------查无此人！---------------------------\n");
		}
		else {
			p3->next = p1;
			p2->next = p3;

		}
		break;
	}
	printf("------------------------------插入成功！------------------------------\n");
	printf("----------------------------------------------------------------------\n");
	return;
}
