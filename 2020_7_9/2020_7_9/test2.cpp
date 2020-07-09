#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//string List(vector<string> v)
//{
//	string s;
//	string judge;
//	for (int i = 0; i < v.size(); i++)
//	{
//		int flag = 0;
//		judge = v[i];
//		for (int j = 0; j < judge.size(); j++)
//		{
//			if (judge[j] == ' ' || judge[j] == ',')
//				flag = 1;
//		}
//		if (i != 0)
//		{
//			s += ',';
//			s += ' ';
//		}
//		if (flag == 1)
//			s += '"';
//		s += judge;
//		if (flag == 1)
//			s += '"';
//
//	}
//	return s;
//}
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		vector<string> v;
//		cin.get();
//		for (int i = 0; i < n; i++)
//		{
//			string str;
//			getline(cin, str);
//			v.push_back(str);
//		}
//		cout << List(v) << endl;
//	}
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//void Sum(int n)
//{
//	string s;
//	s += '1';
//	for (int i = 0; i < n; i++)
//	{
//		int flag = 0;
//		for (int j = 0; j < s.size(); j++)
//		{
//			int sum = 0;
//			sum = (s[j] - '0') * 2 + flag;
//			flag = 0;
//			s[j] = (sum % 10) + '0';
//			if (sum > 9)
//				flag = 1;
//		}
//		if (flag == 1)
//			s += '1';
//	}
//	for (int i = 0; i < s.size(); i++)
//	{
//		cout << s[i];
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		Sum(n - 1);
//	}
//}

#include <iostream>
#include <vector>
using namespace std;

long long Sum(int n)
{
	vector<long long> v;
	v.push_back(1);
	v.push_back(2);
	v.resize(n);
	for (int i = 2; i < v.size(); i++)
	{
		v[i] = v[i - 1] + v[i - 2];
	}
	return v[n - 1];
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		cout << Sum(n) << endl;
	}
}