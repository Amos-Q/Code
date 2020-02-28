#define _CRT_SECURE_NO_WARNINGS 1
#include "all.h"

void filew(struct student stu[N]) {
	FILE *fp;
	int i, no = 0;
	if ((fp = fopen("student.txt", "r")) == NULL)
	{
		printf("文件打开失败!\n");
		//exit(1);  
	}
	for (i = 0; i < N && !feof(fp); i++)
	{
		fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
			stu[i].num, stu[i].name, stu[i].sex, stu[i].Id, stu[i].pass, stu[i].isbd, stu[i].dormitory, stu[i].cad);
		no++;
	}
	sum = no;
	fclose(fp);
	/*for(i=0;i<no&&stu[i].num[0];i++)
	 printf("学号：%s\t姓名：%s\t性别：%s\t省份证号：%s\t密码：%s\t报到：%s\t宿舍：%s\t班级：%s\n",
   stu[i].num,stu[i].name,stu[i].sex,stu[i].Id,stu[i].pass,stu[i].isbd,stu[i].dormitory,stu[i].cad);*/
}
//进入系统界面
int in() {
	system("cls");  //清屏函数
	printf("\t\t\t┌──────────────────────────────┐\n");
	printf("\t\t\t│                              │\n");
	printf("\t\t\t│      新生入学管理系统        │\n");
	printf("\t\t\t│                              │\n");
	printf("\t\t\t│           欢迎使用           │\n");
	printf("\t\t\t│                              │\n");
	printf("\t\t\t│           1.管理员           │\n");
	printf("\t\t\t│                              │\n");
	printf("\t\t\t│           2.新学生           │\n");
	printf("\t\t\t│                              │\n");
	printf("\t\t\t│           0.退出             │\n");
	printf("\t\t\t│                              │\n");
	printf("\t\t\t└──────────────────────────────┘\n");
	//getch();
	int flag;
	printf("请选择身份进入系统:");
	scanf("%d", &flag);
	return flag;
}
//T1.添加学生信息 
void Insert(struct student stu[N]) {
	FILE *fp;
	int i, j, k = 0;
	char name[10];
	if ((fp = fopen("student.txt", "a")) == NULL)
	{
		printf("文件打开失败!");
		exit(1);
	}
	printf("添加学生人数:");
	scanf("%d", &i);
	while (j < i) {
	input:printf("请输入第%d个学生学号：", j + 1);
		scanf("%s", name);
		for (k = 0; k < sum + j; k++)
			if (strcmp(name, stu[k].num) == 0)
			{
				printf("该学号已存在！\n");
				goto input;
			}
		if (k == sum + j) {
			strcpy(stu[sum + j].num, name);
			strcpy(stu[sum + j].pass, "123456");
			strcpy(stu[sum + j].isbd, "未");
			printf("请依次按写顺序输入学生信息：\n姓名\t性别\t身份证号\t\t宿舍\t班级\n");
			scanf("%s\t%s\t%s\t%s\t%s",
				stu[sum + j].name, stu[sum + j].sex, stu[sum + j].Id, stu[sum + j].dormitory, stu[sum + j].cad);
			fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
				stu[sum + j].num, stu[sum + j].name, stu[sum + j].sex, stu[sum + j].Id, stu[sum + j].pass, stu[sum + j].isbd, stu[sum + j].dormitory, stu[sum + j].cad);
			j++;
		}
	}
	sum = sum + i;
	fclose(fp);
	printf("添加成功，按任意键返回主页面!\n");
	getch();
}
//T2.修改学生信息 
void Update(struct student stu[N]) {
	FILE *fp;
	char i[10];
	int j = 0, k, n, m;
input:printf("请输入修改学生信息的学号:");
	scanf("%s", &i);
	for (k = 0; k < sum; k++) {
		//printf("\n%s\n%s\n",i,stu[k].num);
		if (strcmp(stu[k].num, i) == 0) {
			printf("该学生信息如下：\n学号\t姓名\t性别\t身份证号\t\t密码\t报到\t宿舍\t班级\n");
			printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
				stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory, stu[k].cad);
			break;
		}
	}
	if (k == sum) {
		printf("你输入错误，请重新输入！\n");
		goto input;
	}
	printf("请输入要修改的个数:");
	scanf("%d", &n);
	m = 0;
	while (m < n) {
		printf("请选择要修改的第%d个数据（1.学号|2.姓名|3.性别|4.份证号|5.密码|6.报到|7.宿舍|8.班级）：", m + 1);
		scanf("%d", &j);
		printf("请输入修改的数据：");
		switch (j)
		{
		case 1: scanf("%s", stu[k].num); break;
		case 2: scanf("%s", stu[k].name); break;
		case 3: scanf("%s", stu[k].sex); break;
		case 4: scanf("%s", stu[k].Id); break;
		case 5: scanf("%s", stu[k].pass); break;
		case 6: scanf("%s", stu[k].isbd); break;
		case 7: scanf("%s", stu[k].dormitory); break;
		case 8: scanf("%s", stu[k].cad); break;
		}
		m++;
	}
	if ((fp = fopen("student.txt", "w")) == NULL)
	{
		printf("文件打开失败!");
		exit(1);
	}
	k = 0;
	while (k < sum) {
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
			stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory, stu[k].cad);
		k++;
	}
	fclose(fp);
	printf("修改成功，按任意键返回主页面！\n");
	getch();
}
//T3.1查询分类 
int SelectCase(struct student stu[N], int k, int n) {
	n++;
	printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
		stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory, stu[k].cad);
	return n;
}
//T3.2查询结果 
int SelectAlsole(int n) {
	if (n == 0) {
		printf("不存在该数据，请重新输入！\n");
		return 1;
	}
	else {
		printf("成功查询到%d个学生信息，按任意键返回主页面！\n", n);
		getch();
		return 0;
	}
}
//T3.查询学生信息 
void Select(struct student stu[N]) {
	char cx[20];
	int j = 0, k, n = 0;
	struct student *p;
	p = stu;
	printf("请选择要查询的数据（1.学号|2.姓名|3.性别|4.份证号|5.密码|6.报到|7.宿舍|8.班级）：");
	scanf("%d", &j);
input:printf("请输入要查询的数据：");
	scanf("%s", &cx);
	printf("查询结果如下：\n学号\t姓名\t性别\t身份证号\t\t密码\t报到\t宿舍\t班级\n");
	switch (j)
	{
	case 1: {
		for (k = 0; k < sum; k++) {
			//printf("\n%s\n%s\n",i,stu[k].num);
			if (strcmp(stu[k].num, cx) == 0) {
				n = SelectCase(p, k, n);
				break;
			}
		}
		if (SelectAlsole(n))
			goto input;
		break;
	}
	case 2: {
		for (k = 0; k < sum; k++) {
			//printf("\n%s\n%s\n",i,stu[k].num);
			if (strcmp(stu[k].name, cx) == 0) {
				n = SelectCase(p, k, n); break;
			}
		}
		if (SelectAlsole(n))
			goto input;
		break;
	}
	case 3: {
		for (k = 0; k < sum; k++) {
			//printf("\n%s\n%s\n",i,stu[k].num);
			if (strcmp(stu[k].sex, cx) == 0) {
				n = SelectCase(p, k, n);
			}
		}
		if (SelectAlsole(n))
			goto input;
		break;
	}
	case 4: {
		for (k = 0; k < sum; k++) {
			//printf("\n%s\n%s\n",i,stu[k].num);
			if (strcmp(stu[k].Id, cx) == 0) {
				n = SelectCase(p, k, n);
			}
		}
		if (SelectAlsole(n))
			goto input;
		break;
	}
	case 5: {
		for (k = 0; k < sum; k++) {
			//printf("\n%s\n%s\n",i,stu[k].num);
			if (strcmp(stu[k].pass, cx) == 0) {
				n = SelectCase(p, k, n);
			}
		}
		if (SelectAlsole(n))
			goto input;
		break;
	}
	case 6: {
		for (k = 0; k < sum; k++) {
			//printf("\n%s\n%s\n",i,stu[k].num);
			if (strcmp(stu[k].isbd, cx) == 0) {
				n = SelectCase(p, k, n);
			}
		}
		if (SelectAlsole(n))
			goto input;
		break;
	}
	case 7: {
		for (k = 0; k < sum; k++) {
			//printf("\n%s\n%s\n",i,stu[k].num);
			if (strcmp(stu[k].dormitory, cx) == 0) {
				n = SelectCase(p, k, n);
			}
		}
		if (SelectAlsole(n))
			goto input;
		break;
	}
	case 8: {
		for (k = 0; k < sum; k++) {
			//printf("\n%s\n%s\n",i,stu[k].num);
			if (strcmp(stu[k].cad, cx) == 0) {
				n = SelectCase(p, k, n);
			}
		}
		if (SelectAlsole(n))
			goto input;
		break;
	}
	}
}
//T4.删除学生信息
void Delete(struct student stu[N]) {
	FILE *fp;
	char sc[10];
	int k, n, j;
input:printf("请输入要删除的学生学号："); \
	scanf("%s", &sc);
	  for (k = 0; k < sum; k++) {
		  //printf("\n%s\n%s\n",i,stu[k].num);
		  if (strcmp(stu[k].num, sc) == 0) {
			  printf("该学生信息如下：\n学号\t姓名\t性别\t身份证号\t\t密码\t报到\t宿舍\t班级\n");
			  printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
				  stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory, stu[k].cad);
			  break;
		  }
	  }
	  if (k == sum) {
		  printf("没有该学号，请重新输入！\n");
		  goto input;
	  }
	  printf("是否删除该学生信息(1.是|2.否)：");
	  scanf("%d", &n);
	  if (n == 1)
	  {
		  for (k; k < sum; k++) {
			  strcpy(stu[k].num, stu[k + 1].num);
			  strcpy(stu[k].name, stu[k + 1].name);
			  strcpy(stu[k].sex, stu[k + 1].sex);
			  strcpy(stu[k].Id, stu[k + 1].Id);
			  strcpy(stu[k].pass, stu[k + 1].pass);
			  strcpy(stu[k].isbd, stu[k + 1].isbd);
			  strcpy(stu[k].dormitory, stu[k + 1].dormitory);
			  strcpy(stu[k].cad, stu[k + 1].cad);
		  }
		  if ((fp = fopen("student.txt", "w")) == NULL)
		  {
			  printf("文件打开失败!");
			  exit(1);
		  }
		  j = 0;
		  sum = sum - 1;
		  while (j < sum) {
			  fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
				  stu[j].num, stu[j].name, stu[j].sex, stu[j].Id, stu[j].pass, stu[j].isbd, stu[j].dormitory, stu[j].cad);
			  j++;
		  }
		  fclose(fp);
		  printf("删除成功,按任意健返回！");
		  getch();

	  }
	  else if (n == 2) {
		  printf("按任意健返回！");
		  getch();
	  }
	  else {
		  printf("你的输入有误，请重新输入！");
		  goto input;
	  }
}
//T5.汇总新生
void All(struct student stu[N]) {
	int k;
	printf("汇总%d个学生信息如下：\n学号\t姓名\t性别\t身份证号\t\t密码\t报到\t宿舍\t班级\n", sum);
	for (k = 0; k < sum; k++) {
		printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
			stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory, stu[k].cad);
	}
	printf("按任意件返回！");
	getch();
}

