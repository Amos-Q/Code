#define _CRT_SECURE_NO_WARNINGS 1
#include"home.h"

void login()//��¼ 
{
	//�û��������붼�ǣ�123456 
	char userName[15];
	char password[15];
	int i;

	for (i = 1; i <= 3; i++)
	{
		printf("�������û���������\n");
		printf("�û�����");
		gets(userName);
		printf("���룺");
		gets(password);
		if ((strcmp(userName, "123456") == 0) && (strcmp(password, "123456") == 0))
		{
			printf("--��ʾ���˵�--");
			return;
		}
		else
		{
			if (i < 3)
			{
				printf("�û���������������������룬������%d�λ���", 3 - i);
			}
			else
			{
				printf("���󳬹����Σ��Զ��˳�");
				exit(0);
			}
		}
	}
}

void menu()    //�˵�
{
	do
	{
		system("cls");  //����
		char t;
		printf("         ͼ�����Ա��ѯϵͳ\n\n");  //6���ո�ǰ�� �������ÿ�һ�� *_* 
		printf("       | |    1.����ͼ��     | |\n");
		printf("       | |    2.�޸���Ϣ     | |\n");
		printf("       | |    3.ɾ����Ϣ     | |\n");
		printf("       | |    4.ͼ���ѯ     | |\n");
		printf("       | |    5.ͼ������     | |\n");
		printf("       | |    6.�˳����     | |\n");
		printf("       ������Ҫ���еĲ�����");
		t = getchar();
		switch (t)
		{
		case '1':inputBook();
			break;
		case '2':amendBook();
			break;
		case '3':deleteBook();
			break;
		case '4':findBook();
			break;
		case '5':printBook();
			break;
		case '6':over();
			break;
		default:break;
		}
	} while (1);
}

struct BOOK *readIn()//���ļ��е����ݶ����������У�����ֵΪ��ͷ��ַ 
{
	FILE *fp;       //�ļ�ָ��
	int n = 0;
	struct BOOK *head = NULL;
	struct BOOK *p, *p2, *pr = NULL;
	fp = fopen("books", "ab+");     //��ֻ���ķ�ʽ���ļ�
	if (fp == NULL)
	{
		printf("cannot open the file\n");
	}

	while (!feof(fp))        //�ж��ļ�λ�ñ�־�Ƿ��ƶ����ļ�ĩβ���Ƿ������,�ǵĻ�Ϊ1����Ļ�Ϊ0   ����341ҳ�о������ 
	{
		n++;
		p = (struct BOOK *)malloc(N); //���ڴ�����һ�οռ�   
		fread(p, N, 1, fp);     //��fp��ָ����ļ��е����ݸ���p   
		if (n == 1)
		{
			head = p;
			p2 = p;
		}
		else             //��������  �α�316 
		{
			pr = p2;
			p2->next = p;
			p2 = p;
		}
	}

	if (pr != NULL)
	{
		pr->next = NULL;  //���ݶ���������
	}
	else
	{
		head = NULL;  //û�ж���ȥ 
	}

	fclose(fp);    //�ر��ļ�   
	return head;   //����ͷָ��
}

void inputBook()    //����ͼ��  
{
	do
	{
		system("cls");
		char t;
		struct BOOK *p;
		p = (struct BOOK *)malloc(N);     //����ռ�   
		//����ͼ����Ϣ  
		printf("������������");
		scanf("%s", p->name);
		getchar();//���ڽ��ջس���  
		printf("��������������");
		scanf("%s", p->author);
		getchar();
		printf("������ͼ�����ͣ�");
		scanf("%s", p->type);
		getchar();
		printf("������ͼ��۸�");
		scanf("%f", &p->price);
		getchar();
		printf("������ͼ��������");
		scanf("%d", &p->num);
		getchar();

		saveBook(p);	//ͨ��saveBook��������������ͼ�� 
		system("cls");
		printf("      ---------------------------\n");
		printf("      ||(�� ��-��- )�{��ߩרT-||\n");
		printf("      ||                       ||\n");
		printf("      || ����ɹ����Ƿ������  ||\n");
		printf("      ||                       ||\n");
		printf("      || 1.��             2.�� ||\n");
		printf("      ||         ���أ�        ||\n");
		printf("      ---------------------------\n");
		printf("	    ָ�");
		while (1)    //������ѭ����ֹ������������   
		{
			t = getchar();
			if (t == '1')
			{
				break;
			}
			else if (t == '2')
			{
				menu();
			}
		}
	} while (1);
}

