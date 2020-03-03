#define _CRT_SECURE_NO_WARNINGS 1
#include "tree.h"

// �ѵĹ���
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

//��������
void Swap(HPDataType* left, HPDataType *right)
{
	HPDataType tmp = *left;
	*left = *right;
	*right = tmp;
}

//���µ����㷨
void AdjustDown(HPDataType* a, int root,int n)
{
	int parent = root;//�����ҵ��ú��ӽ���˫��,Ȼ�����
	int child = parent * 2 + 1;
	while (child < n)//��ֹ������child��Ϊ0
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

//���ϵ����㷨
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

// ��������ж�����
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

// �ѵ�����
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}

// �ѵĲ���
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

// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_a, 0, hp->_size);
}

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}

// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0 ? 1 : 0;
}

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
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