//S1. 查看状态和注册报到
void Register(struct student stu[N]) {
	int i, k;
	FILE *fp;
	printf("注册报到流程:\n巡天楼注册缴费->宿舍楼领取钥匙->食堂办理饭卡->图书馆办理借书证->注册报到成功\n");
	printf("你的报到状态是：");
	if (strcmp(stu[Sid].isbd, "已") == 0) {
		printf("已报到\n");
		printf("按任意健返回！");
		getch();
	}
	else {
		printf("未报到\n");
		printf("你确认已完成流程并且注册报到（1.是|2.否）：");
		scanf("%d", &i);
		if (i == 1) {
			strcpy(stu[Sid].isbd, "已");
			if ((fp = fopen("student.txt", "w")) == NULL)
			{
				printf("文件打开失败!");
				exit(1);
			}
			k = 0;
			while (k < sum) {
				fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
					stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory, stu[k].cad);
				k++;
			}
			fclose(fp);
			printf("注册成功，按任意键返回主页面！\n");
			getch();
		}
	}
}
//S2. 查看和修改个人信息
void LookUpdatePersonal(struct student stu[N]) {
	FILE *fp;
	char i[10];
	int j = 0, k, n = 5, m;
	printf("你的个人信息如下：\n学号\t姓名\t性别\t身份证号\t\t密码\t报到\t宿舍\t班级\n");
	printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
		stu[Sid].num, stu[Sid].name, stu[Sid].sex, stu[Sid].Id, stu[Sid].pass, stu[Sid].isbd, stu[Sid].dormitory, stu[Sid].cad);
	printf("请输入要修改的个数（1-4,输入0返回）:");
	scanf("%d", &n);
	if (n == 0)
		goto input;
	m = 0;
	while (m < n) {
		printf("请选择要修改的第%d个数据（1.性别|2.份证号|3.密码|4.报到）：", m + 1);
		scanf("%d", &j);
		printf("请输入修改的数据：");
		switch (j)
		{
		case 1: scanf("%s", stu[Sid].sex); break;
		case 2: scanf("%s", stu[Sid].Id); break;
		case 3: scanf("%s", stu[Sid].pass); break;
		case 4: scanf("%s", stu[Sid].isbd); break;
		}
		m++;
	}
	if ((fp = fopen("student.txt", "w")) == NULL)
	{
		printf("文件打开失败!");
		exit(1);
	}
	k = 0;
	while (k < sum) {
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
			stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory, stu[k].cad);
		k++;
	}
	fclose(fp);
	printf("修改成功!");
