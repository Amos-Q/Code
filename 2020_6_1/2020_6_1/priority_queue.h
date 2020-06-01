#pragma once
#include <vector>

namespace bit
{
	// 仿函数  函数对象
	template<class T>
	struct less{
		bool operator()(const T& x1, const T& x2){return x1 < x2;}
	};

	template<class T>
	struct greater{
		bool operator()(const T& x1, const T& x2){return x1 > x2;}
	};

	// 默认是大堆
	template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		void AdjustUp(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[child] > _con[parent])
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void AdjustDwon(int root)
		{
			int parent = root;
			int child = parent * 2 + 1;

			Compare com;
			while (child < _con.size())
			{
				// 选出左右孩子中大的那一个
				//if (child+1 < _con.size() && _con[child+1] > _con[child])
				if (child+1 < _con.size() && com(_con[child], _con[child+1]))
				{
					++child;
				}

				//if (_con[child] > _con[parent])
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}


		void push(const T& x)
		{
			// O(logN)
			_con.push_back(x);
			AdjustUp(_con.size() - 1);
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();

			// O(logN)
			AdjustDwon(0);
		}

		T& top()
		{
			return _con[0];
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};

	void test_priority_queue()
	{
		//priority_queue<int> pq;
		priority_queue<int, vector<int>, greater<int>> pq;
		pq.push(3);
		pq.push(1);
		pq.push(9);
		pq.push(4);
		pq.push(2);

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
}
