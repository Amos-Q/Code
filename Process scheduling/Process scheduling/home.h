#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

struct Node{
	char name;
	int Tarrive;//����ʱ��
	int Tservice;//����ʱ��
	int Tsurplus;//ʣ��ʱ��
	int Tstart;//��ʼʱ��
	int Taccomplish;//���ʱ��
	int prio;//���ȼ�---����Խ�����ȼ�Խ��
	int if_finish;//�����Ƿ����
	int num;//���̸���
};

void display(struct Node job[10], int num);
void RR(struct Node job[10], int num);
void sjf(struct Node job[10], int num);
void Arrive_sort(struct Node job[10], int num);
void Service_sort(struct Node job[10], int num);
void Priority_sort(struct Node job[10], int num);
void Arrive_Short_sort(struct Node job[10], int num);
void fcfs(struct Node job[10], int num);
void print(struct Node job[10], int num);
