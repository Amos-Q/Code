#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		int size = 0;
//		int  residue = 0;
//		for (int i = 0; i < n; i++)
//		{
//			string id, operate;
//			cin >> id >> operate;
//			if (operate == "connect")
//			{
//				if (size == residue)
//				{
//					size++;
//					residue++;
//				}
//				else if (size > residue)
//				{
//					residue++;
//				}
//			}
//			else if (operate == "disconnect")
//			{
//				residue--;
//			}
//		}
//		cout << size << endl;
//	}
//}

//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//void Order(vector<string> v)
//{
//	sort(v.begin(), v.end());
//	vector<string> o;
//	string s;
//	int flag = 0;
//	for (int i = 0; i < v.size(); i++)
//	{
//		string s;
//		int flag = 0;
//		int j = 0;
//		while (j < v[i].size())
//		{
//			s += '/';
//			j++;
//			while (v[i][j] != '/' && j < v[i].size())
//			{
//				s += v[i][j];
//				j++;
//			}
//			for (int os = 0; os < o.size(); os++)
//			{
//				if (o[os] == s)
//				{
//					o[os] = v[i];
//					flag = 1;
//				}
//			}
//			if (flag == 1)
//				break;
//		}
//		if (flag == 0)
//			o.push_back(v[i]);
//		for (int i = 0; i < o.size(); i++)
//		{
//			cout << "mkdir -p " << o[i] << endl;
//		}
//		cout << endl;
//	}
//}
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		vector<string> v;
//		string str;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> str;
//			v.push_back(str);
//		}
//		Order(v);
//	}
//}

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> list(n);
		vector<bool> flag(n, true);
		for (int i = 0; i < n; ++i) cin >> list[i];
		sort(list.begin(), list.end());

		for (int i = 0; i < list.size() - 1; ++i)
		{
			// 1、两串相同
			// 2、前串是后串的子串，而且后串后一位是 '/'
			if (list[i] == list[i + 1]) flag[i] = false;
			else if (list[i].size() < list[i + 1].size() && \
				list[i] == list[i + 1].substr(0, list[i].size()) && list[i + 1][list[i].size()] == '/')
				flag[i] = false;
		}

		for (int i = 0; i < list.size(); ++i)
			if (flag[i]) cout << "mkdir -p " << list[i] << endl;
		cout << endl;
	}
	return 0;
}