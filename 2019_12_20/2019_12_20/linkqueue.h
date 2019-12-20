#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;    /*����������������Ԫ�ص���������*/

typedef struct linkqueuenode {       //ʹ�õ������¼���ݵ���ӣ���ͷ��ӽڵ㣩�ͳ��ӣ���βɾ���ڵ㣩
	datatype data;                 /*������*/
	struct linkqueuenode *next;      	/*����ָ����*/
}linkqueue_node, *linkqueue_pnode;     /*����Ԫ�����Ͷ���*/

typedef struct linkqueue {           //����һ���ṹ�壬��¼���У��������е�ͷ����β�ڵ�
	linkqueue_pnode front, rear;
}link_queue, *link_pqueue;

extern void init_linkqueue(link_pqueue *Q);          //��������
extern bool is_empty_linkqueue(link_pqueue q);            //�ж϶����Ƿ�Ϊ��
extern bool in_linkqueue(datatype data, link_pqueue q);      //���
extern bool out_linkqueue(link_pqueue q, datatype *D);     //����
extern void show_linkqueue(link_pqueue q);            //������ʾ��ͷ����β������
extern void free_linkqueue(link_pqueue q);           //�ͷŶ���

#endif