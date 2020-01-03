#define _CRT_SECURE_NO_WARNINGS 1
#include "home.h"

//������Ϣ
void Init(int Max[10][10],int Allocation[10][10],int Need[10][10],int Available[10],int MAX_PROCESS,int MAX_RESOURCE)
{
	int i = 0;
	int y = 0;
	int arr[10] = { 0 };
	printf("������Դ����:");
	for (y = 0; y < MAX_RESOURCE; y++)
	{
		scanf("%d", &arr[y]);
	}
	printf("����������������Max:\n");
	for (i = 0; i < MAX_PROCESS; i++)
	{
		for (y = 0; y < MAX_RESOURCE; y++)
		{
			scanf("%d", &Max[i][y]);
		}
	}
	printf("������������Allocation:\n");
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
	printf("��������̸���:");
	scanf("%d", &MAX_PROCESS);
	printf("��������Դ����:");
	scanf("%d", &MAX_RESOURCE);
	int Available[10] = { 0 };                 //������Դ����  
	int Max[10][10] = { 0 };        //����������  
	int Allocation[10][10] = { 0 };    //������� 
	int Need[10][10] = { 0 };   //�������  
	int safe[10];
	int process = 0;
	int res[10] = { 0 };
	int i = 0;
	Init(Max,Allocation,Need,Available, MAX_PROCESS, MAX_RESOURCE);
	PrintTable(Max, Allocation,  Need, Available, MAX_PROCESS,MAX_RESOURCE);
	char ch = '0';
	printf("�ȼ���ʼ״̬�Ƿ�ȫ.\n");
	if (SafeCheck(Max,Allocation,Need,Available,safe,MAX_PROCESS,MAX_RESOURCE))
	{
		printf("ϵͳ���ڰ�ȫ״̬\n");
		printf("��ȫ����Ϊ:");
		for (i = 0; i < MAX_PROCESS; i++)
		{
			printf("P%d ", safe[i]);
		}
		printf("\n");
	}
	else
	{
		printf("ϵͳ���ڲ���ȫ״̬�������˳�...\n");
	}
	do
	{
		printf("�Ƿ�������䣿(Y/N):");
		scanf("%s", &ch);
		if (ch == 'N' || ch == 'n')
			break;
		printf("�����������������Ľ���:");
		scanf("%d", &process);
		printf("��������̵���Դ��������:");
		for (i = 0; i < MAX_RESOURCE; i++)
		{
			scanf("%d",&res[i]);
		}
		if (request(Max, process ,res, Allocation, Need, Available, safe, MAX_PROCESS, MAX_RESOURCE))
		{
			printf("����ɹ���\n");
			PrintTable(Max, Allocation, Need, Available, MAX_PROCESS, MAX_RESOURCE);
		}
		else
		{
			printf("����ʧ�ܡ�\n");
		}
	} while (ch == 'Y' || ch == 'y');
	printf("ִ�����");
	system("pause");
	return 0;

}