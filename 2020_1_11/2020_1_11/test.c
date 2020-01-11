#define _CRT_SECURE_NO_WARNINGS 1
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		int a[900] = { 0 };
		ListNode* cur = A;
		int n = 0;
		//保存链表元素
		while (cur)
		{
			a[n++] = cur->val;
			cur = cur->next;
		}
		//判断数组是否为回文结构
		int begin = 0, end = n - 1;
		while (begin < end)
		{
			if (a[begin] != a[end])
				return false;
			++begin;
			--end;
		}

		return true;
	}
};
8.输入两个链表，找出它们的第一个公共结点。OJ链接
/*
解题思路：
此题可以先计算出两个链表的长度，让长的链表先走相差的长度，然后两个链表同时走，直到遇到相同的节点，即为第
一个公共节点
*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	int lenA = 0, lenB = 0;
	struct ListNode* curA = headA, *curB = headB;
	//计算链表长度
	while (curA) {
		++lenA;
		curA = curA->next;
	}

	while (curB) {
		比特科技
			++lenB;
		curB = curB->next;
	}

	int gap = abs(lenA - lenB);
	struct ListNode* longList = headA, *shortList = headB;
	if (lenA < lenB) {
		longList = headB;
		shortList = headA;
	}
	//让长链表先走几步
	while (gap--) {
		longList = longList->next;
	}
	//两个链表同时走，直到遇到相同的节点
	while (longList && shortList)
	{
		if (longList->val == shortList->val) {
			return longList;
		}
		else {
			longList = longList->next;
			shortList = shortList->next;
		}
	}

	return NULL;
}
9.给定一个链表，判断链表中是否有环。 OJ链接
/*
解题思路：
定义快慢指针fast,slow, 如果链表确实有环，fast指针一定会在环内追上slow指针。
*/
typedef struct ListNode Node;
bool hasCycle(struct ListNode *head) {
	Node* slow = head;
	Node* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}
	return false;
}
