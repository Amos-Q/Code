#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//int Sum(int n)
//{
//	int i = 0;
//	while (i++)
//	{
//		if (pow(3, i) > n)
//			return i;
//	}
//}
//
//int main()
//{
//	int n = 0;
//	while (cin >> n && n != 0)
//	{
//		cout << Sum(n) << endl;
//	}
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getFirstUnFormedNum(vector<int> arr, int len) {
	int min = INT_MAX;
	int sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] < min)
			min = arr[i];
		sum += arr[i];
	}
	vector<int> dp(sum + 1, 0);
	for (int i = 0; i < len; ++i)
	{
		for (int j = sum; j >= arr[i]; --j)
		{
			if (dp[j - arr[i]] + arr[i] > dp[j])
			{
				dp[j] = dp[j - arr[i]] + arr[i];
			}
		}
	}
	for (int i = min; i <= sum; ++i)
	{
		if (i != dp[i])
			return i;
	}
	return sum + 1;
}

int main()
{
	vector<int> vv;
	vv.push_back(2);
	vv.push_back(3);
	vv.push_back(4);
	getFirstUnFormedNum(vv,3);
}