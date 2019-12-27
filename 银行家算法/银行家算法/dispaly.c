#define _CRT_SECURE_NO_WARNINGS 1
#include "home.h"

//��̽����
void ProbeAlloc(int Allocation[10][10], int Need[10][10], int Available[10], int process, int res[10], int MAX_RESOURCE)
{
	for (int y = 0; y < MAX_RESOURCE; y++)
	{
		Available[y] -= res[y];
		Allocation[process][y] += res[y];
		Need[process][y] -= res[y];
	}
}
//����̽�������벻��ȫ״̬��������ع�
void RollBack(int Allocation[10][10], int Need[10][10], int Available[10], int process, int res[10], int MAX_PROCESS, int MAX_RESOURCE)
{
	for (int y = 0; y < MAX_RESOURCE; y++)
	{
		Available[y] += res[y];
		Allocation[process][y] -= res[y];
		Need[process][y] += res[y];
	}
}
//��ȫ�Լ��
bool SafeCheck(int Max[10][10], int Allocation[10][10], int Need[10][10], int Available[10], int safe[10], int MAX_PROCESS, int MAX_RESOURCE)
{
	int Work[3] = { 0 };
	bool Finish[5] = { false };
	int x = 0;
	int y = 0;
	int j = 0;
	int p = MAX_PROCESS;
	for (y = 0; y < MAX_RESOURCE; y++)
	{
		Work[y] = Available[y];
	}
	while (p)
	{
		for (x = 0; x < MAX_PROCESS; x++)
		{
			int num = 0;
			if (Finish[x] == false)
			{
				for (y = 0; y < MAX_RESOURCE; y++)
				{
					if (Need[x][y] <= Work[y])
					{
						num++;
						if (num == MAX_RESOURCE)
						{
							for (y = 0; y < MAX_RESOURCE; y++)
							{
								Work[y] += Allocation[x][y];
							}
							Finish[x] = true;
							safe[j++] = x;
						}
					}
				}
			}
		}
		p--;
	}
	//������н��̵�Finish������Ϊtrue���ڰ�ȫ״̬������Ϊ����ȫ״̬
	for (x = 0; x < MAX_PROCESS; x++)
	{
		if (Finish[x] == false)
		{
			return false;
		}
	}
	return true;
}


//��Դ��������
bool request(int Max[10][10], int process, int res[10], int Allocation[10][10], int Need[10][10], int Available[10], int safe[10], int MAX_PROCESS, int MAX_RESOURCE)
{
	int num = 0;
	//request������С��Need�����ж�Ӧ������
	for (int x = 0; x < MAX_RESOURCE; x++)
	{
		if (res[x] <= Need[process][x])
		{
			num++;
			if (num == MAX_RESOURCE)
			{
				num = 0;
				for (x = 0; x < MAX_RESOURCE; x++)
				{
					if (res[x] <= Available[x])
					{
						num++;
						if (num == MAX_RESOURCE)
						{
							ProbeAlloc(Allocation, Need, Available, process, res, MAX_RESOURCE);
							//�����ȫ��������������ɹ������򽫷���ع�������ʧ��
							if (SafeCheck(Max, Allocation, Need, Available, safe, MAX_PROCESS, MAX_RESOURCE))
							{
								num = 0;
								for (x = 0; x < MAX_RESOURCE; x++)
								{
									if(Need[process][x] == 0)
										num++;
									if (num == MAX_RESOURCE)
									{
										for (x = 0; x < MAX_RESOURCE; x++)
										{
											Available[x] += Allocation[process][x];
											Allocation[process][x] = 0;
										}
									}
								}
								return true;
							}
							else
							{
								printf("��ȫ�Լ��ʧ�ܡ�ԭ��ϵͳ�����벻��ȫ״̬���п�������������\n");
								printf("���ڻع�...\n");
								RollBack(Allocation, Need, Available, process, res, MAX_PROCESS, MAX_RESOURCE);
							}
						}
					}
					else
					{
						printf("��ȫ�Լ��ʧ�ܡ�ԭ�������������ڿ�������Դ������\n");
						return false;
					}
				}
			}
		}
		else
		{
			printf("��ȫ�Լ��ʧ�ܡ�ԭ������������������������\n");
			return false;
		}
	}
	return false;
}
//�����Դ�����
void PrintTable(int Max[10][10], int Allocation[10][10], int Need[10][10], int Available[10], int MAX_PROCESS, int MAX_RESOURCE)
{
	int x = 0;
	int y = 0;
	printf("���	 Max    Allocation    Need    Available\n");
	for (x = 0; x < MAX_PROCESS; x++)
	{
		printf("P%d	", x);
		for (y = 0; y < MAX_RESOURCE; y++)
		{
			printf("%d   ", Max[x][y]);
		}
		printf("  ");
		for (y = 0; y < MAX_RESOURCE; y++)
		{
			printf("%d  ", Allocation[x][y]);
		}
		printf("    ");
		for (y = 0; y < MAX_RESOURCE; y++)
		{
			printf("%d  ",Need[x][y]);
		}
		printf("    ");
		if (x == 0)
		{
			for (y = 0; y < MAX_RESOURCE; y++)
			{
				printf("%d  ", Available[y]);
			}
		}
		printf("\n");
	}
}