#define _CRT_SECURE_NO_WARNINGS 1
#include "home.h"

void choose() {
	int k;
	cin >> k;
	switch (k) {
	case 1:
		//��ѯ���� 
		system("cls");
		Select_show();
		break;
	case 2:
		//��ӽ���
		system("cls");
		Add_show();
		break;
	case 3:
		//�޸Ľ��� 
		system("cls");
		Update_show();
		break;
	case 4:
		//ɾ������ 
		system("cls");
		Remove_show();
		break;
	case 0:
		exit(0);
	default:
		cout << "����Ƿ�!����������:";
		choose();
	}
}
void Main_show() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~1.��ѯѧ����Ϣ~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~2.���ѧ����Ϣ~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~3.�޸�ѧ����Ϣ~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~4.ɾ��ѧ����Ϣ~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~0.�˳�����ϵͳ~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "����������ѡ��:";
	choose();
}
int main()
{
	s.length = 0;
	cout << "~~~~~~~~~~~~��ӭ������ϵͳ~~~~~~~~~~~~~~" << endl << endl;
	Main_show();
	return 0;
}