#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"
#include "Queue.h"


void testTree()
{
	char arr[] = "ABD##E#H##CF##G##";
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	BTNode* b = BinaryTreeCreate(arr, sz, &i);
	printf("遍历：\n");
	BinaryTreePrevOrder(b);
	printf("\n");
	BinaryTreeInOrder(b);
	printf("\n");
	BinaryTreePostOrder(b);
	printf("\n");
	printf("结点个数: ");
	int num = BinaryTreeSize(b);
	printf("%d\n", num);

	printf("叶子结点个数: ");
	int n = BinaryTreeLeafSize(b);
	printf("%d\n", n);


	printf("第K层结点个数: ");
	int m = BinaryTreeLevelKSize(b, 4);
	printf("%d\n", m);

	BTNode* ret = BinaryTreeFind(b, 'C');
	printf("%c\n", ret->_data);

	BinaryTreeLevelOrder(b);
	printf("\n");


	printf("是否为完全二叉树(是为1，否为0):  ");
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
