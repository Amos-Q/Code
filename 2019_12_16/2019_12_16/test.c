#define _CRT_SECURE_NO_WARNINGS 1

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode * head = (ListNode*)malloc(sizeof(ListNode));
	head->data = NULL;
	head->prev = head;
	head->next = head;
	return head;
}

// 双向链表打印
void ListPrint(ListNode* plist)
printf("顺序打印：\n");
while (plist != NULL)
{
	printf("%d  \n", plist->val);
	plist = plist->pnext;
}
printf("\n");
}

// 双向链表尾插
void ListPushBack(ListNode* plist, LTDataType x)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = x;
	ListNode * prev = pList->prev;
	prev->next = p;
	p->prev = prev;
	pList->prev = p;
	p->next = pList;
}

// 双向链表尾删
void ListPopBack(ListNode* plist)
{
	ListNode* prev = pList->prev;
	prev->prev->next = pList;
	pList->prev = prev->prev;
	free(prev);
}

// 双向链表头插
void ListPushFront(ListNode* plist, LTDataType x)
{
	ListNode*p = (ListNode*)malloc(sizeof(ListNode));
	p->data = x;
	ListNode* next = plist->next;
	plist->next = p;
	p->prev = plist;
	p->next = next;
	next->prev = p;
}

// 双向链表头删
void ListPopFront(ListNode* plist)
{
	ListNode* next = pList->next;
	pList->next = next->next;
	next->next->prev = pList;
}

// 双向链表查找
ListNode* ListFind(ListNode* plist, LTDataType x)
{
	assert(pList);
	ListNode* p = pList;
	while (p != NULL)
	{
		if（p->data == x）
			return p;
		p = p->next;
	}
}