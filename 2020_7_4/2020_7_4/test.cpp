#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

void oddInOddEvenInEven(vector<int>& arr, int len) 
{
	vector<int> ret;
	ret.resize(2 * len);
	int o = 0;
	int j = 1;
	int i = 0;
	while (i < len)
	{
		if (arr[i] % 2 == 0)
		{
			ret[o] = arr[i];
			o += 2;
		}
		else
		{
			ret[j] = arr[i];
			j += 2;
		}
		i++;
	}
	int t = 0;
	while (t < ret.size())
	{
		if (ret[t] == 0)
			ret.erase(ret.begin() + t);
		else
			t++;
	}
	arr = ret;
}

int main()
{
	vector<int> arr;
	int len = 0;
	while (cin >> len)
	{
		int x = 0;
		for (int i = 0; i < len; i++)
		{
			cin >> x;
			arr.push_back(x);
		}
		oddInOddEvenInEven(arr, len);
	}
	system("pause");
}
