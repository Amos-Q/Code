#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<string.h>
#define N 30
//学生数据结构体 
struct student {
	char num[10];//学号 
	char name[10];//姓名 
	char sex[10];//性别 
	char Id[20];//身份证号 
	char pass[10];//密码 
	char isbd[10];//报到 
	char dormitory[10];//宿舍 
	char cad[15];//班级 
};
int sum, Sid = -1;
//从文件读入学生数据