void saveBook(struct BOOK *p)//��ͼ����Ϣ�����ļ�
{
	//���̣����ļ�-> д��->�ر� 
	FILE *fp;    //�ļ�ָ��   
	fp = fopen("books", "ab");   //��׷�ӵķ�ʽ������Ϊbooks�Ķ������ļ�   
	if (fp == NULL)
	{
		printf("cannot open the file (�p���ը�)");
	}
	if (fwrite(p, N, 1, fp) != 1)   //��p��ָ���һ�δ�СΪN������  д��  p��ָ����ļ���  345ҳ����buffer 
	{
		printf("write error");
	}
	fclose(fp);    //�ر��ļ�
}

void amendBook()//�޸�ͼ����Ϣ 
{
	//���裺��������-> �����޸����� ->�ҵ������������ ->�޸� 
	do {
		system("cls");
		struct BOOK *head, *p;
		int j = 0, x, t;
		char ch;
		FILE *fp;  //�ļ�ָ��
		char _name[20];  //Ҫ�ĵ����� 
		char name[20];   //����
		char author[20]; //������   
		char type[10];   //����   
		float price;     //�۸�   
		int num;         //���� 

		head = readIn();  //�������� 
		p = head;
		printf("��������Ҫ�޸ĵ�ͼ���������");
		scanf("%s", _name);
		while (p != NULL)//�������е�x��Ϊ0�� 
		{
			p->x = 0;
			p = p->next;
		}
		p = head;//����ʹpָ��head
		printf("***********************************ͼ����Ϣ***************************************\n");
		printf("----------------------------------------------------------------------------------\n");
		while (p != NULL)//����Ƚ������е����֣������λ�� 
		{
			if (p != NULL && strcmp(p->name, _name) == 0)
			{
				j++;
				printf("ͼ����:%d\n", j);
				printf("  	����:%s", p->name);
				printf("  	������:%s", p->author);
				printf("  	ͼ�����:%s", p->type);
				printf("  	�۸�:%f", p->price);
				printf("  	����:%d", p->num);
				printf("\n");
				p->x = j;//�ҵ�Ŀ�겢���
			}
			p = p->next;
		}

		//��������û���ҵ�ʱ�ĺ��� 
		if (j == 0)
		{
			printf("û���ҵ���Ϣ(�i.�i), ��0���أ���1��������");
			while (true)
			{
				ch = getchar();
				if (ch == '0')
				{
					menu();
					break;
				}
				if (ch == '1')
				{
					break;
				}
			}
			if (ch == '1')
			{
				continue;
			}
		}

		//�ҵ�����޸Ĳ���
		while (1)
		{
			printf("������Ҫ�޸ĵ�ͼ���ţ�");//�˴���x��ʾ
			scanf("%d", &x);
			if (x > j || x == 0)
			{
				printf("�������������������\n");
			}
			else
			{
				break;
			}
		}

		p = head;     //��p����ָ���ͷ   
		while (p != NULL && p->x != x)   //���������ѯ���������Ľ��   
		{
			p = p->next;
		}
		if (p)    //���p��Ϊ��   
		{
			system("cls");
			//����Ҫ�޸ĵ���Ϣ   
			printf("�������޸ĺ��������");
			scanf("%s", name);
			strcpy(p->name, name);
			printf("\n�������޸ĺ����������");
			scanf("%s", author);
			strcpy(p->author, author);
			printf("\n�������޸ĺ��ͼ�����");
			scanf("%s", type);
			strcpy(p->type, type);
			printf("\n�������޸ĺ��ͼ��۸�");
			scanf("%f", &price);
			p->price = price;
			printf("\n�������޸ĺ��ͼ��������");
			scanf("%d", &num);
			p->num = num;
		}
		printf("-------------------------");
		printf("\n|         ������        |");
		printf("\n|     �Ƿ�ȷ���޸ģ�    |");
		printf("\n| 1.��             2.�� |");
		printf("\n|                       |");
		printf("\n------------------------- ");
		printf("\n  ָ�");
		while (1)   //������ѭ����ֹ������������   
		{
			scanf("%d", &t);
			if (t == 1)
			{
				break;
			}
			if (t == 2)
			{
				menu();
			}
		}

		system("cls");
		printf("�����޸ģ����Ժ�....");

		//��ֻд�ķ�ʽ����Ϊbooks�Ķ������ļ����򿪵�ͬʱ����ļ��е�����
		fp = fopen("books", "wb");
		if (fp == NULL)
		{
			printf("cannot open file");
		}
		if (fwrite(head, N, 1, fp) != 1)   //��headд��fp��ָ����ļ���   
		{
			printf("write error!");
		}
		fclose(fp);   //�ر��ļ�  

		//��ͷ���������д�� 
		if (head != NULL)   //���head��Ϊ��   
		{
			p = head->next;   //��pָ��ڶ������ 
			fp = fopen("books", "ab");   //��׷�ӵķ�ʽ���ļ�
			if (fp == NULL)
			{
				printf("cannot open file");
			}
			while (p != NULL)
			{
				if (fwrite(p, N, 1, fp) != 1)//��pд��fp��ָ����ļ���  
				{
					printf("write error!");
				}
				p = p->next;
			}
			fclose(fp);  //�ر��ļ�   
		}

		printf(" \n(*_*)��");
		printf("\n�޸ĳɹ�����������������˵�...");
		getchar();
		getchar(); //�˴�Ҫ������getchar����Ȼ��֪��Ϊʲô 
		break;
	} while (true);
}

