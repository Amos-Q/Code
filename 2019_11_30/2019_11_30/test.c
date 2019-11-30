#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>   //包含sleep函数


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFESIBLE -1
#define OVERFLOW -2


struct PCB
{
	char name[20];       //进程名
	int Arrive_Time;     //到达时间
	int Serve_Time;      //服务时间
	//int Finish_Time;     //完成时间
	int priority;        //优先级
};




typedef struct LNode            //链表结点定义
{
	PCB data;
	struct LNode *next;
}LNode, *LinkList;


typedef struct Queue            //反馈队列结点定义，实质上还是一个单链表
{
	PCB data;
	int prio;                  //反馈队列的优先级
	int timeblock;             //反馈队列分配的时间片
	struct Queue *next;        //指向下一个反馈队列的指针
}Queue, *LinkQueue;


int Create(LinkList &L)           //利用尾插法创建进程
{
	LinkList p, r;
	int i, n;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	r = L;
	printf("请输入进程的个数：\n");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("请输入正整数！\n");
		return ERROR;
	}
	printf("请依次输入进程名、到达时间、服务时间、优先级\n");
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%s", &(p->data.name));
		scanf("%d", &(p->data.Arrive_Time));
		scanf("%d", &(p->data.Serve_Time));
		//scanf("%d",&(p->data.Finish_Time));
		scanf("%d", &(p->data.priority));
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return OK;
}


int Show(LinkList L)           //输出当前队列中的进程的信息
{
	LinkList p;
	p = L->next;
	if (!p)
	{
		printf("为空！\n");
		return ERROR;
	}
	while (p)
	{
		printf("进程名：%s  到达时间：%d  服务时间：%d  优先级：%d\n", p->data.name, p->data.Arrive_Time, p->data.Serve_Time, p->data.priority);
		p = p->next;
	}
	return OK;
}


void Sort(LinkList &L)   //按照到达时间先后排序
{
	LinkList p, q;
	PCB temp;
	p = L->next;
	q = L->next;
	while ((p != NULL) && (p->next != NULL))       //当创建的队列中有两个及以上队列的时候，利用冒泡排序法按照到达时间先后进行排序
	{
		for (p = L->next; p->next != NULL; p = p->next)
		{
			for (q = L->next; q->next != NULL; q = q->next)
			{
				if (q->data.Arrive_Time > q->next->data.Arrive_Time)
				{
					temp = q->data;
					q->data = q->next->data;
					q->next->data = temp;
				}
			}
		}
	}
}


int getCount(LinkList &L, int time)      //查看当前就绪队列中的进程数，其中time是宏观运行时间
{
	int count = 0;
	LinkList q;
	q = L->next;
	while (q != NULL && q->data.Arrive_Time <= time)
	{
		count++;
		q = q->next;
	}
	return count;
}


void Delet(LinkList &L, LinkList p)   //删除结点函数,删除p的下一个结点
{
	LinkList q;
	q = p->next;
	p->next = q->next;
	free(q);
}


/*----------------------------------------------------------先来先服务算法-----------------------------------------------------------*/
void FCFS(LinkList &L)
{
	LinkList p, q;
	int time = 0, count;
	while (L->next != NULL)
	{
		p = L->next;
		count = getCount(L, time);
		if (count = 0)
			time++;
		else
		{
			printf("\n");
			q = L;
			printf("进程%s正在执行……\n", p->data.name);
			printf("进程%s开始执行的时间为：%d\n", p->data.name, time);
			time += p->data.Serve_Time;
			printf("进程%s完成的时间为：%d\n", p->data.name, time);
			printf("进程%s的周转时间为：%d\n", p->data.name, time - p->data.Arrive_Time);
			Delet(L, q);
			printf("\n");
		}
	}
}


/*---------------------------------------------------------短作业优先调度算法----------------------------------------------------------*/
/*算法思想：注意变量time的使用，非常关键，它能够将就绪队列中有哪些进程动态的表示出来，同时能从开始调度进程为止，时间的变化（以1为单位）*/
/*输入样例：P1 1 2 0;  P2 0 1 2;  P3 0 3 1;                                                                                                */




LinkList Min(LinkList &L, int count)           //求当前就绪队列中服务时间最短的进程，并返回该进程结点的上一结点
{
	LinkList p, q, flag;
	int flagnum = 0;       //用来标记flag变量值是否改变
	int min;
	p = L->next;
	q = L->next;
	flag = L->next;
	min = p->data.Serve_Time;
	while (count > 0)
	{
		if (p->data.Serve_Time < min)
		{
			min = p->data.Serve_Time;
			flag = q;                           //注意变量q保存的是p所指向的上一节点的信息，一定要引入q，否则会出现调度进程为空的现象
			flagnum = 1;
		}
		count--;
		q = p;
		p = p->next;
	}
	if (flagnum == 0)
		flag = L;
	return flag;                              //标记最小服务时间的结点的前一个结点的指针
}


