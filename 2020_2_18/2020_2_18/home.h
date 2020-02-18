#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define N sizeof(struct BOOK) //sizeof求字节数运算符 
struct BOOK
{
	char name[20];//书名 
	char author[20];//作者 
	char type[10];//类型 
	float price;// 价格 
	int num;   // 数量
	int x;//用于修改数据时，找到链表中的某个数据的位置 
	struct BOOK *next;
};

void login();//登录 
void menu();//总菜单 
void over();//退出程序 
struct BOOK *readIn();//将文件中的内容读出到链表中,
void inputBook();//1增添图书 
void saveBook(struct BOOK *p);//将图书信息存入文件
void amendBook();//2修改信息 
void deleteBook();//3删除信息 
void findBook();//4图书查询 
void find_name_book();
void find_author_book();
void find_type_book();
void find_price_book();
void printBook();//图书总览 
void over();//结束程序 