#define _CRT_SECURE_NO_WARNINGS 1
#include "home.h"

void choose() {
	int k;
	cin >> k;
	switch (k) {
	case 1:
		//查询界面 
		system("cls");
		Select_show();
		break;
	case 2:
		//添加界面
		system("cls");
		Add_show();
		break;
	case 3:
		//修改界面 
		system("cls");
		Update_show();
		break;
	case 4:
		//删除界面 
		system("cls");
		Remove_show();
		break;
	case 0:
		exit(0);
	default:
		cout << "输入非法!请重新输入:";
		choose();
	}
}
void Main_show() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~1.查询学生信息~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~2.添加学生信息~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~3.修改学生信息~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~4.删除学生信息~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~0.退出管理系统~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "请输入您的选择:";
	choose();
}
int main()
{
	s.length = 0;
	cout << "~~~~~~~~~~~~欢迎来到本系统~~~~~~~~~~~~~~" << endl << endl;
	Main_show();
	return 0;
}