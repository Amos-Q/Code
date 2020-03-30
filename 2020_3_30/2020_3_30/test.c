#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


void Swap(int* a, int*b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//≤Â»Î≈≈–Ú
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int j = i;
		int tmp = a[j + 1];
		while(j >= 0)
		{
			if (a[j] > tmp)
			{
				a[j + 1] = a[j];
				--j;
			}
			else
			{
				break;
			}
		}
		a[j + 1] = tmp;
	}
}

//œ£∂˚≈≈–Ú
void ShellSort(int* a, int n)
{
	//1.gap > 1Œ™‘§≈≈–Ú
	//2.gap == 1Œ™÷±Ω”≤Â»Î≈≈–Ú
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int j = i;
			int tmp = a[j + gap];
			while (j >= 0)
			{
				if (a[j] > tmp)
				{
					a[j + gap] = a[j];
					j -= gap;
				}
				else
				{
					break;
				}
			}
			a[j + gap] = tmp;
		}
	}
}

// —°‘Ò≈≈–Ú
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int min = begin;
		int max = end;
		for (int i = begin; i < end; i++)
		{
			if (a[i] > a[max])
				max = i;
			if (a[i] < a[min])
				min = i;
		}
		if (begin == max)
			max = min;
		Swap(&a[begin], &a[min]); 
		Swap(&a[end], &a[max]);
		++begin;
		--end;
	}
}


// ∂—≈≈–Ú
void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n&&a[child + 1] > a[child])
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
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{ 
		AdjustDwon(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}
}