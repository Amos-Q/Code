#define _CRT_SECURE_NO_WARNINGS 1
#include "home.h"

void Remove() {
	system("cls");
	if (s.length == 0) {//�ж��Ƿ���ѧ�� 
		cout << "��ϵͳ����ѧ����Ϣ!" << endl;
		Main_show();//�ص������� 
	}
	cout << "������Ҫɾ��ѧ����ѧ��:";
	int sno;
	int count = 0;
	int t = -1;
	while (true) {
		if (count >= 5) {
			system("cls");
			cout << "���Ѿ�����ʧ��" << count << "����,�����½���!" << endl;//ѧ������ʧ��һ���������� 
			Main_show();
		}
		cin >> sno;
		count++;
		for (int i = 0; i < s.length; i++) {//�������飬�ҵ���ѧ��ѧ����Ϣ 
			if (s.stu[i].getSno() == sno) {
				t = i;
				break;
			}
		}
		if (t == -1) {//������û�и�ѧ��
			if (count < 5) {
				cout << "û�и�ѧ������Ϣ,����������:";
			}
			continue;
		}
		else {
			cout << "�Ƿ�Ҫɾ����ѧ��(" << sno << ")����ϢΪ:(Y or N)" << endl;
			cout << "����(" << s.stu[t].getName() << ")\t�Ա�(" << s.stu[t].getSex() << ")\t����(" << s.stu[t].getAge() << ")\t��ѧ(" << s.stu[t].getMath() << ")\tӢ��(" << s.stu[t].getEnglish() << ")\t�����(" << s.stu[t].getComputer() << ")" << endl;
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
					cout << "ɾ���ɹ�!" << endl;
					cout << "�Ƿ����ɾ��ѧ����Ϣ(Y or N):";
					char d;
					while (true) {
						cin >> d;
						if (d == 'Y' || d == 'y') {
							Remove();
						}
						else if (d == 'N' || d == 'n') {
							system("cls");//�������� 
							Main_show();
						}
						else {
							cout << "����Ƿ�!����������:";
						}
					}
				}
				else {
					cout << "����Ƿ�!����������:";
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
		cout << "����Ƿ�,����������:";
		Remove_choose();
	}
}
void Remove_show() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~1.ɾ��ѧ����Ϣ~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~2.�����ϼ�Ŀ¼~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~0.�˳�����ϵͳ~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "����������ѡ��:";
	Remove_choose();
}
void Update() {
	system("cls");
	if (s.length == 0) {
		cout << "��ϵͳ����ѧ����Ϣ!" << endl;
		Main_show();
	}
	cout << "������Ҫ������Ϣѧ����ѧ��:";
	int sno;
	int count = 0;
	int t = -1;
	while (true) {
		cin >> sno;
		count++;
		if (count >= 5) {
			system("cls");
			cout << "���Ѿ�����ʧ��" << count << "����,�����½���!" << endl;//ѧ������ʧ��һ���������� 
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
				cout << "û���ҵ���ѧ��,����������ѧ��:";
			}
			continue;
		}
		else {
			cout << "ѧ��(" << sno << ")" << endl << "����(" << s.stu[t].getName() << ")\t�Ա�(" << s.stu[t].getSex() << ")\t����(" << s.stu[t].getAge() << ")\t��ѧ(" << s.stu[t].getMath() << ")\tӢ��(" << s.stu[t].getEnglish() << ")\t�����(" << s.stu[t].getComputer() << ")" << endl;
			cout << "�������ѧ��������Ϣ:";
			string name, sex;
			int age;
			double math, english, computer;
			cin >> name >> sex >> age >> math >> english >> computer;
			cout << "�Ƿ�Ҫ�޸ĸ�ѧ��(" << sno << ")����ϢΪ:(Y or N)" << endl;
			cout << "����(" << name << ")\t�Ա�(" << sex << ")\t����(" << age << ")\t��ѧ(" << math << ")\tӢ��(" << english << ")\t�����(" << computer << ")" << endl;
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
					cout << "����Ƿ�,����������:";
				}
			}
			cout << "�Ƿ�����޸�ѧ����Ϣ:(Y or N)";
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
					cout << "����Ƿ�,����������:";
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
		cout << "����Ƿ�,����������:";
		Update_choose();
	}
}
void Update_show() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~1.�޸�ѧ����Ϣ~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~2.�����ϼ�Ŀ¼~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~0.�˳�����ϵͳ~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "����������ѡ��:";
	Update_choose();
}
void Select_information() {
	cout << "ѧ��\t����\t�Ա�\t����\n";
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
	cout << "ѧ��\t����\t��ѧ\tӢ��\t�����\t�ܷ�\n";
	for (int i = 0; i < s.length; i++) {
		cout << s.stu[i].getSno() << "\t" << s.stu[i].getName() << "\t" << s.stu[i].getMath() << "\t" << s.stu[i].getEnglish() << "\t" << s.stu[i].getComputer() << "\t" << s.stu[i].getMath() + s.stu[i].getEnglish() + s.stu[i].getComputer() << endl;
		sum1 = sum1 + s.stu[i].getMath();
		sum2 = sum2 + s.stu[i].getEnglish();
		sum3 = sum3 + s.stu[i].getComputer();
	}
	if (s.length != 0) {
		cout.precision(4);
		cout << "\nƽ����:\t\t" << sum1 / s.length << "\t" << sum2 / s.length << "\t" << sum3 / s.length << "\t" << (sum1 + sum2 + sum3) / s.length << endl;
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
	cout << "������ѧ��:";
	int sno;
	do {
		cin >> sno;
		for (int i = 0; i < s.length; i++) {
			if (s.stu[i].getSno() == sno)
				flag = true;
		}
		if (flag) {
			flag = false;
			cout << "��ѧ���Ѵ���!" << endl;
			cout << "����������ѧ��:";
		}
		else {
			s.stu[s.length].setSno(sno);
			break;
		}
	} while (true);
	cout << "����������:";
	string name;
	cin >> name;
	s.stu[s.length].setName(name);
	cout << "�������Ա�";
	string sex;
	cin >> sex;
	s.stu[s.length].setSex(sex);
	cout << "����������:";
	int age;
	cin >> age;
	s.stu[s.length].setAge(age);
	cout << "��������ѧ�ɼ�:";
	double math;
	cin >> math;
	s.stu[s.length].setMath(math);
	cout << "������Ӣ��ɼ�:";
	double english;
	cin >> english;
	s.stu[s.length].setEnglish(english);
	cout << "�����������ɼ�:";
	double computer;
	cin >> computer;
	s.stu[s.length].setComputer(computer);
	system("cls");
	cout << "ѧ��(" << sno << "),����(" << name << "),�Ա�(" << sex << "),����(" << age << "),��ѧ(" << math << "),Ӣ��(" << english << "),�����(" << computer << ")" << endl << "ȷ��Ҫ��Ӹ�ѧ��?(Y or N)" << endl;
	char t;
	do {
		cin >> t;
		if (t == 'Y' || t == 'y') {
			s.length++;
			cout << "��Ҫ���������?(Y or N)" << endl;
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
					cout << "����Ƿ�,����������:";
				}
			} while (true);
		}
		else if (t == 'N' || t == 'n') {
			system("cls");
			Add_show();
		}
		else {
			cout << "����Ƿ�,����������:";
		}
	} while (true);
}