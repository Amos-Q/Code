#define _CRT_SECURE_NO_WARNINGS 1
#include "home.h"
void main()
{
	int n;
	while (n != 6)
	{
		printf("\t��ѧ����������ɼ�����ϵͳ\n");
		printf("1������һ����ѧ����ѧ����������ɼ���¼\n");
		printf("2����ʾ���гɼ���¼\n");
		printf("3�����㲢���ƽ���ɼ���������\n");
		printf("4������ɼ�������\n");
		printf("5����������ļ�chengji.txt\n");
		printf("6���˳�ϵͳ\n");
		printf("����ѡ�����:");
		scanf("%d", &n);
		switch (n)
		{
		case 1:a(); break;
		case 2:b(); break;
		case 3:c(); break;
		case 4:d(); break;
		case 5:e(); break;
		case 6:printf("\n*******************ллʹ�ã�*******************\n"); break;
			break;
		}
	}
	getchar();
}