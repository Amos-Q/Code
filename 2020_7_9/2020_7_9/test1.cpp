#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//using namespace std;
//
//long long Sum(int f, int t)
//{
//	long long cout = 0;
//	vector<long long> v;
//	v.push_back(1);
//	v.push_back(1);
//	v.resize(t);
//	for (int i = 2; i < t; i++)
//		v[i] = v[i - 1] + v[i - 2];
//	for (int i = f - 1; i < t; i++)
//		cout += v[i];
//	return cout;
//}
//
//int main()
//{
//	int from, to;
//	while (cin >> from >> to)
//	{
//		cout << Sum(from, to) << endl;
//	}
//}

#include <iostream>
#include <string>
using namespace std;

int Sum(string s1, string s2)
{
	int sum = 0;
	for (int i = 0; i <= s1.size() - s2.size(); i++)
	{
		if (s1[i] == s2[0])
		{
			string tmp = s1.substr(i, s2.size());
			if (tmp == s2)
				sum++;
		}
		i += (s2.size() - 1);
	}
	return sum;
}

int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		cout << Sum(str1,str2) << endl;
	}
}