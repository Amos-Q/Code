#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//	vector<int> v;
//	for (int i = 0; i < 10; ++i)
//	{
//		v.push_back(i);
//	}
//	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	reverse(v.begin(), v.end()); //数组转置
//
//
//	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	return 0;
//}
//
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//bool Comp(const int &a, const int &b)
//{
//	return a > b;
//}
//
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(3);
//	v.push_back(2);
//	v.push_back(55);
//	v.push_back(-1);
//	v.push_back(0);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	//默认升序
//	sort(v.begin(), v.end());
//
//
//	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	//用降序 需要自定义一个降序函数
//	sort(v.begin(), v.end(), Comp);
//
//
//	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

int main()
{
	string s1;
	s1 = "hello";

	string s2;
	char s[1024];
	//scanf 输入速度比cin快的多
	//scanf 是C函数，不可以输入string
	scanf("%s", s);
	s2 = s;

	cout << s1 << endl;
	cout << s2 << endl;

	return 0;
}