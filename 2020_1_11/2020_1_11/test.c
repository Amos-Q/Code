#define _CRT_SECURE_NO_WARNINGS 1
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		int a[900] = { 0 };
		ListNode* cur = A;
		int n = 0;
		//��������Ԫ��
		while (cur)
		{
			a[n++] = cur->val;
			cur = cur->next;
		}
		//�ж������Ƿ�Ϊ���Ľṹ
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
8.�������������ҳ����ǵĵ�һ��������㡣OJ����
/*
����˼·��
��������ȼ������������ĳ��ȣ��ó��������������ĳ��ȣ�Ȼ����������ͬʱ�ߣ�ֱ��������ͬ�Ľڵ㣬��Ϊ��
һ�������ڵ�
*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	int lenA = 0, lenB = 0;
	struct ListNode* curA = headA, *curB = headB;
	//����������
	while (curA) {
		++lenA;
		curA = curA->next;
	}

	while (curB) {
		���ؿƼ�
			++lenB;
		curB = curB->next;
	}

	int gap = abs(lenA - lenB);
	struct ListNode* longList = headA, *shortList = headB;
	if (lenA < lenB) {
		longList = headB;
		shortList = headA;
	}
	//�ó��������߼���
	while (gap--) {
		longList = longList->next;
	}
	//��������ͬʱ�ߣ�ֱ��������ͬ�Ľڵ�
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
9.����һ�������ж��������Ƿ��л��� OJ����
/*
����˼·��
�������ָ��fast,slow, �������ȷʵ�л���fastָ��һ�����ڻ���׷��slowָ�롣
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
