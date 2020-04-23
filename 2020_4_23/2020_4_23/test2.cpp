//#include <iostream>
//using namespace std;
//
//class Solution {
//public:
//	Solution()
//	{
//		cout << "Solution()" << endl;
//	}
//
//	int Sum_Solution(int n) {
//		// ...
//		cout << "Sum_Solution()" << endl;
//
//		return n;
//	}
//
//	~Solution()
//	{
//		cout << "~Solution()" << endl;
//	}
//};
//
//int main()
//{
//	Solution s1; // s1的声明周期在main函数中
//	s1.Sum_Solution(10);
//
//	//Solution();  // 匿名对象 声明周期就在这一行
//	Solution().Sum_Solution(10);  //只有我这一行会使用这个创建对象，别人不需要使用
//
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int year, month, day;
//	// 这样可以不断接收输入，直到按ctrl + c就结束
//	while (cin >> year >> month >> day)
//	{
//		int n = 0;
//		// 累加1-month-1月的天数
//		for (int i = 1; i < month; ++i)
//		{
//			n += monthDays[i];
//		}
//		// 累加month那个月的天数
//		n += day;
//
//		// 瑞年+1天
//		if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//		{
//			n += 1;
//		}
//
//		cout << n << endl;
//	}
//
//	return 0;
//}
#include <iostream>
using namespace std;

//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//
//class B
//{
//public:
//	B()
//	{
//		cout << "B()" << endl;
//	}
//
//	~B()
//	{
//		cout << "~B()" << endl;
//	}
//};
//
//class C
//{
//public:
//	C()
//	{
//		cout << "C()" << endl;
//	}
//
//	~C()
//	{
//		cout << "~C()" << endl;
//	}
//};
//
//class D
//{
//public:
//	D()
//	{
//		cout << "D()" << endl;
//	}
//
//	~D()
//	{
//		cout << "~D()" << endl;
//	}
//};

//C c;
//int main()
//{
//	A a;
//	B b;
//	static D d;
//
//	return 0;
//}
// C  A  B  D
// ~B ~A ~D ~C

class Widget
{
public:
	Widget()
	{}

	Widget(const Widget& w)
	{
		cout << "Widget(const Widget& w)" << endl;
	}
};

Widget f(Widget u)
{
	Widget v(u);
	Widget w = v;
	return w;
}

//void main(){
//	Widget x;
//	Widget y = f(f(x));
//
//	int* p = nullptr;
//	cout << sizeof(p) << endl;
//}

//int main()
//{
//	// C 函数
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p3 = (int*)malloc(sizeof(int)*10);
//	free(p1);
//	free(p3);
//	
//	// C++ 操作符
//	//int* p2 = new int;
//	int* p2 = new int(10); // 申请一个int4个字节空间，初始化成10
//	int* p4 = new int[10]; // 申请10个int的40个字节空间
//
//	delete p2;
//	delete[] p4;
//
//	return 0;
//}

// 既然已经有了malloc和free，new和delete的意义何在？
// 1、对于上面内置类型，他们效果是一样的。
// 2、对于自定义类型，效果就不一样。malloc只申请空间。new 申请空间+构造函数初始化
// free只释放空间，delete 析构函数+释放空间
class A
{
public:
	A(){
		_a = 0;
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
}; 

class B
{
public:
	B(){
		_a = 0;
		cout << "B()" << endl;
	}

	~B()
	{
		cout << "~B()" << endl;
	}
private:
	int _a;
};

//A a1;
//B b1;
int main()
{
	// 内置类型
	int* p1 = new int;
	int* p2 = (int*)malloc(sizeof(int));

	// 自定义类型
	A* p3 = (A*)malloc(sizeof(A)); // 申请空间
	A* p4 = new A;                 // 申请空间+构造函数初始化

	free(p3);					  // 释放空间
	delete p4;                    // 析构函数+释放空间

	return 0;
}