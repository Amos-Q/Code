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