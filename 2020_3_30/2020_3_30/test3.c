#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 归并排序递归实现
void _MergeSort(int* a, int left,int right,int* tmp)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) >> 1;
	MergeSort(a, left, mid, tmp);
	MergeSort(a, mid + 1, right, tmp);
	int left1 = left, right1 = mid;
	int left2 = mid + 1, right2 = right;
	int index = 0;
	while (left1 <= right1 && left2 <= right2)
	{
		if (a[left1] < a[left2])
			tmp[index++] = a[left1++];
		else
			tmp[index++] = a[left2++];
	}
	if (left1 <= right1)
	{
		while (left1 <= right1)
			tmp[index++] = a[left1++];
	}
	else
	{
		while (left2 <= right2)
		{
			tmp[index++] = a[left2++];
		}
	}
	memcpy(a + left, tmp + left, sizeof(int)*(right - left));
}

void MergeSort(int*a, int n)
{
	int* tmp = (int*)malloc(sizeof(int));
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

// 计数排序
void CountSort(int* a, int n)
{
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;
	int* countArr = (int*)malloc(sizeof(int)*range);
	memset(countArr, 0, sizeof(int)*range);
	for (int i = 0; i < n - 1; i++)
	{
		countArr[a[i] - min]++;
	}
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (countArr[i]--)
		{
			a[j++] = i + min;
		}
	}
}


// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{

}