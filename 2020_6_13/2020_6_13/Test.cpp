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

// 1.�麯����  ->����麯����д�Ƕ�̬������֮һ  
//             ->��̬ԭ���麯����ַ�ŵ���������(�麯����)�У���ָ̬��˭���ñ��������е����������Ҫ���õ��麯����
// 2.��̳У�  ->���������μ̳��е���������Ͷ�����
//             ->ԭ������������ŵ�����λ��(vs�Ƿŵ���������β��)��������д�ƫ���������������������λ�á�

// �ܽ᣺��ס���������ط�����virtual�ؼ��֣�����֮��û��һ���������Ҫ��ϵ��һ��

//int& a = b;  // ����
//int* p = &a; // ȡ��ַ

// ���϶���Ҫ�쵽һ��

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
//	printf("�����%p\n", *(int*)&d);
//	static int x = 1;
//	char* p = "hello world";
//	printf("���ݶΣ�%p\n", &x);
//	printf("�����(������)��%p\n", p);
//
//	return 0;
//}


#include "BSTree.hpp"

int main()
{
	TestBSTree();

	return 0;
}