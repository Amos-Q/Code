#define _CRT_SECURE_NO_WARNINGS 1
#include "all.h"

void filew(struct student stu[N]) {
	FILE *fp;
	int i, no = 0;
	if ((fp = fopen("student.txt", "r")) == NULL)
	{
		printf("�ļ���ʧ��!\n");
		//exit(1);  
	}
	for (i = 0; i < N && !feof(fp); i++)
	{
		fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
			stu[i].num, stu[i].name, stu[i].sex, stu[i].Id, stu[i].pass, stu[i].isbd, stu[i].dormitory, stu[i].cad);
		no++;
	}
	sum = no;
	fclose(fp);
	/*for(i=0;i<no&&stu[i].num[0];i++)
	 printf("ѧ�ţ�%s\t������%s\t�Ա�%s\tʡ��֤�ţ�%s\t���룺%s\t������%s\t���᣺%s\t�༶��%s\n",
   stu[i].num,stu[i].name,stu[i].sex,stu[i].Id,stu[i].pass,stu[i].isbd,stu[i].dormitory,stu[i].cad);*/
}
//����ϵͳ����
int in() {
	system("cls");  //��������
	printf("\t\t\t����������������������������������������������������������������\n");
	printf("\t\t\t��                              ��\n");
	printf("\t\t\t��      ������ѧ����ϵͳ        ��\n");
	printf("\t\t\t��                              ��\n");
	printf("\t\t\t��           ��ӭʹ��           ��\n");
	printf("\t\t\t��                              ��\n");
	printf("\t\t\t��           1.����Ա           ��\n");
	printf("\t\t\t��                              ��\n");
	printf("\t\t\t��           2.��ѧ��           ��\n");
	printf("\t\t\t��                              ��\n");
	printf("\t\t\t��           0.�˳�             ��\n");
	printf("\t\t\t��                              ��\n");
	printf("\t\t\t����������������������������������������������������������������\n");
	//getch();
	int flag;
	printf("��ѡ����ݽ���ϵͳ:");
	scanf("%d", &flag);
	return flag;
}
//T1.���ѧ����Ϣ 
void Insert(struct student stu[N]) {
	FILE *fp;
	int i, j, k = 0;
	char name[10];
	if ((fp = fopen("student.txt", "a")) == NULL)
	{
		printf("�ļ���ʧ��!");
		exit(1);
	}
	printf("���ѧ������:");
	scanf("%d", &i);
	while (j < i) {
	input:printf("�������%d��ѧ��ѧ�ţ�", j + 1);
		scanf("%s", name);
		for (k = 0; k < sum + j; k++)
			if (strcmp(name, stu[k].num) == 0)
			{
				printf("��ѧ���Ѵ��ڣ�\n");
				goto input;
			}
		if (k == sum + j) {
			strcpy(stu[sum + j].num, name);
			strcpy(stu[sum + j].pass, "123456");
			strcpy(stu[sum + j].isbd, "δ");
			printf("�����ΰ�д˳������ѧ����Ϣ��\n����\t�Ա�\t���֤��\t\t����\t�༶\n");
			scanf("%s\t%s\t%s\t%s\t%s",
				stu[sum + j].name, stu[sum + j].sex, stu[sum + j].Id, stu[sum + j].dormitory, stu[sum + j].cad);
			fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
				stu[sum + j].num, stu[sum + j].name, stu[sum + j].sex, stu[sum + j].Id, stu[sum + j].pass, stu[sum + j].isbd, stu[sum + j].dormitory, stu[sum + j].cad);
			j++;
		}
	}
	sum = sum + i;
	fclose(fp);
	printf("��ӳɹ����������������ҳ��!\n");
	getch();
}
//T2.�޸�ѧ����Ϣ 
void Update(struct student stu[N]) {
	FILE *fp;
	char i[10];
	int j = 0, k, n, m;
input:printf("�������޸�ѧ����Ϣ��ѧ��:");
	scanf("%s", &i);
	for (k = 0; k < sum; k++) {
		//printf("\n%s\n%s\n",i,stu[k].num);
		if (strcmp(stu[k].num, i) == 0) {
			printf("��ѧ����Ϣ���£�\nѧ��\t����\t�Ա�\t���֤��\t\t����\t����\t����\t�༶\n");
			printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
				stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory, stu[k].cad);
			break;
		}
	}
	if (k == sum) {
		printf("������������������룡\n");
		goto input;
	}
	printf("������Ҫ�޸ĵĸ���:");
	scanf("%d", &n);
	m = 0;
	while (m < n) {
		printf("��ѡ��Ҫ�޸ĵĵ�%d�����ݣ�1.ѧ��|2.����|3.�Ա�|4.��֤��|5.����|6.����|7.����|8.�༶����", m + 1);
		scanf("%d", &j);
		printf("�������޸ĵ����ݣ�");
		switch (j)
		{
		case 1: scanf("%s", stu[k].num); break;
		case 2: scanf("%s", stu[k].name); break;
		case 3: scanf("%s", stu[k].sex); break;
		case 4: scanf("%s", stu[k].Id); break;
		case 5: scanf("%s", stu[k].pass); break;
		case 6: scanf("%s", stu[k].isbd); break;
		case 7: scanf("%s", stu[k].dormitory); break;
		case 8: scanf("%s", stu[k].cad); break;
		}
		m++;
	}
	if ((fp = fopen("student.txt", "w")) == NULL)
	{
		printf("�ļ���ʧ��!");
		exit(1);
	}
	k = 0;
	while (k < sum) {
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
			stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory, stu[k].cad);
		k++;
	}
	fclose(fp);
	printf("�޸ĳɹ����������������ҳ�棡\n");
	getch();
}
//T3.1��ѯ���� 
int SelectCase(struct student stu[N], int k, int n) {
	n++;
	printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
		stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory, stu[k].cad);
	return n;
}
//T3.2��ѯ��� 
int SelectAlsole(int n) {
	if (n == 0) {
		printf("�����ڸ����ݣ����������룡\n");
		return 1;
	}
	else {
		printf("�ɹ���ѯ��%d��ѧ����Ϣ���������������ҳ�棡\n", n);
		getch();
		return 0;
	}
}
//T3.��ѯѧ����Ϣ 
void Select(struct student stu[N]) {
	char cx[20];
	int j = 0, k, n = 0;
	struct student *p;
	p = stu;
	printf("��ѡ��Ҫ��ѯ�����ݣ�1.ѧ��|2.����|3.�Ա�|4.��֤��|5.����|6.����|7.����|8.�༶����");
	scanf("%d", &j);
input:printf("������Ҫ��ѯ�����ݣ�");
	scanf("%s", &cx);
	printf("��ѯ������£�\nѧ��\t����\t�Ա�\t���֤��\t\t����\t����\t����\t�༶\n");
	switch (j)
	{
	case 1: {
		for (k = 0; k < sum; k++) {
			//printf("\n%s\n%s\n",i,stu[k].num);
			if (strcmp(stu[k].num, cx) == 0) {
				n = SelectCase(p, k, n);
				break;
			}
		}
		if (SelectAlsole(n))
			goto input;
		break;
	}
	case 2: {
		for (k = 0; k < sum; k++) {
			//printf("\n%s\n%s\n",i,stu[k].num);
			if (strcmp(stu[k].name, cx) == 0) {
				n = SelectCase(p, k, n); break;
			}
		}
		if (SelectAlsole(n))
			goto input;
		break;
	}
	case 3: {
		for (k = 0; k < sum; k++) {
			//printf("\n%s\n%s\n",i,stu[k].num);
			if (strcmp(stu[k].sex, cx) == 0) {
				n = SelectCase(p, k, n);
			}
		}
		if (SelectAlsole(n))
			goto input;
		break;
	}
	case 4: {
		for (k = 0; k < sum; k++) {
			//printf("\n%s\n%s\n",i,stu[k].num);
			if (strcmp(stu[k].Id, cx) == 0) {
				n = SelectCase(p, k, n);
			}
		}
		if (SelectAlsole(n))
			goto input;
		break;
	}
	case 5: {
		for (k = 0; k < sum; k++) {
			//printf("\n%s\n%s\n",i,stu[k].num);
			if (strcmp(stu[k].pass, cx) == 0) {
				n = SelectCase(p, k, n);
			}
		}
		if (SelectAlsole(n))
			goto input;
		break;
	}
	case 6: {
		for (k = 0; k < sum; k++) {
			//printf("\n%s\n%s\n",i,stu[k].num);
			if (strcmp(stu[k].isbd, cx) == 0) {
				n = SelectCase(p, k, n);
			}
		}
		if (SelectAlsole(n))
			goto input;
		break;
	}
	case 7: {
		for (k = 0; k < sum; k++) {
			//printf("\n%s\n%s\n",i,stu[k].num);
			if (strcmp(stu[k].dormitory, cx) == 0) {
				n = SelectCase(p, k, n);
			}
		}
		if (SelectAlsole(n))
			goto input;
		break;
	}
	case 8: {
		for (k = 0; k < sum; k++) {
			//printf("\n%s\n%s\n",i,stu[k].num);
			if (strcmp(stu[k].cad, cx) == 0) {
				n = SelectCase(p, k, n);
			}
		}
		if (SelectAlsole(n))
			goto input;
		break;
	}
	}
}
//T4.ɾ��ѧ����Ϣ
void Delete(struct student stu[N]) {
	FILE *fp;
	char sc[10];
	int k, n, j;
input:printf("������Ҫɾ����ѧ��ѧ�ţ�"); \
	scanf("%s", &sc);
	  for (k = 0; k < sum; k++) {
		  //printf("\n%s\n%s\n",i,stu[k].num);
		  if (strcmp(stu[k].num, sc) == 0) {
			  printf("��ѧ����Ϣ���£�\nѧ��\t����\t�Ա�\t���֤��\t\t����\t����\t����\t�༶\n");
			  printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
				  stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory, stu[k].cad);
			  break;
		  }
	  }
	  if (k == sum) {
		  printf("û�и�ѧ�ţ����������룡\n");
		  goto input;
	  }
	  printf("�Ƿ�ɾ����ѧ����Ϣ(1.��|2.��)��");
	  scanf("%d", &n);
	  if (n == 1)
	  {
		  for (k; k < sum; k++) {
			  strcpy(stu[k].num, stu[k + 1].num);
			  strcpy(stu[k].name, stu[k + 1].name);
			  strcpy(stu[k].sex, stu[k + 1].sex);
			  strcpy(stu[k].Id, stu[k + 1].Id);
			  strcpy(stu[k].pass, stu[k + 1].pass);
			  strcpy(stu[k].isbd, stu[k + 1].isbd);
			  strcpy(stu[k].dormitory, stu[k + 1].dormitory);
			  strcpy(stu[k].cad, stu[k + 1].cad);
		  }
		  if ((fp = fopen("student.txt", "w")) == NULL)
		  {
			  printf("�ļ���ʧ��!");
			  exit(1);
		  }
		  j = 0;
		  sum = sum - 1;
		  while (j < sum) {
			  fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
				  stu[j].num, stu[j].name, stu[j].sex, stu[j].Id, stu[j].pass, stu[j].isbd, stu[j].dormitory, stu[j].cad);
			  j++;
		  }
		  fclose(fp);
		  printf("ɾ���ɹ�,�����⽡���أ�");
		  getch();

	  }
	  else if (n == 2) {
		  printf("�����⽡���أ�");
		  getch();
	  }
	  else {
		  printf("��������������������룡");
		  goto input;
	  }
}
//T5.��������
void All(struct student stu[N]) {
	int k;
	printf("����%d��ѧ����Ϣ���£�\nѧ��\t����\t�Ա�\t���֤��\t\t����\t����\t����\t�༶\n", sum);
	for (k = 0; k < sum; k++) {
		printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
			stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory, stu[k].cad);
	}
	printf("����������أ�");
	getch();
}

