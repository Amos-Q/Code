#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <iostream>
#include <vector>
using namespace std;

void Repeat(string s1, string s2)
{
	int max = 0, maxadd = 0;
	int begin = 0;
	int i = 0;
	int j = 0;
	vector<vector<int>> vv;
	for (int i = 0; i < s1.size(); i++)
	{
		for (int j = 0; j < s2.size(); j++)
		{
			if (s1[i] == s2[j])
			{
				vector<int> v;
				v.push_back(i);
				v.push_back(j);
				int len = 0;
				while (i < s1.size() && j < s2.size() && s1[i] == s2[j])
				{
					len++;
					i++;
					j++;
				}
				v.push_back(len);
				vv.push_back(v);
				i = v[0];
				j = v[1];
			}
		}
	}
	for (int i = 0; i < vv.size(); i++)
	{
		if (vv[i][2] > max)
		{
			max = vv[i][2];
			maxadd = i;
		}
	}
	for (int i = 0; i < vv[maxadd][2]; i++)
	{
		cout << s1[vv[maxadd][0] + i];
	}
	cout << endl;
}

int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		if (str1.size() < str2.size())
			Repeat(str1, str2);
		else
			Repeat(str2, str1);
	}
	system("pause");
	return 0;
}

//
//#include<iostream>
//using namespace std;
//
//void Judge(int n)
//{
//	int drink = 0;
//	int k = 0;
//	while (n > 2)
//	{
//		drink += n / 3;
//		k = n / 3;
//		n = k + n % 3;
//	}
//	if (n == 2)
//		drink += 1;
//	cout << drink << endl;
//}
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//		Judge(n);
//	system("pause");
//	return 0;
//}