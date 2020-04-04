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
void Update_choose() {
	int k;
	cin >> k;
	switch (k) {
	case 1:
		system("cls");
		Update();
		break;
	case 2:
		system("cls");
		Main_show();
		break;
	case 0:
		exit(0);
	default:
		cout << "输入非法,请重新输入:";
		Update_choose();
	}
}
void Update_show() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~1.修改学生信息~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~2.返回上级目录~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~0.退出管理系统~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "请输入您的选择:";
	Update_choose();
}
void Select_information() {
	cout << "学号\t姓名\t性别\t年龄\n";
	for (int i = 0; i < s.length; i++) {
		cout << s.stu[i].getSno() << "\t" << s.stu[i].getName() << "\t" << s.stu[i].getSex() << "\t" << s.stu[i].getAge() << endl;
	}
	char c;
	cin >> c;
	while (1) {
		system("cls");
		Select_show();
	}
}
void Select_score() {
	double sum1 = 0, sum2 = 0, sum3 = 0;
	cout << "学号\t姓名\t数学\t英语\t计算机\t总分\n";
	for (int i = 0; i < s.length; i++) {
		cout << s.stu[i].getSno() << "\t" << s.stu[i].getName() << "\t" << s.stu[i].getMath() << "\t" << s.stu[i].getEnglish() << "\t" << s.stu[i].getComputer() << "\t" << s.stu[i].getMath() + s.stu[i].getEnglish() + s.stu[i].getComputer() << endl;
		sum1 = sum1 + s.stu[i].getMath();
		sum2 = sum2 + s.stu[i].getEnglish();
		sum3 = sum3 + s.stu[i].getComputer();
	}
	if (s.length != 0) {
		cout.precision(4);
		cout << "\n平均分:\t\t" << sum1 / s.length << "\t" << sum2 / s.length << "\t" << sum3 / s.length << "\t" << (sum1 + sum2 + sum3) / s.length << endl;
	}
	char c;
	cin >> c;
	while (1) {
		system("cls");
		Select_show();
	}
}
void add() {
	bool flag = false;
	system("cls");
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "请输入学号:";
	int sno;
	do {
		cin >> sno;
		for (int i = 0; i < s.length; i++) {
			if (s.stu[i].getSno() == sno)
				flag = true;
		}
		if (flag) {
			flag = false;
			cout << "该学号已存在!" << endl;
			cout << "请重新输入学号:";
		}
		else {
			s.stu[s.length].setSno(sno);
			break;
		}
	} while (true);
	cout << "请输入姓名:";
	string name;
	cin >> name;
	s.stu[s.length].setName(name);
	cout << "请输入性别";
	string sex;
	cin >> sex;
	s.stu[s.length].setSex(sex);
	cout << "请输入年龄:";
	int age;
	cin >> age;
	s.stu[s.length].setAge(age);
	cout << "请输入数学成绩:";
	double math;
	cin >> math;
	s.stu[s.length].setMath(math);
	cout << "请输入英语成绩:";
	double english;
	cin >> english;
	s.stu[s.length].setEnglish(english);
	cout << "请输入计算机成绩:";
	double computer;
	cin >> computer;
	s.stu[s.length].setComputer(computer);
	system("cls");
	cout << "学号(" << sno << "),姓名(" << name << "),性别(" << sex << "),年龄(" << age << "),数学(" << math << "),英语(" << english << "),计算机(" << computer << ")" << endl << "确定要添加该学生?(Y or N)" << endl;
	char t;
	do {
		cin >> t;
		if (t == 'Y' || t == 'y') {
			s.length++;
			cout << "您要继续添加吗?(Y or N)" << endl;
			char temp;
			do {
				cin >> temp;
				if (temp == 'Y' || temp == 'y') {
					system("cls");
					add();
				}
				else if (temp == 'N' || temp == 'n') {
					system("cls");
					Main_show();
				}
				else {
					cout << "输入非法,请重新输入:";
				}
			} while (true);
		}
		else if (t == 'N' || t == 'n') {
			system("cls");
			Add_show();
		}
		else {
			cout << "输入非法,请重新输入:";
		}
	} while (true);
}