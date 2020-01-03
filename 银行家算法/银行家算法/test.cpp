#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX_PROCESS 100
#define MAX_RESOURCE 100
int Available[MAX_RESOURCE];                    //������Դ����  
int Max[MAX_PROCESS][MAX_RESOURCE];            //����������  
int Allocation[MAX_PROCESS][MAX_RESOURCE];    //������� 
int Need[MAX_PROCESS][MAX_RESOURCE];     //�������  
int Request[MAX_PROCESS][MAX_RESOURCE];        //������Ҫ��Դ�� 
int p[MAX_PROCESS];                             //��¼����
int n, m;                                    //n������,m����Դ  
void Init()                //��ʼ���㷨  
{
	int i, j;
	printf("��������̵���Ŀ:\n");
	scanf("%d", &n);
	printf("��������Դ������:\n");
	scanf("%d", &m);
	printf("������ÿ�������������ĸ���Դ��:\n", n, m);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &Max[i][j]);
		}
	}
	printf("������ÿ�������ѷ���ĸ���Դ��:\n", n, m);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &Allocation[i][j]);
			Need[i][j] = Max[i][j] - Allocation[i][j];
			if (Need[i][j] < 0)
			{
				printf("������ĵ�%d��������ӵ�еĵ�%d����Դ������,����������:\n", i + 1, j + 1);
				j--;
				continue;
			}
		}
	}
	printf("�����������Դ���е���Ŀ:\n");
	for (i = 0; i < m; i++)
	{
		scanf("%d", &Available[i]);
	}
}

bool Safe()    //��ȫ���㷨
{
	int i, j, k, l = 0;
	int Work[MAX_RESOURCE]; //��������,����ʾϵͳ���ṩ�����̼�����������ĸ�����Դ��Ŀ  
	int Finish[MAX_PROCESS];  //ϵͳ�Ƿ����㹻����Դ��������̣�ʹ֮������� 
	for (i = 0; i < m; i++)   //���������ʼ�� 
	{
		Work[i] = Available[i];
	}
	memset(Finish, 0, sizeof(Finish));
	for (i = 0; i < n; i++)
	{
		if (Finish[i]) continue;
		for (j = 0; j < m; j++)//ѭ�����ҵ�i��������Ҫ�ĸ�����Դ���Ƿ񳬹�ϵͳ���еĶ�Ӧ����Դ��  
		{
			//��i��������Ҫ�ĵ�j����Դ�� �� ϵͳ���еĵ�j����Դ�� 
			if (Need[i][j] > Work[j]) break;
		}
		if (j == m)//�����i����������ĸ�����Դ����û�г���ϵͳ���еĶ�Ӧ��Դ��  
		{
			Finish[i] = 1;//���ý��̵�FINISH���Ϊtrue  
			for (k = 0; k < m; k++)
			{
				Work[k] += Allocation[i][k];//��Work��ֵΪ ��i�����̸����ѷ�����Դ����ϵͳ���еĶ�Ӧ��Դ��(��Ϊ���Ľ���ȫ����Դ��������ʱ�߳̽���������Դ������ϵͳ)  
			}
			p[l++] = i;//��¼���̺�  
			i = -1;
		}
		else continue; //�����������ѭ����һ������ 
		if (l == n)//�����н��̶��ܹ�����������ʱ  
		{
			printf("ϵͳ�ǰ�ȫ��\n");
			printf("��ȫ����Ϊ:\n");
			for (k = 0; k < l - 1; k++)
			{
				printf("%d-->", p[k]);
			}
			printf("%d\n", p[l - 1]);
			return true;
		}
	}
	printf("ϵͳ�ǲ���ȫ��\n");
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


void Bank()                //���м��㷨  
{
	int i, num;
	while (1)
	{
		printf("������Ҫ������Դ�Ľ��̺�:");
		scanf("%d", &num);
		num -= 1;
		printf("���������������ĸ���Դ������:\n");
		for (i = 0; i < m; i++)
		{
			scanf("%d", &Request[num][i]);
			if (Request[num][i] > Need[num][i])//����û�ѡ����̵߳ĵ�i����Դ�����������̸߳���Դ���������  
			{
				printf("������������������ý��̶Ը���Դ��������!����������!\n");
				i--;
				continue;
			}
			if (Request[num][i] > Available[i])//����û�ѡ����̵߳ĵ�i����Դ��������ϵͳ���еĵ�i����Դ������  
			{
				printf("�����������������ϵͳӵ�и���Դ����Ŀ!����������!\n");
				i--;
				continue;
			}
			Available[i] -= Request[num][i];//ϵͳ������Դ��ȥ�����˵�  
			Allocation[num][i] += Request[num][i];//�̱߳��������Դ�����������˵�  
			Need[num][i] -= Request[num][i];//�̻߳���Ҫ����Դ��ȥ������õ���  
		}
		if (Safe())//AVAILABLE  ALLOCATION  NEED�䶯֮���Ƿ�ᵼ�²���ȫ  
		{
			printf("ͬ���������!\n");
		}
		else
		{
			printf("�������󱻾ܾ�!\n");
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