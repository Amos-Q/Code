#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int Output(vector<int>v, int k)
//{
//	sort(v.begin(), v.end());
//	int sum = v[0];
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (sum != v[i])
//		{
//			sum = v[i];
//			k--;
//		}
//		if (k == 0)
//			return v[i];
//	}
//}
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		vector<int> v;
//		int x = 0;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> x;
//			v.push_back(x);
//		}
//		int k = 0;
//		cin >> k;
//		cout << Output(v, k - 1) << endl;
//	}
//}


#include <iostream>
#include <vector>
using namespace std;

int sum = 0;

bool Have(vector<int> v, vector<vector<int>> vv)
{
	for (int i = 0; i < vv.size(); i++)
	{
		if (vv[i] == v)
			return true;
	}
	return false;
}

void SetLRU1(vector<int> v, vector<int> &lru, vector<vector<int>> vv)
{
	for (int i = 0; i < vv.size(); i++)
	{
		if (vv[i] == v)
			lru[i] = sum++;
	}
}

void SetLRU2(int x, vector<int> &lru, vector<vector<int>> vv)
{
	for (int i = 0; i < vv.size(); i++)
	{
		if (x == vv[i][0])
			lru[i] = sum++;
	}
}

int LRU(vector<int> &lru)
{
	int min = 999999;
	int minadd = 0;
	for (int i = 0; i < lru.size(); i++)
	{
		if (lru[i] < min)
		{
			min = lru[i];
			minadd = i;
		}
	}
	lru[minadd] = sum++;
	return minadd;
}

void Find(vector<vector<int>> vv, int x)
{
	int flag = 0;
	for (int j = 0; j < vv.size(); j++)
	{
		if (x == vv[j][0])
		{
			flag = 1;
			cout << vv[j][1] << endl;
		}
	}
	if (flag == 0)
		cout << -1 << endl;
}

int main()
{
	int N, K;
	while (cin >> N >> K)
	{
		vector<vector<int>> vv;
		vector<int> lru(K);
		int j = 0;
		for (int i = 0; i < N; i++)
		{
			int opt, x, y;
			vector<int> v;
			cin >> opt;
			if (opt == 1)
			{
				cin >> x >> y;
				v.push_back(x);
				v.push_back(y);
				if (Have(v, vv))
					SetLRU1(v, lru, vv);
				else
				{
					if (vv.size() == K)
					{
						vv[LRU(lru)] = v;
					}
					else
					{
						vv.push_back(v);
						SetLRU1(v, lru, vv);
					}
				}
			}
			if (opt == 2)
			{
				cin >> x;
				Find(vv, x);
				SetLRU2(x, lru, vv);
			}
		}
	}
}