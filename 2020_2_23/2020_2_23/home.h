#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct worker
{
	char ID[20];//工号
	char name[20];//姓名
	char sex[5];//性别
	char born[20];//生日
	char edu[20];//学历
	char position[20];//职务
	char wage[10];//工资
	char address[100];//住址
	char tel[15];//电话
}work[1000];
int n;

void read();
void input();
void output_inf(int id);
void que();
void mod();
void del();
