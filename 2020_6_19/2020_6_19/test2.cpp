#define _CRT_SECURE_NO_WARNINGS 1

void RotateL(Node* parent)
{
	Node* subL = parent->left;
	Node* subLR = subL->right;

	parent->left = subLR;
	if (subLR)
		subLR->_parent = parent;

	subL->right = parent;
	Node* ppNode = parent->_parent;
	parent->_parent = subL;

	// 1��ԭ��parent��������ĸ�������subR�Ǹ�
	// 2��parentΪ������ֻ���������е��������ı����ӹ�ϵ����ôsubRҪ��������λ��
	if (_root == parent)
	{
		_root = subL;
		subL->_parent = nullptr;
	}
	else
	{
		if (ppNode->_left == parent)
			ppNode->_left = subL;
		else
			ppNode->_right = subL;

		subL ->_parent = ppNode;
	}

	parent->_bf = subL->_bf = 0;
}