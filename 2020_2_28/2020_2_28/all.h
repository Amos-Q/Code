#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<string.h>
#define N 30
//ѧ�����ݽṹ�� 
struct student {
	char num[10];//ѧ�� 
	char name[10];//���� 
	char sex[10];//�Ա� 
	char Id[20];//���֤�� 
	char pass[10];//���� 
	char isbd[10];//���� 
	char dormitory[10];//���� 
	char cad[15];//�༶ 
};
int sum, Sid = -1;
//���ļ�����ѧ������