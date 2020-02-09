#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a[N] = { 9,6,5,4,1 }, i, temp;
	printf("/n original array:/n");
	for (i = 0; i < N; i++)
		printf("%4d", a[i]);
	for (i = 0; i < N / 2; i++)
	{
		temp = a[i];
		a[i] = a[N - i - 1];
		a[N - i - 1] = temp;
	}
	printf("/n sorted array:/n");
	for (i = 0; i < N; i++)
		printf("%4d", a[i]);
}

int main()
{
	int number[10];
	input(number);
	max_min(number);
	output(number);
}
input(number)
int number[10];
{int i;
for (i = 0; i < 9; i++)
	scanf("%d,", &number[i]);
scanf("%d", &number[9]);
}
max_min(array)
int array[10];
{int *max, *min, k, l;
int *p, *arr_end;
arr_end = array + 10;
max = min = array;
for (p = array + 1; p < arr_end; p++)
	if (*p > *max) max = p;
	else if (*p < *min) min = p;
k = *max;
l = *min;
*p = array[0]; array[0] = l; l = *p;
*p = array[9]; array[9] = k; k = *p;
return;
}
output(array)
int array[10];
{ int *p;
for (p = array; p < array + 9; p++)
	printf("%d,", *p);
printf("%d/n", array[9]);
}

int main()
{
	int number[20], n, m, i;
	printf("the total numbers is:");
	scanf("%d", &n);
	printf("back m:");
	scanf("%d", &m);
	for (i = 0; i < n - 1; i++)
		scanf("%d,", &number[i]);
	scanf("%d", &number[n - 1]);
	move(number, n, m);
	for (i = 0; i < n - 1; i++)
		printf("%d,", number[i]);
	printf("%d", number[n - 1]);
}
move(array, n, m)
int n, m, array[20];
{
	int *p, array_end;
	array_end = *(array + n - 1);
	for (p = array + n - 1; p > array; p--)
		*p = *(p - 1);
	*array = array_end;
	m--;
	if (m > 0) move(array, n, m);
}
