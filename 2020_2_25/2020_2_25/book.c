#define _CRT_SECURE_NO_WARNINGS 1

struct library//ͼ��ݽṹ��
{
	int xcl;//���

	float price;//����

	char name[20], author[20], chuban[20], kind[20], shuhao[20];

	struct library *next;

};

struct reader//���߽ṹ��
{

	int zhenghao;

	char mingzi[20], riqi[20], zname[20];

	struct reader *next;

};

void mainmenu()//���˵�

{
	system("cls");

	printf("**************************************************");

	printf("\n\n 1.ͼ����Ϣ\n\n");

	printf("\n\n 2.����ϵͳ\n\n");

	printf("\n\n 3.�˳�ϵͳ\n\n");

	printf("\n\n �밴��ѡ�񣬻س�ȷ��\n");

	printf("*************************************************\n");

	return;

}

void menu1() //��ʾͼ�����Ϣ�˵�

{
	system("cls");

	printf("****************************************************");

	printf("\n 1.����ͼ��\n\n");

	printf("\n 2.ɾ��ͼ��\n\n");

	printf("\n 3.ͼ���ѯ\n\n");

	printf("\n 4.������\n\n");

	printf("\n 5.������һ��\n\n");

	printf("\n �밴��ѡ�񣬻س�ȷ��\n");

	printf("***************************************************\n");

	return;

}

void menu2() //��ʾ��ѯ�˵�

{
	system("cls");

	printf("���������,����,���߻�����ѯ��\n");

	printf("��𣨿�ѧ���� ������ѧ ���ξ��� ��ʷ���� ��ʶ��̬ ������\n\n");

	return;

}

void main1()//main1����

{
	void tsgxx();//����

	void jieshuxitong();//����

	char choose;

	mainmenu();

	scanf("%c", &choose);

	switch (choose)//���ܺ���ѡ��

	{
	case '1':

		tsgxx();

		break;

	case '2':

		jieshuxitong();

		break;

	case '3':

		system("cls");

		getch();

		exit(0);

		system("cls");

		break;

	}
}

void tsgxx()//ͼ�����Ϣ����

{
	void tsjinku();

	void shanchu();

	void chaxunts();

	void xianshikucun();//��������

	char choose;

	menu1();

	scanf("%c", &choose);

	scanf("%c", &choose);

	for (;;)

		switch (choose)

		{
		case '1':

			tsjinku();

			break;

		case '2':

			shanchu();

			break;

		case '3':

			chaxunts();

			break;

		case '4':

			xianshikucun();

			break;

		case '5':

			main1();

			break;

		}
}

int tjzs()//ͳ���ı���������

{
	FILE *fp;

	int txcl = 0, n;

	float tprice = 0;

	char tname[20] = { '\0' }, tauthor[20] = { '\0' }, tchuban[20] = { '\0' }, tkind[20] = { '\0' }, tshuhao[20] = { '\0' };

	fp = fopen("library.txt", "r");//���ļ�

	for (n = 0; !feof(fp); n++)//������ļ�

		fscanf(fp, "%s%s%s%s%s%d%f", tshuhao, tname, tauthor, tchuban, tkind, &txcl, &tprice);

	n--;

	fclose(fp);//�ر��ļ�

	return (n);//���ظ���

}
int tjdzzs()//ͳ���ı���������

{
	FILE *fp;

	int zhenghao = 0, n;

	char mingzi[20] = { '\0' }, riqi[20] = { '\0' }, zname[20] = { '\0' };

	fp = fopen("reader.txt", "r");//���ļ�

	for (n = 0; !feof(fp); n++)//������ļ�

		fscanf(fp, "%d%s%s%s ", &zhenghao, &mingzi, &riqi, &zname);

	fclose(fp);//�ر��ļ�

	return (n);//���ظ���

}

void tsjinku()//ͼ����⺯��

{
	FILE *fp;

	int xcl = 0, n = 0;

	float price = 0;

	char name[20] = { '\0' }, author[20] = { '\0' }, kind[20] = { '\0' }, chuban[20] = { '\0' }, shuhao[20] = { '\0' };

	char hitkey;

	system("cls");

	if ((fp = fopen("library.txt", "r")) == NULL)//��ͼ����ļ��������ڴ��ļ����½�

	{
		fp = fopen("library.txt", "w");

		fclose(fp);

	}

	fp = fopen("library.txt", "a");

	printf("\n�밴���¸�ʽ����ͼ����Ϣ:\n��� ���� ���� ������ ��� ������ ����");

	printf("\n����𣨿�ѧ���� ������ѧ ���ξ��� ��ʷ���� ��ʶ��̬ ��������\n");

	for (; hitkey != 27;)//ѭ������

	{
		if (n != 0)

			printf("������:");

		scanf("%s%s%s%s%s%d%f", shuhao, name, author, chuban, kind, &xcl, &price);

		fprintf(fp, "%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n", shuhao, name, author, chuban, kind, xcl, price);

		printf("���������밴�س������������밴Esc\n");

		n++;

		hitkey = getch();

		for (; hitkey != 13 && hitkey != 27;)

			hitkey = getch();

	}

	fclose(fp);

	printf("\n����ɹ����������������һ��!");

	getch();

	tsgxx();//������һ��

}

void shanchu()//ɾ��ͼ����Ϣ

