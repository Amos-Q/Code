#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<set>
//
//using namespace std;
//
//int main()
//{
//	set<int> v;
//	v.insert(1);
//	v.insert(3);
//	v.insert(5);
//	v.insert(2);
//	v.insert(4);
//	v.insert(3);
//
//	//中序遍历 升序遍历
//	for (set<int>::iterator it = v.begin(); it != v.end(); ++it)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	for (set<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); ++rit)
//	{
//		cout << *rit << " ";
//	}
//	cout << endl;
//
//	return 0;
//}
//
//#include<iostream>
//#include<set>
//
//using namespace std;
//struct Comp
//{
////重载()
//	bool operator()(const int &a, const int &b)
//	{
//		return a > b;
//	}
//};
//int main()
//{
//	set<int, Comp> v;
//	v.insert(1);
//	v.insert(3);
//	v.insert(5);
//	v.insert(2);
//	v.insert(4);
//	v.insert(3);
//	for (set<int, Comp>::iterator it = v.begin(); it != v.end(); ++it)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	for (set<int, Comp>::reverse_iterator rit = v.rbegin(); rit != v.rend(); ++rit)
//	{
//		cout << *rit << " ";
//	}
//	cout << endl;
//	return 0;
//}

#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
	map<string, double> m;
	//声明即插入
	m["li"] = 123.4;
	m["wang"] = 23.1;
	m["zhang"] = -21.9;
	m["abc"] = 12.1;
	for (map<string, double>::iterator it = m.begin(); it != m.end(); ++it)
	{
		//first --> key second --> value
		cout << (*it).first << ":" << (*it).second << endl;
	}
	cout << endl;
	return 0;
}