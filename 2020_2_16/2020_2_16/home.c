#define _CRT_SECURE_NO_WARNINGS 1

#include "home.h"

/* ��  ��  ��*/
void a() /* ����һ�����ѧ����¼*/

{
	int i;

	for (i = 0; i < 4; i++)

	{

		printf("������ѧ�� ���� ƽʱ�ɼ� ʵ��ɼ� ���Գɼ���");

		scanf("%d%s%f%f%f", &stu[i].num, stu[i].name, &stu[i].pingshi, &stu[i].shiyan, &stu[i].kaoshi);

	}for (i = 0; i < 4; i++)
		stu[i].zongping = 0.1*stu[i].pingshi + 0.3*stu[i].shiyan + 0.6*stu[i].kaoshi;
}
void b()/* ��ʾ���м�¼*/

{
	int i;

	printf("ѧ��        ����       ƽʱ�ɼ�       ʵ��ɼ�      ���Գɼ�     �����ɼ�\n");

	for (i = 0; i < 4; i++)

		printf("%d%14.2s%14.2f%14.2f%14.2f%14.2f\n", stu[i].num, stu[i].name, stu[i].pingshi, stu[i].shiyan, stu[i].kaoshi, stu[i].zongping);

}

void c()/* ���ȫ��ƽ���ɼ�����ʾ������*/
{
	int a[4] = { 0,1,2,3 };
	int i, j;
	double total = 0, pfc = 0, bzc = 0;
	double ave;
	for (i = 0; i < 4; i++)
	{
		total = total + stu[i].zongping;
	}
	ave = total / 4.0;
	printf("����ƽ���ɼ���%f\n", ave);
	for (i = 0; i < 4; i++)
	{
		pfc = pow((stu[i].zongping - ave), 2) / 4;
	}
	bzc = sqrt(pfc);
	printf("\nƽ������%f\n", pfc);
	printf("\n��׼����%f\n", bzc);
}
void d()

{
	int a[4] = { 0,1,2,3 };
	int i, j, temp;
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 3 - j; i++)
			if (stu[a[i]].zongping > stu[a[i + 1]].zongping)
			{
				temp = a[i]; a[i] = a[i + 1];
				a[i + 1] = temp;

			}
	}

	printf("˳��Ϊ:\n");

	printf("ѧ��     ����      �����ɼ�\n");

	for (i = 0; i < 4; i++)

		printf("%d%10.2s%15.2f\n", stu[a[i]].num, stu[a[i]].name, stu[a[i]].zongping);

	printf("\n");

}

void e()
{
	int i;
	FILE *fp;
	fp = fopen("chengji.txt", "w");

	fprintf(fp, "ѧ��        ����       ƽʱ�ɼ�       ʵ��ɼ�      ���Գɼ�     �����ɼ�\n");

	for (i = 0; i < 4; i++)

		fprintf(fp, "%d%14.2s%14.2f%14.2f%14.2f%14.2f\n", stu[i].num, stu[i].name, stu[i].pingshi, stu[i].shiyan, stu[i].kaoshi, stu[i].zongping);

	printf("\n\n*******************��ϲ��������ɣ�*******************\n\n");
}