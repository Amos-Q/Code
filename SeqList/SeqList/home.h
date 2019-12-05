#define _CRT_SECURE_NO_WARNINGS 1
#pragma one

#include <stdio.h>
#include <stdlib.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* array; // 指向动态开辟的数组
	size_t size;    // 有效数据个数
	size_t capicity;  // 容量空间的大小
}SeqList;

void SeqListInit(SeqList* psl, size_t capacity);
void SeqListDestory(SeqList* psl);
void SeqListPrint(SeqList* psl);
void CheckCapacity(SeqList* psl);
void SeqListPushBack(SeqList* psl, SLDataType x);
void SeqListPopBack(SeqList* psl);
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);
int SeqListFind(SeqList* psl, SLDataType x);
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
void SeqListErase(SeqList* psl, size_t pos);