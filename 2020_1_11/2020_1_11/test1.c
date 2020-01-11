#define _CRT_SECURE_NO_WARNINGS 1
typedef struct ListNode Node;
struct ListNode *detectCycle(struct ListNode *head) {
	Node* slow = head;
	Node* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		//走到相遇点
		if (slow == fast)
		{
			// 求环的入口点
			Node* meet = slow;
			Node* start = head;
			比特科技
				while (meet != start)
				{
					meet = meet->next;
					start = start->next;
				}
			return meet;
		}
	}
	return NULL;
}
11.给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
要求返回这个链表的深度拷贝。OJ链接
/*
解题思路：
此题可以分三步进行：
1.拷贝链表的每一个节点，拷贝的节点先链接到被拷贝节点的后面
2.复制随机指针的链接：拷贝节点的随机指针指向被拷贝节点随机指针的下一个位置
3.拆解链表，把拷贝的链表从原链表中拆解出来
*/
class Solution {
public:
	Node* copyRandomList(Node* head) {
		// 1.拷贝链表，并插入到原节点的后面
		Node* cur = head;
		while (cur)
		{
			Node* next = cur->next;
			Node* copy = (Node*)malloc(sizeof(Node));
			copy->val = cur->val;
			// 插入
			cur->next = copy;
			copy->next = next;
			// 迭代往下走
			cur = next;
		}
		// 2.置拷贝节点的random
		cur = head;
		while (cur)
		{
			Node* copy = cur->next;
			if (cur->random != NULL)
				copy->random = cur->random->next;
			比特科技
			else
				copy->random = NULL;
			cur = copy->next;
		}
		// 3.解拷贝节点，链接拷贝节点
		Node* copyHead = NULL, *copyTail = NULL;
		cur = head;
		while (cur)
		{
			Node* copy = cur->next;
			Node* next = copy->next;
			// copy解下来尾插
			if (copyTail == NULL)
			{
				copyHead = copyTail = copy;
			}
			else
			{
				copyTail->next = copy;
				copyTail = copy;
			}
			cur->next = next;
			cur = next;
		}
		return copyHead;
	}
};
12. 对链表进行插入排序。OJ链表
/*
解题思路：
此题可以先创建一个排序空链表，对于每一个节点找到它在排序链表中的合适位置，然后进入插入操作
*/
typedef struct ListNode Node;
struct ListNode* insertionSortList(struct ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	//创建排序链表
	Node* sortHead = (Node*)malloc(sizeof(Node));
	//头节点首先插入
	sortHead->next = head;
	head = head->next;
	sortHead->next->next = NULL;
	比特科技
		//插入剩余节点
		Node* cur = head;
	while (cur)
	{
		//首先保存next节点
		Node* next = cur->next;
		// 从排序链表的头开始，给待插入的节点找到一个合适的位置
		Node* sortPrev = sortHead;
		Node* sortCur = sortHead->next;

		while (sortCur)
		{
			if (cur->val > sortCur->val)
			{
				sortPrev = sortCur;
				sortCur = sortCur->next;
			}
			else
			{
				break;
			}
		}
		//在合适位置进行插入
		sortPrev->next = cur;
		cur->next = sortCur;
		cur = next;
	}
	Node* sortList = sortHead->next;
	free(sortHead);
	return sortList;
}