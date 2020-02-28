#define _CRT_SECURE_NO_WARNINGS 1

#include "all.h"


//管理员登录审核、主页 
void gl(struct student stu[N]) {
	struct student *p;
	p = stu;
	int n = 0;
	char numgl[3] = { "t1" };
	char passgl[6] = { '1','2','3','4','5','6' };
input:printf("请输入管理账号：");
	char num[3];
	//gets(num);
	scanf("%s", &num);
	printf("请输入管理密码：");
	char pass[6];
	//gets(pass);
	scanf("%s", &pass);
	if (strcmp(numgl, num) != 0 || strcmp(passgl, pass) != 0)
	{
		printf("你输入错误，请重新输入！\n");
		//gl();
		goto input;
	}
	while (n < 6)
	{
		system("cls");
		printf("\t\t\t┌──────────────────────────────┐\n");
		printf("\t\t\t│             管理员           │\n");
		printf("\t\t\t├──────────────────────────────┤\n");
		printf("\t\t\t│      1. 添加学生             │\n");
		printf("\t\t\t│      2. 修改学生信息         │\n");
		printf("\t\t\t│      3. 查询学生信息         │\n");
		printf("\t\t\t│      4. 删除学生             │\n");
		printf("\t\t\t│      5. 汇总新生             │\n");
		printf("\t\t\t│      0. 退出                 │\n");
		printf("\t\t\t└──────────────────────────────┘\n\n");
		printf("请选择（0-5）：");
		scanf("%d", &n);
		switch (n)
		{
		case 1: Insert(p); break;
		case 2: Update(p); break;
		case 3: Select(p); break;
		case 4: Delete(p); break;
		case 5: All(p); break;
			//case 0:exit(1);
		case 0: n = 6; break;
		}
	}
}

//这是主函数 
int main() {
	int n, flag;
	struct student *p, stu[N];
	p = stu;
	filew(p);//读入数据 

	while (1) {
		flag = in();
		if (flag == 1)
			gl(p);
		else if (flag == 2)
			Student(p);
		else
			exit(1);
		//system("cls");  //清屏函数
	}
	return 0;
}