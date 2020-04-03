#define _CRT_SECURE_NO_WARNINGS 1
#include "home.h"

void Remove() {
	system("cls");
	if (s.length == 0) {//判断是否有学生 
		cout << "该系统内无学生信息!" << endl;
		Main_show();//回到主界面 
	}
	cout << "请输入要删除学生的学号:";
	int sno;
	int count = 0;
	int t = -1;
	while (true) {
		if (count >= 5) {
			system("cls");
			cout << "您已经输入失败" << count << "次了,请重新进入!" << endl;//学号输入失败一定次数返回 
			Main_show();
		}
		cin >> sno;
		count++;
		for (int i = 0; i < s.length; i++) {//遍历数组，找到该学号学生信息 
			if (s.stu[i].getSno() == sno) {
				t = i;
				break;
			}
		}
		if (t == -1) {//数组内没有该学号
			if (count < 5) {
				cout << "没有该学生的信息,请重新输入:";
			}
			continue;
		}
		else {
			cout << "是否要删除该学生(" << sno << ")的信息为:(Y or N)" << endl;
			cout << "姓名(" << s.stu[t].getName() << ")\t性别(" << s.stu[t].getSex() << ")\t年龄(" << s.stu[t].getAge() << ")\t数学(" << s.stu[t].getMath() << ")\t英语(" << s.stu[t].getEnglish() << ")\t计算机(" << s.stu[t].getComputer() << ")" << endl;
			char c;
			while (true) {
				cin >> c;
				if (c == 'N' || c == 'n') {
					system("cls");
					Remove_show();
				}
				else if (c == 'Y' || c == 'y') {
					if (t == s.length - 1) {
						s.length--;
					}
					else {
						s.stu[t].copy(s.stu[s.length - 1]);
						s.length--;
					}
					cout << "删除成功!" << endl;
					cout << "是否继续删除学生信息(Y or N):";
					char d;
					while (true) {
						cin >> d;
						if (d == 'Y' || d == 'y') {
							Remove();
						}
						else if (d == 'N' || d == 'n') {
							system("cls");//清屏函数 
							Main_show();
						}
						else {
							cout << "输入非法!请重新输入:";
						}
					}
				}
				else {
					cout << "输入非法!请重新输入:";
				}
			}
		}
	}
}
void Remove_choose() {
	int k;
	cin >> k;
	switch (k) {
	case 1:
		system("cls");
		Remove();
		break;
	case 2:
		system("cls");
		Main_show();
		break;
	case 0:
		exit(0);
	default:
		cout << "输入非法,请重新输入:";
		Remove_choose();
	}
}
void Remove_show() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~1.删除学生信息~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~2.返回上级目录~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~0.退出管理系统~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "请输入您的选择:";
	Remove_choose();
}
void Update() {
	system("cls");
	if (s.length == 0) {
		cout << "该系统内无学生信息!" << endl;
		Main_show();
	}
	cout << "请输入要更新信息学生的学号:";
	int sno;
	int count = 0;
	int t = -1;
	while (true) {
		cin >> sno;
		count++;
		if (count >= 5) {
			system("cls");
			cout << "您已经输入失败" << count << "次了,请重新进入!" << endl;//学号输入失败一定次数返回 
			Main_show();
		}
		for (int i = 0; i < s.length; i++) {
			if (s.stu[i].getSno() == sno) {
				t = i;
				break;
			}
		}
		if (t == -1) {
			if (count < 5) {
				cout << "没有找到该学生,请重新输入学号:";
			}
			continue;
		}
		else {
			cout << "学号(" << sno << ")" << endl << "姓名(" << s.stu[t].getName() << ")\t性别(" << s.stu[t].getSex() << ")\t年龄(" << s.stu[t].getAge() << ")\t数学(" << s.stu[t].getMath() << ")\t英语(" << s.stu[t].getEnglish() << ")\t计算机(" << s.stu[t].getComputer() << ")" << endl;
			cout << "请输入该学生的新信息:";
			string name, sex;
			int age;
			double math, english, computer;
			cin >> name >> sex >> age >> math >> english >> computer;
			cout << "是否要修改该学生(" << sno << ")的信息为:(Y or N)" << endl;
			cout << "姓名(" << name << ")\t性别(" << sex << ")\t年龄(" << age << ")\t数学(" << math << ")\t英语(" << english << ")\t计算机(" << computer << ")" << endl;
			char c;
			while (true) {
				cin >> c;
				if (c == 'Y' || c == 'y') {
					s.stu[t].setName(name);
					s.stu[t].setSex(sex);
					s.stu[t].setAge(age);
					s.stu[t].setMath(math);
					s.stu[t].setEnglish(english);
					s.stu[t].setComputer(computer);
					break;
				}
				else if (c == 'N' || c == 'n') {
					break;
				}
				else {
					cout << "输入非法,请重新输入:";
				}
			}
			cout << "是否继续修改学生信息:(Y or N)";
			char d;
			while (true) {
				cin >> d;
				if (d == 'Y' || d == 'y') {
					system("cls");
					Update();
				}
				else if (d == 'N' || d == 'n') {
					system("cls");
					Main_show();
				}
				else {
					cout << "输入非法,请重新输入:";
				}
			}
		}
	}
}