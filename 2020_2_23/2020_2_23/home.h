#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct worker
{
	char ID[20];//����
	char name[20];//����
	char sex[5];//�Ա�
	char born[20];//����
	char edu[20];//ѧ��
	char position[20];//ְ��
	char wage[10];//����
	char address[100];//סַ
	char tel[15];//�绰
}work[1000];
int n;

void read();
void input();
void output_inf(int id);
void que();
void mod();
void del();
