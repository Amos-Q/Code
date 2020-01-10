#define _CRT_SECURE_NO_WARNINGS 1
typedef struct ListNode Node;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL)
		return l2;
	else if (l2 == NULL)
		return l1;

	Node* head = NULL, *tail = NULL;
	//����������
	head = tail = (Node*)malloc(sizeof(Node));
	tail->next = NULL;
	while (l1 && l2)
	{
		// ȡС�Ľ���β��
		if (l1->val < l2->val)
		{
			tail->next = l1;
			tail = tail->next;
			���ؿƼ�
				l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			tail = tail->next;
			l2 = l2->next;
		}
	}
	//ʣ��Ԫ��ֱ��ƴ��
	if (l1)
		tail->next = l1;
	else
		tail->next = l2;
	Node* list = head->next;
	free(head);
	return list;
}