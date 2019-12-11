#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* newnode = pListHead;
		int length = 0;
		if (pListHead == NULL)
			return 0;
		while (newnode != NULL)
		{
			newnode = newnode->next;
			length++;
		}
		if (k > length)
			return 0;
		length -= k;
		while (length != 0)
		{
			pListHead = pListHead->next;
			length--;
		}
		return pListHead;
	}
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* next = head;
	int length = 0;
	if (head->next == NULL)
		return head;
	while (next != NULL)
	{
		next = next->next;
		length++;
	}
	length = length / 2;
	while (length)
	{
		head = head->next;
		length--;
	}
	return head;
}


