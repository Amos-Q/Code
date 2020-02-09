#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int i, j, k;
	printf("/n");
	for (i = 1; i < 5; i++)
		for (j = 1; j < 5; j++)
			for (k = 1; k < 5; k++)
			{
				if (i != k && i != j && j != k) 
					printf("%d,%d,%d/n", i, j, k);
			}
}

int main()
{
	int day, month, year, sum, leap;
	printf("/nplease input year,month,day/n");
	scanf("%d,%d,%d", &year, &month, &day);
	switch (month)/*先计算某月以前月份的总天数*/
	{
	case 1:sum = 0; break;
	case 2:sum = 31; break;
	case 3:sum = 59; break;
	case 4:sum = 90; break;
	case 5:sum = 120; break;
	case 6:sum = 151; break;
	case 7:sum = 181; break;
	case 8:sum = 212; break;
	case 9:sum = 243; break;
	case 10:sum = 273; break;
	case 11:sum = 304; break;
	case 12:sum = 334; break;
	default:printf("data error"); break;
	}
	sum = sum + day; 
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))/*判断是不是闰年*/
		leap = 1;
	else
		leap = 0;
	if (leap == 1 && month > 2)/*如果是闰年且月份大于2,总天数应该加一天*/
		sum++;
	printf("It is the %dth day.", sum);
}

int main()
{
	int x, y, z, t;
	scanf("%d%d%d", &x, &y, &z);
	if (x > y)
	{
		t = x; x = y; y = t;
	} /*交换x,y的值*/
	if (x > z)
	{
		t = z; z = x; x = t;
	}/*交换x,z的值*/
	if (y > z)
	{
		t = y; y = z; z = t;
	}/*交换z,y的值*/
	printf("small to big: %d %d %d/n", x, y, z);
}

int main()
{
	int a[11] = { 1,4,6,9,13,16,19,28,40,100 };
	int temp1, temp2, number, end, i, j;
	printf("original array is:/n");
	for (i = 0; i < 10; i++)
		printf("%5d", a[i]);
	printf("/n");
	printf("insert a new number:");
	scanf("%d", &number);
	end = a[9];
	if (number > end)
		a[10] = number;
	else
	{
		for (i = 0; i < 10; i++)
		{
			if (a[i] > number)
			{
				temp1 = a[i];
				a[i] = number;
				for (j = i + 1; j < 11; j++)
				{
					temp2 = a[j];
					a[j] = temp1;
					temp1 = temp2;
				}
				break;
			}
		}
	}
	for (i = 0; i < 11; i++)
		printf("%6d", a[i]);
}