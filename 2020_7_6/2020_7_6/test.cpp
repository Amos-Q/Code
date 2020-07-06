#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//using namespace std;
//
//string deciphering(string s)
//{
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] == ' ')
//			continue;
//		s[i] -= 5;
//		if (s[i] < 65)
//			s[i] += 26;
//	}
//	return s;
//}
//
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		cout << deciphering(str) << endl;
//	}
//}


#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

bool Prime(int n)
{
	int sum = 0;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			sum++;
	}
	if (sum == 0)
		return true;
	else
		return false;
}

int Factor(int n)
{
	int sum = 1;
	vector<int> v;
	while (!Prime(n))
	{
		for (int i = 2; i < n; i++)
		{
			if (n%i == 0)
			{
				v.push_back(i);
				n /= i;
				break;
			}
		}
	}
	if(n != 1)
		v.push_back(n);
	sort(v.begin(),v.end());
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] == v[i - 1])
		{
			v.erase(v.begin() + i);
			i--;
		}
		else
			sum++;
	}
	return sum;
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		cout << Factor(n) << endl;
	}
}