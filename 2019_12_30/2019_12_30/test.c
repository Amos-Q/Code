#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>  
#include <process.h>

typedef struct node   //�߱���
{
	int adjvex;    //�ڽӵ�ı��
	int dut;   //��
	struct node *next;   //��һ������ָ�룩
}edgenode;  //�߱���

typedef struct  //�������
{
	int projectname;//������
	int id;//��������
	edgenode *link; //�߱�ͷָ��
}vexnode;

void CreateGraphic(vexnode * Graphicmap, int projectnumber,int activenumber)//����ͼ
{
	int begin, end, duttem, i, k; //����ǰ�ڵ㣬β�ڵ㣬�����ʱ��
	edgenode *p;//  �߱�ͷָ��
	for (i = 0; i < projectnumber; i++)
	{
		Graphicmap[i].projectname = i;//���������Ϊ0��1��2��3......
//		Graphicmap[i].id = 0;//����Ķ�����ʼ��Ϊ0
//		Graphicmap[i].link = NULL;
//	}
//	printf("������ĳ��Ŀ����Ϣ���������������ֱ�ʾ����ʽ����ͷ����β��Ȩֵ��:\n");
//	printf("����:����1,4,3  ��������1��4֮��Ļ��Ҫ3��ʱ�䵥λ��\n");
//	for (k = 0; k < activenumber; k++) //activenumber�ǻ����Ŀ������������
//	{
//		scanf("%d,%d,%d", &begin, &end, &duttem); //�������%d������㡢�յ��Ȩֵ
//		p = (edgenode *)malloc(sizeof(edgenode));//����洢�ռ�
//		p->adjvex = end - 1;//��Ϊ�Ǵ��㿪ʼ�ǵģ�����Ҫ��һ���������յ���뵽�ڽӱ���
//		p->dut = duttem; //�û��Ļʱ��Ϊduttem
//		Graphicmap[end - 1].id++;  //��ȼ�һ
//		p->next = Graphicmap[begin - 1].link;
//		Graphicmap[begin - 1].link = p;//����һ���ڵ���Ϊ��һ����ڵ��ǰ���ڵ�
//	}
//}
//
//int SearchMapPath(vexnode * Graphicmap, int projectnumber,int activenumber, int totaltime) //������·������д���ؼ�·��
//{
//	int i, j, k, m = 0;
//	int front = -1, rear = -1;
//	int* topologystack = (int*)malloc(projectnumber * sizeof(int));//��������
//	int* vl = (int*)malloc(projectnumber * sizeof(int));//������ʾ�ڲ��Ƴ��������̵�ǰ���£�vj������ٷ�����ʱ��
//	int* ve = (int*)malloc(projectnumber * sizeof(int));//������ʾVj���緢��ʱ��
//	int* l = (int*)malloc(activenumber * sizeof(int));//������ʾ�Ai�����ɿ�ʼʱ��
//	int* e = (int*)malloc(activenumber * sizeof(int));//��ʾ����翪ʼʱ��
//	edgenode *p;  //�߱�ͷ��ָ��
//	totaltime = 0; //����������̵����ʱ��
//	for (i = 0; i < projectnumber; i++) 
//		ve[i] = 0;//�Ȱ�ÿ�����̵����緢��ʱ���ʼ��Ϊ��
//	for (i = 0; i < projectnumber; i++)
//	{
//		if (Graphicmap[i].id == 0)
//		{
//			topologystack[++rear] = i; //�����е�ͷ�ڵ����
//			m++;  //��¼����еĶ�����
//		}
//	}
//	while (front != rear)
//	{
//		front++; //����
//		j = topologystack[front]; //��������Ľڵ����γ�����
//		m++;  //��¼����еĽڵ����
//		p = Graphicmap[j].link;  //ָ�򶥵�ָ�����һ������
//		while (p)
//		{
//			k = p->adjvex; // �ڽӵ�
//			Graphicmap[k].id--;//��ȼ�һ������ɾ��һ�����Ϊ���ǰ���ڵ㼰��صĻ�
//			if (ve[j] + p->dut > ve[k])//�����·������VE[K]
//				ve[k] = ve[j] + p->dut;
//			if (Graphicmap[k].id == 0)//���Ϊ��ʱ�����
//				topologystack[++rear] = k;
//			p = p->next; //ָ����һ���ڵ�
//		}
//	}
//	if (m < projectnumber)//����л������ܱ���ÿ���ڵ�
//	{
//		printf("\nͼ�л�·�޷�����ؼ�·��!\n");
//		printf("���˳�������\n");
//		return 0;
//	}
//	totaltime = ve[projectnumber - 1];//������ʱ�伴Ϊ���һ���ڵ����ۼӵ�ʱ��֮��
//	for (i = 0; i < projectnumber; i++)
//		vl[i] = totaltime;
//	for (i = projectnumber - 2; i >= 0; i--)// ����������������Ai�����ɿ�ʼʱ�䣬�������һ���ڵ��ȥ��̵�ʱ��
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
//	printf("| ��� | �յ� | ���翪ʼʱ�� | ������ʱ�� | ��ֵ | ��ע \n");
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
//				printf("�ؼ�� <%2d,%4d>", Graphicmap[j].projectname + 1, Graphicmap[k].projectname + 1);
//				printf("\n");
//				p = p->next;
//			}
//		}
//	}
//	return 1;
//
//}
//
//void seekkeyroot()//������ؼ�·����������
//{
//	int projectnumber, activenumber, totaltime = 0;
//	vexnode Graphicmap;
//	printf("\n");
//	printf("������ϱ�׼����ӭ������ؼ�·����ϵͳ!\n");
//	printf("\n");
//	printf("�����������Ŀ��AOE-���Ľڵ���: ");
//	scanf("%d", &projectnumber);
//	printf("�����������Ŀ��AOE-���Ļ����: ");
//	scanf("%d", &activenumber);
//	CreateGraphic(&Graphicmap, projectnumber, activenumber);//�����ڽ�ͼ
//	SearchMapPath(&Graphicmap, projectnumber, activenumber, totaltime);//������·������д���ؼ�·��
//	printf("\n");
//	printf("�����������õ����ʱ��Ϊ��%d����λʱ��\n", totaltime);
//	system("pause");
//}
//
//int main()
//{
//	char ch;
//	do
//	{
//		system("cls");
//		printf("��ӭ������ؼ�·���㷨����\n");
//		printf("%s", "\ns(start)��ʼ���빤�̵Ľڵ����ݲ�����ؼ�·��\n");	
//		printf("%s", "e(exit)�˳�\n");
//		printf("%s", "������ѡ��:");
//		scanf("%c", &ch);
//	} while (ch != 's'&&ch != 'e');
//	switch (ch)
//	{
//	case's':
//		seekkeyroot();//�ؼ�·��
//		break;
//	case'e':
//		return 1;
//	}
//	system("pause");
//	return 0;
//}