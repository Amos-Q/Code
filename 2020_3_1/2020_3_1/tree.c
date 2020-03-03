#define _CRT_SECURE_NO_WARNINGS 1
#include "tree.h"

// 堆的构建
Heap* HeapCreate(HPDataType* a, int n)
{
	Heap* hp = (Heap*)malloc(sizeof(Heap));
	int i = 0;
	int root = (n - 1 - 1) / 2;
	hp->_a = (HPDataType *)malloc(sizeof(HPDataType)*n);
	hp->_capacity = n;
	hp->_size = n;
	memcpy(hp->_a, a, sizeof(Heap)*n);
	return hp;
}

//交换函数
void Swap(HPDataType* left, HPDataType *right)
{
	HPDataType tmp = *left;
	*left = *right;
	*right = tmp;
}

//向下调整算法
void AdjustDown(HPDataType* a, int root,int n)
{
	int parent = root;//首先找到该孩子结点的双亲,然后调整
	int child = parent * 2 + 1;
	while (child < n)//终止条件：child不为0
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}
		if (a[parent] > a[child])
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

//向上调整算法
void AdjustUp(int* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

// 对数组进行堆排序
void HeapSort(int* a, int n)
{
	int root = (n - 2) / 2;
	for (; root >= 0; root--)
	{
		AdjustDown(a, 0, n);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

// 堆的销毁
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}

// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a,sizeof(HPDataType)*(hp->_capacity));
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	AdjustUp(hp->_a, hp->_size - 1);
}

// 堆的删除
void HeapPop(Heap* hp)
{
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_a, 0, hp->_size);
}

// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}

// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

// 堆的判空
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0 ? 1 : 0;
}

// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k)
{

	int num = n;
	for (int i = (k - 2) / 2; i > 0; --i)
	{
		AdjustDown(a, i, k);
	}
	for (int i = k; i < num; ++i)
	{
		if (a[0] < a[i])
		{
			Swap(&a[0], &a[i]);
		}
		AdjustDown(a, 0, k);
	}
	for (int i = 0; i < k; ++i)
	{
		printf("%d ", a[i]);
	}
}