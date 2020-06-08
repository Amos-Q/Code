#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int Fibonacci(int n)
//{
//	vector<int> v;
//	v.push_back(0);
//	v.push_back(1);
//	int i = 1;
//	while (v[i] <= n)
//	{
//		v.push_back(v[i] + v[i - 1]);
//		i++;
//	}
//	return (n - v[i - 1]) < (v[i] - n) ? (n - v[i - 1]) : (v[i] - n);
//}
//
//int main()
//{
//	int N = 0;
//	cin >> N;
//	cout << Fibonacci(N);
//	system("pause");
//	return 0;
//}
//#include <iostream>
//#include <stack>
//using namespace std;
//
//bool chkParenthesis(string A, int n)
//{
//	// write code here
//	stack<char> st;
//	int i = 0;
//	while (i < n)
//	{
//		if (i < n && A[i] == '(')
//		{
//			st.push(A[i]);
//			i++;
//			continue;
//		}
//		if (i < n && A[i] == ')')
//		{
//			if (st.top() == '(')
//			{
//				st.pop();
//				i++;
//				continue;
//			}
//			else
//				return false;
//		}
//		else
//			return false;
//	}
//	if (st.empty())
//		return true;
//	else
//		return false;
//}
//
//int main()
//{
//	cout << chkParenthesis("(()()())", 8);
//}


#include<iostream>
using namespace std;

//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//{
////A::fun();
//cout << "func(int i)->" << i << endl;
//}
//};
//int main()
//{
//	A a;
//	B b;
//	a = b;
//	b.fun();
//	system("pause");
//}
class Person{
public:
virtual void BuyTicket() { cout << "ÂòÆ±-È«¼Û" << endl; }
};
class Student : public Person {
public:
	virtual void BuyTicket() { cout << "ÂòÆ±-°ë¼Û" << endl; }
};
void Func(Person& p)
{
	p.BuyTicket();
}
int main()
{
	Person Mike;
	Mike.BuyTicket();
	//Func(Mike);
	Student Johnson;
	Johnson.BuyTicket();
	//Func(Johnson);
	system("pause");
	return 0;
}
