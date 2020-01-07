#define _CRT_SECURE_NO_WARNINGS 1
// SeqList.h
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* a;
	size_t size;
	size_t capacity; // unsigned int
}SeqList;
// �����ݵĹ���:��ɾ���
void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);
void SeqListPrint(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDateType x);
void SeqListPushFront(SeqList* ps, SLDateType x);
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);
// ˳������
int SeqListFind(SeqList* ps, SLDateType x);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos);
// SeqList.c
#include "SeqList.h"
void SeqListInit(SeqList* ps) {
	assert(ps);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
void SeqListDestory(SeqList* ps) {
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	���ؿƼ�
		ps->size = ps->capacity = 0;
}
void SeqListPrint(SeqList* ps) {
	assert(ps);
	for (size_t i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("%\n");
}
void CheckCacpity(SeqList* ps) {
	if (ps->size == ps->capacity)
	{
		size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ps->a = (SLDateType*)realloc(ps->a, newcapacity * sizeof(SLDateType));
		ps->capacity = newcapacity;
	}
}
// ���¼����ӿ��Ƚ�������Insert��Erase��ʵ�֣�����ٽ�����ʵ��
void SeqListPushBack(SeqList* ps, SLDateType x) {
	//assert(ps);
	//CheckCacpity(ps);
	//ps->a[ps->size] = x;
	//ps->size++;
	SeqListInsert(ps, ps->size, x);
}
void SeqListPushFront(SeqList* ps, SLDateType x) {
	assert(ps);
	/*CheckCacpity(ps);
	size_t end = ps->size;
	while (end > 0)
	{
	ps->a[end] = ps->a[end - 1];
	--end;
	}
	ps->a[0] = x;
	++ps->size;*/
	���ؿƼ�
		SeqListInsert(ps, 0, x);
}
void SeqListPopFront(SeqList* ps) {
	assert(ps);
	//size_t start = 0;
	//while (start < ps->size-1)
	//{
	// ps->a[start] = ps->a[start + 1];
	// ++start;
	//}
	//size_t start = 1;
	//while (start < ps->size)
	//{
	// ps->a[start-1] = ps->a[start];
	// ++start;
	//}
	//--ps->size;
	SeqListErase(ps, 0);
}
void SeqListPopBack(SeqList* ps) {
	assert(ps);
	//ps->a[ps->size - 1] = 0;
	//ps->size--;
	SeqListErase(ps, ps->size - 1);
}
int SeqListFind(SeqList* ps, SLDateType x) {
	for (size_t i = 0; i < ps->size; ++i)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x) {
	assert(ps);
	assert(pos <= ps->size);
	CheckCacpity(ps);
	���ؿƼ�
		����OJ��
		1. ԭ���Ƴ����������е�Ԫ��val��Ҫ��ʱ�临�Ӷ�ΪO(N)���ռ临�Ӷ�ΪO(1)��OJ����
		//int end = ps->size - 1;
		//while (end >= (int)pos)
		//{
		// ps->a[end + 1] = ps->a[end];
		// --end;
		//}
		size_t end = ps->size;
	while (end > pos)
	{
		ps->a[end] = ps->a[end - 1];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos) {
	assert(ps && pos < ps->size);
	//size_t start = pos;
	//while (start < ps->size-1)
	//{
	// ps->a[start] = ps->a[start + 1];
	// ++start;
	//}
	size_t start = pos + 1;
	while (start < ps->size)
	{
		ps->a[start - 1] = ps->a[start];
		++start;
	}
	ps->size--;
}