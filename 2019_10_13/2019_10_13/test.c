#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n, i, m = 0, k = 0;
	int a[500];

	printf("Please input n:");
	scanf("%d", &n);

	for (i = 0; i < n; i++) //��n������ֵ
	{
		a[i] = i + 1;
	}

	while (m < n - 1) //m�����ܹ������Ϊ0�ĸ���
	{
		for (i = 0; i < n; i++)
		{
			if (a[i] != 0)
			{
				k++;
				if (k % 3 == 0) //k��ÿ����3�����������Ϊ0
				{
					a[i] = 0;
					m++;
				}
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		if (a[i] != 0) //������Ψһһ��������
			printf("The last one is:%d\n", a[i]);
	}
	system("pause");
	return 0;
}