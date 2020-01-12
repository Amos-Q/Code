#define _CRT_SECURE_NO_WARNINGS 1
����˼·��
����������ҳ���ͬ�ڵ�����䣬Ȼ��ɾ�������е�����ֵ��ֱ����������������
* /
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return pHead;

		struct ListNode* n0 = NULL;
		���ؿƼ�
			˫�������ɾ���
			struct ListNode* n1 = pHead;
		struct ListNode* n2 = n1->next;
		while (n2 != NULL)
		{
			//������ڽڵ㲻��ͬ������Ҫɾ�������½ڵ㣬����������
			if (n1->val != n2->val)
			{
				n0 = n1;
				n1 = n2;
				n2 = n2->next;
			}
			else
			{
				//������ڽڵ���ͬ
				//��n2ȥ�ҵ�һ������ͬ�Ľڵ�
				while (n2 && n2->val == n1->val)
				{
					n2 = n2->next;
				}
				//�������ӣ����Ҫɾ���İ���ͷ�ڵ㣬�����ͷ�ڵ�
				if (n0)
					n0->next = n2;
				else
					pHead = n2;

				// ɾ�����ظ��Ľڵ�
				while (n1 != n2)
				{
					struct ListNode* next = n1->next;
					free(n1);
					n1 = next;
				}
				//���½ڵ�
				n1 = n2;
				if (n2)
					n2 = n2->next;
			}
		}

		return pHead;
	}
};
// ��ͷ+˫��+ѭ��������ɾ���ʵ��
typedef int LTDataType;
���ؿƼ�
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
// �������������ͷ���.
ListNode* ListCreate();
// ˫����������
void ListDestory(ListNode* pHead);
// ˫�������ӡ
void ListPrint(ListNode* pHead);
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x);
// ˫������βɾ
void ListPopBack(ListNode* pHead);
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x);
// ˫������ͷɾ
void ListPopFront(ListNode* pHead);
// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x);
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);
// list.c
#include "List.h"
ListNode* BuyListNode(LTDataType x) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->prev = head;
	return head;
}
void ListPrint(ListNode* pHead) {
	assert(pHead);
	ListNode* cur = pHead->next;
	���ؿƼ�
		while (cur != pHead)
		{
			printf("%d->", cur->data);
			cur = cur->next;
		}
	printf("\n");
}
void ListDestroy(ListNode* pHead) {
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(pHead);
}
void ListPushBack(ListNode* pHead, LTDataType x) {
	assert(pHead);
	//ListNode* newnode = BuyListNode(x);
	//// phead tail newnode
	//ListNode* tail = pHead->prev;
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = pHead;
	//pHead->prev = newnode;
	ListInsert(pHead, x);
}
void ListPushFront(ListNode* pHead, LTDataType x) {
	assert(pHead);
	//ListNode* newnode = BuyListNode(x);
	//ListNode* first = pHead->next;
	//pHead->next = newnode;
	//newnode->prev = pHead;
	//newnode->next = first;
	//first->prev = newnode;
	/*ListNode* newNode = BuyListNode(x);
	newNode->next = pHead->next;
	pHead->next->prev = newNode;
	pHead->next = newNode;
   ���ؿƼ�
	newNode->prev = pHead;*/
	ListInsert(pHead->next, x);
}
void ListPopBack(ListNode* pHead) {
	assert(pHead);
	//ListNode* tail = pHead->prev;
	//ListNode* tailPrev = tail->prev;
	//// pHead tailPrev tail
	//tailPrev->next = pHead;
	//pHead->prev = tailPrev;
	//free(tail);
	/*ListNode* tail = pHead->prev;
	pHead->prev = tail->prev;
	tail->prev->next = pHead;
	free(tail);*/
	ListErase(pHead->prev);
}
void ListPopFront(ListNode* pHead) {
	//...
	ListErase(pHead->next);
}
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x) {
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	// prev newnode pos
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos) {
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	���ؿƼ�
		˳�������[ѡ����10��
		prev->next = next;
	next->prev = prev;
	free(pos);
}