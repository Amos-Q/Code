#define _CRT_SECURE_NO_WARNINGS 1
//构造BST
BST(T value) :root(NULL), RefValue(value)
{
	T x;
	cin >> x;
	while (x != RefValue)
	{
		Insert(x, root);    //新建一个结点，调用Insert插入到树中
		cin >> x;
	}
}
//以ptr为根的二叉搜索树中插入所含值为e1的结点
bool Insert(const T& e1, BSTNode<T>* &ptr)    //第二个参数是指针的引用
{
	if (ptr == NULL)
	{
		ptr = new BSTNode<T>(e1);    //构造新结点
		if (ptr == NULL)
		{
			cout << "Memory allocation failed!" << endl;
			exit(1);
		}
		return true;
	}
	else if (e1 < ptr->data)    //小于，插入左子树
	{
		Insert(e1, ptr->left);
	}
	else if (e1 > ptr->data)    //大于，插入右子树
	{
		Insert(e1, ptr->right);
	}
	else    //x已在树中，不插入
	{
		return false;
	}
}//在ptr为根的二叉搜索树中搜索含x的结点。若找到，返回该结点地址，否则返回NULL
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
//以ptr为根的二叉搜索树中删除含x的结点
bool Remove(T x, BSTNode<T>* &ptr)
{
	BSTNode<T>* temp;
	if (ptr != NULL) //ptr不为空进行操作
	{
		if (x < ptr->data)
		{
			Remove(x, ptr->left);
		}
		else if (x > ptr->data)
		{
			Remove(x, ptr->right);
		}
		//找到了要删除的结点
		//1.要删除的结点ptr同时有左右子树
		else if (ptr->left != NULL && ptr->right != NULL)
		{
			temp = ptr->right;    //在右子树中搜索中序下的第一个结点
			while (temp->left != NULL)
			{
				temp = temp->left;
			}
			//用右子树中序下的第一个结点的值填充要删除的结点
			ptr->data = temp->data;
			//然后再新填充值ptr的右子树中删除temp的data值
			Remove(ptr->data, ptr->right);
		}
		else //不同时有左右子树
		{
			temp = ptr;        //temp记住要删除的ptr结点
			if (ptr->left == NULL) //只有右子树
			{
				ptr = ptr->right;
			}
			else    //只有左子树
			{
				ptr = ptr->left;
			}
			delete temp;    //删除结点
			temp = NULL;
			return true;
		}
	}
	else //ptr为空直接返回false
	{
		return false;
	}
}

//销毁以root为根的二叉树搜索树函数
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