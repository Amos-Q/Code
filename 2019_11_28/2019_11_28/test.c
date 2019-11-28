#define _CRT_SECURE_NO_WARNINGS 1
//��10������ת��Ϊ��������
void From10baseTransformTo1_16(int m, int base)
{
	char num[] = "0123456789ABCDEF";
	char result[30] = { 0 };
	int len = 0;
	char temp;
	int start = 0;
	int end = len;

	while (m)                //շת������ȴ����������
	{
		result[len++] = num[m%base];
		m = m / base;
	}

	start = 0;
	end = len - 1;
	while (start < end)   //�ַ�����ת
	{
		temp = result[start];
		result[start] = result[end];
		result[end] = temp;
		start++;
		end--;
	}

	start = 0;
	for (start = 0; start < len; start++)
		printf("%c", result[start]);
	printf("\n");

}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int denominator[20], numerator[20];
	double sum;
	int i;

	denominator[0] = 2;
	denominator[1] = 3;
	numerator[0] = 1;
	numerator[1] = 2;

	sum = (double)numerator[0] / (double)denominator[0] + (double)numerator[1] / (double)denominator[1];

	for (i = 2; i < 20; i++) {
		denominator[i] = denominator[i - 1] + denominator[i - 2];
		numerator[i] = numerator[i - 1] + numerator[i - 2];
		sum = sum + (double)numerator[i] / (double)denominator[i];
	}

	printf("The sum is %lf", sum);

	system("pause");
	return 0;
}
