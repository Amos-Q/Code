#define _CRT_SECURE_NO_WARNINGS 1
#include "home.h"


//�˵�ģ��
void menu()//�˵�
{
	printf("\t\t************ְ����Ϣ����ϵͳ�˵�**********\n");
	printf("\t\t*                                        *\n");
	printf("\t\t*              1.¼��ְ����Ϣ            *\n");
	printf("\t\t*                                        *\n");
	printf("\t\t*              2.��ʾְ����Ϣ            *\n");
	printf("\t\t*                                        *\n");
	printf("\t\t*              3.��ѯְ����Ϣ            *\n");
	printf("\t\t*                                        *\n");
	printf("\t\t*              4.�޸�ְ����Ϣ            *\n");
	printf("\t\t*                                        *\n");
	printf("\t\t*              5.ɾ��ְ����Ϣ            *\n");
	printf("\t\t*                                        *\n");
	printf("\t\t*              0.�˳�                    *\n");
	printf("\t\t*                                        *\n");
	printf("\t\t******************************************\n");
	printf("\t\t������ָ��(0-5): ");
}

int main()
{
	int num;
	n = 0;
	system("color 0B");
	while (1)
	{
		menu();
		scanf("%d", &num);
		system("cls");
		switch (num)
		{
		case 1: input(); break;
		case 2: show();  break;
		case 3: que();   break;
		case 4: mod();   break;
		case 5: del();   break;
		case 0: printf("ллʹ�ã�\n\n"); return 0;
		default:printf("\n--->��Ч��ָ��!\n\n\n");
		}
		system("pause");
		system("cls");
	}
}