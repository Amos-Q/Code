#define _CRT_SECURE_NO_WARNINGS 1
#include "home.h"

void display()//��ʾ������Ϣ
{
	int a = 0;
	struct person *p;
	printf("ID   name   sex     position     place    score         email     telephone\n");
	for (p = player; p < player + 24; p++)
	{
		a = 1;
		printf("%d   %s  %s     %s    %s    %.1f        %s      %ld  \n", p->ID, p->name, p->sex, p->position, p->place, p->score, p->email, p->telephone);
	}
	if (a == 1)
	{
		printf("�������˵�\n");
		system("pause");//ҳ��ͣ��
		system("cls");
		menu();

	}
}
void find()
{
	struct person *p;
	int num, loop;
	printf("\n�������ţ�\n");
	scanf("%d", &num);
	for (p = player; p < player + 24; p++)
	{
		if (p->ID == num)
		{
			loop = 1;
			printf("ID   name   sex     position     place    score    email    telephone");
			printf("\n%d   %s   %s   %s   %s   %f   %s   %ld  \n\n", p->ID, p->name, p->sex, p->position, p->place, p->score, p->email, p->telephone);
			printf("�������˵�\n");
			system("pause\n");
			menu(); break;

		}

	}
	if (loop == 0)
	{
		system("cls");
		printf("�޴���Ա��Ϣ\n");
	}
	printf("�޴���Ա��Ϣ,������ѡ����");
	find();

}
void change()
{
	system("cls");

	int b, c, num;
	struct person *p;
	int loop = 0;
	printf("\n��������Ҫ�޸ĵ���Ա��ţ�\n");
	scanf("%d", &num);
	for (p = player; p < player + 24; p++)
	{
		if (p->ID == num)
		{
			do
			{
				puts("\n\n1.ID   2.name   3.sex    4.position    5.place    6.score    7.email    8.telephone   9.������Ϣ   10.ȡ��������\n");
				printf("��ѡ��Ҫ�޸ĵ���Ϣ����: [  ]\b\b\b");
				scanf("%d", &c);
				if (c > 10 || c < 1)
				{
					system("cls");
					puts("\nѡ�����!������ѡ��!\n");
					getchar();
				}
			} while (c > 10 || c < 1); break;
		}
		else
		{
			if (p == p + 24)
				printf("�޴���Ա��������ѡ��\n");
		}
	}

	do
	{
		switch (c)
		{
		case 1: printf("ID:"); scanf("%d", &p->ID); break;
		case 2: printf("name:"); scanf("%s", p->name); break;
		case 3: printf("sex:"); scanf("%s", p->sex); break;
		case 4: printf("position:"); scanf("%s", p->position); break;
		case 5: printf("place:"); scanf("%s", p->place); break;
		case 6: printf("score:"); scanf("%f", &p->score); break;
		case 7: printf("email:"); scanf("%s", p->email); break;
		case 8: printf("telephone:"); scanf("%ld", &p->telephone); break;
		case 9: change1(); break;
		case 10: menu();
		}
		save();//�޸��걣��
		puts("\n�޸ĺ����Ϣ��\n");
		printf("ID   name   sex     position     place    score    email    telephone\n");
		printf("%d   %s   %s   %s   %s   %f   %s   %ld  \n", p->ID, p->name, p->sex, p->position, p->place, p->score, p->email, p->telephone);
		puts("�Ƿ�����޸� ��ѡ��\n1/��ɲ��˳�  2/�����޸� 3/�޸�������Ա��Ϣ");
		printf("    [  ]\b\b");
		scanf("%d", &b);
	} while (b == 2);
	if (b == 1)
		menu();
	if (b == 3)
		change();


}
void change1()
{
	struct person *p;
	int num, loop = 0;
	printf("\n���ٴ������ţ�\n");
	scanf("%d", &num);
	for (p = player; p < player + 24; p++)
	{
		if (p->ID == num)
		{
			loop = 1;
			printf("���������Ա������Ϣ���������� ID   name   sex     position     place    score    email    telephone\n");
			scanf("%d%s%s%s%s%f%s%ld\n", &p->ID, p->name, p->sex, p->position, p->place, &p->score, p->email, &p->telephone);
			break;//��bug
		}
	}
	if (loop)
	{
		printf("\n�޸ĳɹ�����\n");
		printf("�������˵�");
		system("pause");
		menu();

	}
	else
	{
		system("cls");
		printf("\n�����ڸ���Ա����\n");
		printf("\n");
		change();
	}

}
void sort()//����
{
	struct person p;//����ṹ����������м����
	int j, k;
	int i;
	for (i = 0; i < 24; i++)
	{
		k = i;
		for (j = i + 1; j < 24; j++)
			if (player[j].score > player[k].score)
			{
				k = j;
				p = player[k]; player[k] = player[i]; player[i] = p;
			}
	}
	display();
	printf("�������˵�\n");


}
void max()//�ҳ��÷����
{
	int i, m = 0;
	for (i = 0; i < 24; i++)
	{
		if (player[i].score > player[m].score)
			m = i;
	}
	printf("�����������Ա�ǣ�%s\n\n", player[m].name);
	printf("�������˵�\n");
	system("pause");//ҳ��ͣ��
	menu();
}
int load() /*���ļ�,��ȡ��������ݣ���д��*/
{
	struct person *p;
	p = player;
	FILE *fp;
	int i;
	if ((fp = fopen("file.txt", "rb")) == NULL) /*������ļ���rb��ʾ��һ���������ļ���ֻ���������*/
	{
		printf("\n�ļ�������!\n");
		return 0;
	}
	for (i = 0; !feof(fp); i++)  /*�����ļ���β*/
		for (p = player; p < player + 24; p++)
			fscanf(fp, "%d\t%s\t%s\t%s\t%s\t%f\t%s\t%ld\n", &p->ID, p->name, p->sex, p->position, p->place, &p->score, p->email, &p->telephone);
	fclose(fp);
	return 0;
}
void save() /*����ѧ����Ϣ*/
{
	struct person *p;
	p = player;
	//void exit();
	FILE *fp;
	int i;
	if ((fp = fopen("file.txt", "wb")) == NULL)/*ֻ�򿪻���һ���������ļ���ֻ����д����*/
	{
		printf("\n�ļ�������!\n");
	}
	for (i = 0; i < 24; i++)
		if (player[i].name[0] != '\0')
			if (fprintf(fp, "%d\t%s\t%s\t%s\t%s\t%f\t%s\t%ld\n", p[i].ID, p[i].name, p[i].sex, p[i].position, p[i].place, p[i].score, p[i].email, p[i].telephone) == 1)/*��һ��������Ϊһ������һ����д������ļ�*/
				printf("�ļ�д�����!\n");
	fclose(fp);
}
void face()/*������ʼҳ��*/
{
	system("color 4e");
	printf("\n\t                         �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n\n");
	puts("\n");
	puts("\t                              ��                                       ��");
	puts("\t                              ��                                       ��");
	puts("\t                              ��       ��ӭ������ӹ���ϵͳ!           ��");
	puts("\t                              ��                                       ��");
	puts("\t                              ��                                       ��");
	puts("\t                              ��                �����ˣ��ྩ��ѧԺ�ߺ��         ��");
	puts("\t                              ��                        2019.6.20      �� ");
	puts("\n ");
	printf("\n\t                              �밴�س�����������\n");

	getchar();
	system("cls");
}
void tail()
{
	printf("\n\t                         �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n\n");
	puts("\n");
	puts("\t                             ��                                               ��");
	puts("\t                             ��                                               ��");
	puts("\t                             ��       ��л������ӹ���ϵͳ!��ӭ�´�����!      ��");
	puts("\t                             ��                                               ��");
	puts("\t                             ��                                               ��");
	puts("\t                             ��                  �����ˣ��ྩ��ѧԺ�ߺ��            ��");
	puts("\t                             ��                          2019.6.20            �� ");
	puts("\n ");

}
void menu()/*���˵�*/
{
	int choice;
	int n;
	do
	{
		system("cls");
		printf("\n");
		printf("                                          ---����������Ա��Ϣ����ϵͳ---\n");
		puts("\n");
		printf("                                             1/����Ų�ѯ��Ա��Ϣ\n");
		puts("\n");
		printf("                                             2/  �޸���Ա��Ϣ\n");
		puts("\n");
		printf("                                             3/���ձ������ɼ�����\n");
		puts("\n");
		printf("                                             4/ �����������Ա\n");
		puts("\n");
		printf("                                             5/  ��ʾ������Ϣ\n");
		puts("\n");
		printf("                                             6/     �˳�\n");
		puts("\n");
		printf("                                          ��ѡ���������(1-6) : [ ]\b\b");
		scanf("%d", &n);
		if (n < 1 || n>6)
		{
			system("cls");
			printf("ѡ�����!  ������ѡ��!\n");
			system("pause");
			choice = 1;
		}
		else
		{
			break;
		}
	} while (choice == 1);
	switch (n)
	{
	case 1:system("cls"); system("cls"); find(); break;//����find�����Զ���Ա���в���
	case 2:system("cls"); change(); break;//����change�����Զ���Ա��Ϣ�����޸�
	case 3:system("cls"); sort(); break;//����sort�����Զ���Ա���а��ɼ��������
	case 4:system("cls"); max(); break;//����max���������ȫ�������Ա
	case 5:system("cls"); display(); break;//����display���������ȫ����Ϣ
	case 6:system("cls"); tail(); break;//����tail������չ��ĩβҳ��
	}
}