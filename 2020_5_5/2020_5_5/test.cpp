#define _CRT_SECURE_NO_WARNINGS 1
//����BST
BST(T value) :root(NULL), RefValue(value)
{
	T x;
	cin >> x;
	while (x != RefValue)
	{
		Insert(x, root);    //�½�һ����㣬����Insert���뵽����
		cin >> x;
	}
}
//��ptrΪ���Ķ����������в�������ֵΪe1�Ľ��
bool Insert(const T& e1, BSTNode<T>* &ptr)    //�ڶ���������ָ�������
{
	if (ptr == NULL)
	{
		ptr = new BSTNode<T>(e1);    //�����½��
		if (ptr == NULL)
		{
			cout << "Memory allocation failed!" << endl;
			exit(1);
		}
		return true;
	}
	else if (e1 < ptr->data)    //С�ڣ�����������
	{
		Insert(e1, ptr->left);
	}
	else if (e1 > ptr->data)    //���ڣ�����������
	{
		Insert(e1, ptr->right);
	}
	else    //x�������У�������
	{
		return false;
	}
}//��ptrΪ���Ķ�����������������x�Ľ�㡣���ҵ������ظý���ַ�����򷵻�NULL
BSTNode<T>* Search(T x, BSTNode<T>* ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	else if (x < ptr->data)
	{
		return Search(x, ptr->left);
	}
	else if (x > ptr->data)
	{
		return Search(x, ptr->right);
	}
	else
	{
		return ptr;
	}
}
//��ptrΪ���Ķ�����������ɾ����x�Ľ��
bool Remove(T x, BSTNode<T>* &ptr)
{
	BSTNode<T>* temp;
	if (ptr != NULL) //ptr��Ϊ�ս��в���
	{
		if (x < ptr->data)
		{
			Remove(x, ptr->left);
		}
		else if (x > ptr->data)
		{
			Remove(x, ptr->right);
		}
		//�ҵ���Ҫɾ���Ľ��
		//1.Ҫɾ���Ľ��ptrͬʱ����������
		else if (ptr->left != NULL && ptr->right != NULL)
		{
			temp = ptr->right;    //�������������������µĵ�һ�����
			while (temp->left != NULL)
			{
				temp = temp->left;
			}
			//�������������µĵ�һ������ֵ���Ҫɾ���Ľ��
			ptr->data = temp->data;
			//Ȼ���������ֵptr����������ɾ��temp��dataֵ
			Remove(ptr->data, ptr->right);
		}
		else //��ͬʱ����������
		{
			temp = ptr;        //temp��סҪɾ����ptr���
			if (ptr->left == NULL) //ֻ��������
			{
				ptr = ptr->right;
			}
			else    //ֻ��������
			{
				ptr = ptr->left;
			}
			delete temp;    //ɾ�����
			temp = NULL;
			return true;
		}
	}
	else //ptrΪ��ֱ�ӷ���false
	{
		return false;
	}
}

//������rootΪ���Ķ���������������
void Destroy(BSTNode<T>* &root)
{
	if (root == NULL)
	{
		return;
	}
	if (root->left != NULL)
	{
		Destroy(root->left);
	}
	if (root->right != NULL)
	{
		Destroy(root->right);
	}
	delete root;
	root = NULL;
}