{
	struct library *head = NULL;

	struct library *p, *p1, *p2;

	int txcl = 0, n = 0, j, i;

	float tprice = 0;

	char tname[20] = { '\0' }, tauthor[20] = { '\0' }, tchuban[20] = { '\0' }, tkind[20] = { '\0' }, ttname[20] = { '\0' }, tshuhao[20] = { '\0' };

	char hitkey;

	FILE *fp;

	if ((fp = fopen("library.txt", "r")) == NULL)//���ļ�

	{
		system("cls");

		printf("\n��¼�ļ�������!�����������");

		getch();

		tsgxx();

	}

	else

	{
		system("cls");

		printf("\n��������Ҫɾ��������:");//����ɾ��ͼ������

		scanf("%s", &ttname);

		printf("\nȷ��ɾ����س���ȡ���밴Esc\n");

		hitkey = getch();

		for (; hitkey != 13 && hitkey != 27;)

			hitkey = getch();

		if (hitkey == 27)

			tsgxx();

		fp = fopen("library.txt", "r");

		for (j = 0; !feof(fp);)//���ļ�����Ϣ��ͳ�Ƹ���

		{
			j++;

			fscanf(fp, "%s%s%s%s%s%d%f", tshuhao, tname, tauthor, tchuban, tkind, &txcl, &tprice);
		}

		fclose(fp);

		fp = fopen("library.txt", "r");

		for (i = 1; i < j; i++)

		{
			fscanf(fp, "%s%s%s%s%s%d%f", tshuhao, tname, tauthor, tchuban, tkind, &txcl, &tprice);

			if (strcmp(ttname, tname))//�Ƚ����֣�����ͬ���ֵ���Ϣ���Ƶ�����

			{
				n++;

				if (n == 1)//��������

				{
					p1 = p2 = (struct library*)malloc(LEN);

					head = p1;
				}

				else

				{
					p2->next = p1;

					p2 = p1;

					p1 = (struct library*)malloc(LEN);//�½�����

				}

				strcpy(p1->shuhao, tshuhao);//�������

				strcpy(p1->name, tname);//��������

				strcpy(p1->author, tauthor);//������������

				strcpy(p1->chuban, tchuban);//���Ƴ�����

				strcpy(p1->kind, tkind);//�������

				p1->xcl = txcl;//���Ƹ���

				p1->price = tprice;//���Ƶ���

			}
		}

		if (n == 0)

		{
			head = NULL;
		}

		else

		{

			p2->next = p1;

			p1->next = NULL;

			fclose(fp);

		}
	}

	fp = fopen("library.txt", "w");//����ļ�

	fclose(fp);

	fp = fopen("library.txt", "a");//׷���ļ�

	p = head;

	for (; p != NULL;)//���������ݸ��ǵ��ļ�

	{

		fprintf(fp, "%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n", p->shuhao, p->name, p->author, p->chuban, p->kind, p->xcl, p->price);

		p = p->next;

	}

	fclose(fp);//�ر��ļ�

	system("cls");

	printf("\nɾ���ɹ� \n�������������һ��\n");

	getch();//������һ��

	tsgxx();

}
void chaxunts()//��ѯ����

{

	FILE *fp;

	char choose;

	int txcl = 0, n = 0, k = 0, i, l;

	float tprice = 0;

	char tname[20] = { '\0' }, tauthor[20] = { '\0' }, chazhao[20] = { '\0' }, tchuban[20] = { '\0' },

		tshuhao[20] = { '\0' }, tkind[20] = { '\0' };

	if ((fp = fopen("library.txt", "r")) == NULL)//���ļ�

	{
		system("cls");

		printf("\n��¼�ļ�������!�����������");

		getch();

		tsgxx();

	}

	l = tjzs();//����ļ�����

	menu2();//���ò˵�����

	scanf("%s", chazhao);

	system("cls");

	for (i = 0; i < l; i++)

	{
		fscanf(fp, "%s%s%s%s%s%d%f", tshuhao, tname, tauthor, tchuban, tkind, &txcl, &tprice);//���ļ���Ϣ

		if (!strcmp(chazhao, tshuhao) || !strcmp(chazhao, tname) || !strcmp(chazhao, tauthor) || !strcmp(chazhao, tkind))//�����ѯ��Ϣ

		{
			if (k == 0)

			{

				printf("��ѯ���:\n\n");

				printf("���\t����\t����\t\t������\t\t���\t\t�ִ���\t����\n");

			}

			printf("%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n", tshuhao, tname, tauthor, tchuban, tkind, txcl, tprice);

			k++;

		}
	}

	if (k == 0)//�ļ���Ϊ��������޼�¼

	{
		system("cls");

		printf("\n�޷��ϼ�¼!\n");

		getch();

		tsgxx();

	}

	fclose(fp);

	getch();//����

	tsgxx();

}

void xianshikucun()//��ʵ�����Ϣ

{

	FILE *fp;

	int xcl = 0, n = 0, i = 0, j = 0;

	float price = 0;

	char name[20] = { '\0' }, author[20] = { '\0' }, kind[20] = { '\0' }, chuban[20] = { '\0' }, shuhao[20] = { '\0' };

	if ((fp = fopen("library.txt", "r")) == NULL)//���ļ���

	{

		system("cls");

		printf("\n��¼�ļ�������!");

	}

	n = tjzs();

	if (n == 0)

	{
		system("cls");

		printf("\n���κμ�¼!");

	}

	fp = fopen("library.txt", "r");//��ֻ���ļ�

	system("cls");

	printf("���\t����\t����\t\t������\t\t���\t\t�����\t����\n");

	for (i = 0; i < n; i++)//�����Ϣ

	{

		fscanf(fp, "%s%s%s%s%s%d%f", shuhao, name, author, chuban, kind, &xcl, &price);

		printf("%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n", shuhao, name, author, chuban, kind, xcl, price);

	}

	fclose(fp);

	printf("\n�����������\n");

	getch();//����

	tsgxx();

}