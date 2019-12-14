#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
	public ListNode insertionSortList(ListNode head) {
		ListNode res = null;
		ListNode p = head;
		while (p != null) {
			ListNode next = p.next;
			res = insert(res, p);
			p = next;
		}

		return res;
	}

	private ListNode insert(ListNode head, ListNode node) {
		if (head == null || head.val > node.val) {
			node.next = head;
			return node;
		}

		head.next = insert(head.next, node);
		return head;
	}
}

此为第二种，链表不进行增断链表，而是进行指针值的变动

struct ListNode* insertionSortList(struct ListNode* head) {
	if (!head)
		return NULL;
	struct ListNode * p, *q;
	int temp;

	for (p = head; p; p = p->next)
	{
		for (q = p->next; q; q = q->next)
		{
			if (p->val > q->val)
			{
				temp = p->val;
				p->val = q->val;
				q->val = temp;
			}
		}

	}
	return head;
}
