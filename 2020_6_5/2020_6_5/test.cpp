//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//bool hw(string str)
//{
//	int right = str.size() - 1;
//	int left = 0;
//	while (left < right)
//	{
//		if (str[left] == str[right])
//		{
//			left++;
//			right--;
//		}
//		else
//			return false;
//	}
//	return true;
//}
//
//int main()
//{
//	string A;
//	string B;
//	cin >> A >> B;
//	int num = 0;
//	for (int i = 0; i <= A.size(); i++)
//	{
//		string A2;
//		A2 = A;
//		A2.insert(i, B);
//		if (hw(A2))
//			num++;
//	}
//	cout << num;
//	system("pause");
//	return 0;
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> v;
//	v.resize(n);
//	for (int i = 0; i < n; i++)
//		cin >> v[i];
//	int sum = 0;
//	int max = -9999999;
//	for (int i = 0; i < v.size(); i++)
//	{
//		sum += v[i];
//		if (sum > max)
//			max = sum;
//		if (sum < 0)
//			sum = 0;
//	}
//	cout << max;
//	system("pause");
//	return 0;
//}


#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

struct A {

	char a : 1;
	char b : 8;

};

int main()
{
	int t = sizeof(struct A);
	cout << t << endl;
	system("pause");
	return 0;

}