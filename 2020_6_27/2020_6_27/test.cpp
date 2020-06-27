#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int Max_divisor(int a,int b)
//{
//	int max = 0;
//	for (int i = 1; i <= a; i++)
//	{
//		if (a%i == 0 && b%i == 0)
//		{
//			if (i > max)
//				max = i;
//		}
//	}
//	return max;
//}
//
//void Pow(int n, int a)
//{
//	vector<int> v;
//	int b = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> b;
//		v.push_back(b);
//	}
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (a >= v[i])
//			a += v[i];
//		else
//			a += Max_divisor(a, v[i]);
//	}
//	cout << a << endl;
//}
//
//int main()
//{
//	int N = 0;
//	int a = 0;
//	while(cin >> N >> a)
//		Pow(N, a);
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

char Once(string s)
{
	vector<int> v;
	v.resize(77);
	for (int i = 0; i < s.size(); i++)
	{
		v[s[i] - 'A']++;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (v[s[i] - 'A'] == 1)
			return s[i];
	}
}

int main()
{
	string str;
	while (cin >> str)
		cout << Once(str);
	system("pause");
	return 0;
}