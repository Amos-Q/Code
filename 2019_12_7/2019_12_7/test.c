#define _CRT_SECURE_NO_WARNINGS 1


//1.删除链表中等于给定值 val 的所有节点。
//
//示例 :
//
//输入: 1->2->6->3->4->5->6, val = 6
//	输出 : 1->2->3->4->5

struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* newNode = head;
	struct ListNode* ret = head;
	if (newNode == NULL)
	{
		return 0;
	}
	while (head->val == val)
	{
		if (head->next == NULL)
		{
			return 0;
		}
		else
		{
			head = head->next;
		}
	}
	while (ret->next != NULL)
	{
		newNode = ret->next;
		if (newNode->val != val)
		{
			ret = ret->next;
		}
		else
		{
			ret->next = newNode->next;
		}
	}
	if (head->next == NULL)
	{
		if (head->val == val)
		{
			return 0;
		}
	}
	return head;
}


2.