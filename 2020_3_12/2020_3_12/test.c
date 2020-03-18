#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"
#include "Queue.h"


void testTree()
{
	char arr[] = "ABD##E#H##CF##G##";
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	BTNode* b = BinaryTreeCreate(arr, sz, &i);
	printf("������\n");
	BinaryTreePrevOrder(b);
	printf("\n");
	BinaryTreeInOrder(b);
	printf("\n");
	BinaryTreePostOrder(b);
	printf("\n");
	printf("������: ");
	int num = BinaryTreeSize(b);
	printf("%d\n", num);

	printf("Ҷ�ӽ�����: ");
	int n = BinaryTreeLeafSize(b);
	printf("%d\n", n);


	printf("��K�������: ");
	int m = BinaryTreeLevelKSize(b, 4);
	printf("%d\n", m);

	BTNode* ret = BinaryTreeFind(b, 'C');
	printf("%c\n", ret->_data);

	BinaryTreeLevelOrder(b);
	printf("\n");


	printf("�Ƿ�Ϊ��ȫ������(��Ϊ1����Ϊ0):  ");
	printf("%d\n", BinaryTreeComplete(b));
	printf("\n");


	BinaryTreeDestory(b);
}
int main()
{
	testTree();
	system("pause");
	return 0;
}
