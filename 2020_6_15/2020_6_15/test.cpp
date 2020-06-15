#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//using namespace std;
//
//bool Prime(int num)
//{
//	int flag = 0;
//	int j = 0;
//	for (j = 1; j < num; j++)
//	{
//		if (num % j != 0)
//			flag++;
//	}
//	if (flag == (num - 2))
//		return true;
//	return false;
//}
//
//void Min(int n)
//{
//	vector<int> v;
//	int min = 99999;
//	int min1 = 0;
//	int i = 0;
//	int j = 0;
//	for (i = 2; i < n; i++)
//	{
//		if (Prime(i))
//			v.push_back(i);
//	}
//	for (i = 0; i < v.size(); i++)
//	{
//		if (Prime(n - v[i]))
//		{
//			if ((n - v[i] - v[i] >= 0) && (n - v[i] - v[i] < min))
//			{
//				min = n - v[i] - v[i];
//				min1 = v[i];
//			}
//		}
//	}
//	cout << min1 << endl;
//	cout << n - min1 << endl;
//}
//
//int main()
//{
//	int N = 0;
//	while(cin >> N)
//		Min(N);
//	system("pause");
//	return 0;
//}

#include <iostream>
using namespace std;

int main()
{
	int i = 0;
	int j = 0;
	i = 4355;
	j = 4 << 1;
	cout << (i|j);
	system("pause");
	return 0;
}