void SJP(LinkList &L)        //短作业优先调度算法的主体模块
{
	int time = 0, count;
	LinkList p, q;
	while (L->next != NULL)
	{
		count = getCount(L, time);
		if (count == 0)       //如果当前队列中没有进程，那么就让时间加一
			time++;
		else if (count == 1)  //如果就绪队列中只有1个进程
		{
			//printf("this is one!\n");
			p = L->next;
			printf("进程%s正在执行……\n", p->data.name);
			Sleep(2000);
			printf("开始执行的时间：%d\n", time);
			time += p->data.Serve_Time;
			printf("进程%s完成时间：%d\n", p->data.name, time);
			q = L;
			Delet(L, q);
			printf("\n");
		}
		else   //如果就绪队列中有两个以上的进程，先调度执行服务时间短的进程
		{
			//printf("this is two!\n");           此句为调试信息，可以不用要
			q = Min(L,count);
		//printf("q所指进程为：%s\n",q->data.name);    此句为调试信息，主要是指明指针q所指的结点，避免出现乱码的现象
		p = q->next;
		printf("进程%s正在执行……\n",p->data.name);
		Sleep(2000);
		printf("开始执行的时间:%d\n",time);
		time += p->data.Serve_Time;
		printf("进程%s完成时间：%d\n",p->data.name,time);
		Delet(L,q);
		printf("\n");
		}
			//Show(L);             由于是在L中进行操作，所以本句是为了监控L中结点的变化，便于调试
	}
}


/*----------------------------------------------------------非抢占式的优先级调度算法-------------------------------------------------------*/
/*算法思想：和短作业优先调度算法一致，只不过短作业优先调度算法的优先级是服务时间，而非抢占式的优先级调度算法的优先级则是人为设定的         */
/* 输入样例：p1 1 2 0; p2 0 1 2; p3 0 3 1;                                                                                                 */


LinkList Max_Priority(LinkList &L, int count)            //求就绪队列中优先级最高的进程结点（默认数字小的优先级高）
{
	LinkList p, q, flag;
	int flagnum = 0;
	p = L->next;
	flag = p;
	q = L->next;
	int max;
	max = p->data.priority;
	while (count > 0)
	{
		if (p->data.priority < max)
		{
			max = p->data.priority;
			flag = q;
			flagnum = 1;
		}
		count--;
		q = p;
		p = p->next;
	}
	if (flagnum == 0)
		flag = L;
	return flag;
}


void Non_priority(LinkList &L)       //非抢占式优先级调度算法
{
	int time = 0, count;
	LinkList p, q;
	while (L->next != NULL)
	{
		count = getCount(L, time);
		//printf("count的值为：%d\n",count);  此句为调试语句，通过输出count的值来监控执行的是下面if……else if语句中的哪个模块
		if (count == 0)
			time++;
		else if (count == 1)
		{
			p = L->next;
			printf("进程%s正在调度……\n", p->data.name);
			Sleep(2000);
			printf("进程%s开始调度的时间为：%d\n", p->data.name, time);
			time += p->data.Serve_Time;
			printf("进程%s完成时间为：%d\n", p->data.name, time);
			q = L;
			Delet(L, q);
			printf("\n");
		}
		else
		{
			p = Max_Priority(L, count);
			q = p->next;
			printf("进程%s正在调度……\n", q->data.name);
			Sleep(2000);
			printf("进程%s开始调度的时间为：%d\n", q->data.name, time);
			time += q->data.Serve_Time;
			printf("进程%s完成时间为：%d\n", q->data.name, time);
			Delet(L, p);
			printf("\n");
		}
		//Show(L);  调试语句
	}
}


/*------------------------------------------------------抢占式优先级调度算法---------------------------------------------------------------*/
/*算法思想：在非抢占式优先级调度算法上进行改进，每执行1s，就判断一次当前就绪队列中是否有比当前正在执行的进程优先级高的，如果有则让优先级高的
进程先执行*/
/*测试用例：P1 1 3 0    P2 0 2 2    P3  0 2 1
*/


