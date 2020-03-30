#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int end = n - 1; end > 0; end--)
	{
		int flag = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}


// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	int key = a[right];
	int kedyindex = right;
	while (left < right)
	{
		while (left < right && a[left] <= key)
		{
			left++;
		}
		while (left < right && a[right] >= key)
		{
			--right;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[kedyindex]);
	return left;
}


// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int key = a[left];
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			--right;
		}
		a[left] = a[right];
		while (left < right && a[left] <= key)
		{
			++left;
		}
		a[right] = a[left];
	}
	a[left] = key;
	return left;
}


// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	int key = a[right];
	int cur = left;
	int prev = left - 1;
	while (cur < right)
	{
		if (a[cur] <= key)
		{
			++prev;
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	++prev;
	Swap(&a[prev], &a[right]);
	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int keyindex = PartSort1(a, left, right);
	//int keyindex = PartSort2(a, left, right);
	//int keyindex = PartSort3(a, left, right);
	QuickSort(a, left, keyindex - 1);
	QuickSort(a, keyindex + 1, right);
}


// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, left);
	StackPush(&st, right);
	while (!StackEmpt(&st))
	{
		right = StackTop(&st);
		StackPop(&st);
		right = StackTop(&st);
		StackPop(&st);
		int keyindex = PartSort1(a, left, right);
		if (left < keyindex - 1)
		{
			StackPush(&st,left);
			StackPush(&st, keyindex - 1);
		}
		if (keyindex + 1 < right)
		{
			StackPush(&st, keyindex + 1);
			StackPush(&st, right);
		}
	}
	StackDestory(&st);
}