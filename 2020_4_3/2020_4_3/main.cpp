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