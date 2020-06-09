#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int Max(int a, int b)
//{
//	return a > b ? a : b;
//}
//
//void Mcm(int a, int b)
//{
//	int max = Max(a, b);
//	while (1)
//	{
//		if (max%a == 0 && max % b == 0)
//			break;
//		max++;
//	}
//	cout << max;
//}
//int main()
//{
//	int A = 0;
//	int B = 0;
//	cin >> A >> B;
//	Mcm(A, B);
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Judge(string *str, int n)
{
	string tmp;
	vector<int> v;
	v.resize(2);
	tmp = str[0];
	int i = 1;
	while (1)
	{
		while (i < n && tmp >= str[i])
		{
			tmp = str[i];
			i++;
		}
		if (i == n)
			v[0] = 1;
		tmp = str[0];
		i = 1;
		while (i < n && tmp <= str[i])
		{
			tmp = str[i];
			i++;
		}
		if (i == n)
			v[0] = 1;
		tmp = str[0];
		i = 1;
		while (i < n && tmp.size() >= str[i].size())
		{
			tmp = str[i];
			i++;
		}
		if (i == n)
			v[1] = 1;
		tmp = str[0];
		i = 1;
		while (i < n && tmp.size() <= str[i].size())
		{
			tmp = str[i];
			i++;
		}
		if (i == n)
			v[1] = 1;
		break;
	}
	if (v[0] == 1 && v[1] == 1)
		cout << "both";
	else if (v[0] == 1)
		cout << "lexicographically";
	else if (v[1] == 1)
		cout << "lengths";
	else
		cout << "none";
}

int main()
{
	int n = 0;
	cin >> n;
	string *str = new string[n];
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	Judge(str,n);
	system("pause");
	return 0;
}