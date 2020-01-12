#define _CRT_SECURE_NO_WARNINGS 1
解题思路：
此题可以先找出相同节点的区间，然后删除区间中的所有值，直到把链表遍历完结束
* /
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return pHead;

		struct ListNode* n0 = NULL;
		比特科技
			双链表的增删查改
			struct ListNode* n1 = pHead;
		struct ListNode* n2 = n1->next;
		while (n2 != NULL)
		{
			//如果相邻节点不相同，则不需要删除，更新节点，继续向后遍历
			if (n1->val != n2->val)
			{
				n0 = n1;
				n1 = n2;
				n2 = n2->next;
			}
			else
			{
				//如果相邻节点相同
				//则n2去找第一个不相同的节点
				while (n2 && n2->val == n1->val)
				{
					n2 = n2->next;
				}
				//重新链接，如果要删除的包括头节点，则更新头节点
				if (n0)
					n0->next = n2;
				else
					pHead = n2;

				// 删除掉重复的节点
				while (n1 != n2)
				{
					struct ListNode* next = n1->next;
					free(n1);
					n1 = next;
				}
				//更新节点
				n1 = n2;
				if (n2)
					n2 = n2->next;
			}
		}

		return pHead;
	}
};
// 带头+双向+循环链表增删查改实现
typedef int LTDataType;
比特科技
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
// 创建返回链表的头结点.
ListNode* ListCreate();
// 双向链表销毁
void ListDestory(ListNode* pHead);
// 双向链表打印
void ListPrint(ListNode* pHead);
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x);
// 双向链表尾删
void ListPopBack(ListNode* pHead);
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x);
// 双向链表头删
void ListPopFront(ListNode* pHead);
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x);
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);
// 双向链表删除pos位置的节点
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
	比特科技
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
   比特科技
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
// 双向链表在pos的前面进行插入
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
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos) {
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	比特科技
		顺序表、链表[选择题10道
		prev->next = next;
	next->prev = prev;
	free(pos);
}