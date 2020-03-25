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