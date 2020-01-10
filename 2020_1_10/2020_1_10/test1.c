#define _CRT_SECURE_NO_WARNINGS 1
typedef struct ListNode Node;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL)
		return l2;
	else if (l2 == NULL)
		return l1;

	Node* head = NULL, *tail = NULL;
	//创建空链表
	head = tail = (Node*)malloc(sizeof(Node));
	tail->next = NULL;
	while (l1 && l2)
	{
		// 取小的进行尾插
		if (l1->val < l2->val)
		{
			tail->next = l1;
			tail = tail->next;
			比特科技
				l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			tail = tail->next;
			l2 = l2->next;
		}
	}
	//剩余元素直接拼接
	if (l1)
		tail->next = l1;
	else
		tail->next = l2;
	Node* list = head->next;
	free(head);
	return list;
}