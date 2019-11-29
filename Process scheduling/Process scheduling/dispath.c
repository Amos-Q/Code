#define _CRT_SECURE_NO_WARNINGS 1
#include "home.h"

void display(struct Node job[10],int num)
{
	int ch = 0;
	printf("—————————————————————————\n");
	printf("——————————1、FCFS算法 —————————\n");
	printf("——————————2、SJF算法——————————\n");
	printf("——————————3、RR算法 ——————————\n");
	printf("——————————4、优先级算法 ————————\n");
	printf("——————————5、退出 ———————————\n");
	printf("—————————————————————————\n");
	do {
		printf("请选择:");
		scanf("%d", &ch);
		switch (ch) {
		case 1:
			Arrive_sort(job,num);
			fcfs(job, num);
			print(job,num);
			break;
		case 2:
			Service_sort(job, num);
			sjf(job,num);
			print(job,num);
			break;
		case 3:
			RR(job,num);
			break;
		case 4:
			Arrive_sort(job, num);
			Priority_sort(job, num);
			print(job, num);
			break;
		case 5:
			printf("退出!");
			break;
		default:
			printf("输入错误，请重新输入!\n");
			break;
		}
	} while (ch != 5);
}

void Arrive_Short_sort(struct Node job[10], int num)//到达时间从小到大排序
{
	int temp1, temp2, temp3;
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].Tarrive > job[j].Tarrive)
			{
				temp1 = job[j].name;
				job[j].name = job[i].name;
				job[i].name = temp1;
				temp2 = job[j].Tarrive;
				job[j].Tarrive = job[i].Tarrive;
				job[i].Tarrive = temp2;
				temp3 = job[j].Tservice;
				job[j].Tservice = job[i].Tservice;
				job[i].Tservice = temp3;
			}
		}
	}
}

void fcfs(struct Node job[10], int num)//先来先服务
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		if (i > 0)
			job[i].Taccomplish = job[i - 1].Taccomplish + job[i].Tservice;
		else
			job[i].Taccomplish = job[i].Tservice;
	}
}

void Service_sort(struct Node job[10], int num)//服务时间排序
{
	int temp1, temp2, temp3;
	for (int i = 1; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].Tservice > job[j].Tservice)
			{
				temp1 = job[j].name;
				job[j].name = job[i].name;
				job[i].name = temp1;
				temp2 = job[j].Tarrive;
				job[j].Tarrive = job[i].Tarrive;
				job[i].Tarrive = temp2;
				temp3 = job[j].Tservice;
				job[j].Tservice = job[i].Tservice;
				job[i].Tservice = temp3;
			}
		}
	}
}

void sjf(struct Node job[10], int num)//短作业优先
{
	int i = 0;
	int faile = 0;
	while(num)
	{
		static i = 1;
		if (job[i].Tstart < job[i - 1].Taccomplish)
		{
			job[i].Taccomplish = job[i].Tarrive + job[i].Tservice;
			i++;
			num--;
		}
		else
			faile = i;
	}
}


void RR(struct Node job[10], int num)//RR算法
{
	int q;
	printf("请输入时间片长度:");
	scanf("%d", &q);
	int flag = 1;//标志队列中是否还有进程
	int finish_pro = 0;//完成的进程数
	printf("进程名称\t""开始时间\t""运行时间\t""剩余服务时间\t""结束时间\t\n");
	int time;//记录当前时刻时间
	int c = 0;
	while (finish_pro < num)
	{
		flag = 0;//就绪队列里没进程
		for (int i = c; i < num; i++)
		{
			Arrive_sort(job, num);
			job[i].Tsurplus = job[i].Tservice;
			job[i].Tstart = job[i - 1].Taccomplish;//上一个作业结束时间
			if (job[i].Tstart < job[i].Tarrive)//该作业的开始时间小于到达时间
			{
				job[i].Tstart = job[i].Tarrive;
			}
			else
			{
				job[i].Tstart = job[i - 1].Taccomplish;
			}
			time = job[i].Tstart;
			if (job[i].if_finish == 1) continue;//该进程已完成
			else
			{
				if (job[i].Tsurplus <= q && time >= job[i].Tarrive)//未完成且少于一个时间片
				{
					flag = 1;
					time = time + job[i].Tsurplus;
					job[i].if_finish = 1;//该进程完成
					job[i].Taccomplish = time;
					printf("%c\t\t%d\t\t%d\t\t%d\t\t%d\n", job[i].name, job[i].Taccomplish - job[i].Tsurplus, job[i].Tsurplus, 0, job[i].Taccomplish);
					job[i].Tsurplus = 0;
				}
				else if (job[i].Tsurplus > q && time >= job[i].Tarrive)
				{
					flag = 1;
					time = time + q;
					job[i].Tsurplus -= q;
					job[i].Taccomplish = time;
					printf("%c\t\t%d\t\t%d\t\t%d\t\t%d\n", job[i].name, time - q, q, job[i].Tsurplus, job[i].Taccomplish);
					job[num].name = job[i].name;
					job[num].Tarrive = time;
					job[num].Tservice = job[i].Tsurplus;
					num++;
				}
				if (job[i].if_finish == 1) finish_pro++;//一个进程完成加一
			}
			c++;
		}break;
		if (flag == 0 && finish_pro < num)//没执行完且没进入就绪队列
		{
			for (int i = 0; i < num; i++)
			{
				if (job[i].if_finish == 0)
				{
					time = job[i].Tarrive;
					break;
				}
			}
		}
	}
}

void Priority_sort(struct Node job[10], int num)//非抢占优先级算法
{
	int i = 0;
	printf("请依次输入优先级:\n");
	for (i = 0; i < num; i++)
	{
		scanf("%d", &job[i].prio);
	}
	int temp1, temp2, temp3, temp4;
	for (i = 1; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].prio < job[j].prio)
			{
				temp1 = job[j].name;
				job[j].name = job[i].name;
				job[i].name = temp1;
				temp2 = job[j].Tarrive;
				job[j].Tarrive = job[i].Tarrive;
				job[i].Tarrive = temp2;
				temp3 = job[j].Tservice;
				job[j].Tservice = job[i].Tservice;
				job[i].Tservice = temp3;
				temp4 = job[j].prio;
				job[j].prio = job[i].prio;
				job[i].prio = temp3;
			}
		}
	}
	for (i = 0; i < num; i++)
	{
		if (i > 0)
			job[i].Taccomplish = job[i - 1].Taccomplish + job[i].Tservice;
		else
			job[i].Taccomplish = job[i].Tservice;
	}
}

void print(struct Node job[10], int num)
{
	printf("进程名\t    到达时间\t    服务时间 \t   完成时间\n");

	for (int i = 0; i < num; i++)
	{
		printf("%c\t\t%d\t\t%d\t\t%d\n", job[i].name, job[i].Tarrive, job[i].Tservice, job[i].Taccomplish);
	}
}