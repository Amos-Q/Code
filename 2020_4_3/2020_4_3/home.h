#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstring>
#include<process.h>

#define Max 200

struct Student {
	student stu[Max];
	int length;
};
Student s;

using namespace std;

void Select_choose();//��ѯ����ѡ���� 
void Select_show();//��ѯ���� 
void Main_show();//������ 
void choose();//������ѡ���� 
void Add_show();//��ӽ��� 
void Add_choose();//��ӽ���ѡ���� 
void add();//��Ӻ��� 
void Select_information();//��ѯѧ����Ϣ 
void Select_score();//��ѯѧ������ 
void Update_show();//�޸Ľ��� 
void Updeta_choose();//�޸Ľ���ѡ���� 
void Update();//�޸���Ϣ���� 
void Remove_show();//ɾ������ 
void Remove_choose();//ɾ������ѡ���� 
void Remove();//ɾ������ 
