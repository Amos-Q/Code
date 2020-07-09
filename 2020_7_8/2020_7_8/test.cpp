#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <math.h>
//using namespace std;
//
//int month_day(int year, int month)
//{
//	int day[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	if (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0)
//		day[1] += 1;
//	return day[month - 1];
//}
//
//int Prime(int month)
//{
//	int prime[] = { 2,1,1,2,1,2,1,2,2,2,1,2 };
//	return prime[month - 1];
//}
//
//int Income(int year1, int month1, int day1, int year2, int  month2, int day2)
//{
//	int come = 0;
//	while (year1 < year2)
//	{
//		while (1)
//		{
//			while (1)
//			{
//				come += (month_day(year1, month1) - day1 + 1)*Prime(month1);
//				day1 = 1;
//				break;
//			}
//			month1++;
//			if (month1 > 12)
//			{
//				month1 -= 12;
//				break;
//			}
//		}
//		year1++;
//	}
//	while (month1 < month2)
//	{
//		while (1)
//		{
//			come += (month_day(year1, month1) - day1 + 1)*Prime(month1);
//			day1 = 1;
//			break;
//		}
//		month1++;
//	}
//	come += (day2 - day1 + 1) * Prime(month1);
//	return come;
//}
//
//
//int main()
//{
//	int year1, month1, day1, year2, month2, day2;
//	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
//	{
//		cout << Income(year1, month1, day1, year2, month2, day2) << endl;
//	}
//}

#include <iostream>
#include <vector>
using namespace std;

vector<int> Fibonacci()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.resize(100001);
	for (int i = 2; i < 100001; i++)
	{
		v[i] = v[i - 1] + v[i - 2];
		v[i] %= 1000000;
	}
	return v;
}

int main()
{
	int n = 0;
	vector<int> v;
	v = Fibonacci();
	while (cin >> n)
	{
		if (n > 29)
			printf("%06d\n", v[n - 1]);
		else
			cout << v[n - 1] << endl;
	}
}