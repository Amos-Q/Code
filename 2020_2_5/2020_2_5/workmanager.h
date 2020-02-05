#define _CRT_SECURE_NO_WARNINGS 1
#pragma once//防止头文件包含
#include<string>
#include<fstream>
#include <iostream>
using namespace std;

#define FILENAME "empFlie.txt"
//worker类
class worker
{
public:
	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位
	virtual string getDeptName() = 0;

	//职工编号
	int m_id;
	//职工姓名
	string m_name;
	//部门编号
	int m_number;
};


class WorkManager
{
public:
	//构造函数
	WorkManager();

	//展现菜单
	void Show_Menu();

	//退出功能
	void ExitSystem();

	//记录职工人数
	int m_EmNum;

	//职工数组指针
	worker **m_EmpArray;

	//添加职工
	void Add_Emp();

	//保存文件
	void save();

	//判断文件是否为空 标志
	bool m_FileIsEmpty;

	//统计文件中人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示职工
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//判断职工是否存在 如果存在返回职工所在数组中的位置，不存在返回-1
	int IsExist(int id);


	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//按照编号排序
	void Sort_Emp();

	//清除文件
	void Clean_File();

	//析构函数
	~WorkManager();
};





//普通员工类
class Employee :public worker
{
public:
	//构造函数
	Employee(int id, string name, int number);

	//显示个人信息
	virtual void showInfo();

	//获取岗位
	virtual string getDeptName();


};

//经理类
class Manager :public worker
{
public:
	//构造函数
	Manager(int id, string name, int number);

	//显示个人信息
	virtual void showInfo();

	//获取岗位
	virtual string getDeptName();


};


//老板类
class Boss :public worker
{
public:
	//构造函数
	Boss(int id, string name, int number);

	//显示个人信息
	virtual void showInfo();

	//获取岗位
	virtual string getDeptName();


};
