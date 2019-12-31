#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define INFINITY 10000      /* 假定弧上权值无穷大时为10000 */
#define MAX_VERTEX_NUM 100  /* 图中最大节点数 */
typedef char VexType;       /* 顶点类型设置为字符型 */
typedef int weight;         /* 弧上权值类型设置为整型 */
typedef struct              /* 弧表节点 */
{
	VexType vex[MAX_VERTEX_NUM];                 /* 图中节点 */
	weight edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];/* 邻接矩阵 */
	int vexnum;                                  /* 节点的数目 */
	int edgenum;                                 /* 弧的数目 */
}MGraph;

void CreateDG(MGraph * DG);          /* 邻接矩阵法创建有向图（directed graph） */
void PrintDG(MGraph DG);             /* 邻接矩阵形式输出图DG */
void ShortestPath_Dijkstra(MGraph DG, VexType StartVex);
/* 从节点StartVex开始求最短路径 */
void locateVex(MGraph DG, VexType vex, int * index);
/* 定位节点vex的下标并赋给index */

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
	int i = 0, j, k, w;                 /* w：权值 */
	char ch;

	printf("请依次输入顶点数、弧数：");
	scanf("%d %d", &(DG->vexnum), &(DG->edgenum));

	printf("请依次输入顶点（以回车结束输入）：");
	getchar();
	while ((ch = getchar()) != '\n')    /* 输入顶点信息 */
		DG->vex[i++] = ch;

	for (i = 0; i < DG->vexnum; i++)    /* 初始化邻接矩阵 */
		for (j = 0; j < DG->vexnum; j++)
			DG->edges[i][j] = INFINITY;

	printf("顶点 | 下标\n");
	for (i = 0; i < DG->vexnum; i++)    /* 显示图中顶点及其对应下标 */
	{
		printf("%3c%6d\n", DG->vex[i], i);
	}

	printf("请输入依次每条弧的弧尾下标(不带箭头)、弧头下标(带箭头)、权值（格式：i j w）：\n");
	for (k = 0; k < DG->edgenum; k++)   /* 建立邻接矩阵 */
	{
		scanf("\n%d%d%d", &i, &j, &w);  /* 输入弧的两个节点及权值 */
		DG->edges[i][j] = w;            /* 将矩阵对应位置元素置为权值 */
	}
}
void PrintDG(MGraph DG)
{
	int i, j;

	for (i = 0; i < DG.vexnum; i++)         /* 输出邻接矩阵 */
	{
		for (j = 0; j < DG.vexnum; j++)
		{
			if (DG.edges[i][j] == INFINITY) /* 节点不连通时，输出无穷大 */
				printf("    ∞");
			else                            /* 节点连通时，输出弧上权值 */
				printf("%5d", DG.edges[i][j]);
		}
		printf("\n");
	}
}
void ShortestPath_Dijkstra(MGraph DG, VexType StartVex)
{
	int i, j, v, index;         /* index：开始节点下标 */
	int min;                    /* 开始节点到指定节点的最短路径权值和 */
	int final[100];       /* 集合S，元素值为1：下标为i的节点以加入集合S；为0：未加入 */
	int P[100][100];/* 开始节点到各节点的最短路径 */
	int D[100];           /* 开始节点到下标为i的节点的最短路径权值之和 */

	locateVex(DG, StartVex, &index);
	for (i = 0; i < DG.vexnum; i++)
	{
		final[i] = 0;                   /* 初始化，刚开始集合S为空 */
		D[i] = DG.edges[index][i];

		for (j = 0; j < DG.vexnum; j++) /* 初始化路径，假设所有节点都不连通 */
			P[i][j] = 0;
		if (D[i] < INFINITY)            /* 若节点连通，则在数组P[i]中标明路径 */
		{
			P[i][index] = 1;
			P[i][i] = 1;
		}
	}
	D[index] = 0; final[index] = 1;     /* 开始节点加入S集 */

	for (i = 1; i < DG.vexnum; i++)
	{
		min = INFINITY;
		for (j = 0; j < DG.vexnum; j++)
			if (!final[j])
				if (D[j] < min) { v = j; min = D[j]; }
		final[v] = 1;                   /* 把离StartVex最近的下标为v的节点加入S */

		for (j = 0; j < DG.vexnum; j++)
			if (!final[j] && (min + DG.edges[v][j] < D[j]))
			{/* 若下标为j的节点为加入S且有更短路径，则更新D[j]和最短路径 */
				D[j] = min + DG.edges[v][j];
				for (int k = 0; k < DG.vexnum; k++)
					P[j][k] = P[v][k];
				P[j][j] = 1;
			}
	}

	printf("节点 %c 到各节点的最短路径：\n", StartVex);
	for (i = 0; i < DG.vexnum; i++)
	{
		for (j = 0; j < DG.vexnum; j++)
			printf("%5d", P[i][j]);
		printf("\n");
	}

	printf("节点 %c 到各节点的最短路径值：", StartVex);
	for (i = 0; i < DG.vexnum; i++)
	{
		if (D[i] == INFINITY)
			printf("∞, ");
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
	printf("节点定位失败！\n");
}