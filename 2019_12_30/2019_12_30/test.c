#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>  
#include <process.h>

typedef struct node   //边表结点
{
	int adjvex;    //邻接点的编号
	int dut;   //弧
	struct node *next;   //下一个弧（指针）
}edgenode;  //边表结点

typedef struct  //顶点表结点
{
	int projectname;//顶点域
	int id;//顶点的入度
	edgenode *link; //边表头指针
}vexnode;

void CreateGraphic(vexnode * Graphicmap, int projectnumber,int activenumber)//创建图
{
	int begin, end, duttem, i, k; //弧的前节点，尾节点，活动持续时间
	edgenode *p;//  边表头指针
	for (i = 0; i < projectnumber; i++)
	{
		Graphicmap[i].projectname = i;//顶点的命名为0，1，2，3......
//		Graphicmap[i].id = 0;//顶点的度数初始化为0
//		Graphicmap[i].link = NULL;
//	}
//	printf("请输入某项目的信息，并请用整形数字表示（格式：弧头，弧尾，权值）:\n");
//	printf("例如:输入1,4,3  即代表结点1与4之间的活动需要3个时间单位。\n");
//	for (k = 0; k < activenumber; k++) //activenumber是活动的数目，即弧的条数
//	{
//		scanf("%d,%d,%d", &begin, &end, &duttem); //请输入第%d条的起点、终点和权值
//		p = (edgenode *)malloc(sizeof(edgenode));//分配存储空间
//		p->adjvex = end - 1;//因为是从零开始记的，所以要减一，就是让终点插入到邻接表内
//		p->dut = duttem; //该弧的活动时间为duttem
//		Graphicmap[end - 1].id++;  //入度加一
//		p->next = Graphicmap[begin - 1].link;
//		Graphicmap[begin - 1].link = p;//让下一个节点作为下一插入节点的前驱节点
//	}
//}
//
//int SearchMapPath(vexnode * Graphicmap, int projectnumber,int activenumber, int totaltime) //求出最大路径，并写出关键路径
//{
//	int i, j, k, m = 0;
//	int front = -1, rear = -1;
//	int* topologystack = (int*)malloc(projectnumber * sizeof(int));//拓扑排列
//	int* vl = (int*)malloc(projectnumber * sizeof(int));//用来表示在不推迟整个工程的前提下，vj允许最迟发生的时间
//	int* ve = (int*)malloc(projectnumber * sizeof(int));//用来表示Vj最早发生时间
//	int* l = (int*)malloc(activenumber * sizeof(int));//用来表示活动Ai最迟完成开始时间
//	int* e = (int*)malloc(activenumber * sizeof(int));//表示活动最早开始时间
//	edgenode *p;  //边表头的指针
//	totaltime = 0; //存放整个工程的最短时间
//	for (i = 0; i < projectnumber; i++) 
//		ve[i] = 0;//先把每个工程的最早发生时间初始化为零
//	for (i = 0; i < projectnumber; i++)
//	{
//		if (Graphicmap[i].id == 0)
//		{
//			topologystack[++rear] = i; //让所有的头节点入队
//			m++;  //记录入队列的顶点数
//		}
//	}
//	while (front != rear)
//	{
//		front++; //出队
//		j = topologystack[front]; //拓扑排序的节点依次出队列
//		m++;  //记录入队列的节点个数
//		p = Graphicmap[j].link;  //指向顶点指向的下一个顶点
//		while (p)
//		{
//			k = p->adjvex; // 邻接点
//			Graphicmap[k].id--;//入度减一，等于删除一个入度为零的前驱节点及相关的弧
//			if (ve[j] + p->dut > ve[k])//将最长的路径赋给VE[K]
//				ve[k] = ve[j] + p->dut;
//			if (Graphicmap[k].id == 0)//入度为零时入队列
//				topologystack[++rear] = k;
//			p = p->next; //指向下一个节点
//		}
//	}
//	if (m < projectnumber)//如果有环，则不能遍历每个节点
//	{
//		printf("\n图有回路无法计算关键路径!\n");
//		printf("将退出本程序！\n");
//		return 0;
//	}
//	totaltime = ve[projectnumber - 1];//最短完成时间即为最后一个节点所累加的时间之和
//	for (i = 0; i < projectnumber; i++)
//		vl[i] = totaltime;
//	for (i = projectnumber - 2; i >= 0; i--)// 用逆拓扑排序来求活动Ai最迟完成开始时间，即从最后一个节点减去最短的时间
//	{
//		j = topologystack[i];
//		p = Graphicmap[j].link;
//		while (p)
//		{
//			k = p->adjvex;
//			if ((vl[k] - p->dut) < vl[j])
//			{
//				vl[j] = vl[k] - p->dut;
//				p = p->next;
//			}
//		}
//	}
//	i = 0;
//	printf("\n");
//	printf("| 起点 | 终点 | 最早开始时间 | 最迟完成时间 | 差值 | 备注 \n");
//	for (j = 0; j < projectnumber; j++)
//	{
//		p = Graphicmap[j].link;
//		while (p)
//		{
//			k = p->adjvex;
//			e[++i] = ve[j];
//			l[i] = vl[k] - p->dut;
//			printf("| %4d | %4d | %11d  | %11d  | %3d  |", Graphicmap[j].projectname + 1, Graphicmap[k].projectname + 1, e[i], l[i], l[i] - e[i]);
//			if (l[i] == e[i])  
//			{ 
//				printf("关键活动 <%2d,%4d>", Graphicmap[j].projectname + 1, Graphicmap[k].projectname + 1);
//				printf("\n");
//				p = p->next;
//			}
//		}
//	}
//	return 1;
//
//}
//
//void seekkeyroot()//定义求关键路径的主函数
//{
//	int projectnumber, activenumber, totaltime = 0;
//	vexnode Graphicmap;
//	printf("\n");
//	printf("输入符合标准，欢迎进入求关键路径的系统!\n");
//	printf("\n");
//	printf("请输入这个项目的AOE-网的节点数: ");
//	scanf("%d", &projectnumber);
//	printf("请输入这个项目的AOE-网的活动个数: ");
//	scanf("%d", &activenumber);
//	CreateGraphic(&Graphicmap, projectnumber, activenumber);//创建邻接图
//	SearchMapPath(&Graphicmap, projectnumber, activenumber, totaltime);//求出最大路径，并写出关键路径
//	printf("\n");
//	printf("整个工程所用的最短时间为：%d个单位时间\n", totaltime);
//	system("pause");
//}
//
//int main()
//{
//	char ch;
//	do
//	{
//		system("cls");
//		printf("欢迎进入求关键路径算法程序\n");
//		printf("%s", "\ns(start)开始输入工程的节点数据并求出关键路径\n");	
//		printf("%s", "e(exit)退出\n");
//		printf("%s", "请输入选择:");
//		scanf("%c", &ch);
//	} while (ch != 's'&&ch != 'e');
//	switch (ch)
//	{
//	case's':
//		seekkeyroot();//关键路径
//		break;
//	case'e':
//		return 1;
//	}
//	system("pause");
//	return 0;
//}