#define _CRT_SECURE_NO_WARNINGS 1
#include "main.h"
int main()
{
	int a[10];
	int i;
	printf("please enter ten int number:\n");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	//select_Sort2(a,10);
	//bubble_Sort(a,10);
	//insert_Sort(a,10);
	quick_Sort(a, 0, 9);
	printf("after sorted:\n");
	for (i = 0; i < 10; i++)
	{
		printf("%5d", a[i]);
	}
	return 0;
}