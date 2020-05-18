#pragma once

namespace fxd
{
	//template<class T>
	//class vector
	//{
	//public:

	//private:
	//	T* _a;
	//	size_t _size;
	//	size_t _capacity;
	//};
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T)*sz);
					delete[] _start;
				}
				_start = tmp;
				_finish = tmp + sz;
				_endofstorage = tmp + n;
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 2 : capacity()* 2;
				reserve(newcapacity);
			}

			*_finish = x;
			++_finish;
		}

		void pop_back();
		void insert(iterator pos, const T& x);
		iterator erase(iterator pos);


		size_t size()
		{
			return _finish - _start;
		}

		size_t capacity()
		{
			return _endofstorage - _start;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		cout << v.size() << endl;
		cout << v.capacity() << endl;

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

}

// 迭代器失效
void test_vector8()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	vector<int>::iterator it = v.begin();

	v.push_back(6);
	v.push_back(7);


	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void test_vector9()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it); // erase会返回删除的it的下一个位置的迭代器
		}
		else
		{
			++it;
		}
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

#include "vector.h"

int main()
{
	//test_vector9();
	fxd::test_vector1();

	return 0;
}