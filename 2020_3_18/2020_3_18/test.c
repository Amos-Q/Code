#define _CRT_SECURE_NO_WARNINGS 1

void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		// [begin, end] ѡ��һ����С�ģ�ѡ��һ�������±�
		int mini = begin, maxi = end;
		for (int i = begin; i <= end; ++i)
		{
			if (a[i] > a[maxi])
				maxi = i;

			if (a[i] < a[mini])
				mini = i;
		}
		Swap(&a[begin], &a[mini]);
		// ����
		if (begin == maxi)
			maxi = mini;

		Swap(&a[end], &a[maxi]);

		printf("[%d,%d]", begin, end);
		PrintArray(a, n);

		++begin;
		--end;
	}
}

// ƽ��ʱ�临�Ӷȣ�O(N^1.3)  ʲô��������˳������(Ԥ����ȫ�������ˣ�������ֱ�Ӳ�������)
void ShellSort(int* a, int n)
{
	// gap > 1ʱΪԤ����         �ӽ�����
	// gap == 1ʱΪֱ�Ӳ�������  ����
	int gap = n;
	while (gap > 1)
	{
		// ���Ϊgap��Ԥ����
		gap = gap / 3 + 1;  // +1�Ǳ�֤���һ��һ����1
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