#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

void Luck(vector<vector<int>> vv)
{
	int sum = 0;
	for (int i = 0; i < vv.size(); i++)
	{
		vector<int> v = vv[i];
		int sum1 = v[0];
		int sum2 = v[0];
		for (int j = 1; j < v.size(); j++)
		{
			sum1 += v[j];
			sum2 *= v[j];
		}
		if (sum1 > sum2)
			sum++;
	}
	cout << sum << endl;
}

void Distribute(vector<vector<int>> &vvv, vector<int> v,int n)
{
	long long sum = pow(2, n);
	for (int i = 1; i < sum; i++)
	{
		vector<int> vv;
		int x = 0;
		while (x < n)
		{
			if ((i >> x & 1) == 1)
			{
				vv.push_back(v[x]);
			}
			x++;
		}
		vvv.push_back(vv);
	}
	for (int i = 0; i < vvv.size(); i++)
	{
		for (int j = i + 1; j < vvv.size(); j++)
		{
			if (vvv[i] == vvv[j])
			{
				vvv.erase(vvv.begin() + j);
				j--;
			}
		}
	}
}

int main()
{
	vector<vector<int>> vvv;
	vector<int> v;
	int n = 0;
	cin >> n;
	int val = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		v.push_back(val);
	}
	Distribute(vvv, v, n);
	Luck(vvv);
	system("pause");
	return 0;
}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//void Getday(int year, int month, int day)
//{
//	int monthday[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	int sum = 0;
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//		sum += 1;
//	for (int i = 0; i < month - 1; i++)
//		sum += monthday[i];
//	sum += day;
//	cout << sum << endl;
//}
//
//int main()
//{
//	int year = 0;
//	int month = 0;
//	int day = 0;
//	cin >> year >> month >> day;
//	Getday(year, month, day);
//	system("pause");
//	return 0;
//}