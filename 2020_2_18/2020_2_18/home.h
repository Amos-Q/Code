#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define N sizeof(struct BOOK) //sizeof���ֽ�������� 
struct BOOK
{
	char name[20];//���� 
	char author[20];//���� 
	char type[10];//���� 
	float price;// �۸� 
	int num;   // ����
	int x;//�����޸�����ʱ���ҵ������е�ĳ�����ݵ�λ�� 
	struct BOOK *next;
};

void login();//��¼ 
void menu();//�ܲ˵� 
void over();//�˳����� 
struct BOOK *readIn();//���ļ��е����ݶ�����������,
void inputBook();//1����ͼ�� 
void saveBook(struct BOOK *p);//��ͼ����Ϣ�����ļ�
void amendBook();//2�޸���Ϣ 
void deleteBook();//3ɾ����Ϣ 
void findBook();//4ͼ���ѯ 
void find_name_book();
void find_author_book();
void find_type_book();
void find_price_book();
void printBook();//ͼ������ 
void over();//�������� 