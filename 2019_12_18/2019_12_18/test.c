#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct node
{
	int data;
	struct node *next;
}linknode;

typedef struct
{
	linknode *front;
	linknode *rear;
}listqueue;

listqueue *lq;

void setnull(listqueue *llq);
int empty(listqueue *llq);
void enqueue(listqueue *llq, int x);
void dequeue(listqueue *llq, int *x);
int front(listqueue *llq);


int main()
{
	int sel = 0;
	int ret = 0;
	int num = 0;

	lq = (listqueue *)malloc(sizeof(listqueue));
	if (NULL == lq)
	{
		printf("lq malloc failed\n");
		return 0;
	}

	setnull(lq);

	while (1)
	{
		printf("链式队列操作如下所示:\n");
		printf("\t1:进队列\n\t2:出队列\n\t3:取队首数据\n\t4:退出\n");
		printf("请输入选项:");
		scanf("%d", &sel);
		getchar();
		switch (sel)
		{
		case 1:
			printf("请输入进队列数据:\n");
			scanf("%d", &num);
			enqueue(lq, num);
			break;
		case 2:
			dequeue(lq, &ret);
			printf("取队首元素:%d\n", ret);
			break;
		case 3:
			ret = front(lq);
			if (ret == 0)
			{
				printf("取队首元素错误\n");
			}
			else
			{
				printf("取队首元素是:%d\n", ret);
			}
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("请选择正确的数据\n");
			break;
		}

	}

	return 0;
}

void setnull(listqueue *llq)
{
	llq->front = llq->rear = (linknode *)malloc(sizeof(linknode));
	if (NULL == llq)
	{
		printf("malloc failed\n");
		return;
	}
	llq->rear->next = NULL;
	//return llq;
}
int empty(listqueue *llq)
{
	if (llq->front == llq->rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void enqueue(listqueue *llq, int x)
{
	llq->rear->next = (linknode *)malloc(sizeof(linknode));
	if (NULL == llq->rear->next)
	{
		printf("llq->rear->next null\n");
		return;
	}
	llq->rear = llq->rear->next;
	llq->rear->data = x;
	llq->rear->next = NULL;
	//return llq;
}
void dequeue(listqueue *llq, int *x)
{
	if (empty(llq))
	{
		printf("dequeu underflow\n");
		return;
	}
	linknode *p = NULL;
	p = llq->front;
	llq->front = llq->front->next;
	free(p);
	p = NULL;
	*x = llq->front->data;
	//return llq;
}
int front(listqueue *llq)
{
	if (empty(llq))
	{
		printf("front underflow\n");
		return 0;
	}
	return llq->front->next->data;
}

顺序队列：

#include <stdio.h>
#include <stdlib.h>

#define maxsize 5
typedef int datatype;
typedef struct
{
	datatype front;
	datatype rear;
	datatype data[maxsize];
}sequeue;

void setnull(sequeue *lsq);
int empty(sequeue *lsq);
int enqueue(sequeue *lsq, int x);
int dequeue(sequeue *lsq);
int front(sequeue *lsq);

int main()
{
	int sel = 0;
	int ret = 0;
	int num = 0;
	sequeue *sq = NULL;
	sq = (sequeue *)malloc(sizeof(sequeue));
	if (NULL == sq)
	{
		printf("sq malloc failed\n");
		exit(0);
	}

	setnull(sq);
	while (1)
	{
		printf("顺序队列操作如下所示:\n");
		printf("\t1:进队列\n\t2:出队列\n\t3:取队首数据\n\t4:退出\n");
		printf("请输入选项:");
		scanf("%d", &sel);
		getchar();
		switch (sel)
		{
		case 1:
			printf("请输入进队列数据:\n");
			scanf("%d", &num);
			ret = enqueue(sq, num);
			if (ret == 0)
			{
				printf("进队列错误\n");
			}
			else
			{
				printf("进队列正确\n");
			}
			break;
		case 2:
			ret = dequeue(sq);
			if (ret == 0)
			{
				printf("出队列错误\n");
			}
			else
			{
				printf("出队列元素是:%d\n", ret);
			}
			break;
		case 3:
			ret = front(sq);
			if (ret == 0)
			{
				printf("取队首元素错误\n");
			}
			else
			{
				printf("取队首元素是:%d\n", ret);
			}
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("请选择正确的数据\n");
			break;
		}

	}

	return 0;
}
void setnull(sequeue *lsq)
{
	lsq->front = lsq->rear = maxsize - 1;
}
int empty(sequeue *lsq)
{
	if (lsq->front == lsq->rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int enqueue(sequeue *lsq, int x)
{
	printf("enqueue front:%d\n", lsq->front);
	printf("enqueue rear:%d\n", lsq->rear);
	if ((lsq->front) == ((lsq->rear + 1) % maxsize))
	{
		printf("sequeue full\n");
		return 0;
	}
	lsq->rear = (lsq->rear + 1) % maxsize;
	lsq->data[lsq->rear] = x;
	return 1;
}
int dequeue(sequeue *lsq)
{
	printf("sequeue front:%d\n", lsq->front);
	printf("sequeue rear:%d\n", lsq->rear);
	if (empty(lsq))
	{
		printf("sequeue empty\n");
		return 0;
	}
	lsq->front = (lsq->front + 1) % maxsize;
	int num = 0;
	num = lsq->data[lsq->front];
	return num;
}
int front(sequeue *lsq)
{
	if (empty(lsq))
	{
		printf("sequeue empty\n");
		return 0;
	}
	int num = 0;
	num = lsq->data[lsq->front + 1];
	return num;
}