#define _CRT_SECURE_NO_WARNINGS 1
/*
解题思路： 此题一般常用的方法有两种，三指针翻转法和头插法
1. 三指针翻转法
 记录连续的三个节点，原地修改节点指向
2. 头插法
 每一个节点都进行头插
*/
// 三个指针翻转的思想完成逆置
struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;

	struct ListNode* n1, *n2, *n3;
	n1 = head;
	n2 = n1->next;
	n3 = n2->next;
	n1->next = NULL;
	//中间节点不为空，继续修改指向
	while (n2)
	{
		//中间节点指向反转
		n2->next = n1;
		//更新三个连续的节点
		n1 = n2;
		n2 = n3;
		比特科技
			if (n3)
				n3 = n3->next;
	}
	//返回新的头
	return n1;
}
// 取节点头插的思想完成逆置
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* newhead = NULL;
	struct ListNode* cur = head;
	while (cur)
	{
		struct ListNode* next = cur->next;
		//头插新节点，更新头
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}

	return newhead;
}
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		struct ListNode* slow = pListHead;
		struct ListNode* fast = slow;
		while (k--)
		{
			if (fast)
				fast = fast->next;
			else
				return NULL;
		}

		while (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}

		return slow;
	}
};