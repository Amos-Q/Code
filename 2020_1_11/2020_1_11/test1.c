#define _CRT_SECURE_NO_WARNINGS 1
typedef struct ListNode Node;
struct ListNode *detectCycle(struct ListNode *head) {
	Node* slow = head;
	Node* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		//�ߵ�������
		if (slow == fast)
		{
			// �󻷵���ڵ�
			Node* meet = slow;
			Node* start = head;
			���ؿƼ�
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
11.����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
Ҫ�󷵻�����������ȿ�����OJ����
/*
����˼·��
������Է��������У�
1.���������ÿһ���ڵ㣬�����Ľڵ������ӵ��������ڵ�ĺ���
2.�������ָ������ӣ������ڵ�����ָ��ָ�򱻿����ڵ����ָ�����һ��λ��
3.��������ѿ����������ԭ�����в�����
*/
class Solution {
public:
	Node* copyRandomList(Node* head) {
		// 1.�������������뵽ԭ�ڵ�ĺ���
		Node* cur = head;
		while (cur)
		{
			Node* next = cur->next;
			Node* copy = (Node*)malloc(sizeof(Node));
			copy->val = cur->val;
			// ����
			cur->next = copy;
			copy->next = next;
			// ����������
			cur = next;
		}
		// 2.�ÿ����ڵ��random
		cur = head;
		while (cur)
		{
			Node* copy = cur->next;
			if (cur->random != NULL)
				copy->random = cur->random->next;
			���ؿƼ�
			else
				copy->random = NULL;
			cur = copy->next;
		}
		// 3.�⿽���ڵ㣬���ӿ����ڵ�
		Node* copyHead = NULL, *copyTail = NULL;
		cur = head;
		while (cur)
		{
			Node* copy = cur->next;
			Node* next = copy->next;
			// copy������β��
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
12. ��������в�������OJ����
/*
����˼·��
��������ȴ���һ���������������ÿһ���ڵ��ҵ��������������еĺ���λ�ã�Ȼ�����������
*/
typedef struct ListNode Node;
struct ListNode* insertionSortList(struct ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	//������������
	Node* sortHead = (Node*)malloc(sizeof(Node));
	//ͷ�ڵ����Ȳ���
	sortHead->next = head;
	head = head->next;
	sortHead->next->next = NULL;
	���ؿƼ�
		//����ʣ��ڵ�
		Node* cur = head;
	while (cur)
	{
		//���ȱ���next�ڵ�
		Node* next = cur->next;
		// �����������ͷ��ʼ����������Ľڵ��ҵ�һ�����ʵ�λ��
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
		//�ں���λ�ý��в���
		sortPrev->next = cur;
		cur->next = sortCur;
		cur = next;
	}
	Node* sortList = sortHead->next;
	free(sortHead);
	return sortList;
}