void deleteBook()//ɾ��ͼ����Ϣ ���裺�����ļ�-> �ҵ�Ҫɾ��������-> ɾ��->���� 
{
	do
	{
		system("cls");
		FILE *fp;
		struct BOOK *head, *p, *pre = NULL;
		int j = 0, x;
		char name[20];
		char t, c, ch;

		head = readIn();    //����

		printf("��������Ҫɾ����ͼ���������\n");
		scanf("%s", name);
		p = head;

		while (p != NULL)
		{
			p->x = 0;  //��xȫ��Ϊ0���� �޸���Ϣ   ���Ĳ���
			p = p->next;
		}

		p = head;
		printf("*************************ͼ����Ϣ*****************************\n");
		printf("--------------------------------------------------------------\n");

		while (p != NULL)
		{
			if (p != NULL && strcmp(p->name, name) == 0)
			{
				j++;
				printf("ͼ����:%d\n", j);
				printf("  	����:%s", p->name);
				printf("  	������:%s", p->author);
				printf("  	ͼ�����:%s", p->type);
				printf("  	�۸�:%f", p->price);
				printf("  	����:%d", p->num);
				printf("\n");
				p->x = j;
			}
			p = p->next;
		}

		if (j == 0)   //���j=0����û���ҵ���Ӧ��ͼ��
		{
			printf("û���ҵ���Ӧ����Ϣ��(��0���أ���1��������)\n");
			while (1)   //��ѭ����Ϊ�˷�ֹ��0��1��������������
			{
				ch = getchar();
				if (ch == '0')
				{
					menu();
					break;
				}
				else if (ch == '1')
				{
					break;
				}
			}
			if (ch == '1')     //��������ch����1�����������ѭ�� 
			{
				continue;
			}
		}

		while (1)
		{
			printf("��������Ҫɾ����ͼ��ı�ţ�\n");
			scanf("%d", &x);
			if (x > j || x == 0)
			{
				printf("�����������������!");
			}
			else
			{
				break;
			}
		}

		printf("-------------------------\n");
		printf("|       (��'��'��)      |\n");
		printf("|     �Ƿ�ȷ��ɾ����    |\n");
		printf("| 1.��             2.�� |\n");
		printf("|                       |\n");
		printf("-------------------------\n");
		while (1)
		{
			t = getchar();
			if (t == '1')
			{
				break;
			}
			else if (t == '2')
			{
				menu();
			}
		}

		//��������������ɾ��һ����Ϣ���أ�= 
		p = head;
		while (p != NULL && p->x != x)
		{
			pre = p;
			p = p->next;
		}

		if (p != NULL)
		{
			if (pre == NULL)
			{
				head = head->next;  //ɾ��ͷ�� ʱ 
			}
			else
			{
				pre->next = p->next;  //ɾ������ 
			}
		}
		free(p);  //��ָ��p�ͷŵ� ,���������ڴ�й© 

		fp = fopen("books", "wb");//��ֻд�ķ�ʽ����Ϊbooks�Ķ������ļ�
		if (fp == NULL)
		{
			printf("cannot open file");
		}
		if (fwrite(head, N, 1, fp) != 1)
		{
			printf("write error!");
		}
		fclose(fp);

		if (head != NULL)
		{
			p = head->next;
			fp = fopen("books", "ab");  //��׷�ӵķ�ʽ���ļ�
			if (fp == NULL)
			{
				printf("cannot open file");
			}
			while (p != NULL)
			{
				if (fwrite(p, N, 1, fp) != 1)
				{
					printf("write error!");
				}
				p = p->next;
			}
			fclose(fp);
		}

		system("cls");
		printf("����ɾ�������Ժ�....\n");
		printf("-------------------------\n");
		printf("|        .(*_*).        |\n");
		printf("|  ɾ���ɹ����Ƿ������ |\n");
		printf("| 1.��             2.�� |\n");
		printf("|                       |\n");
		printf("-------------------------\n");
		printf("  ָ�");

		while (1)
		{
			c = getchar();
			if (c == '1')
			{
				break;
			}
			else if (c == '2')
			{
				menu();
			}
		}
	} while (1);
}

