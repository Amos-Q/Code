#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include <vector>
//using namespace std;
//
//void Sum(int l, vector<vector<int>> vv)
//{
//	vector<int> v(l,0);
//	int begin, end;
//	for (int i = 0; i < vv.size(); i++)
//	{
//		begin = vv[i][0];
//		end = vv[i][1];
//		for (int len = begin; len <= end; len++)
//		{
//			v[len - 1]++;
//		}
//	}
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i];
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int T, L, n;
//	while (cin >> T)
//	{
//		for (int i = 0; i < T; i++)
//		{
//			cin >> L >> n;
//			vector<vector<int>> vv(n, vector<int>(2));
//			for (int x = 0; x < n; x++)
//			{
//				for (int y = 0; y < 2; y++)
//				{
//					cin >> vv[x][y];
//				}
//			}
//			Sum(L, vv);
//		}
//	}
//}




#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Judge(vector<int> p,vector<int> q)
{
	vector<int> out;
	vector<int> beginq(q);
	vector<int> beginp(p);
	vector<int> end;
	sort(q.begin(), q.end());
	sort(p.begin(), p.end());
	for (int i = 0; i < p.size(); i++)
	{
		int flag = -1;
		for (int j = 0; j < q.size(); j++)
		{
			if (p[i] <= q[j])
			{
				flag = q[j];
				q[j] = -1;
				break;
			}
		}
		out.push_back(flag);
	}
	for (int i = 0; i < out.size(); i++)
	{
		if (out[i] != -1)
		{
			for (int j = 0; j < beginq.size(); j++)
			{
				if (out[i] == beginq[j])
				{
					beginq[j] = -1;
					end.push_back(j + 1);
					break;
				}
			}
		}
		else
			end.push_back(-1);
	}
	for (int i = 0; i < beginp.size(); i++)
	{
		for (int j = 0; j < p.size(); j++)
		{
			if (beginp[i] == p[j])
			{
				p[j] = -1;
				cout << end[j] << ' ';
				break;
			}
		}
	}
	//for (int i = 0; i < end.size(); i++)
	//{
	//	cout << end[i] << ' ';
	//}
	cout << endl;
}

int main()
{
	int T;
	while (cin >> T)
	{
		for (int i = 0; i < T; i++)
		{
			int n, m;
			cin >> n >> m;
			vector<int> p(n);
			vector<int> q(m);
			for (int x = 0; x < n; x++)
			{
				cin >> p[x];
			}
			for (int x = 0; x < m; x++)
			{
				cin >> q[x];

			}
			Judge(p, q);
		}
	}
}