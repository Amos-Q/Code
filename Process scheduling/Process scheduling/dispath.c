#define _CRT_SECURE_NO_WARNINGS 1
#include "home.h"

void display(struct Node job[10],int num)
{
	int ch = 0;
	printf("1��FCFS�㷨\n");
	printf("2��SJF�㷨\n");
	printf("3��RR�㷨\n");
	printf("4�����ȼ��㷨\n");
	printf("5���˳�\n");
	do {
		printf("��ѡ��:");
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
			Priority_sort(job, num);
			print(job, num);
			break;
		case 5:
			printf("�˳�!");
			break;
		default:
			printf("�����������������!\n");
			break;
		}
	} while (ch != 5);
}

void Arrive_sort(struct Node job[10], int num)//����ʱ���С��������
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

void fcfs(struct Node job[10], int num)//�����ȷ���
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

void Service_sort(struct Node job[10], int num)//����ʱ������
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

void sjf(struct Node job[10], int num)//����ҵ����
{
	int i = 0;
	int faile = 0;
	char temp1 = 0;
	int temp2 = 0;
	int temp3 = 0;
	for (i = 0; i < num;)
	{
		job[0].Taccomplish = job[0].Tservice;
		if (job[i].Tarrive <= job[i - 1].Taccomplish)
		{
			job[i].Taccomplish = job[i - 1].Taccomplish + job[i].Tservice;
		}
		else
		{
			faile = i+1;
			for (; faile < num; faile++)
			{
				if (job[faile].Tarrive <= job[i - 1].Taccomplish)
				{
					temp1 = job[faile].name;
					temp2 = job[faile].Tarrive;
					temp3 = job[faile].Tservice;
					for (faile; faile > i;faile--)
					{
						job[faile].name = job[faile - 1].name;
						job[faile].Tarrive = job[faile - 1].Tarrive;
						job[faile].Tservice = job[faile - 1].Tservice;
					}
					job[i].name = temp1;
					job[i].Tarrive = temp2;
					job[i].Tservice = temp3;
					job[i].Taccomplish = job[i - 1].Taccomplish + job[i].Tservice;
					break;
				}
			}
		}
		i++;
	}
}

void RR(struct Node job[10], int num)//RR�㷨
{
	int q;
	printf("������ʱ��Ƭ����:");
	scanf("%d", &q);
	int flag = 1;
	int finish_pro = 0;
	printf("��������\t""��ʼʱ��\t""����ʱ��\t""ʣ�����ʱ��\t""����ʱ��\t\n");
	int time;
	int c = 0;
	while (finish_pro < num)
	{
		flag = 0;
		for (int i = c; i < num; i++)
		{
			Arrive_sort(job, num);
			job[i].Tsurplus = job[i].Tservice;
			job[i].Tstart = job[i - 1].Taccomplish;
			if (job[i].Tstart < job[i].Tarrive)
			{
				job[i].Tstart = job[i].Tarrive;
			}
			else
			{
				job[i].Tstart = job[i - 1].Taccomplish;
			}
			time = job[i].Tstart;
			if (job[i].if_finish == 1) continue;
			else
			{
				if (job[i].Tsurplus <= q && time >= job[i].Tarrive)
				{
					flag = 1;
					time = time + job[i].Tsurplus;
					job[i].if_finish = 1;//�ý������
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
				if (job[i].if_finish == 1) finish_pro++;//һ��������ɼ�һ
			}
			c++;
		}break;
		if (flag == 0 && finish_pro < num)//ûִ������û�����������
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

void Priority_sort(struct Node job[10], int num)//����ռ���ȼ��㷨
{
	int i = 0;
	printf("�������������ȼ�:\n");
	for (i = 0; i < num; i++)
	{
		scanf("%d", &job[i].prio);
	}
	char temp1 = 0;
	int temp2 = 0;
	int temp3 = 0;
	int temp4 = 0;
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
				job[i].prio = temp4;
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
	printf("������\t    ����ʱ��\t    ����ʱ�� \t   ���ʱ��\n");

	for (int i = 0; i < num; i++)
	{
		printf("%c\t\t%d\t\t%d\t\t%d\n", job[i].name, job[i].Tarrive, job[i].Tservice, job[i].Taccomplish);
	}
}