#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define INFINITY 10000      /* �ٶ�����Ȩֵ�����ʱΪ10000 */
#define MAX_VERTEX_NUM 100  /* ͼ�����ڵ��� */
typedef char VexType;       /* ������������Ϊ�ַ��� */
typedef int weight;         /* ����Ȩֵ��������Ϊ���� */
typedef struct              /* ����ڵ� */
{
	VexType vex[MAX_VERTEX_NUM];                 /* ͼ�нڵ� */
	weight edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];/* �ڽӾ��� */
	int vexnum;                                  /* �ڵ����Ŀ */
	int edgenum;                                 /* ������Ŀ */
}MGraph;

void CreateDG(MGraph * DG);          /* �ڽӾ��󷨴�������ͼ��directed graph�� */
void PrintDG(MGraph DG);             /* �ڽӾ�����ʽ���ͼDG */
void ShortestPath_Dijkstra(MGraph DG, VexType StartVex);
/* �ӽڵ�StartVex��ʼ�����·�� */
void locateVex(MGraph DG, VexType vex, int * index);
/* ��λ�ڵ�vex���±겢����index */

int main(void)
{
	MGraph g;

	CreateDG(&g);
	printf("------------------------------\n");
	printf("vexnum = %d ; edgenum = %d\n", g.vexnum, g.edgenum);
	printf("------------------------------\n");
	PrintDG(g);
	printf("------------------------------\n");
	ShortestPath_Dijkstra(g, '0');
	system("pause");
	return 0;
}
void CreateDG(MGraph * DG)
{
	int i = 0, j, k, w;                 /* w��Ȩֵ */
	char ch;

	printf("���������붥������������");
	scanf("%d %d", &(DG->vexnum), &(DG->edgenum));

	printf("���������붥�㣨�Իس��������룩��");
	getchar();
	while ((ch = getchar()) != '\n')    /* ���붥����Ϣ */
		DG->vex[i++] = ch;

	for (i = 0; i < DG->vexnum; i++)    /* ��ʼ���ڽӾ��� */
		for (j = 0; j < DG->vexnum; j++)
			DG->edges[i][j] = INFINITY;

	printf("���� | �±�\n");
	for (i = 0; i < DG->vexnum; i++)    /* ��ʾͼ�ж��㼰���Ӧ�±� */
	{
		printf("%3c%6d\n", DG->vex[i], i);
	}

	printf("����������ÿ�����Ļ�β�±�(������ͷ)����ͷ�±�(����ͷ)��Ȩֵ����ʽ��i j w����\n");
	for (k = 0; k < DG->edgenum; k++)   /* �����ڽӾ��� */
	{
		scanf("\n%d%d%d", &i, &j, &w);  /* ���뻡�������ڵ㼰Ȩֵ */
		DG->edges[i][j] = w;            /* �������Ӧλ��Ԫ����ΪȨֵ */
	}
}
void PrintDG(MGraph DG)
{
	int i, j;

	for (i = 0; i < DG.vexnum; i++)         /* ����ڽӾ��� */
	{
		for (j = 0; j < DG.vexnum; j++)
		{
			if (DG.edges[i][j] == INFINITY) /* �ڵ㲻��ͨʱ���������� */
				printf("    ��");
			else                            /* �ڵ���ͨʱ���������Ȩֵ */
				printf("%5d", DG.edges[i][j]);
		}
		printf("\n");
	}
}
void ShortestPath_Dijkstra(MGraph DG, VexType StartVex)
{
	int i, j, v, index;         /* index����ʼ�ڵ��±� */
	int min;                    /* ��ʼ�ڵ㵽ָ���ڵ�����·��Ȩֵ�� */
	int final[100];       /* ����S��Ԫ��ֵΪ1���±�Ϊi�Ľڵ��Լ��뼯��S��Ϊ0��δ���� */
	int P[100][100];/* ��ʼ�ڵ㵽���ڵ�����·�� */
	int D[100];           /* ��ʼ�ڵ㵽�±�Ϊi�Ľڵ�����·��Ȩֵ֮�� */

	locateVex(DG, StartVex, &index);
	for (i = 0; i < DG.vexnum; i++)
	{
		final[i] = 0;                   /* ��ʼ�����տ�ʼ����SΪ�� */
		D[i] = DG.edges[index][i];

		for (j = 0; j < DG.vexnum; j++) /* ��ʼ��·�����������нڵ㶼����ͨ */
			P[i][j] = 0;
		if (D[i] < INFINITY)            /* ���ڵ���ͨ����������P[i]�б���·�� */
		{
			P[i][index] = 1;
			P[i][i] = 1;
		}
	}
	D[index] = 0; final[index] = 1;     /* ��ʼ�ڵ����S�� */

	for (i = 1; i < DG.vexnum; i++)
	{
		min = INFINITY;
		for (j = 0; j < DG.vexnum; j++)
			if (!final[j])
				if (D[j] < min) { v = j; min = D[j]; }
		final[v] = 1;                   /* ����StartVex������±�Ϊv�Ľڵ����S */

		for (j = 0; j < DG.vexnum; j++)
			if (!final[j] && (min + DG.edges[v][j] < D[j]))
			{/* ���±�Ϊj�Ľڵ�Ϊ����S���и���·���������D[j]�����·�� */
				D[j] = min + DG.edges[v][j];
				for (int k = 0; k < DG.vexnum; k++)
					P[j][k] = P[v][k];
				P[j][j] = 1;
			}
	}

	printf("�ڵ� %c �����ڵ�����·����\n", StartVex);
	for (i = 0; i < DG.vexnum; i++)
	{
		for (j = 0; j < DG.vexnum; j++)
			printf("%5d", P[i][j]);
		printf("\n");
	}

	printf("�ڵ� %c �����ڵ�����·��ֵ��", StartVex);
	for (i = 0; i < DG.vexnum; i++)
	{
		if (D[i] == INFINITY)
			printf("��, ");
		else
			printf("%d, ", D[i]);
	}
}
void locateVex(MGraph DG, VexType vex, int * index)
{
	int i;

	for (i = 0; i < DG.vexnum; i++)
	{
		if (DG.vex[i] == vex)
		{
			*index = i;
			return;
		}
	}
	printf("�ڵ㶨λʧ�ܣ�\n");
}