void findBook()//�����ѯ 
{
	do
	{
		system("cls");
		char t;
		printf(" --------ͼ���ѯ--------\n");
		printf("*     1.����������ѯ      *\n");
		printf("*     2.�������߲�ѯ      *\n");
		printf("*     3.�������Ͳ�ѯ      *\n");
		printf("*     4.���ռ۸��ѯ      *\n");
		printf("��0�������˵�\nָ�");
		t = getchar();
		switch (t)
		{
		case '0':menu();
			break;
		case '1':find_name_book();//���ĸ�������ʵ��һ���ģ� (��'��'��)�����������ô��뿴�����Ƚϳ�@_@ 
			break;
		case '2':find_author_book();
			break;
		case '3':find_type_book();
			break;
		case '4':find_price_book();
			break;
		default:break;
		}
	} while (1);
}

void find_name_book()//����������ѯ
{
	system("cls");
	struct BOOK *head, *p;
	head = readIn();
	char name[20];
	printf("��������Ҫ��ѯͼ���������");
	scanf("%s", name);
	getchar();//���ջس��ַ��õ� 
	printf("\n���ڲ�ѯ....");
	p = head;
	printf("*************************ͼ����Ϣ*****************************\n");
	printf("--------------------------------------------------------------\n");

	while (p != NULL)
	{
		if (p != NULL && strcmp(p->name, name) == 0)
		{
			printf("����:%s", p->name);
			printf("  	������:%s", p->author);
			printf("  	ͼ�����:%s", p->type);
			printf("  	�۸�:%f", p->price);
			printf("  	����:%d", p->num);
			printf("\n");
		}
		p = p->next;
	}

	printf("����������أ�");
	getchar();
	findBook();
}

