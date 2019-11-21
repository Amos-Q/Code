#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int(*parr3[10])[5];
	printf("%d\n", sizeof(parr3)); // 40
	int a1[5];
	parr3[0] = &a1;
	parr3[1] = &a1;

	return 0;
}

#include <stdio.h>
void test()
{
	printf("hehe\n");
}

int func(int a)
{
	printf("heheda\n");
	return a;
}

int main()
{
	printf("%p\n", test); // 函数指针
	printf("%p\n", &test);

	int a[10];
	int(*pa)[10] = &a;

	//函数指针变量
	void(*pf)() = test;
	test();
	(*pf)();
	pf();

	int(*pfunc)(int);
	pfunc = func;
	pfunc(10);

	(*(void(*)())0)();

	return 0;
}

#include <stdio.h>

typedef void(*P_FUNC)(int);

void f1(int a)
{
	printf("我来了:%d\n", a);
}

//void(*signal(int, void(*)(int)))(int);
P_FUNC signal(int, P_FUNC);

int main()
{
	void(*pf1)(int) = f1;
	P_FUNC pf2 = f1;

	pf1(1);
	pf2(2);
	(*pf1)(3);
	(*pf2)(4);

	return 0;
}

#include <stdio.h>
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a*b;
}
int div(int a, int b)
{
	return a / b;
}
int main()
{
	int x, y;
	int input = 1;
	int ret = 0;
	do
	{
		printf("*************************\n");
		printf("  1:add           2:sub  \n");
		printf("  3:mul           4:div  \n");
		printf("*************************\n");
		printf("请选择：");
		scanf("%d", &input);
		if (input < 1 || input > 4)
		{
			printf("无效选项,请重新选择\n");
			continue;
		}

		int(*func_array[5])(int, int) = { 0, add, sub, mul, div };
		printf("输入操作数：");
		scanf("%d %d", &x, &y);
		ret = func_array[input](x, y);
		printf("ret = %d\n", ret);
		
	} while (input);

	return 0;
}

#include <stdio.h>

qosrt函数的使用者得实现一个比较函数
int compareint(const void * a, const void * b)
{
	return *(int*)b - *(int*)a;
}

int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int i = 0;

	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof (int), compareint);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

int int_cmp(const void * p1, const void * p2)
{
	return (*(int *)p1 - *(int *)p2);
}

int int_cmp_greater(int a, int b)
{
	return a - b;
}

int int_cmp_less(int a, int b)
{
	return b - a;
}

void bubble_sort(int* a, int n, int(*pf_com)(int, int))
{
	for (int end = n; end > 0; --end)
	{
		int exchange = 0;
		for (int i = 1; i < end; ++i)
		{
			if (pf_com(a[i - 1], a[i]) > 0)
			{
				int tmp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = tmp;
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}
	
}

int main()
{
	//int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int arr[] = {  1,2,3,4,5,6,7,9,8 };

	int i = 0;
	bubble_sort(arr, sizeof(arr) / sizeof(arr[0]), int_cmp_less);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}