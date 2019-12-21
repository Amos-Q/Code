#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	Node* copyRandomList(Node* head) {
		// 1.拷贝节点，并插入原节点的后面
		Node* cur = head;
		while (cur)
		{
			Node* next = cur->next;
			Node* copyNode = (Node*)malloc(sizeof(Node));
			copyNode->val = cur->val;
			copyNode->next = NULL;
			copyNode->random = NULL;

			// cur copyNode next
			cur->next = copyNode;
			copyNode->next = next;

			cur = next;
		}

		// 2.置random
		cur = head;
		while (cur)
		{
			Node* copyNode = cur->next;
			if (cur->random)
				copyNode->random = cur->random->next;
			else
				copyNode->random = NULL;

			cur = cur->next->next;
		}

		//3.拆
		Node* copyHead = NULL, *copyTail = NULL;
		cur = head;
		while (cur)
		{
			Node* copyNode = cur->next;
			Node* next = copyNode->next;

			// cur copyNode next
			// copyNode尾插到拷贝链表
			if (copyTail == NULL)
			{
				copyHead = copyTail = copyNode;
			}
			else
			{
				copyTail->next = copyNode;
				copyTail = copyNode;
			}
			cur->next = next;

			cur = next;
		}

		return copyHead;
	}
};