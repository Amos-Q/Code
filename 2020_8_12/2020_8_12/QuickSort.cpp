#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

void Quick_Sort(vector<int> &v, int left, int right)
{
	if(left < right)
	{
		int i = left, j = right;
		int temp = v[i];
		while (i < j)
		{
			while (i < j&&v[j] >= temp)
				j--;
			if (i < j)
			{
				v[i] = v[j];
				i++;
			}
			while (i < j&&v[i] <= temp)
				i++;
			if (i < j)
			{
				v[j] = v[i];
				j--;
			}
			v[i] = temp;
		}
		Quick_Sort(v, left, i - 1);
		Quick_Sort(v, i + 1, right);
	}
}

int main()
{
	vector<int> v = { 74,36,37,5,23,74};
	Quick_Sort(v, 0, v.size() - 1);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
	}
	system("pause");
}