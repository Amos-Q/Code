#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int Sum(int n)
//{
//	vector<int> v(n,0);
//	v.resize(n);
//	v[0] = 1;
//	v[1] = 2;
//	for (int i = 2; i < n; i++)
//	{
//		v[i] = v[i - 1] + v[i - 2];
//	}
//	return v[n - 1];
//}
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		cout << Sum(n) << endl;
//	}
//}


#include <iostream>
#include <vector>
using namespace std;

int house(int* person, int personLen) {
	// write code here
	vector<int> v;
	for (int i = 0; i < personLen; i++)
	{
		v.push_back(*(person + i));
	}
	int min = INT_MAX;
	int minadd = 0;
	vector<int> ps(personLen, 0);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < min)
			min = v[i];
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == min)
		{
			ps[i] = 1;
			minadd = i;
		}
	}
	ps[minadd] = 1;
	int minl = minadd;
	int minr = minadd;
	int left = minadd - 1;
	int right = minadd + 1;
	while (left >= 0)
	{
		if (v[left] > v[minl])
			ps[left] = ps[minl]+1;
		else
			ps[left] = ps[minadd];
		left--;
		minl--;
	}
	while (right <= personLen)
	{
		if (v[right] > v[minr])
			ps[right] = ps[minr]+1;
		else
			ps[right] = ps[minadd];
		right++;
		minr++;
	}
	int cout = 0;
	for (int i = 0; i < personLen; i++)
	{
		cout += ps[i];
	}
	return cout;
}

int main()
{
	int person[] = { 3,5,4,2,1 };
	int personLen = 5;
	cout << house(person, personLen) << endl;
}