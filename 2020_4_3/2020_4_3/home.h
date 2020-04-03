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

void Select_choose();//查询界面选择函数 
void Select_show();//查询界面 
void Main_show();//主界面 
void choose();//主界面选择函数 
void Add_show();//添加界面 
void Add_choose();//添加界面选择函数 
void add();//添加函数 
void Select_information();//查询学生信息 
void Select_score();//查询学生分数 
void Update_show();//修改界面 
void Updeta_choose();//修改界面选择函数 
void Update();//修改信息函数 
void Remove_show();//删除界面 
void Remove_choose();//删除界面选择函数 
void Remove();//删除函数 
