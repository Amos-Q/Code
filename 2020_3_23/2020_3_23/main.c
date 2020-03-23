#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}

		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	//升序建一个大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

int main()
{
	int arr[] = { 3, 5, 4, 6, 7, 9, 1, 2 };
	int size = sizeof(arr) / sizeof(arr[0]);

	//InsertSort(arr, size);
	//PrintArray(arr, size);

	//ShellSort(arr, size);
	//PrintArray(arr, size);

	HeapSort(arr, size);
	//PrintArray(arr, size);

	//BubbleSort(arr, size);
	//PrintArray(arr, size);


	return 0;
}