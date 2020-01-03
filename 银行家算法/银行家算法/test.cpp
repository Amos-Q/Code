#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX_PROCESS 100
#define MAX_RESOURCE 100
int Available[MAX_RESOURCE];                    //可用资源数组  
int Max[MAX_PROCESS][MAX_RESOURCE];            //最大需求矩阵  
int Allocation[MAX_PROCESS][MAX_RESOURCE];    //分配矩阵 
int Need[MAX_PROCESS][MAX_RESOURCE];     //需求矩阵  
int Request[MAX_PROCESS][MAX_RESOURCE];        //进程需要资源数 
int p[MAX_PROCESS];                             //记录序列
int n, m;                                    //n个进程,m个资源  
void Init()                //初始化算法  
{
	int i, j;
	printf("请输入进程的数目:\n");
	scanf("%d", &n);
	printf("请输入资源的种类:\n");
	scanf("%d", &m);
	printf("请输入每个进程最多所需的各资源数:\n", n, m);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &Max[i][j]);
		}
	}
	printf("请输入每个进程已分配的各资源数:\n", n, m);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &Allocation[i][j]);
			Need[i][j] = Max[i][j] - Allocation[i][j];
			if (Need[i][j] < 0)
			{
				printf("您输入的第%d个进程所拥有的第%d个资源数错误,请重新输入:\n", i + 1, j + 1);
				j--;
				continue;
			}
		}
	}
	printf("请输入各个资源现有的数目:\n");
	for (i = 0; i < m; i++)
	{
		scanf("%d", &Available[i]);
	}
}

bool Safe()    //安全性算法
{
	int i, j, k, l = 0;
	int Work[MAX_RESOURCE]; //工作数组,他表示系统可提供给进程继续运行所需的各类资源数目  
	int Finish[MAX_PROCESS];  //系统是否有足够的资源分配给进程，使之运行完成 
	for (i = 0; i < m; i++)   //工作数组初始化 
	{
		Work[i] = Available[i];
	}
	memset(Finish, 0, sizeof(Finish));
	for (i = 0; i < n; i++)
	{
		if (Finish[i]) continue;
		for (j = 0; j < m; j++)//循环查找第i个进程需要的各个资源数是否超过系统现有的对应的资源数  
		{
			//第i个进程需要的第j个资源数 ＞ 系统现有的第j个资源数 
			if (Need[i][j] > Work[j]) break;
		}
		if (j == m)//如果第i个进程所需的各个资源数都没有超过系统现有的对应资源数  
		{
			Finish[i] = 1;//给该进程的FINISH标记为true  
			for (k = 0; k < m; k++)
			{
				Work[k] += Allocation[i][k];//将Work赋值为 第i个进程各个已分配资源数＋系统现有的对应资源数(因为当改进程全部资源数都满足时线程结束并将资源返还给系统)  
			}
			p[l++] = i;//记录进程号  
			i = -1;
		}
		else continue; //如果超过继续循环下一个进程 
		if (l == n)//当所有进程都能够被满足运行时  
		{
			printf("系统是安全的\n");
			printf("安全序列为:\n");
			for (k = 0; k < l - 1; k++)
			{
				printf("%d-->", p[k]);
			}
			printf("%d\n", p[l - 1]);
			return true;
		}
	}
	printf("系统是不安全的\n");
	return false;
}

//void Print()
//{
//	int i = 0;
//	int y = 0;
//	for (; i < 3; i++)
//	{
//		for (; y < 3; y++)
		{
			printf("%d %d %d", Max[3][3],Allocation[3][3],Need[3][3]);
		}
		printf("\n");
	}
}


void Bank()                //银行家算法  
{
	int i, num;
	while (1)
	{
		printf("请输入要申请资源的进程号:");
		scanf("%d", &num);
		num -= 1;
		printf("请输入进程所请求的各资源的数量:\n");
		for (i = 0; i < m; i++)
		{
			scanf("%d", &Request[num][i]);
			if (Request[num][i] > Need[num][i])//如果用户选择的线程的第i个资源请求数＞该线程该资源所需的数量  
			{
				printf("您输入的请求数超过该进程对该资源的需求量!请重新输入!\n");
				i--;
				continue;
			}
			if (Request[num][i] > Available[i])//如果用户选择的线程的第i个资源请求数＞系统现有的第i个资源的数量  
			{
				printf("您输入的请求数超过系统拥有该资源的数目!请重新输入!\n");
				i--;
				continue;
			}
			Available[i] -= Request[num][i];//系统可用资源减去申请了的  
			Allocation[num][i] += Request[num][i];//线程被分配的资源加上已申请了的  
			Need[num][i] -= Request[num][i];//线程还需要的资源减去已申请得到的  
		}
		if (Safe())//AVAILABLE  ALLOCATION  NEED变动之后，是否会导致不安全  
		{
			printf("同意分配请求!\n");
		}
		else
		{
			printf("您的请求被拒绝!\n");
			for (i = 0; i < m; i++)
			{
				Available[i] += Request[num][i];
				Allocation[num][i] -= Request[num][i];
				Need[num][i] += Request[num][i];
			}
		}
	}
}


int main()
{
	Init();
	Bank();
	return 0;
}