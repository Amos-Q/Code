#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//long int Failrec(int n)
//{
//	if (n < 2)
//		return 0;
//	if (n == 2)
//		return 1;
//	if (n == 3)
//		return 2;
//	return (n - 1)*(Failrec(n - 1) + Failrec(n - 2));
//}
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		cout << Failrec(n) << endl;
//	}
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Judge(vector<int> v)
{
	vector<int> maxlen(v.size(), 1);
	int c = 1;
	for (int i = 1; i < v.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j])
			{
				maxlen[i] = max(maxlen[i], maxlen[j] + 1);
			}
		}
		c = max(c, maxlen[i]);
	}
	cout << c << endl;
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		Judge(v);
	}
}