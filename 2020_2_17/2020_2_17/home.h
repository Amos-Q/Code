#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<windows.h>
#define  len sizeof(phone)

typedef struct PHONE {
	char name[10];
	char home[5];
	char phone1[20];
	char phone2[20];
	char email[20];
	int sign;
	//  int classify;
	struct PHONE *next;
}phone;
phone *head;

void mainmenuface();

void show_one(phone *p);

phone * Lookdata(phone *p1);

phone * Inputdata();

void readfile();

Seek(phone *p2);

Keepdata(phone *p2);

Changedata(phone *p);

void deletedata();

void input(phone *p1);

void Insertdata();
