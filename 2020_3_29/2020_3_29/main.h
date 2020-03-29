#define _CRT_SECURE_NO_WARNINGS 1
/*
顺序循环队列
UP @hey超级巨星
*/
#include <stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
#define ERROR 0
#define OK 1
#define True 1
#define False 0
#define MAXSIZE 20
typedef int Status;
typedef int Elemtype;
typedef struct
{
	Elemtype* base;
	Elemtype front;
	Elemtype rear;
	int maxsize = 0;
}Queue;