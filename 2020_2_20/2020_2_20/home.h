#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void display();
void find();
void menu();
void change1();
int load();
void save();
void sore();
struct person
{
	int ID;
	char name[24];
	char sex[24];
	char position[24];
	char place[24];
	float score;
	char email[24];
	long telephone;
}player[24];