void Pre_priority(LinkList &L)
{
	int time = 0, count;
	LinkList p, q;
	while (L->next != NULL)
	{
		count = getCount(L, time);               //判断当前时间内，就绪队列里有多少进程
		if (count == 0)
			time++;                           //如果没有，则将时间加一，再进行判断
		if (count == 1)
		{
			q = L;
			p = q->next;
			printf("进程%s执行1s\n", p->data.name);
			time++;
			p->data.Serve_Time--;
			if (p->data.Serve_Time == 0)
			{
				printf("进程%s的完成时间为：%d\n", p->data.name, time);
				printf("进程%s的周转时间为：%d\n", p->data.name, time - p->data.Arrive_Time);
				Delet(L, q);                 //【重点】这里的参数一定要填q,而不是p,因为定义的函数Delet删除的是p所指向结点的下一个结点
			}
			printf("\n");
		}
		if (count >= 2)
		{
			q = Max_Priority(L, count);
			p = q->next;
			printf("进程%s执行1s\n", p->data.name);
			time++;
			p->data.Serve_Time--;
			if (p->data.Serve_Time == 0)
			{
				printf("进程%s的完成时间为：%d\n", p->data.name, time);
				printf("进程%s的周转时间为：%d\n", p->data.name, time - p->data.Arrive_Time);
				Delet(L, q);            //同上
			}
			//Show(L);  调试语句
			printf("\n");
		}
	}
}


/*---------------------------------------------------多级反馈队列调度算法-----------------------------------------------------------------*/
/*算法思想：设置三个反馈队列L1,L2,L3,同一队列中采用先来先服务算法，只有当优先级高的队列中没有可以调度的队列，调度下一级反馈队列，最后
一级队列中采用时间片轮转算法,取链表L中的第一个结点插入到Q1,注意time_的引用*/
/*测试用例：p1 0 6 0            Q1: 1 2
            P2 1 4 0            Q2: 2 2
			P3 2 2 0            Q3: 3 4
*/


void Create_Q(LinkQueue &Q)
{
	Q = (LinkQueue)malloc(sizeof(Queue));
	Q->next = NULL;
}


void Create_DuojiQ(LinkQueue &Q1, LinkQueue &Q2, LinkQueue &Q3)
{
	Create_Q(Q1);
	Create_Q(Q2);
	Create_Q(Q3);
	printf("请依次输入三级反馈队列的优先级和时间片！\n");
	printf("Q1:\t");
	scanf("%d%d", &Q1->prio, &Q1->timeblock);
	printf("Q2:\t");
	scanf("%d%d", &Q2->prio, &Q2->timeblock);
	printf("Q3:\t");
	scanf("%d%d", &Q3->prio, &Q3->timeblock);
}


void Delet_(LinkQueue &Q, LinkQueue p)   //删除结点函数,删除p的下一个结点
{
	LinkQueue q;
	q = p->next;
	p->next = q->next;
	free(q);
}


void Output(LinkQueue Q)
{
	LinkQueue q;
	q = Q->next;
	while (q != NULL)
	{
		printf("进程名：%s  到达时间：%d  服务时间：%d\n", q->data.name, q->data.Arrive_Time, q->data.Serve_Time);
		q = q->next;
	}
}




void InsertEnd1(LinkList &L, LinkQueue &Q)   //取L的队头元素插入到Q队列的末尾
{
	LinkList p, q;
	LinkQueue m, n, r;
	p = L;
	q = L->next;
	m = Q->next;
	r = Q;


	if (m == NULL && (q != NULL))
	{
		n = (LinkQueue)malloc(sizeof(Queue));
		n->data = q->data;
		Delet(L, p);
		r->next = n;
		r = n;
	}
	else if (m != NULL && (q != NULL))
	{
		q = L->next;
		while (m->next != NULL)              //注意这里一定要是m->next!=NULL,不能写成且能够m!=NULL
			m = m->next;
		r = m;
		n = (LinkQueue)malloc(sizeof(Queue));
		n->data = q->data;
		Delet(L, p);
		r->next = n;
		r = n;
	}
	r->next = NULL;


}


void InsertEnd2(LinkQueue &Q1, LinkQueue &Q2)   //取Q1的队头元素插入到Q2队列的末尾,
{
	LinkQueue p, q;
	LinkQueue m, n, r;
	p = Q1;
	q = Q1->next;
	m = Q2->next;
	r = Q2;
	if (m == NULL && (q != NULL))
	{
		n = (LinkQueue)malloc(sizeof(Queue));
		n->data = q->data;
		Delet_(Q1, p);
		r->next = n;
		r = n;
	}
	else if (m != NULL && (q != NULL))            //Q2不为空的时候
	{
		while (m->next != NULL)              //注意这里一定要是m->next!=NULL,不能写成且能够m!=NULL
			m = m->next;
		r = m;
		n = (LinkQueue)malloc(sizeof(Queue));
		n->data = q->data;
		r->next = n;
		r = n;
		Delet_(Q1, p);
	}
	r->next = NULL;


}


int getCount_(LinkQueue &Q, int time_)      //查看当前就绪队列中的进程数，其中time是宏观运行时间
{
	int count_ = 0;
	LinkQueue q;
	q = Q->next;
	while (q != NULL && q->data.Arrive_Time <= time_)
	{
		count_++;
		q = q->next;
	}
	return count_;
}






