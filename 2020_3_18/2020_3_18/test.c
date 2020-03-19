#define _CRT_SECURE_NO_WARNINGS 1

void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		// [begin, end] 选出一个最小的，选出一个最大的下标
		int mini = begin, maxi = end;
		for (int i = begin; i <= end; ++i)
		{
			if (a[i] > a[maxi])
				maxi = i;

			if (a[i] < a[mini])
				mini = i;
		}
		Swap(&a[begin], &a[mini]);
		// 修正
		if (begin == maxi)
			maxi = mini;

		Swap(&a[end], &a[maxi]);

		printf("[%d,%d]", begin, end);
		PrintArray(a, n);

		++begin;
		--end;
	}
}

// 平均时间复杂度：O(N^1.3)  什么情况下最坏：顺序有序(预排序全部白做了，还不如直接插入排序)
void ShellSort(int* a, int n)
{
	// gap > 1时为预排序         接近有序
	// gap == 1时为直接插入排序  有序
	int gap = n;
	while (gap > 1)
	{
		// 间隔为gap的预排序
		gap = gap / 3 + 1;  // +1是保证最后一次一定是1
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}

			a[end + gap] = tmp;
		}
	}
}

void TestShellSort()
{
	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}