void find_author_book()//�������߲�ѯ
{
	system("cls");
	struct BOOK *head, *p;
	head = readIn();
	char author[20];
	printf("��������Ҫ��ѯͼ������ߣ�");
	scanf("%s", author);
	getchar();//���ջس��ַ��õ� 
	printf("\n���ڲ�ѯ....");
	p = head;
	printf("*************************ͼ����Ϣ*****************************\n");
	printf("--------------------------------------------------------------\n");

	while (p != NULL)
	{
		if (p != NULL && strcmp(p->author, author) == 0)
		{
			printf("����:%s", p->name);
			printf("  	������:%s", p->author);
			printf("  	ͼ�����:%s", p->type);
			printf("  	�۸�:%f", p->price);
			printf("  	����:%d", p->num);
			printf("\n");
		}
		p = p->next;
	}

	printf("����������أ�");
	getchar();
	findBook();
}

void find_type_book()//�������Ͳ�ѯ
{
	system("cls");
	struct BOOK *head, *p;
	head = readIn();
	char type[10];
	printf("��������Ҫ��ѯͼ������ͣ�");
	scanf("%s", type);
	getchar();//���ջس��ַ��õ� 
	printf("\n���ڲ�ѯ....");
	p = head;
	printf("*************************ͼ����Ϣ*****************************\n");
	printf("--------------------------------------------------------------\n");

	while (p != NULL)
	{
		if (p != NULL && strcmp(p->type, type) == 0)
		{
			printf("����:%s", p->name);
			printf("  	������:%s", p->author);
			printf("  	ͼ�����:%s", p->type);
			printf("  	�۸�:%f", p->price);
			printf("  	����:%d", p->num);
			printf("\n");
		}
		p = p->next;
	}

	printf("����������أ�");
	getchar();
	findBook();
}

void find_price_book()//����price��ѯ
{
	system("cls");
	struct BOOK *head, *p;
	head = readIn();
	float price;
	printf("��������Ҫ��ѯͼ���price��");
	scanf("%f", &price);
	getchar();//���ջس��ַ��õ� 
	printf("\n���ڲ�ѯ....");
	p = head;
	printf("*************************ͼ����Ϣ*****************************\n");
	printf("--------------------------------------------------------------\n");

	while (p != NULL)
	{
		if (p != NULL && (p->price == price))
		{
			printf("����:%s", p->name);
			printf("  	������:%s", p->author);
			printf("  	ͼ�����:%s", p->type);
			printf("  	�۸�:%f", p->price);
			printf("  	����:%d", p->num);
			printf("\n");
		}
		p = p->next;
	}

	printf("����������أ�");
	getchar();
	findBook();
}

void printBook()//ͼ������ 
{
	system("cls");
	struct BOOK *head, *p;
	int sum = 0;
	head = readIn();
	printf("*********************************************ͼ����Ϣ**********************************************\n");
	printf("---------------------------------------------------------------------------------------------------\n");
	if (head == NULL)
	{
		printf("�����ʱû����Ŷ~�Ͽ�ȥ��Ӽ�����(��.��)(�����������)");
		getchar();
		menu();
	}
	p = head;
	while (p != NULL)
	{
		printf("����:%s", p->name);
		printf("  	������:%s", p->author);
		printf("  	ͼ�����:%s", p->type);
		printf("  	�۸�:%f", p->price);
		printf("  	����:%d", p->num);
		printf("\n");
		sum += p->num;// ͼ��������
		p = p->next;
	}
	printf("ͼ��������Ϊ��%d\n", sum);
	printf("�����������");
	getchar();
	getchar();
}

void over()//�������� 
{
	char t;
	printf("      -----------------------\n");
	printf("      |   ��ȷ��Ҫ�˳���  |\n");
	printf("      | 1.ȷ��     2.ȡ��   |\n");
	printf("      -----------------------\n");
	printf("      ָ�");
	while (1)
	{
		t = getchar();         //����t
		switch (t)
		{
		case '1':
			printf("���ڰ�ȫ�˳�....\n");
			printf("�Ѱ�ȫ�˳����\n");
			printf("��лʹ�ã�\n");
			printf("^_^  ^_^  ^_^");
			exit(0);
			break; //��ֹ����
		case '2':
			menu();
			break;   //���ú���������˵� 
		default:
			break;
		}
	}
}