void Run(LinkQueue &Q1, LinkQueue &Q2, int &time_)            //根据每个队列分配的时间片，按照先来先服务算法执行
{
	LinkQueue p, q;
	int count_;
	while (Q1->next != NULL)
	{
		p = Q1->next;
		count_ = getCount_(Q1, time_);
		if (count_ = 0)
			time_++;
		else
		{
			q = Q1;
			if (p->data.Serve_Time <= Q1->timeblock)
			{
				printf("进程%s正在执行……\n", p->data.name);
				printf("进程%s开始执行的时间为：%d\n", p->data.name, time_);
				time_ += p->data.Serve_Time;
				printf("进程%s完成的时间为：%d\n", p->data.name, time_);
				printf("进程%s的周转时间为：%d\n", p->data.name, time_ - p->data.Arrive_Time);
				Delet_(Q1, q);          //这里的删除函数不能省
				printf("\n");
			}
			else
			{
				printf("进程%s正在执行……\n", p->data.name);
				printf("进程%s开始执行的时间为：%d\n", p->data.name, time_);
				time_ += Q1->timeblock;
				p->data.Serve_Time -= Q1->timeblock;
				printf("进程%s消耗%d个时间片，转入下一级反馈队列\n", p->data.name, Q1->timeblock);
				InsertEnd2(Q1, Q2);
				//Delet_(Q1,q);     //因为InsertEnd2中包含了删除，所以此处不能多此一举
			}
		}
	}
}


void TimeRound(LinkQueue &Q3, int &time_)              //时间片轮转算法
{
	LinkQueue q, p;
	q = Q3->next;
	while (Q3->next != NULL)
	{
		p = Q3;
		q = Q3->next;               //【重点】虽然在上面已经对q进行初始化，但是由于下面的else语句中的InsertEnd2中
								  //里面嵌套调用了Delet_函数，头结点发生了变化,故在while循环里还需要再初始化一次
		printf("进程%s执行1s\n", q->data.name);
		time_++;
		q->data.Serve_Time--;
		printf("Serve_Time 的值为：%d\n", q->data.Serve_Time);
		if (q->data.Serve_Time == 0)
		{
			printf("进程%s已经完成，完成时间为：%d\n", q->data.name, time_);
			Delet_(Q3, p);
		}
		else
		{
			InsertEnd2(Q3, Q3);
			//Delet_(Q3,p);           注意InsertEnd2中已经删掉了插入的结点，所以这里不需要多次一句
		}
	}
}


void MultiDispatch(LinkList &L, LinkQueue &Q1, LinkQueue &Q2, LinkQueue &Q3)      //多级反馈队列调度算法
{
	int time_ = 0, count_;
	LinkList p;
	p = L;
	Create_DuojiQ(Q1, Q2, Q3);
	while (L->next != NULL)
	{
		InsertEnd1(L, Q1);
		//Output(Q1);            调试语句
		//Delet(L,p);           //此处不需要，因为在InsertEnd1函数中已经把插入的结点从L中删除过了
	}
	while (Q1->next != NULL)
	{
		printf("\n");
		printf("^-^当前反馈队列为Q1 ^-^\n");
		Run(Q1, Q2, time_);
	}
	while (Q2->next != NULL)
	{
		printf("\n");
		printf("^-^当前反馈队列为Q2 ^-^\n");
		Run(Q2, Q3, time_);
	}
	while (Q3->next != NULL)
	{
		printf("\n");
		printf("^-^当前反馈队列为Q3 ^-^\n");
		TimeRound(Q3, time_);
	}
}


/*-----------------------------------------------------------主函数-----------------------------------------------------------------------*/


void main()
{
	LinkList L;
	LinkQueue Q1, Q2, Q3;
	int x;
	printf("-------------------进程调度------------------\n");
	printf("                1.   创建进程                \n");
	printf("                2. 显示进程信息              \n");
	printf("                3.先来先服务算法             \n");
	printf("                4.短作业优先算法             \n");
	printf("                5.非抢占式优先级调度算法     \n");
	printf("                6.抢占式优先级调度算法       \n");
	printf("                7.多级反馈队列算法           \n");
	printf("                8.退出                       \n");
	printf("---------------------------------------------\n");
	while (1)
	{
		printf("Choice:\t");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			Create(L);
			Sort(L);
			break;
		case 2:
			Show(L);
			break;
		case 3:
			FCFS(L);
			break;
		case 4:
			SJP(L);
			break;
		case 5:
			Non_priority(L);
			break;
		case 6:
			Pre_priority(L);
			break;
		case 7:
			MultiDispatch(L, Q1, Q2, Q3);
			break;
		case 8:
			exit(0);
		}
	}
}