#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//using namespace std;
//
//void Sum(int m)
//{
//	vector<vector<int>> vv;
//	vector<int> root;
//	root.push_back(1);
//	root.push_back(1);
//	vv.push_back(root);
//	int pass = 0;
//	m -= 2;
//	while (m--)
//	{
//		vector<int> v;
//		v.push_back(0);
//		int sum = 0;
//		if (++pass >= 2)
//		{
//			vv[pass-2][0] = 1;
//		}
//		for (int i = 0; i < vv.size(); i++)
//		{
//			if (vv[i][0] == 1)
//			{
//				sum += vv[i][1];
//			}
//		}
//		v.push_back(sum);
//		vv.push_back(v);
//	}
//	int out = 0;
//	for (int i = 0; i < vv.size(); i++)
//	{
//		out += vv[i][1];
//	}
//	cout << out << endl;
//}
//
//int main()
//{
//	int month = 0;
//	while(cin >> month)
//		Sum(month);
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//bool Judge(string s1, string s2, int p1, int p2)
//{
//	int begin1 = 0, begin2 = 0;
//	while (begin1 < s1.size() || begin2 < s2.size())
//	{
//		if (s1[begin1] == s2[begin2])
//		{
//			begin1++;
//			begin2++;
//		}
//		else if (s1[begin1] == '?')
//		{
//			begin1++;
//			begin2++;
//		}
//		else if (s1[begin1] == '*')
//		{
//			int next1 = begin1 + 1;
//			if (s1[next1] == '*')
//				begin1++;
//			else if (s1[next1] == '\0')
//				return true;
//			else
//			{
//				int next2 = begin2;
//				while (next2 < s2.size())
//				{
//					if (s1[next1] == s2[next2])
//						if (Judge(s1, s2, next1, next2))
//							return true;
//					next2++;
//				}
//			}
//		}
//		else
//			return false;
//	}
//	if (s1[begin1] == '*' && s1[begin1 + 1] == '\0')
//		return true;
//	else if (s1[begin1] != '\0' || s2[begin2] != '\0')
//		return false;
//	return true;
//}
//
//int main()
//{
//	string str1;
//	string str2;
//	while (cin >> str1 >> str2)
//	{
//		int pos1 = 0, pos2 = 0;
//		if (Judge(str1, str2, pos1, pos2))
//			cout << "true" << endl;
//		else
//			cout << "false" << endl;
//	}
//	system("pause");
//	return 0;
//}

#include <iostream>
using namespace std;

class A {
public:
	 ~A() {
		cout << "~A()";
	}
};
class B {
public:
	 ~B() {
		cout << "~B()";
	}
};
class C : public A, public B {
public:
	~C() {
		cout << "~C()";
	}
};
int main() {
	C * c = new C;
	B * b1 = dynamic_cast<B *>(c);
	//A * a2 = dynamic_cast<A *>(b1);
	delete b1;
	system("pause");
	return 0;
}