#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"

int main()
{
	BinTree T = CreateBinTree();//����һ��Ԫ�ؾͻ�һ�γ������ͻ��������źã�����һ����ȫ������
	SequenceTraversal(T);
	return 0;
}