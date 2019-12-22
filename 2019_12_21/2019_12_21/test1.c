#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
struct ListNode* insertionSortList(struct ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;

	Node* sortHead = (Node*)malloc(sizeof(Node));
	sortHead->next = head;
	head = head->next;
	sortHead->next->next = NULL;

	// 取head链表的节点进行插入
	while (head)
	{
		Node* headNext = head->next;

		Node* prev = sortHead;
		Node* cur = sortHead->next;
		while (cur)
		{
			if (cur->val > head->val)
			{
				prev->next = head;
				head->next = cur;
				break;
			}
			else
			{
				prev = cur;
				cur = cur->next;
			}
		}

		if (cur == NULL)
		{
			prev->next = head;
			head->next = NULL;
		}

		head = headNext;
	}

	return sortHead->next;
}