#define _CRT_SECURE_NO_WARNINGS 1
#include "home.h"

//输入信息
void Init(int Max[10][10],int Allocation[10][10],int Need[10][10],int Available[10],int MAX_PROCESS,int MAX_RESOURCE)
{
	int i = 0;
	int y = 0;
	int arr[10] = { 0 };
	printf("各个资源总数:");
	for (y = 0; y < MAX_RESOURCE; y++)
	{
		scanf("%d", &arr[y]);
	}
	printf("请输入最大需求矩阵Max:\n");
	for (i = 0; i < MAX_PROCESS; i++)
	{
		for (y = 0; y < MAX_RESOURCE; y++)
		{
			scanf("%d", &Max[i][y]);
		}
	}
	printf("请输入分配矩阵Allocation:\n");
	for (i = 0; i < MAX_PROCESS; i++)
	{
		for (y = 0; y < MAX_RESOURCE; y++)
		{
			scanf("%d", &Allocation[i][y]);
		}
	}
	for (i = 0; i < MAX_PROCESS; i++)
	{
		for (y = 0; y < MAX_RESOURCE; y++)
		{
			Need[i][y] = Max[i][y] - Allocation[i][y];
		}
	}
	for (y = 0; y < MAX_RESOURCE; y++)
	{
		for (i = 0; i < MAX_PROCESS; i++)
		{
			arr[y] -= Allocation[i][y];
		}
		Available[y] = arr[y];
	}
}

int main()
{
	int MAX_PROCESS = 0;
	int MAX_RESOURCE = 0;
	printf("请输入进程个数:");
	scanf("%d", &MAX_PROCESS);
	printf("请输入资源个数:");
	scanf("%d", &MAX_RESOURCE);
	int Available[10] = { 0 };                 //可用资源数组  
	int Max[10][10] = { 0 };        //最大需求矩阵  
	int Allocation[10][10] = { 0 };    //分配矩阵 
	int Need[10][10] = { 0 };   //需求矩阵  
	int safe[10];
	int process = 0;
	int res[10] = { 0 };
	int i = 0;
	Init(Max,Allocation,Need,Available, MAX_PROCESS, MAX_RESOURCE);
	PrintTable(Max, Allocation,  Need, Available, MAX_PROCESS,MAX_RESOURCE);
	char ch = '0';
	printf("先检查初始状态是否安全.\n");
	if (SafeCheck(Max,Allocation,Need,Available,safe,MAX_PROCESS,MAX_RESOURCE))
	{
		printf("系统处于安全状态\n");
		printf("安全序列为:");
		for (i = 0; i < MAX_PROCESS; i++)
		{
			printf("P%d ", safe[i]);
		}
		printf("\n");
	}
	else
	{
		printf("系统处于不安全状态。程序将退出...\n");
	}
	do
	{
		printf("是否继续分配？(Y/N):");
		scanf("%s", &ch);
		if (ch == 'N' || ch == 'n')
			break;
		printf("请依次输入请求分配的进程:");
		scanf("%d", &process);
		printf("请输入进程的资源请求数量:");
		for (i = 0; i < MAX_RESOURCE; i++)
		{
			scanf("%d",&res[i]);
		}
		if (request(Max, process ,res, Allocation, Need, Available, safe, MAX_PROCESS, MAX_RESOURCE))
		{
			printf("分配成功。\n");
			PrintTable(Max, Allocation, Need, Available, MAX_PROCESS, MAX_RESOURCE);
		}
		else
		{
			printf("分配失败。\n");
		}
	} while (ch == 'Y' || ch == 'y');
	printf("执行完毕");
	system("pause");
	return 0;

}