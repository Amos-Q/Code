#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool Judge(string a, string b)
{
	if (a.size() > b.size())
		return true;
	else if (a.size() == b.size())
		return a > b;
	else
		return false;
}

string Add(string a, string b)
{
	int end1 = a.size() - 1;
	int end2 = b.size() - 1;
	int sum = 0;
	string ret;
	int flag = 0;
	while (end1 >= 0 && end2 >= 0)
	{
		sum = (a[end1] - '0') + (b[end2] - '0') + flag;
		flag = 0;
		if (sum > 9)
		{
			sum %= 10;
			flag = 1;
		}
		ret += sum + '0';
		end1--;
		end2--;
	}
	while (end1 >= 0)
	{
		sum = (a[end1] - '0') + flag;
		flag = 0;
		if (sum > 9)
		{
			sum %= 10;
			flag = 1;
		}
		ret += sum + '0';
		end1--;
	}
	while (end2 >= 0)
	{
		sum = (b[end2] - '0') + flag;
		flag = 0;
		if (sum > 9)
		{
			sum %= 10;
			flag = 1;
		}
		ret += sum + '0';
		end2--;
	}
	if(flag == 1)
		ret += flag + '0';
	reverse(ret.begin(),ret.end());
	return ret;
}

int main()
{
	string a, b, c;
	while (cin >> a >> b >> c)
	{
		if (Judge(Add(a, b), c) && Judge(Add(a, c), b) && Judge(Add(b, c), a))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}