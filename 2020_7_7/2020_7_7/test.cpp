#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//#include <math.h>
//#include <algorithm>
//using namespace std;
//
//bool Prime(int n)
//{
//	int sum = 0;
//	for (int i = 2; i <= sqrt(n); i++)
//	{
//		if (n%i == 0)
//			sum++;
//	}
//	if (sum == 0)
//		return true;
//	else
//		return false;
//}
//
//void Factor(int n)
//{
//	cout << n << ' ' << '=' << ' ';
//	int sum = 1;
//	vector<int> v;
//	while (!Prime(n))
//	{
//		for (int i = 2; i < n; i++)
//		{
//			if (n%i == 0)
//			{
//				v.push_back(i);
//				n /= i;
//				break;
//			}
//		}
//	}
//	if (n != 1)
//		v.push_back(n);
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (i != 0)
//			cout << ' ' << '*' << ' ';
//		cout << v[i];
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		Factor(n);
//	}
//}


#include <iostream>
using namespace std;
int dweek(int year, int month, int day)
{
	if (month == 1 || month == 2)
	{
		month += 12;
		year -= 1;
	}
	int c = year / 100;
	year = year % 100;
	int week = year + (year / 4) + (c / 4) - 2 * c + 26 * (month + 1) / 10 + day - 1;
	week = week % 7;
	if (week == 0)
	{
		week = 7;
	}
	return week;
}

int demand(int year, int month, int count, int d_week)
{
	int week = dweek(year, month, 1);
	int day = 1 + (count - 1) * 7 + ((7 - week) + d_week) % 7;
	if (day > 31)
		day -= 7;
	return day;
}

int main()
{
	int y;
	while (cin >> y)
	{
		cout << y << "-01-01" << endl;
		printf("%d-01-%02d\n", y, demand(y, 1, 3, 1));
		printf("%d-02-%02d\n", y, demand(y, 2, 3, 1));
		printf("%d-05-%02d\n", y, demand(y, 5, 5, 1));//µ¹Êý
		cout << y << "-07-04" << endl;
		printf("%d-09-%02d\n", y, demand(y, 9, 1, 1));
		printf("%d-11-%02d\n", y, demand(y, 11, 4, 4));
		cout << y << "-12-25" << endl << endl;
	}
}