#define _CRT_SECURE_NO_WARNINGS 1
#pragma once//��ֹͷ�ļ�����
#include<string>
#include<fstream>
#include <iostream>
using namespace std;

#define FILENAME "empFlie.txt"
//worker��
class worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ
	virtual string getDeptName() = 0;

	//ְ�����
	int m_id;
	//ְ������
	string m_name;
	//���ű��
	int m_number;
};


class WorkManager
{
public:
	//���캯��
	WorkManager();

	//չ�ֲ˵�
	void Show_Menu();

	//�˳�����
	void ExitSystem();

	//��¼ְ������
	int m_EmNum;

	//ְ������ָ��
	worker **m_EmpArray;

	//���ְ��
	void Add_Emp();

	//�����ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ�� ��־
	bool m_FileIsEmpty;

	//ͳ���ļ�������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//�ж�ְ���Ƿ���� ������ڷ���ְ�����������е�λ�ã������ڷ���-1
	int IsExist(int id);


	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//���ձ������
	void Sort_Emp();

	//����ļ�
	void Clean_File();

	//��������
	~WorkManager();
};





//��ͨԱ����
class Employee :public worker
{
public:
	//���캯��
	Employee(int id, string name, int number);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ
	virtual string getDeptName();


};

//������
class Manager :public worker
{
public:
	//���캯��
	Manager(int id, string name, int number);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ
	virtual string getDeptName();


};


//�ϰ���
class Boss :public worker
{
public:
	//���캯��
	Boss(int id, string name, int number);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ
	virtual string getDeptName();


};
