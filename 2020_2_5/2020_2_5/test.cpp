#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include"workmanager.h"
using namespace std;

int main()
{

	//测试代码
	//worker *work = NULL;
	//work = new Employee(1, "张三", 1);
	//work->showInfo();
	//delete work;

	////worker *work = NULL;
	//work = new Manager(2, "李四", 2);
	//work->showInfo();
	//delete work;

	////worker *work = NULL;
	//work = new Boss(3, "王五", 3);
	//work->showInfo();
	//delete work;
	int choice = 0;
	//实例化管理者对象
	WorkManager wm;
	//调用展示菜单的成员函数
	while (true)
	{
		wm.Show_Menu();
		cout << "请输入你的选择:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.ExitSystem();
			break;
		case 1://添加职工
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.Show_Emp();
			break;
		case 3://删除职工
			//测试
			wm.Del_Emp();
			break;
		case 4://修改职工
			wm.Mod_Emp();
			break;
		case 5://查找职工
			wm.Find_Emp();
			break;
		case 6://排序职工
			wm.Sort_Emp();
			break;
		case 7://清空文件
			wm.Clean_File();
			break;

		default:
			break;
		}
		//system("cls");

	}
	cout << "请输入您的选择" << endl;
	return 0;
}
