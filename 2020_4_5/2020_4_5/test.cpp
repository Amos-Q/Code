#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

int main(void)
{
	const int &a = 10;
	int *p = (int *)&a;

	*p = 12;

	cout << a << endl;

	return 0;
}

#include <iostream>
using namespace std;

int main(void)
{
	int a = 2;
	const int &b = a;

	b = 3;

	cout << a << b << &a << &b << endl;

	return 0;
}


#include <stdio.h>
#include <math.h>

int main()
{
	int n, i, flag = 0;
	printf("Enter a positive integer: ");
	scanf("%d", &n);
	//�������
	if (n == 1)
		printf(" 1 is not a prime number or composite number. ");
	else
	{
		for (i = 2; i <= sqrt(n); ++i) //��л@Angelas�����Ż����жϴ�����n/2-1������sqrt(n)-1��
		{
			if (n % i == 0)
			{
				flag = 1;
			}
		}
		if (flag == 0)
			printf("%d is a prime number.", n);
		else
			printf("%d is not a prime number.", n);
	}
	return 0;
}