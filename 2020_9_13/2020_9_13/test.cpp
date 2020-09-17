#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include<vector>
//#include <string>
//#include <algorithm>
//#include <map>
//using namespace std;
//
//int main()
//{
//	string s;
//	while (getline(cin, s))
//	{
//		vector<int> v;
//		map<int, int> m;
//		int c = 1;
//		int sum = 0;
//		for (int i = s.size()-1; i >= 0; i--)
//		{
//			if (s[i] == ' ')
//			{
//				v.push_back(sum);
//				c = 1;
//				sum = 0;
//			}
//			else
//			{
//				sum += (s[i] - '0') * c;
//				c *= 10;
//			}
//		}
//		v.push_back(sum);
//		for (int i = 0; i < v.size(); i++)
//		{
//			m[v[i]]++;
//		}
//		int flag = -1;
//		for (auto e : m)
//		{
//			if (e.second > (v.size() / 2))
//			{
//				flag = 0;
//				cout << e.first << endl;
//				break;
//			}
//		}
//		if (flag == -1)
//			cout << -1 << endl;
//	}
//}


//#include <iostream>
//#include <string>
//#include <unordered_set>
//using namespace std;
//
//int main()
//{
//	string s;
//	while (cin >> s)
//	{
//		unordered_set<char> st;
//		int r = -1;
//		int max = 0;
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (i != 0)
//			{
//				st.erase(s[i - 1]);
//			}
//			while (r + 1 < s.size() && !st.count(s[r + 1]))
//			{
//				st.insert(s[r + 1]);
//				r++;
//			}
//			if ((r - i + 1) > max)
//				max = r - i + 1;
//		}
//		cout << max << endl;
//	}
//}

//#include <iostream>
//#include<vector>
//#include <string>
//#include <algorithm>
//#include <unordered_map>
//using namespace std;
//
//int main()
//{
//	string s;
//	getline(cin, s);
//	vector<int> v;
//	unordered_map<int, int> m;
//	for (auto &e : s)
//	{
//		if (e != ' ')
//			v.push_back(e - '0');
//	}
//	for (int i = 0; i < v.size(); i++)
//	{
//		m[v[i]]++;
//	}
//	auto it = m.begin();
//	int num = -1;
//	while (it != m.end())
//	{
//		if (it->second > v.size() / 2)
//		{
//			num = it->first;
//			break;
//		}
//		it++;
//	}
//	cout << num << endl;
//	return 0;
//}


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	string s;
	while (getline(cin,s))
	{
		vector<int> v;
		for (auto &e : s)
		{
			if (e != ' ')
				v.push_back(e - '0');
		}
		sort(v.begin(), v.end());
		return 0;
	}
}