#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <assert.h>

int cmp1(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);//a>b 返回正值
}

int cmp2(const void * a, const void *b)
{
	return(*(char*)a - *(char*)b);
}
int cmp3(const void * a, const void * b)
{
	if (fabs(*(double*)a - *(double *)b) < 1 * exp(-20))
		return 0;
	else
		return(((*(double*)a - *(double*)b) > 0) ? 1 : -1);
}


void swap(char* p1, char* p2, int size)
{
	assert(p1 && p2);
	int i = 0;
	for (i = 0; i < size; i++)//必须将一个元素的所有字节循环比较完，才算将这个元素比较完了
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2++;
	}
}
void my_qsort(void* arr[], int sz, int size, int(*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - i - 1; j++)
		{
			if (cmp((char*)arr + j * size, (char*)arr + (j + 1)*size) > 0)
			{
				swap((char*)arr + j * size, (char*)arr + (j + 1)*size, size);
			}
		}
	}
}

int main()
{
	int i;
	int a[10] = { 7,8,5,1,2,3,6,9,7,10 };
	char b[10] = { 'b','a','c','d','e','f','w','g','h','j' };
	double c[10] = { 0.1,0.2,0.9,0.5,0.3,0.6,0.7,0.8,1.1,1.2 };
	qsort(a, 10, sizeof(int), &cmp1);
	qsort(b, 10, sizeof(char), cmp2);
	qsort(c, 10, sizeof(double), cmp3);
	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");
	for (i = 0; i < 10; i++)
		printf("%c ", b[i]);
	printf("\n");
	for (i = 0; i < 10; i++)
		printf("%lf ", c[i]);
	printf("\n");


	my_qsort(a,10,sizeof(a[0]),cmp1);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	my_qsort(b, 10, sizeof(b[0]), cmp2);
	for (i = 0; i < 10; i++)
	{
		printf("%c ", b[i]);
	}
	printf("\n");
	my_qsort(c, 10, sizeof(c[0]), cmp3);
	for (i = 0; i < 10; i++)
	{
		printf("%lf ", c[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}