input:printf("按任意键返回主页面！\n");
	getch();
}
//S3. 查看宿舍和班级情况
void DormitoryCnd(struct student stu[N]) {
	char cx[20];
	int j = 0, k, n = 0;
	printf("请选择要查询的数据（1.宿舍|2.班级|3.返回）：");
	scanf("%d", &j);
	if (j == 1)
	{
		printf("查询结果如下：\n学号\t姓名\t报到\t宿舍\t班级\n");
		for (k = 0; k < sum; k++) {
			if (strcmp(stu[Sid].dormitory, stu[k].dormitory) == 0) {
				n++;
				printf("%s\t%s\t%s\t%s\t%s\n",
					stu[k].num, stu[k].name, stu[k].isbd, stu[k].dormitory, stu[k].cad);
			}
		}
		printf("成功查询到%d个学生信息，按任意键返回主页面！\n", n);
		getch();
	}
	else if (j == 2) {
		printf("查询结果如下：\n学号\t性别\t姓名\t报到\t宿舍\t班级\n");
		for (k = 0; k < sum; k++) {
			if (strcmp(stu[Sid].cad, stu[k].cad) == 0) {
				n++;
				printf("%s\t%s\t%s\t%s\t%s\t%s\n",
					stu[k].num, stu[k].name, stu[k].sex, stu[k].isbd, stu[k].dormitory, stu[k].cad);
			}
		}
		printf("成功查询到%d个学生信息，按任意键返回主页面！\n", n);
		getch();
	}
	else
		;
}
//新生登录审核、主页 
void Student(struct student stu[N]) {
	int i, n = 0;
	struct student *p;
	p = stu;
input:printf("请输入学号：");
	char num[10];
	scanf("%s", &num);
	//gets(num);
	printf("请输入密码：");
	char pass[10];
	scanf("%s", &pass);
	//gets(passgl);
	for (i = 0; i < sum; i++)
	{
		//printf("%d\n%s\t%s\n%s\t%s\n",i,num,pass,stu[i].num,stu[i].pass);
		if (strcmp(stu[i].num, num) == 0 && strcmp(stu[i].pass, pass) == 0) {
			Sid = i;
			break;
		}
	}
	if (i == sum) {
		printf("你输入错误，请重新输入！\n");
		goto input;
	}
	while (n < 4)
	{
		system("cls");
		printf("\t\t\t┌────────────────────────────────┐\n");
		printf("\t\t\t│             学生               │\n");
		printf("\t\t\t├────────────────────────────────┤\n");
		printf("\t\t\t│      1. 查看状态和注册报到     │\n");
		printf("\t\t\t│      2. 查看和修改个人信息     │\n");
		printf("\t\t\t│      3. 查看宿舍和班级情况     │\n");
		printf("\t\t\t│      0. 退出                   │\n");
		printf("\t\t\t│                                │\n");
		if (Sid != (-1)) {
			printf("\t\t\t│         欢迎%s登录！         │\n", stu[Sid].name);
		}
		printf("\t\t\t└────────────────────────────────┘\n\n");
		printf("请选择（0-3）：");
		scanf("%d", &n);
		switch (n)
		{
		case 1: Register(p); break;
		case 2: LookUpdatePersonal(p); break;
		case 3: DormitoryCnd(p); break;
			//case 0:exit(1);
		case 0: n = 4; break;
		}
	}
}
