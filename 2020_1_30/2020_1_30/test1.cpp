#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include"workmanager.h"
using namespace std;

int main()
{

	//���Դ���
	//worker *work = NULL;
	//work = new Employee(1, "����", 1);
	//work->showInfo();
	//delete work;

	////worker *work = NULL;
	//work = new Manager(2, "����", 2);
	//work->showInfo();
	//delete work;

	////worker *work = NULL;
	//work = new Boss(3, "����", 3);
	//work->showInfo();
	//delete work;
	int choice = 0;
	//ʵ���������߶���
	WorkManager wm;
	//����չʾ�˵��ĳ�Ա����
	while (true)
	{
		wm.Show_Menu();
		cout << "���������ѡ��:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1://���ְ��
			wm.Add_Emp();
			break;
		case 2://��ʾְ��
			wm.Show_Emp();
			break;
		case 3://ɾ��ְ��
			//����
			wm.Del_Emp();
			break;
		case 4://�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5://����ְ��
			wm.Find_Emp();
			break;
		case 6://����ְ��
			wm.Sort_Emp();
			break;
		case 7://����ļ�
			wm.Clean_File();
			break;

		default:
			break;
		}
		//system("cls");

	}
	cout << "����������ѡ��" << endl;
	return 0;
}
