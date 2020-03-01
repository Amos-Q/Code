#define _CRT_SECURE_NO_WARNINGS 1
#include "tree.h"

// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	int i = 0;
	int root = (n - 1 - 1) / 2;//root:������һ����Ҷ�ӽ��
	//��������ռ�
	hp->_a = (HPDataType *)malloc(sizeof(HPDataType)*n);
	hp->_capacity = n;
	hp->_size = n;
	//�������е�Ԫ�ط��ڶ���
	for (; i < n; i++)
	{
		hp->_a[i] = a[i];
	}
	//�ѵ���
	for (; root >= 0; --root)//�ӵ�����һ����Ҷ�ӽ���������
	{
		AdjustDown(a,root, n);//�������µ����ķ�����
	}
}

void AdjustDown(int* a, int root,int n)
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

// �ѵ�����
void HeapDestory(Heap* hp)
{

}

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);

// ��������ж�����
void HeapSort(int* a, int n);

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k);
void TestTopk();