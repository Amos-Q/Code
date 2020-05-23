#define _CRT_SECURE_NO_WARNINGS 1
/*�����Ԫ�������ڵ�ṹ*/
typedef struct _BSTreeNode {
	int data;
	struct _BSTreeNode *left;
	struct _BSTreeNode *right;
}BSTreeNode;

/*ת���Ӷ���������������˫������*/
BSTreeNode* ConvertNode(BSTreeNode *pNode, bool asRight)
{
	if (pNode == NUll)
	{
		return;
	}
	//����������
	BSTreeNode *pleft = NULL;
	//����������
	BSTreeNode *pright = NULL;
	//1. ����������������ֵ����ǰnode
	if (pNode->left)
	{
		pleft = ConvertNode(pNode->left, false);
	}
	if (pleft)
	{
		pleft->right = pNode;
		pNode->left = pleft;
	}
	//2. ���������������Сֵ����ǰnode
	if (pNode->right)
	{
		pright = ConvertNode(pNode->right, true);
	}
	if (pright)
	{
		pright->left = pNode;
		pNode->right = pright;
	}
	BSTreeNode *p_temp = pNode;
	if (asRight)
	{
		while (p_temp->left)
		{
			p_temp = p_temp->left;
		}
	}
	else
	{
		while (p_temp->right)
		{
			p_temp = p_temp->right;
		}
	}
	return p_temp;
}

/*ת������������������˫������*/
BSTreeNode* Convert(BSTreeNode *p_headoftree)
{
	return ConvertNode(p_headoftree, true);
}

void push(const T& data)
{
	s1.push(data);
}
void pop()
{
	if (s1.empty() && s2.empty())
	{
		cout << "The queue is empty";
	}
	if (!s2.empty())
	{
		s2.pop();
	}
	else
	{
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}
}