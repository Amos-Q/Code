#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<stack>
//#include<string>
//using namespace std;
//int main() {
//	stack<int> s1;
//	int n;
//	while (cin >> n)
//	{
//		for (int i = 0; i < n; i++) {
//			string s;
//			cin >> s;
//			if (s[0] >= '0'&&s[0] <= '9') {
//				int num = 0;
//				for (int i = 0; i < s.length(); i++)
//					num = num * 10 + s[i] - '0';
//				s1.push(num);
//			}
//			else {
//				int x = s1.top(); s1.pop();
//				int y = s1.top(); s1.pop();
//				if (s == "+")       s1.push(x + y);
//				else if (s == "-")  s1.push(y - x);
//				else if (s == "*")  s1.push(x*y);
//				else if (s == "/")  s1.push(y / x);
//			}
//		}
//		cout << s1.top() << endl;
//	}
//	return 0;
//}


// write your code here cpp
// write your code here cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool Check(vector<vector<char>> vv, int i, int j, char c)
{
	int sum = 0;
	for (int x = i; x < i + 5 && i < 20; x++)
	{
		if (vv[x][j] == c)
			sum++;
	}
	if (sum >= 5)
		return true;
	sum = 0;
	for (int y = j; y < j + 5 && y < 20; y++)
	{
		if (vv[i][y] == c)
			sum++;
	}
	if (sum >= 5)
		return true;
	sum = 0;
	for (int x= i, y = j;x < i + 5 && x < 20 && y < j + 5 && y < 20; x++, y++)
	{
		if (vv[x][y] == c)
			sum++;
	}
	if (sum >= 5)
		return true;
	return false;
}

string Judge(vector<vector<char>> vv)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (vv[i][j] == '*' || vv[i][j] == '+')
			{
				if (Check(vv, i, j, vv[i][j]))
					return "Yes";
			}
		}
	}
	return "No";
}

int main()
{
	while (1)
	{
		vector<vector<char>> vv(20, vector <char>(20));
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				cin >> vv[i][j];
			}
		}
		cout << Judge(vv) << endl;
	}
}