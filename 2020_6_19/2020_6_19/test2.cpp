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

	// 1、原来parent是这颗树的跟，现在subR是根
	// 2、parent为根的树只是整颗树中的子树，改变链接关系，那么subR要顶替他的位置
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