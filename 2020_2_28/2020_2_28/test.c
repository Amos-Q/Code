#define _CRT_SECURE_NO_WARNINGS 1

#include "all.h"


//����Ա��¼��ˡ���ҳ 
void gl(struct student stu[N]) {
	struct student *p;
	p = stu;
	int n = 0;
	char numgl[3] = { "t1" };
	char passgl[6] = { '1','2','3','4','5','6' };
input:printf("����������˺ţ�");
	char num[3];
	//gets(num);
	scanf("%s", &num);
	printf("������������룺");
	char pass[6];
	//gets(pass);
	scanf("%s", &pass);
	if (strcmp(numgl, num) != 0 || strcmp(passgl, pass) != 0)
	{
		printf("������������������룡\n");
		//gl();
		goto input;
	}
	while (n < 6)
	{
		system("cls");
		printf("\t\t\t����������������������������������������������������������������\n");
		printf("\t\t\t��             ����Ա           ��\n");
		printf("\t\t\t����������������������������������������������������������������\n");
		printf("\t\t\t��      1. ���ѧ��             ��\n");
		printf("\t\t\t��      2. �޸�ѧ����Ϣ         ��\n");
		printf("\t\t\t��      3. ��ѯѧ����Ϣ         ��\n");
		printf("\t\t\t��      4. ɾ��ѧ��             ��\n");
		printf("\t\t\t��      5. ��������             ��\n");
		printf("\t\t\t��      0. �˳�                 ��\n");
		printf("\t\t\t����������������������������������������������������������������\n\n");
		printf("��ѡ��0-5����");
		scanf("%d", &n);
		switch (n)
		{
		case 1: Insert(p); break;
		case 2: Update(p); break;
		case 3: Select(p); break;
		case 4: Delete(p); break;
		case 5: All(p); break;
			//case 0:exit(1);
		case 0: n = 6; break;
		}
	}
}

//���������� 
int main() {
	int n, flag;
	struct student *p, stu[N];
	p = stu;
	filew(p);//�������� 

	while (1) {
		flag = in();
		if (flag == 1)
			gl(p);
		else if (flag == 2)
			Student(p);
		else
			exit(1);
		//system("cls");  //��������
	}
	return 0;
}