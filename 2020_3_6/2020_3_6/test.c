#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>;
//#include <stdlib.h>
//#include <time.h>
//int main()
//{
//	int n; int a[100];
//	scanf("%d", &n);//输入n
//	srand(n);
//	int i;
//	for (i = 0; i < n; i++)
//		a[i] = rand() % 21;//设置随机数，并赋值给数组a
//	printf("%d", a[0]);
//	for (i = 1; i < n; i++)
//		printf(",%d", a[i]);
//	printf("\n");//先输出一次随机数组
//	int m = a[0];
//	for (i = 0; i + 1 < n; i++)
//	{
//		if (m >= a[i + 1])
//			m = a[i + 1];
//	}
//	printf("min=%d\n", m);//取出最小值
//	for (i = 0; i < n; i++)
//	{
//		if (m == a[i])
//			a[i] = -1;//把所有最小值项化为-1
//	}
//	int b[100]; int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (a[i] > 0)
//		{
//			b[j] = a[i]; j++;//将非负项转入数组b
//		}
//	}
//	printf("%d", b[0]);
//	for (i = 1; i < j; i++)
//		printf(",%d", b[i]);
//	system("pause");
//	return 0;
//}
//
//
//#include<stdio.h>
//#define N 1000
//int main()
//{
//	int n, i, s[N], A = 0, B = 0, C = 0, D = 0, E = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &s[i]);
//	}
//	for (i = 0; i < n; i++)
//	{
//		if (s[i] >= 90)
//			A++;
//		else if (s[i] < 90 && s[i] >= 80)
//			B++;
//		else if (s[i] < 80 && s[i] >= 70)
//			C++;
//		else if (s[i] < 70 && s[i] >= 60)
//			D++;
//		else
//			E++;
//	}
//	printf("%d %d %d %d %d", A, B, C, D, E);
//	return 0;
//}


#include<stdio.h>
int main()
{
	int m, n;
	float a;
	scanf("%d %d", &m, &n);
	a = (float)m / n;
	if (a < 1.1)
	{
		printf("OK");
	}
	else if (a >= 1.1&&a < 1.5)
	{
		printf("Exceed %.f%%. Ticket 200", (a - 1) * 100);
	}
	else
	{
		printf("Exceed %.f%%. License Revoked", (a - 1) * 100);
	}
	return 0;
}


