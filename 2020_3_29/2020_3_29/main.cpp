#define _CRT_SECURE_NO_WARNINGS 1

#include "main.h"
int main()
{
	int sat;
	//��ʼ������
	Queue Q = Initinteract();
	TravQueue(Q);
	//��������
	int loc, val;
	char m;
	while (1)
	{
		printf("\n�����밴A������ֵ�밴B��������C");
		//system("cls");
		cin >> m;
		switch (m)
		{
		case 'A':
			printf("��ʼ���룬���������ֵ\n");
			scanf_s("%d", &val);
			sat = InsertQueue(Q, val);
			break;
		case 'B':
			printf("��ʼɾ��\n");
			printf("�ѵ���ֵ%d\n", DeQueue(Q));
			break;
		case 'C':
			printf("��ǰ����ֵ����");
			TravQueue(Q);
			break;
		default:
			exit(0);
		}
	}
}