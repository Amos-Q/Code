#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	cout << "please input the number:" << endl;
	string str;
	cin >> str;
	int str_length = str.length();
	int *a = new int[str_length];

	for (int i = 0; i < str_length; i++)
	{
		a[i] = str[i] - '0';
	}


	int k = str_length;
	//排序
	for (int i = 0; i < k; i++)
	{
		for (int j = i; j < k; j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	//找出第一个非零的数
	int nozero = -1;
	for (int i = 0; i < k; i++)
	{
		if (a[i] != 0)
		{
			nozero = i;
			break;
		}
	}
	if (nozero != -1)
	{
		int temp = a[0];
		a[0] = a[nozero];
		a[nozero] = temp;
	}

	ostringstream oss;
	string c;
	string d;
	for (int i = 0; i < k; i++)
	{
		oss << a[i];
		c = oss.str();
		d += c;
	}
	cout << c;

	delete[]a;
	getchar();
	getchar();
}