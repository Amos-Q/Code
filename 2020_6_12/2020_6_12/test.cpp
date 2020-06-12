#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

void Maxnum(int b)
{
	int max = 0;
	int num = 0;
	vector<int> v;
	while (b > 1)
	{
		v.push_back(b % 2);
		b /= 2;
	}
	v.push_back(b);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == 1)
			num++;
		else
		{
			if (num > max)
				max = num;
			num = 0;
		}
	}
	if (num > max)
		max = num;
	cout << max << endl;
}

int main()
{
	int byte = 0;
	while (cin >> byte)
		Maxnum(byte);
	return 0;
}