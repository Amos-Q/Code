#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>

template<class T>
struct binary_tree_node
{
	T _data;
	binary_tree_node<T>* _left;
	binary_tree_node<T>* _right;

	binary_tree_node(const T& x)
		:_data(x)
		, _left(NULL)
		, _right(NULL)
	{}
};

template<class T> class binary_tree
{
	typedef binary_tree_node<T>node;
public:
	binary_tree(T* a, size_t n, const T&invalid)
	{
		size_t index = 0;
		_root = _create_tree(a, n, invalid, index);
	}
	node*copy_tree(node* root)
	{
		if (root == NULL)
		{
			return NULL;
		}
		node* new_root = new node(root->_data);
		new_root->_left = copy_tree(root->_left);
		new_root->_right = copy_tree(root->_right);

		return new_root;
	}
	binary_tree(const binary_tree<T>& t)
	{
		_root = copy_tree(t._root);
	}
	binary_tree<T>& operator=(binary_tree<T> t)
	{
		swap(_root, t._root);
		return *this;
	}
	~binary_tree()
	{
		destory(_root);
		_root = NULL;
	}
	void destory(node* root)
	{
		if (root == NULL)
			return;
		destory(root->_left);
		destory(root->_right);

		delete root;
	}
//创建一棵二叉树
	node* _create_tree(T*a, size_t n, const T& invalid, size_t& index)
	{
		node* root = NULL;
		if (a[index] != invalid)
		{
			root = new node(a[index]);
			root->_left = _create_tree(a, n, invalid, ++index);
			root->_right = _create_tree(a, n, invalid, ++index);
		}
		return root;
	}

	//前序遍历
	void prev_order()
	{
		_prev_order(_root);
		cout << endl;
	}
	void _prev_order(node*root)
	{
		if (root == NULL)
			return;
		cout << root->_data << "  ";
		_prev_order(root->_left);
		_prev_order(root->_right);
	}

	//非递归的前序遍历
	void prev_order_no_r()
	{
		node* cur = _root;
		stack<node*>s;
		while (cur || !s.empty())
		{
			while (cur)
			{
				cout << cur->_data << "  ";
				s.push(cur);
				cur = cur->_left;
			}
			node* top = s.top();
			s.pop();
			//子问题
			cur = top->_right;
		}
		cout << endl;
	}

	//中序遍历
	void in_order()
	{
		_in_order(_root);
		cout << endl;
	}
	void _in_order(node* root)
	{
		//中序遍历：左子树->根节点->右子树
		if (root == NULL)return;

		_in_order(root->_left);
		cout << root->_data << "  ";
		_in_order(root->_right);
	}
	//非递归的中序遍历
	void in_order_no_r()
	{
		node* cur = _root;
		stack<node*>s;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}

			node* top = s.top();
			cout << top->_data << "  ";
			s.pop();

			cur = top->_right;
		}
		cout << endl;
	}

	//非递归的后序遍历
	void post_order_no_r()
	{
		node* cur = _root;
		node*prev = NULL;
		stack<node*>s;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}
			node* top = s.top();
			if (top->_right == NULL || top->_right == prev)
			{
				cout << top->_data << "  ";
				s.pop();
				prev = top;
			}
			else
			{
				cur = top->_right;
			}
		}
		cout << endl;
	}

	//求节点个数
	int size()
	{
		size_t size = 0;
		_size(_root, size);
		return size;
	}
	void _size(node* root, size_t&size)
	{
		if (root == NULL)return;
		_size(root->_left, size);
		++size;
		_size(root->_right, size);
	}

	//求叶子节点的个数
	size_t leaf_size()
	{
		return _leaf_size(_root);
	}
	size_t _leaf_size(node*root)
	{
		//二叉树为空的时候
		if (root == NULL)return 0;
		//二叉树只有一个节点的时候
		if (root->_left == NULL && root->_right == NULL)
			return 1;
		//叶子节点=左子树叶子节点+右子树叶子节点
		return _leaf_size(root->_left) + _leaf_size(root->_right);
	}
	


	//求二叉树的高度
	size_t height()
	{
		return _height(_root);
	}
	size_t _height(node* root)
	{
		//二叉树为空的时候，高度为0
		if (root == NULL)return 0;
		size_t left_height = _height(root->_left);
		size_t right_height = _height(root->_right);
		//二叉树非空时，高度为左子树和右子树中较高的一个
		return left_height > right_height ? left_height + 1 : right_height + 1;
	}
	//求第K层的节点个数：
	size_t get_k_level(size_t k)
	{
		return _get_k_level(_root, k);
	}
	size_t _get_k_level(node* root, size_t k)
	{
		//空树返回0
		if (root == NULL)return 0;
		//第一层只有一个节点
		if (k == 1)return 1;
		//注意这里为什么是k-1?  如果你需要求第二层的节点个数，则需要用第一层的根节点访问他的左子树和右子树的第一层的个数
		return _get_k_level(root->_left, k - 1) + _get_k_level(root->_right, k - 1);
	}

	//层序遍历
	void level_order()
	{
		queue<node *>q;
		if (_root)
			q.push(_root);
		while (!q.empty())
		{
			node* front = q.front();
			cout << front->_data << "  ";
			q.pop();
			if (front->_left)
				q.push(front->_left);
			if (front->_right)
				q.push(front->_right);
		}
		cout << endl;
	}
	//判断二叉树是否为完全二叉树
	bool is_complete_tree()
	{
		queue<node*>q;
		if (_root)
			q.push(_root);
		bool flag = true;
		while (!q.empty())
		{
			node* front = q.front();
			q.pop();
			if (front->_left)
			{
				if (flag == false)
					return false;
				q.push(front->_left);
			}
			else
			{
				flag = false;
			}
			if (front->_right)
			{
				if (flag == false)
					return false;
				q.push(front->_right);
			}
			else
				flag = false;
		}
		return true;
	}

	//查找一个节点是否在一棵二叉树中
	node* find(const T&x)
	{
		return _find(_root, x);
	}
	node* _find(node*root, const T& x)
	{
		if (root == NULL)return NULL;
		if (root->_data == x)return root;

		node* ret1 = _find(root->_left, x);
		if (ret1)return ret1;

		node* ret2 = _find(root->_data, x);
		if (ret2)return ret2;

		return NULL;
	}

protected:
	node *_root;
};


//测试部分
void test_binary_tree()
{
	int array[] = { 1, 2, 3, '#', '#', 4, 40, '#', '#', '#', 5, 6, '#', '#', '#' };
	binary_tree<int> t(array, sizeof(array) / sizeof(int), '#');
	t.prev_order();
	t.prev_order_no_r();
	t.in_order();
	t.in_order_no_r();
	t.post_order_no_r();
	t.level_order();

	cout << "size:" << t.size() << endl;
	cout << "leaf_size:" << t.leaf_size() << endl;
	cout << "height:" << t.height() << endl;
	cout << "is_complete_tree:" << t.is_complete_tree() << endl;
	cout << "k_level_size:" << t.get_k_level(4) << endl;

	binary_tree<int> t1(t);
	t1.prev_order_no_r();
}

int main(void)
{
	test_binary_tree();
	system("pause");
}
