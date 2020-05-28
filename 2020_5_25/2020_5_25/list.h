#pragma once

namespace fxd
{
	template<class T>
	struct __list_node
	{
		__list_node<T>* _next;
		__list_node<T>* _prev;
		T _data;

		__list_node(const T& x = T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	// __list_iterator<T, T&, T*>   -> iterator
	// __list_iterator<T, const T&, const T*>   -> const_iterator
	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef __list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> Self;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		// *it
		Ref operator*()
		{
			return _node->_data;
		}

		// it->
		Ptr operator->()
		{
			return &_node->_data;
		}

		// ++it;
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		// it++
		Self operator++(int)
		{
			Self tmp(*this);
			//_node = _node->_next;
			++(*this);

			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			Self tmp(*this);
			//_node = _node->_prev;
			--(*this);

			return tmp;
		}

		// it != end()
		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}

		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
	};

		template<class T>
		class list
		{
			typedef __list_node<T> Node;
		public:
			typedef __list_iterator<T, T&, T*> iterator;
			// 思考const_iterator是如何实现，提示：可以去分析一下原代码
			typedef __list_iterator<T, const T&, const T*> const_iterator;

		iterator begin(){
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		// 带头双向循环链表
		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		// lt2(lt1)
		list(const list<T>& lt)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			//const_iterator it = lt.begin();
			//while (it != lt.end())
			//{
			//	//this->pop_back(*it);
			//	push_back(*it);
			//	++it;
			//}

			for (auto e : lt)
				push_back(e);
		}

		// lt1 = lt3
		// lt1 = lt1
	/*	list<T>& operator=(const list<T>& lt)
		{
			if (this != &lt)
			{
				clear();
				for (auto e : lt)
					push_back(e);
			}

			return *this;
		}*/

		// lt1 = lt3
		list<T>& operator=(list<T> lt)
		{
			swap(_head, lt._head);
			return *this;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				erase(it++);
			}
		}

		void push_back(const T& x)
		{
			/*Node* tail = _head->_prev;
			Node* newnode = new Node(x);
			
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;*/
			insert(end(), x);
		}

		void pop_back()
		{
			//erase(iterator(_head->_prev));
			erase(--end());
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			// prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}

		void erase(iterator pos)
		{
			assert(pos != end());

			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			delete cur;

			prev->_next = next;
			next->_prev = prev;
		}

	private:
		Node* _head;
	};

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++ it;
		}
		cout << endl;
	}

	struct Date
	{
		int _year = 0;
		int _month = 1;
		int _day = 1;
	};

	void test_list2()
	{
		int* p1 = new int;
		*p1;
		Date* p2 = new Date;
		*p2;
		p2->_year;

		list<Date> lt;
		lt.push_back(Date());
		lt.push_back(Date());

		list<Date>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << *it << " ";
			cout << it->_year << "-" << it->_month << "-" << it->_day << endl; // 更喜欢这么用
			cout << (*it)._year << "-" << (*it)._month << "-" << (*it)._day << endl;

			++it;
		}
		cout << endl;
	}

	void print_list(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			//*it = 1;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		print_list(lt);

		lt.pop_back();
		lt.pop_front();
		print_list(lt);

		lt.clear();
		lt.push_back(10);
	}

	void test_list4()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);

		list<int> lt2(lt1);
		print_list(lt2);

		list<int> lt3;
		lt3.push_back(10);
		lt3.push_back(20);
		lt3.push_back(30);
		lt3.push_back(40);
		lt1 = lt3;
		print_list(lt1);
	}
}