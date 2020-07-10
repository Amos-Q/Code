#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include <vector>
//using namespace std;
//
//void Probability(int n)
//{
//	vector<long long>v1{ 0,0,1 }, v2{ 0,1,2 };
//	v1.resize(n+1);
//	v2.resize(n+1);
//	for (int i = 3; i <= n; i++)
//	{
//		v1[i] = (i - 1) * (v1[i - 2] + v1[i - 1]);
//		v2[i] = i * v2[i - 1];
//	}
//	printf("%.2f%c\n", 1.0*v1[n] / v2[n] * 100, '%');
//}
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		Probability(n);
//	}
//	return 0;
//}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string Judge(string s1, string s2)
{
	vector<string> v;
	string s;
	int flag = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] == '"')
		{
			flag ^= 1;
			continue;
		}
		else if (s1[i] == ',')
		{
			if (flag == 1)
				s += s1[i];
			else
			{
				v.push_back(s);
				s.clear();
			}
		}
		else
			s += s1[i];
	}
	v.push_back(s);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == s2)
			return "Ignore";
	}
	return "Important!";
}

int main()
{
	string s1;
	string s2;
	while (getline(cin,s1))
	{
		getline(cin, s2);
		cout << Judge(s1, s2) << endl;
	}
}