#define _CRT_SECURE_NO_WARNINGS 1
//#include <unordered_map>
//#include <iostream>
//using namespace std;
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//void LRU(vector<vector<int>> vv, int x)
//{
//	int flag = 0;
//	for (int j = 0; j < vv.size(); j++)
//	{
//		if (x == vv[j][0])
//		{
//			flag = 1;
//			cout << vv[j][1] << endl;
//		}
//	}
//	if (flag == 0)
//		cout << -1 << endl;
//}
//
//int main()
//{
//	int N, K;
//	while (cin >> N >> K)
//	{
//
//		vector<int, unordered_map<int, int>> vm;
//		int j = 0;
//		int flag = 0;
//		for (int i = 0; i < N; i++)
//		{
//			int opt, x, y;
//			vector<int> v;
//			cin >> opt;
//			if (opt == 1)
//			{
//				cin >> x >> y;
//				m[x] = y;
//				if (m.size() == K)
//
//				else
//			}
//			if (opt == 2)
//			{
//				cin >> x;
//				LRU(vv, x);
//			}
//			j++;
//			if (j == K)
//			{
//				j = 0;
//				flag = 1;
//			}
//		}
//	}
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//int Judge(string s1, string s2)
//{
//	int len = 0;
//	int i = 0;
//	int j = 0;
//	int t = 0;
//	while (i < s1.size() && j < s2.size())
//	{
//		if (s1[i] == s2[j])
//		{
//			i++;
//			j++;
//			len++;
//			t = 0;
//		}
//		else
//		{
//			if (s1[i] == s2[j + 1])
//			{
//				j += 2;
//				i++;
//				len++;
//				t = 0;
//			}
//			else if (s2[j] == '?' && t < 3)
//			{
//				i++;
//				t++;
//				len++;
//			}
//			else
//				break;
//		}
//		if (len != 0)
//			return len;
//		else
//			return -1;
//	}
//}
//
//int main()
//{
//	string s1, s2;
//	while (cin >> s1 >> s2)
//	{
//		cout << Judge(s1, s2) << endl;
//	}
//}

#include <iostream>
#include <map>
#include <vector>
using namespace std;

//bool Same(vector<vector<int>> vv, int i, int j)
//{
//	int x = 0;
//	while (x < vv[i].size())
//	{
//		if (vv[i][x] == vv[j][x])
//		{
//			x++;
//		}
//		else
//			break;
//	}
//	if (x == vv[i].size())
//		return true;
//	else
//		return false;
//}
//
//void Judge(vector<vector<int>> vv, vector<int> n)
//{
//	map<int, int> m;
//	for (int i = 0; i < n.size() - 1; i++)
//	{
//		for (int j = i + 1; j < n.size(); j++)
//		{
//			if (n[i] == n[j])
//			{
//				if (Same(vv, i, j))
//					m[n[i]]++;
//			}
//		}
//	}
//	for (auto& e : m)
//		cout << e.second << ' ' << e.first << endl;
//}
//
//int main()
//{
//	int N;
//	while (cin >> N)
//	{
//		vector<vector<int>> vv;
//		vector<int> n;
//		while (N--)
//		{
//			int num;
//			cin >> num;
//			vector<int> v(num);
//			n.push_back(num);
//			for (int i = 0; i < num; i++)
//			{
//				cin >> v[i];
//
//			}
//			vv.push_back(v);
//		}
//		Judge(vv, n);
//	}
//}
int main(void) {
http://www.taobao.com 
	cout << "welcome to taobao" << endl; 
	return 0;
}