//S1. �鿴״̬��ע�ᱨ��
void Register(struct student stu[N]) {
	int i, k;
	FILE *fp;
	printf("ע�ᱨ������:\nѲ��¥ע��ɷ�->����¥��ȡԿ��->ʳ�ð�����->ͼ��ݰ������֤->ע�ᱨ���ɹ�\n");
	printf("��ı���״̬�ǣ�");
	if (strcmp(stu[Sid].isbd, "��") == 0) {
		printf("�ѱ���\n");
		printf("�����⽡���أ�");
		getch();
	}
	else {
		printf("δ����\n");
		printf("��ȷ����������̲���ע�ᱨ����1.��|2.�񣩣�");
		scanf("%d", &i);
		if (i == 1) {
			strcpy(stu[Sid].isbd, "��");
			if ((fp = fopen("student.txt", "w")) == NULL)
			{
				printf("�ļ���ʧ��!");
				exit(1);
			}
			k = 0;
			while (k < sum) {
				fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
					stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory, stu[k].cad);
				k++;
			}
			fclose(fp);
			printf("ע��ɹ����������������ҳ�棡\n");
			getch();
		}
	}
}
//S2. �鿴���޸ĸ�����Ϣ
void LookUpdatePersonal(struct student stu[N]) {
	FILE *fp;
	char i[10];
	int j = 0, k, n = 5, m;
	printf("��ĸ�����Ϣ���£�\nѧ��\t����\t�Ա�\t���֤��\t\t����\t����\t����\t�༶\n");
	printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
		stu[Sid].num, stu[Sid].name, stu[Sid].sex, stu[Sid].Id, stu[Sid].pass, stu[Sid].isbd, stu[Sid].dormitory, stu[Sid].cad);
	printf("������Ҫ�޸ĵĸ�����1-4,����0���أ�:");
	scanf("%d", &n);
	if (n == 0)
		goto input;
	m = 0;
	while (m < n) {
		printf("��ѡ��Ҫ�޸ĵĵ�%d�����ݣ�1.�Ա�|2.��֤��|3.����|4.��������", m + 1);
		scanf("%d", &j);
		printf("�������޸ĵ����ݣ�");
		switch (j)
		{
		case 1: scanf("%s", stu[Sid].sex); break;
		case 2: scanf("%s", stu[Sid].Id); break;
		case 3: scanf("%s", stu[Sid].pass); break;
		case 4: scanf("%s", stu[Sid].isbd); break;
		}
		m++;
	}
	if ((fp = fopen("student.txt", "w")) == NULL)
	{
		printf("�ļ���ʧ��!");
		exit(1);
	}
	k = 0;
	while (k < sum) {
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
			stu[k].num, stu[k].name, stu[k].sex, stu[k].Id, stu[k].pass, stu[k].isbd, stu[k].dormitory, stu[k].cad);
		k++;
	}
	fclose(fp);
	printf("�޸ĳɹ�!");
