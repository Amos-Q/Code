#define _CRT_SECURE_NO_WARNINGS 1
#include"home.h"


void SeqListInit(SeqList* psl, size_t capacity)
{
	psl->array = NULL;

}
void SeqListPrint(SeqList* psl)
void CheckCapacity(SeqList* psl)
void SeqListPushBack(SeqList* psl, SLDataType x)
void SeqListPopBack(SeqList* psl)
void SeqListPushFront(SeqList* psl, SLDataType x)
void SeqListPopFront(SeqList* psl)
int SeqListFind(SeqList* psl, SLDataType x)
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
void SeqListErase(SeqList* psl, size_t pos)
