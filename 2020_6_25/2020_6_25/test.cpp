#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <algorithm>
//#include <string>
//using namespace std;
//
//void Reverse(string s)
//{
//	reverse(s.begin(),s.end());
//	cout << s;
//}
//
//int main()
//{
//	string str;
//	cin >> str;
//	Reverse(str);
//	system("pause");
//	return 0;
//}

//#include <string> 
//#include <iostream> 
//#include <vector> 
//using namespace std;
//void Repeat(string s1, string s2)
//{
//	int max = 0;
//	int begin = 0; int i = 0;
//	int j = 0;
//	vector<vector<int>> vv;
//	for (int i = 0; i < s1.size(); i++)
//	{
//		for (int j = 0; j < s2.size(); j++)
//		{
//			if (s1[i] == s2[j] || s1[i] == s2[j] + 32 || s1[i] + 32 == s2[j])
//			{
//				vector<int> v;
//				v.push_back(i);
//				v.push_back(j);
//				int len = 0;
//				while (i < s1.size() && j < s2.size() && s1[i] == s2[j])
//				{
//					len++;
//					i++;
//					j++;
//				}
//				v.push_back(len);
//				vv.push_back(v);
//				i = v[0]; j = v[1];
//			}
//		}
//	}
//	for (int i = 0; i < vv.size(); i++)
//	{
//		if (vv[i][2] > max)
//		{
//			max = vv[i][2];
//		}
//	}
//	cout << max << endl;
//}
//
//int main()
//{
//	string str1;
//	string str2;
//	while (cin >> str1 >> str2)
//		Repeat(str1, str2);
//	system("pause");
//	return 0;
//}


#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Now(int n, string s)
{
	vector<int> v;
	for (int i = 1; i <= n; i++)
		v.push_back(i);
	int now = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'U')
		{
			if (now == 0)
			{
				now = v.size() - 1;
			}
			else
				now--;
		}
		else
		{
			if (now == v.size() - 1)
			{
				now = 0;
			}
			else
				now++;
		}
	}
	int flag = now;
	if (flag % 10 > 4 || flag % n > 4)
	{
		for (int i = now - 3; i <= now; i++)
		{
			cout << v[i] << ' ';
		}
		cout << endl;
	}
	else
	{
		flag = flag / 10;
		flag *= 10;
		for (int i = flag - 1; i < flag + 4; i++)
		{
			cout << v[i] << ' ';
		}
		cout << endl;
	}
	cout << v[now] << endl;
}

int main()
{
	int N = 0;
	string str;
	while(cin >> N >> str)
		Now(N, str);
	system("pause");
	return 0;
}