#define _CRT_SECURE_NO_WARNINGS 1
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		if (pHead == NULL)
			return NULL;

		struct ListNode* lessHead, *lessTail, *greaterHead, *greaterTail;
		//���������ͷ
		lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
		greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
		struct ListNode* cur = pHead;
		while (cur)
		{
			//С��x��β�嵽lessTail
			if (cur->val < x)
			{
				lessTail->next = cur;
				lessTail = lessTail->next;
			}
			//���ڵ���x��β�嵽greaterTail
			else
			{
				greaterTail->next = cur;
				greaterTail = greaterTail->next;
			}
			���ؿƼ�
				cur = cur->next;
		}
		//������������
		lessTail->next = greaterHead->next;
		greaterTail->next = NULL;
		//��ȡ��ͷ
		pHead = lessHead->next;
		free(lessHead);
		free(greaterHead);

		return pHead;
	}
};
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		if (A == NULL || A->next == NULL)
			return true;
		ListNode* slow, *fast, *prev, *cur, *nxt;
		slow = fast = A;
		//�ҵ��м�ڵ�
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		prev = NULL;
		//��벿������
		cur = slow;
		while (cur)
		{
			nxt = cur->next;
			cur->next = prev;
			prev = cur;
			cur = nxt;
		}
		//���ȶ�
		while (A && prev)
		{
			if (A->val != prev->val)
				return false;
			A = A->next;
			prev = prev->next;
		}
		���ؿƼ�
			return true;
	}
};
/*
����Ҳ�����Ȱ������е�Ԫ��ֵȫ�����浽�����У�Ȼ�����ж������Ƿ�Ϊ���ġ�������ʹ�����ֽⷨ����Ϊ���û��
����������󳤶ȣ�����ͬ�˽ⷨ
*/
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