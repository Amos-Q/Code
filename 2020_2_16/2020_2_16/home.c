#define _CRT_SECURE_NO_WARNINGS 1

#include "home.h"

/* 子  函  数*/
void a() /* 输入一个班的学生记录*/

{
	int i;

	for (i = 0; i < 4; i++)

	{

		printf("请输入学号 姓名 平时成绩 实验成绩 考试成绩：");

		scanf("%d%s%f%f%f", &stu[i].num, stu[i].name, &stu[i].pingshi, &stu[i].shiyan, &stu[i].kaoshi);

	}for (i = 0; i < 4; i++)
		stu[i].zongping = 0.1*stu[i].pingshi + 0.3*stu[i].shiyan + 0.6*stu[i].kaoshi;
}
void b()/* 显示所有记录*/

{
	int i;

	printf("学号        姓名       平时成绩       实验成绩      考试成绩     总评成绩\n");

	for (i = 0; i < 4; i++)

		printf("%d%14.2s%14.2f%14.2f%14.2f%14.2f\n", stu[i].num, stu[i].name, stu[i].pingshi, stu[i].shiyan, stu[i].kaoshi, stu[i].zongping);

}

void c()/* 求出全班平均成绩，显示均方差*/
{
	int a[4] = { 0,1,2,3 };
	int i, j;
	double total = 0, pfc = 0, bzc = 0;
	double ave;
	for (i = 0; i < 4; i++)
	{
		total = total + stu[i].zongping;
	}
	ave = total / 4.0;
	printf("总评平均成绩是%f\n", ave);
	for (i = 0; i < 4; i++)
	{
		pfc = pow((stu[i].zongping - ave), 2) / 4;
	}
	bzc = sqrt(pfc);
	printf("\n平方差是%f\n", pfc);
	printf("\n标准差是%f\n", bzc);
}
void d()

{
	int a[4] = { 0,1,2,3 };
	int i, j, temp;
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 3 - j; i++)
			if (stu[a[i]].zongping > stu[a[i + 1]].zongping)
			{
				temp = a[i]; a[i] = a[i + 1];
				a[i + 1] = temp;

			}
	}

	printf("顺序为:\n");

	printf("学号     姓名      总评成绩\n");

	for (i = 0; i < 4; i++)

		printf("%d%10.2s%15.2f\n", stu[a[i]].num, stu[a[i]].name, stu[a[i]].zongping);

	printf("\n");

}

void e()
{
	int i;
	FILE *fp;
	fp = fopen("chengji.txt", "w");

	fprintf(fp, "学号        姓名       平时成绩       实验成绩      考试成绩     总评成绩\n");

	for (i = 0; i < 4; i++)

		fprintf(fp, "%d%14.2s%14.2f%14.2f%14.2f%14.2f\n", stu[i].num, stu[i].name, stu[i].pingshi, stu[i].shiyan, stu[i].kaoshi, stu[i].zongping);

	printf("\n\n*******************恭喜，保存完成！*******************\n\n");
}