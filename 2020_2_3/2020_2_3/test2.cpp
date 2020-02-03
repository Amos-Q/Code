#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a;
	cin >> a;
	int k = a.length();
	//排序
	for (int i = 0; i < k; i++)
	{
		for (int j = i; j < k; j++)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}

	//找出第一个非零的数
	int nozero = -1;
	for (int i = 0; i < k; i++)
	{
		if (a[i] != '0')
		{
			nozero = i;
			break;
		}
	}
	if (nozero != -1)
	{
		swap(a[0], a[nozero]);
	}
	cout << a;

	getchar();
	getchar();
}