input:printf("�������������ҳ�棡\n");
	getch();
}
//S3. �鿴����Ͱ༶���
void DormitoryCnd(struct student stu[N]) {
	char cx[20];
	int j = 0, k, n = 0;
	printf("��ѡ��Ҫ��ѯ�����ݣ�1.����|2.�༶|3.���أ���");
	scanf("%d", &j);
	if (j == 1)
	{
		printf("��ѯ������£�\nѧ��\t����\t����\t����\t�༶\n");
		for (k = 0; k < sum; k++) {
			if (strcmp(stu[Sid].dormitory, stu[k].dormitory) == 0) {
				n++;
				printf("%s\t%s\t%s\t%s\t%s\n",
					stu[k].num, stu[k].name, stu[k].isbd, stu[k].dormitory, stu[k].cad);
			}
		}
		printf("�ɹ���ѯ��%d��ѧ����Ϣ���������������ҳ�棡\n", n);
		getch();
	}
	else if (j == 2) {
		printf("��ѯ������£�\nѧ��\t�Ա�\t����\t����\t����\t�༶\n");
		for (k = 0; k < sum; k++) {
			if (strcmp(stu[Sid].cad, stu[k].cad) == 0) {
				n++;
				printf("%s\t%s\t%s\t%s\t%s\t%s\n",
					stu[k].num, stu[k].name, stu[k].sex, stu[k].isbd, stu[k].dormitory, stu[k].cad);
			}
		}
		printf("�ɹ���ѯ��%d��ѧ����Ϣ���������������ҳ�棡\n", n);
		getch();
	}
	else
		;
}
//������¼��ˡ���ҳ 
void Student(struct student stu[N]) {
	int i, n = 0;
	struct student *p;
	p = stu;
input:printf("������ѧ�ţ�");
	char num[10];
	scanf("%s", &num);
	//gets(num);
	printf("���������룺");
	char pass[10];
	scanf("%s", &pass);
	//gets(passgl);
	for (i = 0; i < sum; i++)
	{
		//printf("%d\n%s\t%s\n%s\t%s\n",i,num,pass,stu[i].num,stu[i].pass);
		if (strcmp(stu[i].num, num) == 0 && strcmp(stu[i].pass, pass) == 0) {
			Sid = i;
			break;
		}
	}
	if (i == sum) {
		printf("������������������룡\n");
		goto input;
	}
	while (n < 4)
	{
		system("cls");
		printf("\t\t\t��������������������������������������������������������������������\n");
		printf("\t\t\t��             ѧ��               ��\n");
		printf("\t\t\t��������������������������������������������������������������������\n");
		printf("\t\t\t��      1. �鿴״̬��ע�ᱨ��     ��\n");
		printf("\t\t\t��      2. �鿴���޸ĸ�����Ϣ     ��\n");
		printf("\t\t\t��      3. �鿴����Ͱ༶���     ��\n");
		printf("\t\t\t��      0. �˳�                   ��\n");
		printf("\t\t\t��                                ��\n");
		if (Sid != (-1)) {
			printf("\t\t\t��         ��ӭ%s��¼��         ��\n", stu[Sid].name);
		}
		printf("\t\t\t��������������������������������������������������������������������\n\n");
		printf("��ѡ��0-3����");
		scanf("%d", &n);
		switch (n)
		{
		case 1: Register(p); break;
		case 2: LookUpdatePersonal(p); break;
		case 3: DormitoryCnd(p); break;
			//case 0:exit(1);
		case 0: n = 4; break;
		}
	}
}
