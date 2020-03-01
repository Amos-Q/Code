#define _CRT_SECURE_NO_WARNINGS 1
#include "tree.h"

// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	int i = 0;
	int root = (n - 1 - 1) / 2;//root:倒数第一个非叶子结点
	//给堆申请空间
	hp->_a = (HPDataType *)malloc(sizeof(HPDataType)*n);
	hp->_capacity = n;
	hp->_size = n;
	//将数组中的元素放在堆中
	for (; i < n; i++)
	{
		hp->_a[i] = a[i];
	}
	//堆调整
	for (; root >= 0; --root)//从倒数第一个非叶子结点调整到根
	{
		AdjustDown(a,root, n);//利用向下调整的方法调
	}
}

void AdjustDown(int* a, int root,int n)
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
			int tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// 堆的销毁
void HeapDestory(Heap* hp)
{

}

// 堆的插入
void HeapPush(Heap* hp, HPDataType x);
// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);

// 对数组进行堆排序
void HeapSort(int* a, int n);

// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k);
void TestTopk();