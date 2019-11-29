#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

struct Node{
	char name;
	int Tarrive;//到达时间
	int Tservice;//服务时间
	int Tsurplus;//剩余时间
	int Tstart;//开始时间
	int Taccomplish;//完成时间
	int prio;//优先级---数字越大优先级越高
	int if_finish;//进程是否完成
	int num;//进程个数
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
