#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;    /*定义链队列中数据元素的数据类型*/

typedef struct linkqueuenode {       //使用单链表记录数据的入队（队头添加节点）和出队（队尾删除节点）
	datatype data;                 /*数据域*/
	struct linkqueuenode *next;      	/*链接指针域*/
}linkqueue_node, *linkqueue_pnode;     /*链表元素类型定义*/

typedef struct linkqueue {           //定义一个结构体，记录队列（单链表）中的头结点和尾节点
	linkqueue_pnode front, rear;
}link_queue, *link_pqueue;

extern void init_linkqueue(link_pqueue *Q);          //创建队列
extern bool is_empty_linkqueue(link_pqueue q);            //判断队列是否为空
extern bool in_linkqueue(datatype data, link_pqueue q);      //入队
extern bool out_linkqueue(link_pqueue q, datatype *D);     //出队
extern void show_linkqueue(link_pqueue q);            //依次显示队头到队尾的数据
extern void free_linkqueue(link_pqueue q);           //释放队列

#endif