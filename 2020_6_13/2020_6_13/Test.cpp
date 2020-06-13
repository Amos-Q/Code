#include <iostream>
using namespace std;

//#include<iostream>
//using namespace std;
//class A{
//public:
//	A(char *s) { cout << s << endl; }
//	~A(){}
//};
//
//class B :virtual public A
//{
//public:
//	B(char *s1, char*s2) :A(s1) { cout << s2 << endl; }
//};
//
//class C :virtual public A
//{
//public:
//	C(char *s1, char*s2) :A(s1) { cout << s2 << endl; }
//};
//
//class D :public B, public C
//{
//public:
//	D(char *s1, char *s2, char *s3, char *s4) :B(s1, s2), C(s1, s3), A(s1)
//	{
//		cout << s4 << endl;
//	}
//};
//
//int main() {
//	D *p = new D("class A", "class B", "class C", "class D");
//	delete p;
//	return 0;
//}


//class A
//{
//public:
//	virtual ~A()
//	{
//		cout << "A::~A()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	virtual ~B()
//	{
//		cout << "B::~B()" << endl;
//	}
//};
//
//int main()
//{
//	A* p = new B;
//	delete p; // p->destruator() + operator delete(p)
//
//	return 0;
//}

// 1.虚函数，  ->概念：虚函数重写是多态的条件之一  
//             ->多态原理：虚函数地址放到对象的虚表(虚函数表)中，多态指向谁调用本质是运行到对象虚表找要调用的虚函数。
// 2.虚继承，  ->概念：解决菱形继承中的数据冗余和二义性
//             ->原理：将虚基类对象放到公共位置(vs是放到整个对象尾部)，虚基表中存偏移量，来计算虚基类对象的位置。

// 总结：记住这里两个地方都用virtual关键字，他们之间没有一点关联，不要联系到一起。

//int& a = b;  // 引用
//int* p = &a; // 取地址

// 以上都不要混到一起

//class A
//{
//public:
//	int _a;
//};
//
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._a = 6;
//
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	printf("虚基表：%p\n", *(int*)&d);
//	static int x = 1;
//	char* p = "hello world";
//	printf("数据段：%p\n", &x);
//	printf("代码段(常量区)：%p\n", p);
//
//	return 0;
//}


#include "BSTree.hpp"

int main()
{
	TestBSTree();

	return 0;
}