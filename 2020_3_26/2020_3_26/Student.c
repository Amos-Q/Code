#define _CRT_SECURE_NO_WARNINGS 1
#include "Student.h"

int main()
{

	printf(" =========================================================\n");
	printf("<                   ѧ������ϵͳ                          >\n");
	printf(" =========================================================\n");
	printf("                       ����ѡ���ܣ�\n��1���ɼ�¼�� ��2����ʾȫ����3���ɼ���ѯ ��4���ɼ��޸� (0)�˳�\n");
	int a = 0;
	scanf("%d", &a);
	while (a)
	{

		switch (a)
		{
		case 1:
			Add();
			break;
		case 2:
			Display(H);
			break;
		case 3:
			Search(H);
			break;
		case 4:
			Change(H);
			break;

		}
		printf("                       ����ѡ���ܣ�\n��1���ɼ�¼�� ��2����ʾȫ����3���ɼ���ѯ ��4���ɼ��޸� (0)�˳�\n");
		scanf("%d", &a);

	}
	printf(" =========================================================\n");
	return 0;
}
